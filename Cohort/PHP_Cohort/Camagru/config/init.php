<?php session_start();
ini_set('display_errors', 1);

require "./functions/includeCss.func.php";
require "./functions/includeJs.func.php";
require "./functions/includeTitle.func.php";
require "./functions/sanitize.func.php";
require "./functions/redirect.func.php";
require "./functions/printarray.func.php";
require "./functions/sendMail.func.php";
require "./functions/pagination.func.php";


spl_autoload_register(function($className)
{
	require_once ("./classes/{$className}.class.php");
});


$validate = new Validation();
$crud = new Crud();
$session = new Session();
$info = new Info();

$pageName = basename($_SERVER['PHP_SELF']);
$pageName = explode(".", $pageName);
$pageName = $pageName[0];

if ($crud->pdoErrorCode == "1049" && $pageName != "install")
{
    redirect("./config/install.php");
}

$cssList = [
	"index"						=> "gallery",
	"gallery"						=> "gallery",
	"profile" 				=> "profile",
	"register" 				=> "form",
	"login"						=> ["form", "login"],
	"forgot-password" => "form",
	"reset-password" 	=> "form",
	"edit" 	=> "edit"
];

$jsList = [
	"index" => "main",
	"gallery" => "main",
	"edit"	=> "edit",
	"profile"	=> "profile"
];

$titleList = [
	"index" 					=> "Camagru | Home",
	"gallery" 					=> "Camagru | My snaps",
	"profile" 				=> "Camagru | Profile",
	"register" 				=> "Camagru | Register",
	"login" 					=> "Camagru | Login",
	"edit" 						=> "Camagru | Snap a Pic",
	"forgot-password" => "Camagru | Forgot Password",
	"reset-password" 	=> "Camagru | Reset Password"
];

//Pagination 
$page_num = (isset($_GET['page'])) ? $_GET['page'] : 1;
$recor_per_page = 4;

$userId = ($session->get("id")) ? $session->get("id") : 0;

// Logout
if (isset($_GET['logout']))
{
	$session->destroy(["loggedin","id"]);
	redirect("index.php");
}




?>
