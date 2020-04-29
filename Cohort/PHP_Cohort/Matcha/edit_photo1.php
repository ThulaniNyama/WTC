<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>matcha</title>
  <meta content="width=device-width, initial-scale=1.0" name="viewport">
  <meta content="" name="keywords">
  <meta content="" name="description">

  <!-- Favicons -->
  <link href="img/favicon.png" rel="icon">
  <link href="img/apple-touch-icon.png" rel="apple-touch-icon">

  <!-- Bootstrap CSS File -->
  <link href="lib/bootstrap/css/bootstrap.min.css" rel="stylesheet">

  <!-- Libraries CSS Files -->
  <link href="lib/font-awesome/css/font-awesome.min.css" rel="stylesheet">
  <link href="lib/animate/animate.min.css" rel="stylesheet">
  <link href="lib/ionicons/css/ionicons.min.css" rel="stylesheet">
  <link href="lib/owlcarousel/assets/owl.carousel.min.css" rel="stylesheet">
  <link href="lib/lightbox/css/lightbox.min.css" rel="stylesheet">

  <!-- Main Stylesheet File -->
  <link href="css/style.css" rel="stylesheet">

</head>


  <?php require 'header.php'; 
require 'required/functions.php';
 iNotConnected(); 
 ?>

<?php 
	$uploadfile = "";
	if (!empty($_POST))
	{

		if ($_FILES['mon_fichier']['error'] > 0)
			put_flash('danger', "Error : Problem while uploading.", "edit_photo.php");

		if ($_FILES['mon_fichier']['size'] > intval($_POST['MAX_FILE_SIZE']))
			put_flash('danger', "Error : File too big.", "edit_photo1.php");

		$extensions_valides = array('jpg');

		$extension_upload = strtolower(substr(strrchr($_FILES['mon_fichier']['name'], '.'), 1));
		if (!(in_array($extension_upload,$extensions_valides)))
			put_flash('danger', "Error : Invalid extension.", "edit_photo1.php");

		require_once 'required/functions.php';
		require_once 'required/database.php';

		$uploaddir = 'img/user/' .$_SESSION['auth']->id;

		if (!is_dir($uploaddir))
			mkdir($uploaddir, 0777);

		$uploadfile = $uploaddir ."/" .basename($_FILES['mon_fichier']['name']);

		if (file_exists($uploadfile))
			unlink($uploadfile);

		if (move_uploaded_file($_FILES['mon_fichier']['tmp_name'], $uploadfile)) {
		    $path = $uploadfile;
			$type = pathinfo($path, PATHINFO_EXTENSION);
			$data = file_get_contents($path);
			rename($uploadfile, "img/user/" .$_SESSION['auth']->id ."/profile1.jpg");
			$req = $pdo->prepare('UPDATE users SET profile_img1 = ? WHERE id = ?');
			$req->execute(["img/user/" .$_SESSION['auth']->id ."/profile1.jpg", $_SESSION['auth']->id]);
			$_SESSION['auth']->profile_img = "img/user/" .$_SESSION['auth']->id ."/profile1.jpg";
		} else {
			put_flash('danger', "Error : Problem while uploading.", "edit_photo1.php");
		}

	}
?>


<div class="banner-home">
	<div class="login">
		<div style="position: relative; top: 15%; color: whitesmoke; z-index: 2;">
			<?php if(empty($_POST)) { ?>
					<center><h1>No file selected</h1></center>
						<center>
						<form class="form-group" method="POST" action="edit_photo1.php" enctype="multipart/form-data">
						     <label for="icone">File (JPG | 5 Mo) :</label> 
						     <input type="hidden" name="MAX_FILE_SIZE" value="5242880" />
						     <input type="file" name="mon_fichier" id="mon_fichier" /><br><br>
						     <input class="btn-commenta" type="submit" name="submit" value="Upload" />
						</form><br>
						</center>
				<?php }else{ ?>
					<br><br>
					<center>
						<img src="<?php echo "img/user/" .$_SESSION['auth']->id ."/profile1.jpg"; ?>" width="20%">
						<br><br>
						<a href="edit_photo.php"><input type="submit" class="btn btn-primary" value="Change"></a>
						<a href="profile.php"><input type="submit" class="btn btn-primary" value="Save"></a>
					</center>
				<?php } ?>
		</div>
	</div>
</div>