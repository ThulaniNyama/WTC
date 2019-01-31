window.onload = function(e)
{

	var img = document.querySelectorAll('img');
	var like = document.getElementsByClassName('heart');
	var comment = document.getElementsByClassName('comment');
	var close = document.getElementsByClassName('btn-close')

	var i = 0;
	var tab = [];


	$("img").on("click", expand);
	function expand()
	{
		var src = this.src,
			imgId = this.id.replace("id","3"),
			cover = document.querySelector(".cover"),
			imgLikes = this.parentNode.querySelectorAll(".info span")[0],
			imgComments = (this.parentNode.children)[1].querySelectorAll(".comment span"),
			img = document.querySelector(".photo img");
			icons = document.querySelectorAll(".cover .photo .info .icon"),
			likes = document.querySelector(".cover .photo .info span"),
			postId = this.parentNode.getAttribute("data-id"),
			comments = (icons[1].children)[0];


		img.src = src;
		document.querySelector("input#postId").value = postId;
		document.querySelector(".cover .photo").setAttribute("data-id", postId);
		likes.children[0].innerHTML = imgLikes.children[0].innerHTML;
		likes.className = imgLikes.className;
		comments.innerHTML = imgComments[0].innerHTML;
		cover.style.display = "block";

		getComments(postId);
		$(".heart").on("click", likePost);
	}

	function getComments(postId)
	{
		var ajax = new XMLHttpRequest(),
			params = "getComments=true&postId="+postId;

		ajax.open("GET", "index.php?"+params, true);
		ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
		ajax.onreadystatechange = function()
		{
		    if (this.readyState == 4 && this.status == 200)
			 {
				 document.querySelector(".comments").innerHTML = this.responseText;
			 }
		};
		ajax.send();
	}


	$("#close-btn").on("click",function(e){
		this.parentNode.style.display = "none";
		location.reload();
	});


	$(".heart").on("click", likePost);
	function likePost()
	{
		if (session > 0)
		{
			var postId = this.parentNode.parentNode.getAttribute("data-id"),
				 liked = null,
				 count = parseInt(getSibling(this, "SPAN").children[0].innerHTML);

			if (this.classList.contains("icon-heart-o"))
			{
				this.classList.add("icon-heart");
				this.classList.remove("icon-heart-o");
				liked = 1;
				count += 1;
			}
			else if (this.classList.contains("icon-heart"))
			{
				this.classList.add("icon-heart-o");
				this.classList.remove("icon-heart");
				liked = 0;
				count -= 1
			}
			getSibling(this, "SPAN").children[0].innerHTML = count;
			var ajax = new XMLHttpRequest(),
				 params="action=like&postId="+postId+"&liked="+liked;

			ajax.open("POST", "index.php", true);
			ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
			ajax.onreadystatechange = function()
			{
			    if (this.readyState == 4 && this.status == 200)
				 {
					 // $(".heart").on("click", likePost);
					 console.log(this.responseText);
				 }
			};
			console.log(postId);
			ajax.send(params);
		}
		else
			window.location.href = "login.php";
	}

	$(".icon.comment").on("click", function(){
		var img = this.parentNode.parentNode.children[0];
		img.click();
	});

	$("#input").on("keydown", commentPost);
	function commentPost(e)
	{
		var ajax = new XMLHttpRequest(),
			 enter = e.keyCode;
			 comment = this.value.trim(),
			 postId = document.querySelector("input#postId").value,
			 that = this,
			 commentCount = document.querySelector(".cover .photo .info .icon-comment span");

		if (enter == 13 && comment != "")
		{
			e.preventDefault();

			var params="action=comment&postId="+postId+"&comment="+comment;

			ajax.open("POST", "index.php", true);
			ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
			ajax.onreadystatechange = function()
			{
			    if (this.readyState == 4 && this.status == 200){
					 getComments(postId);
					 commentCount.innerHTML = parseInt(commentCount.innerHTML) + 1;
					 that.value = "";
					 console.log(this.responseText);
				 }
			};
			ajax.send(params);
		}
		else if (enter == 13 && comment == "")
			e.preventDefault();
	}

	$(".delete-post").on("click", deletePost)
	function deletePost(e)
	{
		e.preventDefault();
		var ajax = new XMLHttpRequest(),
			 authId = this.getAttribute("data-auth"),
			 postId = this.getAttribute("data-post"),
			 params = "?post-id="+postId+"&auth-id="+authId;

		var desition = window.confirm("Are you sure you would like to delete this post?");

		if (desition == true)
		{
			ajax.open("GET", params, true);
			ajax.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
			ajax.onreadystatechange = function()
			{
			    if (this.readyState == 4 && this.status == 200)
				 {
					console.log(this.responseText);
				 }
			};
			ajax.send();
			this.parentNode.parentNode.style.display = "none";
		}
	}


	function getSibling(el, siblig)
	{
		while (el.nodeName != siblig && el)
		{
			el = el.nextSibling;
		}
		return el;
	}




}
