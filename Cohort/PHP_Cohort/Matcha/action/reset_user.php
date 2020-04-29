<?php
	require '../required/functions.php';
	iConnected();

	if (empty($_POST))
		put_flash('danger', "Error : Invalid values.", "../reset.php");

	$username = $_POST['username'];

	//verify username
	if (empty($username) || !preg_match('/^[a-zA-Z0-9]+$/', $username) || strlen($username) > 20)
		put_flash('danger', "Error : Invalid username.", "../reset.php");

	//verify userExi
	require '../required/database.php';
	$req = $pdo->prepare('SELECT * FROM users WHERE username = ?');
	$req->execute([$username]);
	$userExi = $req->fetch();

	if ($userExi)
	{
		$req = $pdo->prepare('UPDATE users SET password = ? WHERE username = ?');
		$rnd = str_random(10);
		$password = password_hash($rnd, PASSWORD_BCRYPT);
		if ($req->execute([$password, $username]))
		{
			send_mail($userExi->mail, "Account modification", "Hi, there is your new password :\n" .$rnd);	
			put_flash('success', "Success : Password has been reset, check your mails.", "../login.php");
		}
		else
			put_flash('danger', "Error : Can't reset psw.", "../reset.php");

	}
	else
	{
		put_flash('danger', "Error : username does not exists.", "../reset.php");
	}

?>