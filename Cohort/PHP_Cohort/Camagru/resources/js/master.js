var session = document.querySelector("meta[name='loggedin']").getAttribute("content");


var $ = function (selector)
{
  var self = {};

  self.selector = selector;
  self.element = document.querySelectorAll(self.selector);

  if(self.element.length == 1)
  	self.element = document.querySelector(self.selector);

  self.html = function(html){
	 if (!html)
		return self.element.innerHTML;
	 else
		self.element.innerHTML = html;
	 return self;
  }

  self.text = function(text)
  {
	 if (!text)
		return self.element.textContent;
	 else
		self.element.textContent = text;
	 return self;
  }

  self.on = function(type, callback)
  {
	  if(self.element.length > 1)
	  {
		  	var i = 0;
	  		while(i < self.element.length)
	  		{
	  			self.element[i]['on'+ type] = callback;
	  			i++;
	  		}
	  }
	  else
	  	self.element['on'+ type] = callback;

	 return self;
  }

  self.detache = function(type)
  {
	  if(self.element.length > 1)
	  {
		  	var i = 0;
	  		while(i < self.element.length)
	  		{
	  			self.element[i]['on'+ type] = function(){ return false;};
	  			i++;
	  		}
	  }
	  else
	  	self.element['on'+ type] = function() { return false;};

	 return self;
  }



  self.attr = function(attr, value)
  {
	 if (!value)
	 {
		 if (self.element.length > 1)
		 	return self.element[0].getAttribute(attr);
		 else
		 	return self.element.getAttribute(attr);
	 }
	 else
	 {
		 if (self.element.length > 1)
		{
			var i = 0;
			while(i < self.element.length)
			{
				self.element[i].setAttribute(attr, value)
				i++;
			}
		}
		 else
		   self.element.setAttribute(attr, value)
	 }
	 return self;
  }

  self.eq = function(num)
  {
	 self.element = document.querySelector(self.selector+":nth-child("+num+")");
	 return self;
  }

  self.css = function(rule, style)
  {
	 self.element.style[rule] = style;
	 return self;
  }

	self.parent = function()
	{
		return self.element.parentNode;
		return self;
	}


  return self;
}
