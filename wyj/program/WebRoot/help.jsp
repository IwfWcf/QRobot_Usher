<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'help.jsp' starting page</title>
    
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
   	例子：<br/>
  	类型1：<br/>
  	问题<input type="text" value="你叫什么名字 ">  答复<input type="text" value="我叫小Q "> <br/>
  	类型2：<br/>
  	问题1<input type="text" value="我喜欢你 ">    答复1<input type="text" value="我也喜欢你 "> <br/>
  	问题2<input type="text" value="真的假的 ">    答复2<input type="text" value="真的 ">   <br/>
  	类型3: <br/>
  	问题<input type="text" value="*的名字叫*">   答复<input type="text" size="30" value="我知道了，你的名字叫*(2)">  *（2）表示为问题中的第二个星号的内容 <br/>
  	类型4：<br/>
  	问题<input type="text" value="我有一本书">
  	答复1<input type="text" value="这本书多少钱"> 答复2<input type="text" value="什么类型的书"> 答复3<input type="text" value="能借给我看吗"><br/>
  	答复4<input type="text" value="你拥有多久了"> 答复5<input type="text" value="多厚呀"> 答复6<input type="text" value="你拥有很多书吗"> 从这六个中随机选一个来答复
  	
  	<br/><a href="http://localhost:8080/program/index.jsp" >返回上一界面</a>
  </body>
</html>
