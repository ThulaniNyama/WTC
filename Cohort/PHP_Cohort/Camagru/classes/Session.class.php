<?php

class Session
{
	private $session_exists = false;
	public $currentSession 	= NULL;

	public function exists($name)
	{
		if (isset($_SESSION[$name]))
			return 1;
		else
			return 0;
	}

	public function set($name, $value)
	{
		if (!isset($_SESSION[$name]))
			$_SESSION[$name] = $value;
	}

	public function get($name)
	{
		if (isset($_SESSION[$name]))
		{
			return $_SESSION[$name];
		}
		else
			return 0;
	}

	public function update($name, $value)
	{
		if (isset($_SESSION[$name]))
		{
			$_SESSION[$name] = $value;
			return "Session ". $name ." has been updated";
		}
		else
			return "Session ". $name ." does does not exist";

	}

	public function destroy($name)
	{
		if (is_array($name))
		{
			foreach ($name as $session)
			{
				if ($this->exists($session))
					unset($_SESSION[$session]);
			}
		}
		else
		{
			if ($this->exists($name))
			{
				unset($_SESSION[$name]);
					$this->message = "Goodbye see you soon...";
			}
			else
				$this->message = "Please login :(";
		}

	}

	public static function doc()
	{
	  $doc = "classes/docs/".get_class().".doc.txt";

	  if (file_exists($doc))
		{
		  $read = fopen($doc, "r");
		  echo "\n";
		  while ($read && !feof($read))
			  echo fgets($read);
	  }
		echo "\n";
	}
}

?>
