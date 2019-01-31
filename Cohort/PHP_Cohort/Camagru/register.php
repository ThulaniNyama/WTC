<?php include("config/init.php");
if ($session->exists("loggedin"))
    redirect("index.php");

if($validate::requestExists())
{
	$validate->setRules([
		"username" => "username|required|min:3",
		"email"	=> "Email Address|required|email",
		"password" => "Password|required|password",
		"confirm-password" => "Confirm password|required|matches:password"
	])->validate();
	$errors = $validate->errors;
	if (count($errors) == 0)
	{
		$username = $_POST['username'];
		$email = $_POST['email'];

		$sql = "SELECT * FROM users WHERE username='".$username."' OR email='".$email."'";
		$crud->query($sql);


		if ($crud::$rowCount)
			$errors[] = "Username or Email Address already in use";
		else
		{
			$crud->create([
				"table" => "users",
				"fields" => ["username", "email", "password"],
				"values" => [
					sanitize($_POST['username']),
					sanitize($_POST['email']),
					password_hash(sanitize($_POST['password']), PASSWORD_BCRYPT)
				]
			]);
			$code = uniqid();
			$crud->create([
				"table" => "links",
				"fields" => ["link", "user_id", "type"],
				"values" => [
					$code,
					$crud::$lastInsertedId,
					1
				]
			]);
			$username = $_POST['username'];
			$message = "Click on the link to activate your account: http://localhost:8080/camagru/login.php?code={$code}&username={$username}";

			$email = $_POST['email'];
			sendMail($email, "ACCOUNT ACTIVATION", $message);
			redirect("login.php");
		}
	}
}

if (isset($_SESSION["loggedin"]))
	redirect("index.php");
?>
<?php include("inc/header.php");?>

	<?php include("inc/errors.inc.php");?>
	<form class="form shadow" action="?" method="post">
    <h2>Camagru</h2>
		<div class="input-wrapper">
			<span class="icon icon-user"></span><input class="input" type="text" name="username" value="<?= (isset($_POST["username"])) ? $_POST["username"] : "" ?>" placeholder="Username">
		</div>
		<div class="input-wrapper">
			<span class="icon icon-at"></span><input class="input" type="text" name="email" value="<?= (isset($_POST["email"])) ? $_POST["email"] : "" ?>" placeholder="Email address">
		</div>
		<div class="input-wrapper">
			<span class="icon icon-key-fill"></span><input class="input" type="password" name="password" value="<?= (isset($_POST["password"])) ? $_POST["password"] : "" ?>" placeholder="Password">
		</div>
		<div class="input-wrapper">
			<span class="icon icon-key-fill"></span><input class="input" type="password" name="confirm-password" value="" placeholder="Confirm Password">
		</div>

		<input class="btn shallow"type="submit" name="submit" value="REGISTER">

	</form>


<?php include("inc/footer.php");?>
