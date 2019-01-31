<!DOCTYPE html>
<html lang="en">
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<link rel="icon" type="image/png" href="inc/logos/wethinkcode-logo-white.png">
	<meta name="loggedin" content="<?= $userId;?>">
	<meta http-equiv="X-UA-Compatible" content="ie=edge">
	<link rel="stylesheet" href="resources/css/fontastic.css">
	<link rel="stylesheet" href="resources/css/master.css">
	<?php includeCss($pageName, $cssList);?>
	<title><?php includeTitle($pageName, $titleList); ?></title>
	
</head>
<body>
	<header class="shadow">
		<?php if ($pageName == "index" || $pageName == "gallery"): ?>
			<div class="cover" style="display: none;">
				<span class="icon icon-close-circled" id="close-btn"></span>
				<div class="photo clearfix">
					<form class="comment-form" action="index.html" method="post">
						<input type="hidden" name="post-id" value="" id="postId">
						<?php if ($userId): ?>
							<input class="input" type="text" name="" value="" placeholder="Comment" id="input">
						<?php endif; ?>
					</form>
					<img src="resources/img/img6.jpeg" alt="">
					<div class="info">
						<span class="icon icon-heart-o heart"><span>200</span> </span>
				    	<span class="icon icon-comment"><span>10</span></span>
						<div class="comments">


						</div>
					</div>
				</div>
			</div>
		<?php endif; ?>
		<div class="container">
		
			<div class="logo"><a href="index.php"><img src="inc/logos/WeThinkCode-South-Africa.gif" alt="We Think Code"></a></div>
			<nav>
				<ul>
					<li>
						<a href="<?php echo (isset($_SESSION['loggedin'])) ? "edit" : "login"; ?>.php" class="btn fill rounded snap">Camagru-Cam
							<span class="icon icon-camera-retro"></span>
						</a>
					</li>
					<?php if (isset($_SESSION['loggedin']) && !empty($_SESSION['loggedin'])): ?>
						<li>
							<label for="drop-down">
								<span class="user"><?php echo strtoupper($_SESSION['loggedin'][0]); ?></span>
							</label>
							<input type="checkbox" id="drop-down">
							<ul class="drop-down shadow">
								<li><a href="gallery.php"><span class="icon icon-picture-o"></span> Camagru-Snaps</a></li>
								<li><a href="profile.php"><span class="icon icon-widget"></span> My Profile</a></li>
								<li><a href="?logout"><span class="icon icon-sign-out"></span> Log-out</a></li>
							</ul>

						</li>
					<?php else: ?>
							<li>
								<a href="login.php" class="">Log-in</a>
							</li>
							<li>
								<a href="register.php" class="">Sign-up</a>
							</li>
					<?php endif; ?>
				</ul>
			</nav><br>
		</div>
	</header>
	<main>
		<div class="container clearfix">
