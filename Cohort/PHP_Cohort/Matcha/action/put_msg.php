<?php
	require '../required/functions.php';
	if (session_status() == PHP_SESSION_NONE) { session_start(); }
		iNotConnected();

	if (empty($_POST))
		put_flash('danger', "Invalid action.", "/index.php");

	require '../required/database.php';
	if (strlen($_POST['text']) < 70 && strlen($_POST['text']) > 0 && $_POST['id'] !== 0)
	{
		$req = $pdo->prepare("INSERT INTO messages SET sender = ?, receiver = ?, text = ?");
		$req->execute([$_SESSION['auth']->id, $_POST['id'], htmlspecialchars($_POST['text'])]);

		if (!is_blocked($_POST['id'], $_SESSION['auth']->id))
		{
			$req = $pdo->prepare("INSERT INTO notifications SET emitter = ?, receiver = ?, text = ?");
			$req->execute([$_SESSION['auth']->id, $_POST['id'], "Sent you a message."]);
		}
	}