<?php 
	if (session_status() == PHP_SESSION_NONE) { session_start(); }
	require '../required/functions.php';
	iNotConnected();
	unset($_SESSION['auth']); 
	header('Location: ../index.php');
	exit();
?>