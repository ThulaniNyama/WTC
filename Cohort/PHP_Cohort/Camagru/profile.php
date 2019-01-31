<?php include("config/init.php");
if (!$session->exists("loggedin"))
    redirect("index.php");

$crud->getAllWhere([
	"table" => "users",
	"where" => ["id" => $_SESSION["id"]]
]);

$user = $crud::$result[0];

if($validate::requestExists())
{
	if (isset($_POST["update"]))
	{
		$validate->setRules([
			"username" => "Username|required|min:3",
			"email"	=> "Email Address|required|email",
			"password" => "Password|required|password",
			"confirm-password" => "Confirm password|required|matches:password"
		])->validate();
		$errors = $validate->errors;

		if (count($validate->errors) == 0)
		{

			if ($user['email'] != $_POST['email'])
			{
				$crud->getAllWhere([
					"table" => "users",
					"where" => ["email" => $_POST['email']]
				]);
				if ($crud::$rowCount)
					$errors[] = "Email already in use";
			}
			if ($user['username'] != $_POST['username'])
			{
				$crud->getAllWhere([
					"table" => "users",
					"where" => ["username" => $_POST['username']]
				]);
				if ($crud::$rowCount)
					$errors[] = "Username already taken";
			}

			if (count($errors) == 0)
			{
				$crud->update([
					"table" => "users",
					"set" => [
						"username" => sanitize($_POST['username']),
						"email" => sanitize($_POST['email']),
						"password" => password_hash(sanitize($_POST['password']), PASSWORD_BCRYPT)
					],
					"where" => [
						"id" => $_SESSION["id"]
					]
				]);
				$crud->getAllWhere([
					"table" => "users",
					"where" => ["username" => $_POST["username"]]
				]);
				if ($crud::$rowCount && password_verify($_POST['password'], $crud::$result[0]["password"]))
				{
					$session->update("loggedin", $_POST["username"]);
					redirect("profile.php");
				}
			}
		}
	}
	elseif (isset($_POST["notification"]))
	{
		$crud->update([
			"table" => "users",
			"set" => ["notification" => $_POST["notification"]],
			"where" => ["id" => $session->get("id")]
		]);
		echo "Success!";
		die();
	}
	elseif (isset($_GET["delete-account"]))
	{
		$crud->delete([
			"table" => "users",
			"where" => ["id" => $_SESSION["id"]]
		]);
		redirect("index.php?logout");
	}

}

?>
<?php include("inc/header.php");?>
<h1><span class="icon icon-widget"></span> Edit Preferences </h1>
<div class="left">
	<?php include ("inc/errors.inc.php"); ?>
	<form class="form" action="?" method="post">
		<input class="input" type="text" name="username" value="<?= $user['username']; ?>" placeholder="Username">
		<input class="input" type="text" name="email" value="<?= $user['email']; ?>" placeholder="Email Address">
		<input class="input" type="password" name="password" value="<?= (isset($_POST['password'])) ? $_POST['password'] : ""; ?>" placeholder="Password">
		<input class="input" type="password" name="confirm-password" value="" placeholder="Confirm Password">
		<input class="btn shallow fill"type="submit" name="update" value="UPDATE">
	</form>
</div>

<div class="right">
	<div class="notification">
		<label for="notification"> <?= ($user["notification"]) ? "Turn off notification" : "Turn on notification"; ?></label>
		<span class="icon <?= ($user["notification"]) ? "icon-bell" : "icon-bell-slash"; ?> "></span>
	</div><br>

	<a class="btn shallow fill" href="?logout">Log out</a> <br>
	<a class="btn shallow fill-slash" href="?delete-account">Delete account</a>
</div>


<?php include("inc/footer.php");?>
