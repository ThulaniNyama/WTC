<?php

function printArray($array)
{
	if (is_array($array))
		echo "<pre>", print_r($array), "</pre>";
	else
		echo $array . "<br>";
}

?>
