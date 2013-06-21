<%@ page language="java" import="java.util.*" pageEncoding="GB2312"%>
<%@ page import="java.io.FileOutputStream"%>
<%@ page import="java.io.OutputStreamWriter"%>
<%@ page import="java.io.*"%>
<%@ page import="java.util.ArrayList"%>


<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01 Transitional//EN">
<html>
  <head>
    <base href="<%=basePath%>">
    
    <title>My JSP 'add.jsp' starting page</title>
    
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
        <% 
        	String firstwenti = new String(request.getParameter("firstwenti").getBytes("ISO-8859-1"),"UTF-8");
        	String firstdaan = new String(request.getParameter("firstdaan").getBytes("ISO-8859-1"),"UTF-8") ;
        	String secondwenti = new String(request.getParameter("secondwenti").getBytes("ISO-8859-1"),"UTF-8");
        	String seconddaan = new String(request.getParameter("seconddaan").getBytes("ISO-8859-1"),"UTF-8") ;
        	
        	
       
        	String filename = "D:\\实训\\实训资料的当地仓库\\QRobot_Usher\\wyj\\program\\bots\\super\\aiml\\new.aiml" ;
        	
        	File file = new File(filename);
  	        BufferedReader br = new BufferedReader(new FileReader(file.getAbsolutePath()));
            String str = null;
            List list = new ArrayList();
            while( (str=br.readLine()) != null ){
      		   list.add(str);
  		    }
		    BufferedWriter bw = new BufferedWriter(new FileWriter(file.getAbsolutePath()));
  		    for( int i=0;i<list.size()-1;i++ ){
   		    	bw.write(list.get(i).toString());
   		    	bw.newLine();
            }
  		    bw.flush();
  		    bw.close();

        	
        	
        	
   		   	FileOutputStream stream;
 		    OutputStreamWriter writer;
	       try 
   	       {
  		       stream = new FileOutputStream(filename, true);
    	       writer = new OutputStreamWriter(stream);
    	       writer.write("<category>\n");   	  
    	       writer.write("<pattern>");
    	       writer.write(firstwenti);
    	       writer.write("</pattern>\n");  
    	       writer.write("<template>");
    	       writer.write(firstdaan);
    	       writer.write("</template>\n");
    	       writer.write("</category>\n"); 
    	       
    	       writer.write("<category>\n"); 
    	       writer.write("<pattern>");
    	       writer.write(secondwenti);
    	       writer.write("</pattern>\n");
    	       writer.write("<that>");
    	       writer.write(firstdaan);
    	       writer.write("</that>\n");
    	       writer.write("<template>");
    	       writer.write(seconddaan);
    	       writer.write("</template>\n");
    	       writer.write("</aiml>"); 

               writer.close();
               stream.close();
           }
           catch(Exception e) 
           {
            	e.getStackTrace ();
           }
        	
        	
         %>
         <%= firstwenti %><br>
         <%= firstdaan %><br>
         <%= secondwenti %><br>
         <%= seconddaan %><br>
    	添加成功 <br>
    	<a href="http://localhost:8080/program/index.jsp" >返回上一界面</a>
  </body>
</html>
