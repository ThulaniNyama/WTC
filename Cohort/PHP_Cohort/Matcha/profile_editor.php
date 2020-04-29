<?php include_once 'header2.php' ?>

<script>
        $(document).ready(function(){ 
        	$("#seed_one").autocomplete({source: "action/tags.php"}); 
        	$("#seed_two").autocomplete({source: "action/tags.php"}); 
        	$("#seed_three").autocomplete({source: "action/tags.php"}); 
        });
</script>
  <div id="home" class="intro route bg-image" style="background-image: url(image/blur.jpg)">
<div class="banner-home">
	<div class="login">
    	<div class="container" style="position: relative; top: 10%; color: whitesmoke; z-index: 2;">
			<form action="action/profile_editor.php" method="POST">
			<br><br>
				<div class="form-group">
		            <label for="name" style="color:black">Your name :</label>
		            <input type="text" class="form-control" name="name" value="<?php echo $_SESSION['auth']->name ?>" required>
		        </div>
		        <div class="form-group">
		        	<label for="age">Age : </label>
		        	<input type="number" min="18" max="99" name="age" value="<?php echo $_SESSION['auth']->age; ?>" style="color: black" required>
		        </div>
		        <div class="form-group">
		        	<label for="gender" style="color:black">Gender : </label>
		        	<p>

		      		<?php if ($_SESSION['auth']->gender === "M") { ?>
		        		<input type="radio" name="gender" value="M" checked style="color:black">Male
		        	<?php }else{ ?>
		        		<input type="radio" name="gender" value="M" style="color:black">Male
		        	<?php } ?>

		        	<?php if ($_SESSION['auth']->gender === "F") { ?>
		        		<input type="radio" name="gender" value="F" checked style="color:black">Female</p>
		        	<?php }else{ ?>
		        		<input type="radio" name="gender" value="F" style="color:black">Female</p>
		        	<?php } ?>
		        	</p>
		        </div>
		        <div class="form-group">
		            <label for="orientation" style="color:black">Interested in:</label>
		            <p>
		            	<?php if ($_SESSION['auth']->orientation === "M") { ?>
			            	<input type="radio" name="orientation" value="M" checked style="color:black">Male
			            <?php }else{ ?>
			            	<input type="radio" name="orientation" value="M">Male
			            <?php } ?>
			       		
			       		<?php if ($_SESSION['auth']->orientation === "F") { ?>
			            	<input type="radio" name="orientation" value="F" checked>Female
			            <?php }else{ ?>
			            	<input type="radio" name="orientation" value="F">Female
			            <?php } ?>

			            <?php if ($_SESSION['auth']->orientation === "M-F") { ?>
			            	<input type="radio" name="orientation" value="M-F" checked>Male/Female
			            <?php }else{ ?>
			            	<input type="radio" name="orientation" value="M-F">Male/Female
			            <?php } ?>
			        </p>
		        </div>
		        <div class="form-group">
		        	<label for="bio">Your bio :</label>
		        	<input type="textarea" name="bio" class="form-control" maxlength="255" value="<?php echo $_SESSION['auth']->bio ?>">
		        </div>
		        <div class="form-group">
		        	<label>Interest : </label><br>
		        	<p style="color: black!important">
			        	<input minlength="2" type="text" id="seed_one" name="i1" value="<?php echo $_SESSION['auth']->i1; ?>">
			        	<input minlength="2" type="text" id="seed_two" name="i2" value="<?php echo $_SESSION['auth']->i2; ?>">
			        	<input minlength="2" type="text" id="seed_three" name="i3" value="<?php echo $_SESSION['auth']->i3; ?>">
		        	</p>
		        </div>
		        <div class="form-group">
		        	<center><input type="submit" class="btn btn-dark btn-block" name="submit" value="Update"></center>
		        </div>
			</form>
		</div>
	</div>
</div>