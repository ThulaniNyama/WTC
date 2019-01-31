<?php

require_once ("Db.class.php");

class Crud extends Db
{
	public static $success = false;
	private static $message;
	private $params = [];
	public $response;
	public $cnx;
	public static $rowCount = 0;
	public static $lastInsertedId;
	public static $result;

	public function __construct($path = null)
	{
		parent::__construct($this->getCredentials($path));
		$this->cnx = $this->connect();
	}

	public function create(array $params)
	{
		$table;
		$fields;
		$values;

		if (isset($params['table']) && isset($params["fields"]) && isset($params["values"]))
		{
			$table = $params['table'];
			$fields = implode(", ", $params["fields"]);
			$values = "";

			$i = 0;
			foreach ($params["values"] as $value)
			{
				$coma = ($i+1 < count($params["values"])) ? ", " : " ";
				$values .= '"'.$value.'" '.$coma;
				$i++;
			}

			$sql = "INSERT INTO  $table ($fields) VALUES($values)";
			$stm = $this->cnx->prepare($sql);
			if ($stm->execute())
			{
				self::$lastInsertedId = $this->cnx->lastInsertId();
				self::$message = "New record inserted";
			}
			else
				self::$message = "Unable to insert record";
		}
	}


	public function getAll(array $params)
	{
		if (isset($params["table"]) && !empty($params["table"]))
		{
			$table = $params["table"];
			$orderBy = "";
			if (isset($params["orderby"]) && is_array($params["orderby"]) && count($params["orderby"]) > 1)
				$orderBy = "ORDER BY ". $params["orderby"][0] . " " .$params["orderby"][1];

			$sql = "SELECT * FROM $table $orderBy";
			$stm = $this->cnx->prepare($sql);
			$stm->execute();
			self::$result = $stm->fetchAll(PDO::FETCH_ASSOC);
			self::$rowCount = $stm->rowCount();

			return $this;
		}
	}

	public function getAllWhere(array $params)
	{

		if (isset($params['table']) && isset($params['where']))
		{
			$table = $params['table'];
			$where = "";
			$orderBy = "";
			$i = 0;

			foreach ($params['where'] as $key => $val)
			{
				$and = (count($params['where']) > 1 && ($i+1 < count($params['where']))) ? " AND " : "";
				$where .= $key."=".'"'.$val.'"'.$and;
				$i++;
			}

			if (isset($params["orderby"]) && is_array($params["orderby"]) && count($params["orderby"]) > 1)
				$orderBy = "ORDER BY ". $params["orderby"][0] . " " .$params["orderby"][1];

			$sql = "SELECT * FROM $table WHERE $where $orderBy";
			$stm = $this->cnx->prepare($sql);
			$stm->execute();
			self::$result = $stm->fetchAll(PDO::FETCH_ASSOC);
			self::$rowCount = $stm->rowCount();

			if (self::$rowCount)
				self::$message = self::$rowCount . " record found";
			else
				self::$message = "No record found";
			return $this;
		}
	}

	public function query($sql)
	{
		$type = explode(" ", $sql)[0];
		$stm = $this->cnx->prepare($sql);
		$success = $stm->execute();

		if (strtoupper($type) == "SELECT")
		{
			self::$result = $stm->fetchAll(PDO::FETCH_ASSOC);
			self::$rowCount = $stm->rowCount();
			self::$success = $success;
		}
		else
			self::$success = $success;
	}


	public function update(array $params)
	{
		if (isset($params['table']) && isset($params['where']) && isset($params['where']))
		{
			$table = $params['table'];
			$where = "";
			$set = "";
			$i = 0;

			foreach ($params['where'] as $key => $val)
			{
				$and = (count($params['where']) > 1 && ($i+1 < count($params['where']))) ? " AND " : "";
				$where .= $key."=".'"'.$val.'"'.$and;
				$i++;
			}

			$i = 0;
			foreach ($params['set'] as $key => $val)
			{
				$coma = (count($params['set']) > 1 && ($i+1 < count($params['set']))) ? ", " : "";
				$set .= $key."=".'"'.$val.'" '.$coma;
				$i++;
			}


			$sql = "UPDATE $table SET $set  WHERE  $where";
			$stm = $this->cnx->prepare($sql);
			if ($stm->execute())
				self::$message = "Record updated";

		}
	}


	public function delete(array $params)
	{
		if (isset($params['table']) && isset($params['where']))
		{

			$where = "";
			$table = $params['table'];

			$i = 0;
			foreach ($params['where'] as $key => $val)
			{
				$and = (count($params['where']) > 1 && ($i+1 < count($params['where']))) ? " AND " : "";
				$where .= $key."=".'"'.$val.'"'.$and;
				$i++;
			}

			$sql = "DELETE FROM $table WHERE  $where";
			$stm = $this->cnx->prepare($sql);
			if ($stm->execute())
				self::$message = "Record successfully deleted!";
			else
				self::$message = "Unable to delete record!";
		}
	}

	public static function getMessage()
	{
		return self::$message;
	}

	public function first()
	{
		self::$result = self::$result[0];
		return $this;
	}

	public function last()
	{
		$count = count(self::$result);
		self::$result = self::$result[$count - 1];
		return $this;
	}

	public function getCredentials($path = null)
	{
		$pth = ($path) ? $path : "./config/database.php";
		$file = fopen($pth,"r");
		$credentials;
		$key;
		$value;

		while(!feof($file))
		{
			$line = explode("=",fgets($file));
			$key = (isset($line[0])) ? trim($line[0]) : "";
			$value = (isset($line[1])) ? trim($line[1]) : "";

			if (!empty($key) && !empty($value))
				$credentials[trim($key, "$")] = trim(trim($value,';'), "\"");
		}
		fclose($file);
		return $credentials;
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
