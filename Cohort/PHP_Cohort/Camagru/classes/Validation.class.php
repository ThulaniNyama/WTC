<?php

class Validation
{
	public static $request = false;
    private static $rules;
    private static $label;
    public $errors = [];

	public static function requestExists()
	{
		$type = $_SERVER["REQUEST_METHOD"];
		switch ($type)
		{
			case 'POST':
					return (!empty($_POST)) ? true : false;
				break;

			case 'GET':
					return (!empty($_GET)) ? true : false;
				break;

			default:
					return false;
				break;
		}
	}

	public function validate()
    {
		$request = $_REQUEST;
        foreach (self::$rules as $field => $rules)
        {
            if (array_key_exists($field, $request))
            {
                $value = $request[$field];
                $arrRules = $this->parseRules($rules);

                foreach($arrRules as $key => $val)
                {
                    $this->generateErrors(self::$label, $value, $key, $val);
                }
            }
        }
		return $this;
    }

	public function setRules(array $rules)
	{
		self::$rules = $rules;
		return $this;
	}

	private function parseRules($rules)
    {
        $arr = [];

        if (strpos($rules, "|") !== false)
            $rules = explode("|", $rules);
        self::$label = $rules[0];
        unset($rules[0]);
        if (is_array($rules))
        {
            foreach ($rules  as $rule)
            {
                if (strpos($rule, ":") !== false)
                    $rule = explode(":", $rule);
                if (is_array($rule))
                    $arr[$rule[0]] = $rule[1];
                else
                    $arr[$rule] = true;
            }
        }
        else
        {
            if (strpos($rules, ":") !== false)
                $rules = explode(":", $rules);
            if (is_array($rules))
                $arr[$rules[0]] = $rules[1];
            else
                $arr[$rules] = true;
        }
        return $arr;
    }

	private function generateErrors($label, $input, $rule, $required)
    {
		$input = trim($input);
        if ($rule == "required" && empty(trim($input)))
			$this->errors[] = "{$label} is required";
		else if (!empty($input))
		{
			switch ($rule)
			{
				case 'email':
					if (!filter_var($input, FILTER_VALIDATE_EMAIL))
						$this->errors[] = "Invalid email address";
					break;

				case 'password':
					if (!$this->isSecurePassword($input))
						$this->errors[] = "Password not secure enough";
					break;

				case 'min':
					if (strlen($input) < $required)
						$this->errors[] = "{$label} must be a minimum of {$required}";
					break;

				case 'max':
					if (strlen($input) > $required)
						$this->errors[] = "{$label} must have a maximum of {$required} characters";
					break;

				case 'matches':
					if ($input !== $_REQUEST[$required])
						$this->errors[] = "{$label} must match {$required}";
					break;

				case 'url':
					if (!filter_var($url, FILTER_VALIDATE_URL))
						$this->errors[] = "{$label} is not a valid url";
					break;
			}
		}
    }
	private function isSecurePassword($password)
	{
		$uppercase = preg_match('@[A-Z]@', $password);
		$lowercase = preg_match('@[a-z]@', $password);
		$number    = preg_match('@[0-9]@', $password);

		if(!$uppercase || !$lowercase || !$number || strlen($password) < 6)
			return 0;
		else
			return 1;
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
