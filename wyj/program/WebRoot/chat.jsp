<%@ page language="java" import="java.util.*,manager.ChatSession" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
<head>
<script src="//ajax.googleapis.com/ajax/libs/jquery/1.8.3/jquery.min.js">
</script>
<!-- 
<script>

var xmlhttp;
	if (window.XMLHttpRequest)
	  {// code for IE7+, Firefox, Chrome, Opera, Safari
	  xmlhttp=new XMLHttpRequest();
	  }
	else
	  {// code for IE6, IE5
	  xmlhttp=new ActiveXObject("Microsoft.XMLHTTP");
	  }

	xmlhttp.onreadystatechange=function()
	  {
	  if (xmlhttp.readyState==4 && xmlhttp.status==200)
	    {
  				 $("ol").append(xmlhttp.responseText);
	    }
	  }
	  
$(document).ready(function(){
	
  $("#btn2").click(function(){
	    var url="/getMessage";
 	    url=url+"?message="+$("#wenti").val();
 		xmlHttp.open("GET",url,true);	
		xmlhttp.send();
    $("ol").append($("#wenti").val());
  });
});
</script>
-->
<script>
	$("#btn2").click(function(){
		$.ajax("/getMessage",
		{"message":$("#wenti").val()}
		,function(data,status){
		$("ol").append("<li>"+data+"</li>");
		});
	});
</script>
</head>

<body>
<p>This is a paragraph.</p>
<p>This is another paragraph.</p>
<ol>
<li>List item 1</li>
<li>List item 2</li>
<li>List item 3</li>
</ol>
<input type="text" id="wenti" name="wenti" value="fff">
<button id="btn2">提交</button>



</body>
</html>
