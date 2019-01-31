window.onload = function(e)
{
	var canvas = document.querySelector("#canvas"),
		 context = canvas.getContext("2d");

	var screen = document.querySelector("#screen"),
		video = document.querySelector("video"),
		img = document.querySelector("#screen img"),
		vendorUrl = window.URL || window.webkitURL;
	var width, height;
	var srcs = {
		count: 0,
		src: [],
		size: {
			width: 0,
			height: 0
		}
	};

	var base = {exists: false, message: ""};

	navigator.getMedia = navigator.getUserMedia ||
								navigator.webkitGetUserMedia ||
								navigator.mozGetUserMedia ||
								navigator.msGetUserMedia;

	function getFileFromPc()
	{
		if (!base.exists)
			document.querySelector("#form-btn-upload").click();
	}
	document.querySelector("#btn-upload").addEventListener("click", getFileFromPc);


	document.querySelector("#form-btn-upload").addEventListener("change", previewImg);

	function previewImg(e)
	{
		if (this.files && this.files[0])
		{
			// console.log(this.files[0].size);
			if (this.files[0].size > 5000000)
			{
				document.querySelector(".message-box").innerHTML = "File too big, max 6MB";
				document.querySelector(".message-box").style.display = "block";
				  setTimeout(function(){
					  document.querySelector(".message-box").style.display = "none";
				  }, 2000);
			}
			else
			{
				var obj = new FileReader();

				obj.onload = function(data)
				{
						img.onload =  function(ev)
						{
							width = ev.target.width;
							height = ev.target.height;

							srcs.size.width = width;
							srcs.size.height = height;

							canvas.width = width;
							canvas.height = height;
							context.drawImage(img, 0, 0, width, height);
							canvas.style.display = "block";
						}
						img.src = data.target.result;
						srcs.src[srcs.count] = data.target.result;
						srcs.count++;
						base.exists = true;
						document.querySelector("#btnCamara").style.visibility = "hidden";
						document.querySelector("#btnCapture").style.visibility = "hidden";
						document.querySelector("#btn-upload").style.visibility = "hidden";
						document.querySelector("#btnSave").style.visibility = "visible";
				}
				obj.readAsDataURL(this.files[0]);
			}
		}
	}


	$(".frames img").on("click", overlayImage);
	function overlayImage()
	{
		if (base.exists)
		{
			var layer = document.createElement("img");

			layer.setAttribute("class", "layer");
			layer.setAttribute("src", this.src);

			screen.appendChild(layer);

			srcs.src[srcs.count] = this.src;
			srcs.count++;
		}
	}



	$("#btnCamara").on("click", useCamera);

	function useCamera()
	{
		video.style.display = "block";
		navigator.getMedia({
				video: true,
				audio: false
			},
			function(stream)
			{
				video.src = vendorUrl.createObjectURL(stream);
				base.exists = true;
				document.querySelector("#btnCapture").style.visibility = "visible";
				document.querySelector("#btn-upload").style.visibility = "hidden";

			},
			function (error)
			{

			}
		)
	}

	$("#btnCapture").on("click", captureImage);
	function captureImage()
	{
		if (base.exists)
		{
			width = video.offsetWidth;
			height = video.offsetHeight;

			canvas.width = width;
			canvas.height = height;
			context.drawImage(video, 0, 0, width, height);

			canvas.style.display = "block";
			video.style.display = "none";

			srcs.src[srcs.count] = canvas.toDataURL("image/png");
			srcs.count++;
			base.exists = true;
			document.querySelector("#btnSave").style.visibility = "visible";
			document.querySelector("#btnCamara").style.visibility = "hidden";
			document.querySelector("#btnCapture").style.visibility = "hidden";
		}
	}

	$("#btnSave").on("click", saveImage);
	function saveImage()
	{
		if (base.exists)
		{
			var ajax = new XMLHttpRequest(),
				 i = 0,
				 params = "";

			while (i < srcs.src.length)
			{
				params += "img"+i+"="+srcs.src[i]+ ((i+1 != srcs.src.length) ? "&" : "");
				i++;
			}

			params +="&width="+srcs.size.width+"&height="+srcs.size.width;
			ajax.open("POST", "edit.php", true);
			ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
			ajax.onreadystatechange = function()
			{
			    if (this.readyState == 4 && this.status == 200)
				 {
					 document.querySelector(".message-box").classList.add("success");
					 document.querySelector(".message-box").innerHTML = "Snap successfully saved";
					 document.querySelector(".message-box").style.display = "block";
					setTimeout(function(){
						document.querySelector(".message-box").style.display = "none";
						location.reload();
					}, 2000);
			    }
			};
			ajax.send(params);
		}
	}


};
