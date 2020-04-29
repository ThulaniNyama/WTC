
<?php
	
	if (session_status() == PHP_SESSION_NONE) { session_start(); }
	require '../required/functions.php';
	iConnected();

	if (empty($_POST) || isset($_SESSION['auth']))
		put_flash('danger', "Error : You cannot acces this page.", '../index.php');

	
	$username = $_POST['username'];
	$psw = $_POST['password'];

	//verify username
	if (empty($username) || !preg_match('/^[a-zA-Z0-9]+$/', $username) || strlen($username) > 20)
		put_flash('danger', "Error : Invalid username.", "../login.php");

	//verify psw
	if (empty($psw) || strlen($psw) > 20)
		put_flash('danger', "Error : Invalid password", "../login.php");

	//user exi
	require '../required/database.php';
	$req = $pdo->prepare('SELECT * FROM users WHERE username = ?');
	$req->execute([$username]);
	$userExi = $req->fetch();

	if ($userExi)
	{
		if (password_verify($psw, $userExi->password))
		{
			if ($userExi->reported)
				put_flash('danger', "You've been reported, your account is blocked", "/login.php");
			$_SESSION['auth'] = $userExi;
			$json = file_get_contents('http://ip-api.com/json');
			$obj = json_decode($json);
			$_SESSION['auth']->location = $obj->regionName;
			$req = $pdo->query("UPDATE users SET location ='" .addslashes($obj->regionName) ."', lastonline = NOW() WHERE id =" .intval($_SESSION['auth']->id));
			put_flash('success', "Welcome back ", "../index.php");
		}
		else
			put_flash('danger', "Error : Invalid username or password.", "../login.php");
	}
	else
	{
		put_flash('danger', "Error : Invalid username or password.", "../login.php");
	}
	