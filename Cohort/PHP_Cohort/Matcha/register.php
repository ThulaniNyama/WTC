
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

<?php require 'views/navbar.php'; require 'required/functions.php'; iConnected(); ?>
<div id="home" class="intro route bg-image" style="background-image: url(image/blur.jpg)">
<div class="login">
    <div class="container" style="position: relative; top: 10%; color: whitesmoke; z-index: 2;">
     <center><h1 style="font-family: Gabriola; font-style: italic; font-size: 4vw; color:black;">Sign Up</h1></center>
        <form action="action/register_user.php" method="POST">
            <div class="form-group">
            <center><label for="username" style="font-size: 2vw; color:black; font-family: Gabriola; font-style: italic;">Username </label></center>
                <center><input type="text" class="form-control" name="username" style="background: transparent;width:90%;" id="username" required></center>
            </div>
            <div class="form-group">
            <center><label for="Email" style="font-size: 2vw; color:black; font-family: Gabriola; font-style: italic;">Email </label></center>
                <center><input type="email" class="form-control" name="email"style="background: transparent;width:90%; " id="Email" required></center>
            </div>
            <div class="form-group">
            <center><label for="psw" style="font-size: 2vw; color:black; font-family: Gabriola; font-style: italic;">Password </label></center>
                <center><input type="password" class="form-control" name="password"style="background: transparent;width:90%; " id="psw" required></center>
            </div>
            <div class="form-group">
            <center><label for="pswr" style="font-size: 2vw; color:black; font-family: Gabriola; font-style: italic;">Repeat Password </label></center>
                <center><input type="password" class="form-control" name="passwordr" style="background: transparent;width:90%; "id="pswr" required></center>
            </div>
            <div class="form-group">
                <center><input type="submit" class="btn btn-dark btn-block"  name="btn" value="Sign Up"></center>
            </div>
        </form>
    </div>    
</div>

