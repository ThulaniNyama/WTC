<?php include("config/init.php");
if ($session->exists("loggedin"))
    redirect("index.php");

if($validate::requestExists())
{
	$validate->setRules([
		"email" => "Email address|required|email"
	])->validate();
	$errors = $validate->errors;

	if (count($errors) == 0)
	{
		$crud->getAllWhere([
			"table" => "users",
			"where" => [
				"email" => sanitize($_POST['email'])
			]
		]);
		if ($crud::$rowCount == 0)
			$errors[] = "Invalid email address, try again";
		else
		{
			$code = uniqid();
			$crud->create([
				"table" => "links",
				"fields" => ["user_id", "link", "type"],
				"values" => [
					$crud::$result[0]["id"],
					$code,
					2
				]
			]);
			$message = "Click on the link to RESET your password: http://localhost:8080/camagru/reset-password.php?code={$code}&type=2";
			$email = $_POST['email'];
			sendMail($email, "RESET PASSWORD", $message);
			redirect("login.php");
		}
	}

}
?>

<?php include("inc/header.php");?>

<?php include ("inc/errors.inc.php"); ?>
<form class="form shadow" action="?" method="post">
  <h2>Camagru</h2>

  <span>You will receive an email with the link to reset your password</span>
  <div class="input-wrapper">
    <span class="icon icon-at"></span><input class="input" type="text" name="email" value="" placeholder="Email address">
  </div>
  <input class="btn shallow"type="submit" name="submit" value="SEND EMAIL"><br>
</form>


<?php include("inc/footer.php");?>
