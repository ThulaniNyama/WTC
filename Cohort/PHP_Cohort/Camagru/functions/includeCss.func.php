<?php

function includeCss($pageName, $cssList)
{
	if (array_key_exists($pageName, $cssList))
	{
		$cssFile = $cssList[$pageName];

		if (is_array($cssFile))
		{
			foreach ($cssFile as $file)
			{
				if (file_exists("resources/css/{$file}.css"))
					echo '<link rel="stylesheet" href="resources/css/'.$file.'.css">'.PHP_EOL;
			}
		}
		else
		{
			if (file_exists("resources/css/{$cssFile}.css"))
				echo '<link rel="stylesheet" href="resources/css/'.$cssFile.'.css">'.PHP_EOL;
		}

	}
}

?>
