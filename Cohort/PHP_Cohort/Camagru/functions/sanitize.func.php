<?php

function sanitize($input)
{
	$value = trim($input);
	$value = stripslashes($value);
	$value = strip_tags($value);

	return $value;
}

?>
