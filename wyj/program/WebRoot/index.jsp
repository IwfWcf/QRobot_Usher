<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'index.jsp' starting page</title>
	<meta http-equiv="pragma" content="no-cache">
	<meta http-equiv="cache-control" content="no-cache">
	<meta http-equiv="expires" content="0">    
	<meta http-equiv="keywords" content="keyword1,keyword2,keyword3">
	<meta http-equiv="description" content="This is my page">
	<!--
	<link rel="stylesheet" type="text/css" href="styles.css">
	-->
	
	
	
  </head>
  
  <body>
  	<h1 align="center"> 小Q学学学</h1>
  	<form method="post" action="add.jsp">
  	  	请输入问题<input type="text" name="wenti">
 	 	请输入答案<input type="text" name="daan">
 	 	<input type="submit" name="submit" value="提交添加内容">
  	</form>
    <br>有关联的两个问题：<br>
  	<form method="post"" action="add1.jsp">
  		请输入第一个问题<input type="text" name="firstwenti">
  		请输入第一个答案<input type="text" name="firstdaan"><br>
  		请输入第二个问题<input type="text" name="secondwenti">
  		请输入第二个答案<input type="text" name="seconddaan">
  		<input type="submit" name="submit" value="提交添加内容">	
  	</form>

  </body>
</html>
