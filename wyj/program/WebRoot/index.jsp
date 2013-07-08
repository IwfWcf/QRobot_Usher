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
  	<center>
   	类型1：  
  	<form  method="post" action="add.jsp">
  	  	请输入问题<input  type="text" name="wenti">
 	 	请输入答复<input type="text" name="daan">
 	 	<input type="submit" name="submit" value="提交添加内容">
  	</form> 	
           类型2：
  	<form method="post"" action="add1.jsp">
  		请输入第一个问题<input type="text" name="firstwenti">
  		请输入第一个答复<input type="text" name="firstdaan"><br>
  		请输入第二个问题<input type="text" name="secondwenti">
  		请输入第二个答复<input type="text" name="seconddaan"><br>
  		<input type="submit" name="submit" value="提交添加内容">	
  	</form>
  	类型3：
  	<form method="post" action="add2.jsp">
  		问题<input type="text" name="wenti">
  		答复<input type="text" size="30" name="daan">
  		<input type="submit" value="提交添加内容">
  	</form>
  	类型4：
  	<form method="post" action="add3.jsp">
  		问题<input type="text" name="wenti">
  		答复1<input type="text" name="daan1" > 答复2<input type="text" name="daan2"> 答复3<input type="text" name="daan3"><br/>
  		答复4<input type="text"  name="daan4" > 答复5<input type="text" name="daan5"> 答复6<input type="text" name="daan6">
  		<input type="submit"  value="提交添加内容">
  	</form>
  	<br/>
  	<a href="help.jsp">帮助</a>
  	</center>
  </body>
</html>
