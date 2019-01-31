<?php include("config/init.php");
if ($session->exists("loggedin"))
    redirect("index.php");

if (isset($_GET["code"]))
{
	$crud->getAllWhere([
		"table" => "links",
		"where" => [
			"link" => $_GET["code"],
			"type" => 1
		]
	]);
	if ($crud::$rowCount)
	{
		$crud->update([
			"table" => "users",
			"set" => ["confirmed" => 1],
			"where" => ["id" => $crud::$result[0]["user_id"]]
		]);
		$crud->delete([
			"table" => "links",
			"where" => ["link" => $_GET["code"]]
		]);
	};
}
if($validate::requestExists() && isset($_POST["login"]))
{
	$validate->setRules([
		"username" => "username|required|min:3",
		"password" => "Password|required"
	])->validate();
	$errors = $validate->errors;

	if (count($errors) == 0)
	{
		$crud->getAllWhere([
			"table" => "users",
			"where" => [
				"username" => $_POST["username"],
				"confirmed" => 1
			]
		]);
		if ($crud::$rowCount)
			$user = $crud::$result[0];
		if ($crud::$rowCount && password_verify($_POST['password'], $user["password"]))
		{
			$session->set("loggedin", $_POST["username"]);
			$session->set("id", $crud::$result[0]["id"]);
			redirect("index.php");
		}
		else
			$errors[] = "Invalid Username or Password";
	}
}

if (isset($_SESSION["loggedin"]))
	redirect("index.php");

?>
<?php include("inc/header.php");?>

<?php include("inc/errors.inc.php");?>
<form class="form shadow" action="?" method="post">
  <h2>Login</h2>

  <p>Please verify your credentials</p>
  <div class="input-wrapper">
    <span class="icon icon-user"></span><input class="input" type="text" name="username" value="<?= (isset($_GET["username"]) ? $_GET["username"] : "")?><?= (isset($_POST["username"]) ? $_POST["username"] : "")?>" placeholder="Username">
  </div>
  <div class="input-wrapper">
    <span class="icon icon-key-fill"></span><input class="input" type="password" name="password" value="" placeholder="Password">
  </div>
  <input class="btn shallow" type="submit" name="login" value="LOG IN"><br>
  <a href="forgot-password.php">Forgot Password?</a>
</form>


<?php include("inc/footer.php");?>
