<?php ini_set('display_errors', 1);

	require_once ("../classes/Crud.class.php");

    $dir = "sql/";
    $files = scandir($dir);
	 $crud = new Crud("database.php");

    /*=======================
        - CREATE DATABASE
    =======================*/
    $sql = file_get_contents($dir."_db.sql");
    try
    {
		 $i = 0;
        $db = $crud->getCredentials("database.php");
        $cnx = new PDO("mysql:host=".$db["DB_DSN"].";", $db["DB_USER"] , $db["DB_PASSWORD"]);
        $cnx->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);

		  while ($i < 2)
		  {
		  		$cnx->query($sql);
				$i++;
		  }
		  echo "Database successfully created <br>";
		  createTables($crud,$dir, $files);

    }
    catch(PDOException $e)
    {
        echo $e->getMessage();
    }

    /*=======================
        - CREATE TABLES
    =======================*/

	 function createTables($crud, $dir, $files)
	 {
		 $crud = new Crud("database.php");
		 foreach ($files as $file)
		 {
			  $path = $dir . $file;
			  $sql = getContent($path);
			  $file = explode(".", $file);

			  if ($file[1] == "sql")
			  {
				 if ($file[0] != "_db")
				 {
					$crud->cnx->query($sql);
				 }
			  }
		 }
		 echo "Tables successfully created <br>";
		 header("Location: ../index.php");
	 }

    function getContent($path)
    {
        $content = "";
        if (file_exists($path))
	    {
			$read = fopen($path, 'r');
			echo "\n";
	    	while ($read && !feof($read))
	        	$content .= fgets($read);
		}
        return $content;
    }
