<?php include("config/init.php");
if ($session->exists("loggedin"))
    redirect("index.php");


if($validate::requestExists() && $_SERVER["REQUEST_METHOD"] == "POST")
{
    $validate->setRules([
        "password" => "Password|required",
        "confirm-password" => "Confirm Password|required|matches:password"
    ])->validate();
    $errors = $validate->errors;
	 $userId = $_POST["user-id"];

    if (count($errors) == 0)
    {
        $crud->update([
            "table" => "users",
            "set" => [
                "password" => password_hash(sanitize($_POST['password']), PASSWORD_BCRYPT)
            ],
            "where" => ["id" => $_POST["user-id"]]
        ]);

		  $crud->delete([
			  "table" => "links",
			  "where" => [
				  "link" => $_POST["code"],
				  "type" => $_POST["type"]
			  ]
		  ]);
        redirect("login.php");
    }
}
elseif ((isset($_GET['code']) && isset($_GET['type'])))
{
	$crud->getAllWhere([
		"table" => "links",
		"where" => [
			"link" => $_GET['code'],
			"type" => $_GET['type']
		]
	]);
	if (!$crud::$rowCount)
		redirect("index.php");
	$userId = $crud::$result[0]["user_id"];
}
else
	redirect("index.php");
?>

<?php include("inc/header.php");?>
<?php include("inc/errors.inc.php");?>

<form class="form shadow" action="?" method="post">
  <h2>Camagru</h2>

  <div class="input-wrapper">
    <span class="icon icon-key-fill"></span><input class="input" type="password" name="password" value="<?= (isset($_POST["password"]) ? $_POST["password"] : "")?>" placeholder="Password">
  </div>
  <div class="input-wrapper">
    <span class="icon icon-key-fill"></span><input class="input" type="password" name="confirm-password" value="<?= (isset($_POST["confirm-password"]) ? $_POST["confirm-password"] : "")?>" placeholder="Confirm Password">
  </div>
  <input type="hidden" name="code" value="<?=  (isset($_GET['code'])) ? $_GET['code'] : $_POST['code']; ?>">
  <input type="hidden" name="type" value="<?=  (isset($_GET['type'])) ? $_GET['type'] : $_POST['type']; ?>">
  <input type="hidden" name="user-id" value="<?= $userId ?>">
  <input class="btn shallow"type="submit" name="submit" value="RESET PASSWORD"><br>
</form>

<?php include("inc/footer.php");?>
