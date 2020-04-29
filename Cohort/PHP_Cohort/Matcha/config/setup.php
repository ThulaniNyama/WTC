<?php
include 'database.php';

try {
    $db = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = sprintf("DROP DATABASE IF EXISTS %s; CREATE DATABASE %s", $DB_NAME, $DB_NAME);
    $db->exec($sql);
    echo "Database created successfully\n\n\n";
}

catch (PDOException $e) {
    echo "ERROR CREATING DB: \n".$e->getMessage()."\nAborting process\n\n\n";
    exit;
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS`blocked` (
	  `id` int(11) NOT NULL AUTO_INCREMENT,
	  `blocker` int(11) NOT NULL,
	  `blocked` int(11) NOT NULL,
	  PRIMARY KEY (`id`)
	  )ENGINE=MyISAM AUTO_INCREMENT=7 DEFAULT CHARSET=latin1;";
	  $db->exec($sql);
	  echo "BLOCKED table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: BLOCKED ".$e->getMessage()."\nAborting process\n\n\n";
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `likes` (
		`id` int(11) NOT NULL AUTO_INCREMENT,
		`emitter` int(11) NOT NULL,
		`receiver` int(11) NOT NULL,
		PRIMARY KEY (`id`)
	  ) ENGINE=MyISAM AUTO_INCREMENT=37 DEFAULT CHARSET=utf8;";
	  $db->exec($sql);
	  echo "LIKES table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: LIKES ".$e->getMessage()."\nAborting process\n\n\n";
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `matches` (
		`id` int(11) NOT NULL AUTO_INCREMENT,
		`A` int(11) NOT NULL,
		`B` int(11) NOT NULL,
		PRIMARY KEY (`id`)
	  ) ENGINE=MyISAM AUTO_INCREMENT=13 DEFAULT CHARSET=utf8;";
	  $db->exec($sql);
	  echo "MATCHES table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: MATCHES ".$e->getMessage()."\nAborting process\n\n\n";
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `messages` (
		`id` int(11) NOT NULL AUTO_INCREMENT,
		`sender` int(11) NOT NULL,
		`receiver` int(11) NOT NULL,
		`text` varchar(255) NOT NULL,
		PRIMARY KEY (`id`)
	  ) ENGINE=MyISAM AUTO_INCREMENT=34 DEFAULT CHARSET=latin1;";
	  $db->exec($sql);
	  echo "MESSAGES table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: MESSAGES ".$e->getMessage()."\nAborting process\n\n\n";
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `notifications` (
		`id` int(11) NOT NULL AUTO_INCREMENT,
		`emitter` int(11) NOT NULL,
		`receiver` int(11) NOT NULL,
		`text` varchar(255) NOT NULL,
		`seen` int(11) NOT NULL DEFAULT '0',
		PRIMARY KEY (`id`)
	  ) ENGINE=MyISAM AUTO_INCREMENT=312 DEFAULT CHARSET=utf8;";
	  $db->exec($sql);
	  echo "NOTIFICATIONS table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: NOTIFICATIONS ".$e->getMessage()."\nAborting process\n\n\n";
}

try{
	$db = new PDO($DB_DSN_NAME, $DB_USER, $DB_PASSWORD);
	$db->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
	$sql = "CREATE TABLE IF NOT EXISTS `users` (
		`id` int(11) NOT NULL AUTO_INCREMENT,
		`username` varchar(20) NOT NULL,
		`mail` varchar(255) NOT NULL,
		`password` varchar(255) NOT NULL,
		`verif` tinyint(1) NOT NULL DEFAULT '0',
		`name` varchar(255) NOT NULL DEFAULT 'Unknown',
		`age` int(11) NOT NULL DEFAULT '0',
		`gender` varchar(3) NOT NULL DEFAULT 'N/A',
		`orientation` varchar(3) NOT NULL DEFAULT 'M/F',
		`bio` varchar(255) NOT NULL DEFAULT 'No bio set yet.',
		`profile_img` varchar(255) NOT NULL DEFAULT 'img/profile.jpg',
		`i1` varchar(255) NOT NULL DEFAULT 'Example',
		`i2` varchar(255) NOT NULL DEFAULT 'Example',
		`i3` varchar(255) NOT NULL DEFAULT 'Example',
		`popscore` int(11) NOT NULL DEFAULT '0',
		`location` varchar(255) NOT NULL DEFAULT 'Unknown',
		`lati` float NOT NULL DEFAULT '0',
		`longi` float NOT NULL DEFAULT '0',
		`lastonline` datetime NOT NULL DEFAULT CURRENT_TIMESTAMP,
		`reported` int(11) NOT NULL DEFAULT '0',
		PRIMARY KEY (`id`)
	  ) ENGINE=MyISAM AUTO_INCREMENT=1068 DEFAULT CHARSET=utf8;";
	  $db->exec($sql);
	  echo "USERS table created\n\n\n";

} catch (PDOException $e){
	echo "ERROR CREATING TABLE: USERS ".$e->getMessage()."\nAborting process\n\n\n";
}