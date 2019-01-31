<?php if (isset($errors) && count($errors) > 0): ?>
	<div class="message-box danger">
		<ul>
		<?php foreach($errors as $error): ?>
			<li><?php echo $error;?></li>
		<?php endforeach; ?>
		</ul>
	</div>
<?php endif; ?>
