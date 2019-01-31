<?php

require_once ("Db.class.php");

class Info extends Crud
{
	public function __construct()
	{
		parent::__construct();
	}
    public function likes($id)
    {
        $this->getAllWhere([
            "table" => "likes",
            "where" => ["post_id" => $id]
        ]);

        return self::$rowCount;
    }
    public function comments($id)
    {
        $this->getAllWhere([
            "table" => "comments",
            "where" => ["post_id" => $id],
				"orderby" => ["created_at", "DESC"]
        ]);

        return self::$result;
    }
    public function iLiked($postId, $userId)
    {
        $this->getAllWhere([
            "table" => "likes",
            "where" => [
					"post_id" => $postId,
					"user_id" => $userId
				]
        ]);

        return self::$rowCount;
    }
	public function auth($userId)
	{
		$this->getAllWhere([
			"table" => "users",
			"where" => ["id" => $userId]
		]);

		$auth = [
			"name" => self::$result[0]["username"],
			"email" => self::$result[0]["email"],
			"notification" => self::$result[0]["notification"]
		];
		return $auth;
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
