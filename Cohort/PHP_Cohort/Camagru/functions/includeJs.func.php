<?php

function includeJs($pageName, $jsList)
{
	if (array_key_exists($pageName, $jsList))
	{
		$jsFile = $jsList[$pageName];
		if (is_array($jsFile))
		{
			foreach ($jsFile as $file)
			{
				if (file_exists("resources/js/{$file}.js"))
					echo '<script src="resources/js/'.$file.'.js"></script>' . PHP_EOL;
			}
		}
		else
		{
			if (file_exists("resources/js/{$jsFile}.js"))
				echo '<script src="resources/js/'.$jsFile.'.js"></script>'.PHP_EOL;
		}
	}
}

?>
