<?php
	if (session_status() == PHP_SESSION_NONE) { session_start(); }
	require '../required/functions.php';
	iNotConnected();
	
	if (empty($_POST))
		put_flash('danger', "Invalid action.", "/index.php");

	require '../required/database.php';
	$req = $pdo->query("UPDATE users SET reported = 1 WHERE id =" .intval($_POST['id']));
	put_flash('info', "User reported.", "/index.php");
