<?php

function includeTitle($pageName, $titleList)
{
	if (array_key_exists($pageName, $titleList))
	{
		$title = $titleList[$pageName];
		echo $title;
	}
}

?>
