
<!DOCTYPE html>
<html lang="en">
<head>
  <meta charset="utf-8">
  <title>Profile</title>
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
 
<style>
.MainPhoto{
    border: 1px solid black;
    width:30%;
    height: 150px;
    border-radius: 50%;
}

</style>
<div id="home" class="intro route bg-image" style="background-image: url(image/blur.jpg)">
<div class="container">
<div class="banner-home"><br><br><br>
    <center><a href="profile_editor.php"><input class="btn btn-dark" type="submit" name="Edit" value="Edit Profile" style="position: absolute; z-index: 9999999999999; left: 0"></a>
                <a href="edit_photo.php"><input class="btn btn-dark" type="submit" name="EditPhoto" value="Edit Photo" style="position: absolute; z-index: 9999999999999; left: 110px"></a></center>
                <br><br><br>
    <div class="left-container">
        <div class="MainPhoto">
            <img src="<?php echo $_SESSION['auth']->profile_img; ?>" width="100%" title="profile" alt="profile_img">
        </div>
    </div>
    <div class="middle-container"><br><br><br><br><br><br>
        <h1 class="text-primary">Profile of <?php echo $_SESSION['auth']->name ." - " . Age . $_SESSION['auth']->age; ?>
            <span style="font-size: 2vw; color: yellow"><?php echo $_SESSION['auth']->popscore; ?></span>
        </h1>
        <div class="infos-container">
            <?php if ($_SESSION['auth']->gender === "M") { ?>
                <h4><span class="text-secondary">Gender :</span> <span style="color: cherry;"><?php echo $_SESSION['auth']->gender; ?></span></h4>
            <?php }else{ ?>
                <h4><span class="text-warning">Gender :</span> <span style="color: currant;"><?php echo $_SESSION['auth']->gender; ?></span></h4>
            <?php } ?>
            <br>
            <?php if ($_SESSION['auth']->orientation === "F") { ?>
                <h4><span class="text-primary">Interested by :</span> <span style="color: fuchsia;"><?php echo $_SESSION['auth']->orientation; ?></span></h4>
            <?php }else{ ?>
                <h4><span class="text-primary">Interested by :</span> <span style="color: royalblue;"><?php echo $_SESSION['auth']->orientation; ?></span></h4>
            <?php } ?>
            <br>
            <h4><span class="text-primary">Bio :</span></h4>
            <textarea class="form-control"><?php echo $_SESSION['auth']->bio ?></textarea>
            <br>
            <h4><span class="text-primary">Interest :</span> <span class="htag">#</span><span><?php echo $_SESSION['auth']->i1; ?></span>
                <span class="text-primary">#</span><span><?php echo $_SESSION['auth']->i2; ?></span>
                <span class="text-primary">#</span><span><?php echo $_SESSION['auth']->i3; ?></span></h4>
        </div>
      
    </div>
   </div>
</div>
