window.onload = function(e)
{

	document.querySelector(".notification .icon").addEventListener("click", toggleNotification);

	function toggleNotification(e)
	{

		var notification,
			action = document.querySelector("label[for='notification']");
		if (this.classList.contains("icon-bell"))
		{
			this.classList.add("icon-bell-slash");
			this.classList.remove("icon-bell");
			notification = 0;
			action.innerHTML = "Turn on notification";
		}
		else if (this.classList.contains("icon-bell-slash"))
		{
			this.classList.add("icon-bell");
			this.classList.remove("icon-bell-slash");
			notification = 1;
			action.innerHTML = "Turn off notification";
		}

		var ajax = new XMLHttpRequest(),
			 params="notification="+notification;

		ajax.open("POST", "profile.php", true);
		ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
		ajax.onreadystatechange = function()
		{
		    if (this.readyState == 4 && this.status == 200){ }
		};
		ajax.send(params);

	}


}
