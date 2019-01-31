<?php

	function sendMail($to, $subject, $message)
	{
		$headers = "MIME-Version: 1.0" . "\r\n";
		$headers .= "Content-type:text/html;charset=UTF-8" . "\r\n";
		$headers .= "Reply-To: Camagru Info <Camagru@info.com>\r\n";
		$headers .= "Return-Path: Camagru Infor <Camagru@info.com>\r\n";
		$headers .= 'From: Camagru Info <Camagru@info.com>' . "\r\n";

		mail($to, $subject, $message, $headers);
	}



?>
