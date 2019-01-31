<?php include("config/init.php");

	if (!$session->get("loggedin"))
		redirect("index.php");

	$crud->getAllWhere([
		"table" => "posts",
		"where" => ["user_id" => $session->get("id")],
		"orderby" => ["created_at", "DESC"]
	]);
	
	$data = pagination($recor_per_page, $page_num, $crud::$result);
	$posts = $data['content'];

	if (isset($_GET["post-id"]) && isset($_GET["auth-id"]))
	{
		if ($_GET["auth-id"] == $session->get("id"))
		{
			$crud->delete([
				"table" => "posts",
				"where" => ["id" => $_GET["post-id"]]
			]);
		}
		die();
	}


	if ($validate::requestExists() && $_SERVER["REQUEST_METHOD"] == "POST")
	{
		$action = $_POST["action"];
		$postId = $_POST["postId"];
		$userId = $session->get("id");

		if ($action == "like")
		{
			$liked = $_POST["liked"];

			if ($liked == 1)
			{
				$crud->create([
					"table" => "likes",
					"fields" => ["post_id", "user_id"],
					"values" => [$postId, $userId]
				]);
			}
			else {
				$crud->delete([
					"table" => "likes",
					"where" => ["user_id" => $userId]
				]);
			};
		}
		elseif ($action == "comment")
		{
			$comment = $_POST["comment"];
			$crud->create([
				"table" => "comments",
				"fields" => ["post_id", "user_id", "comment"],
				"values" => [$postId, $userId, $comment]
			]);

			$crud->getAllWhere([
				"table" => "posts",
				"where" => ["id" => $postId]
			]);

			$auth = $info->auth($crud::$result[0]["user_id"]);

			if ($auth["notification"])
			{
				$message = $session->get("loggedin") . " has commented on your post";
				sendMail($email, "NEW COMMENT", $message);
			}
		}
		die();
	}
	elseif ($validate::requestExists() && isset($_GET["getComments"]))
	{

		$comments = "";

		foreach ($info->comments($_GET["postId"]) as $key => $comment)
		{
			$date = strtotime($comment["created_at"]);
			$date = date('d M Y', $date);

			$comments .= "<div class='comment'>";
			$comments .= "<p>". $comment["comment"] ."</p>";
			$comments .=	"<span class='date'>". $date ."</span>";
			$comments .= "</div>";
		}
		echo $comments;
		die();
	}

?>
<?php include("inc/header.php");?>

<?php foreach ($posts as $key => $post): ?>
	<div class="photo" data-id="<?= $post["id"]; ?>">
	  <img src="<?= str_replace(' ', '+', $post["post"]); ?>" alt="" id="id2">
	  <div class="info clearfix">
	    <span class="icon <?= ($info->iLiked($post["id"], $userId)) ? "icon-heart" : "icon-heart-o";  ?> heart"><span><?= $info->likes($post["id"]); ?></span> </span>
	    <span class="icon icon-comment comment"><span><?= count($info->comments($post["id"])); ?></span></span>
		 <?php if($post["user_id"] != $userId): ?>
	    	<a href="?auth=<?= $post["user_id"]; ?>"><span class="icon icon-user"><span><?= $info->auth($post["user_id"])["name"]; ?></span></span></a>
		<?php else: ?>
	    	<a href="#" data-post="<?= $post["id"];?>" data-auth="<?= $post["user_id"];?>" class="delete-post"><span class="icon icon-trash"><span>Delete</span></span></a>
		<?php endif; ?>
	  </div>
	</div>
<?php endforeach; ?>

<?php if ($data['pages'] > 1): ?>
	<div class="pagination">
	  <ul class="clearfix">
		 <?php $i = 1; while ($i <= $data['pages']){ ?>
				<li><span class=""><a href="?page=<?= $i;?>"><?= $i;?></a></span></li>
		 <?php $i++; } ?>
	  </ul>
	</div>
<?php endif; ?>
<?php include("inc/footer.php");?>
