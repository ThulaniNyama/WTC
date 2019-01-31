<?php

	function pagination($record_per_page = 5, $page_num = 1, $content)
	{
		$pages = ceil(count($content)/$record_per_page);
		$start = ($page_num - 1) * $record_per_page;

		$i = 0;
		$result = [];

		foreach ($content as $cont)
		{
			if ($i < count($content) && ($i < ($start + $record_per_page)))
			{
				if ($i >= $start && $i < ($start + $record_per_page))
					$result[] = $cont;
			}
			else
				break;
			$i++;
		}

		$return['pages'] = $pages;
		$return["content"] = $result;

		return $return;
	}

?>
