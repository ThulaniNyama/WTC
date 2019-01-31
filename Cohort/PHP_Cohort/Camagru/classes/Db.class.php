<?php

class Db
{
	private $cnx;
	private $host;
	private $db_name;
	private $db_user;
	private $db_password;
    public $pdoErrorCode = null;

	public function __construct(array $params)
	{
		if (isset($params["DB_DSN"]) && isset($params['DB_NAME']) && isset($params['DB_USER']) && isset($params['DB_PASSWORD']))
		{
			$this->host 		= $params["DB_DSN"];
			$this->db_name 		= $params['DB_NAME'];
			$this->db_user 		= $params['DB_USER'];
			$this->db_password 	= $params['DB_PASSWORD'];

			try {
			    $this->cnx = new PDO("mysql:host=$this->host;dbname=$this->db_name", $this->db_user, $this->db_password);
			    $this->cnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
			    return $this->cnx;
		    }
			catch(PDOException $e)
		    {
            $this->pdoErrorCode = $e->getCode();
		    	echo "Connection failed: " . $e->getMessage() . "<br>";
		    }
		}
	}

	public function connect()
	{
		return $this->cnx;
	}

	public static function doc()
    {
    	$doc = "docs/".get_class().".doc.txt";

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
