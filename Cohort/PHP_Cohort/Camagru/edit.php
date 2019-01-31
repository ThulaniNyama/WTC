<?php include("config/init.php");

if (!$session->exists("loggedin"))
    redirect("index.php");

if ($_SERVER['REQUEST_METHOD'] == "POST")
{
	if (isset($_POST["img0"]) && !empty($_POST["img0"]))
	{
		$userId = $session->get("id");

		$data = $_POST['img0'];
		$data = str_replace("data:image/jpeg;base64,", "", $data);
		$data = str_replace("data:image/jpg;base64,", "", $data);
		$data = str_replace("data:image/png;base64,", "", $data);
		$data = str_replace(" ", "+", $data);
		$image = imagecreatefromstring(base64_decode($data));

		$tmp = 'resources/img/image.jpg';
		header('Content-Type: image/jpeg');
		imagejpeg($image, $tmp);
		imagedestroy($image);

		unset($_POST['img0']);
		$layers = $_POST;

		$filesize = filesize($tmp);
		$filesize = round($filesize / 1024 / 1024, 1);

		list($width, $height) = getimagesize($tmp);

		foreach ($layers as $key => $value)
		{
			if ($key != "width" && $key != "height")
			{
				resizeImage($value, $width, $height);

				$img1 = imagecreatefromjpeg($tmp);
				imagealphablending($img1, true);
				imagesavealpha($img1, true);

				$img2 = imagecreatefrompng("resources/img/layer.png");
				imagecopy($img1, $img2, 0, 0, 0, 0, $width, $height);

				imagejpeg($img1, $tmp);
				imagedestroy($img1);
				imagedestroy($img2);
			}
		}
		$img = "data:image/png;base64,".base64_encode(file_get_contents($tmp));
		$crud->create([
			"table" => "posts",
			"fields" => ["user_id", "post"],
			"values" => [$userId, $img]
		]);
		unlink($tmp);
		if (file_exists("resources/img/layer.png"))
			unlink("resources/img/layer.png");
		echo "Success!!";
	}
	die();
}

	function resizeImage($filename, $w, $h)
	{
		header('Content-Type: image/png');

		list($width, $height) = getimagesize($filename);

		$thumb = imagecreatetruecolor($w, $h);
		imagealphablending($thumb, false);
		imagesavealpha($thumb, true);

		$source = imagecreatefrompng($filename);
		imagealphablending($source, true);

		imagecopyresampled($thumb, $source, 0, 0, 0, 0, $w, $h, $width, $height);

		imagepng($thumb, "resources/img/layer.png");
		imagedestroy($thumb);

	}

?>
<?php include("inc/header.php");?>

<div class="message-box danger"></div>
<div class="camara-section clearfix">
	<div class="screen clearfix" id="screen">
		<video autoplay="true" id="videoElement">

    	</video>
		<img src="" alt="">
		<canvas id="canvas" width="300" height="300"></canvas>
	</div>
	<div class="option clearfix">
		<div class="btn" id="btnCamara"> <span class="icon icon-ios-videocam"></span><br>Camera</div>
		<div class="btn" id="btnCapture"> <span class="icon icon-camera-retro"></span><br>Capture</div>
		<div class="btn" id="btn-upload"> <span class="icon icon-laptop"></span ><br>Upload Snap</div>
		<div class="btn" id="btnSave"> <span class="icon icon-floppy"></span>Save</div>
		<form class="" action="index.html" method="post">
			<input type="file" name="" value="" id="form-btn-upload">
		</form>
	</div>
	<div class="frames clearfix">
		<img src="resources/img/frame1.png" alt="">
		<img src="resources/img/frame2.png" alt="">
		<img src="resources/img/frame3.png" alt="">
		<img src="resources/img/frame4.png" alt="">
		<img src="resources/img/frame5.png" alt="">
	</div>
</div>

<?php include("inc/footer.php");?>
