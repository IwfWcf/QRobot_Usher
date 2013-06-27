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
        	String wenti = new String(request.getParameter("wenti").getBytes("ISO-8859-1"),"UTF-8");
        	String daan1 = new String(request.getParameter("daan1").getBytes("ISO-8859-1"),"UTF-8") ;
        	String daan2 = new String(request.getParameter("daan2").getBytes("ISO-8859-1"),"UTF-8") ;
        	String daan3 = new String(request.getParameter("daan3").getBytes("ISO-8859-1"),"UTF-8") ;
        	String daan4 = new String(request.getParameter("daan4").getBytes("ISO-8859-1"),"UTF-8") ;
        	String daan5 = new String(request.getParameter("daan5").getBytes("ISO-8859-1"),"UTF-8") ;
        	String daan6 = new String(request.getParameter("daan6").getBytes("ISO-8859-1"),"UTF-8") ;
        	String[] daan = {daan1 , daan2 , daan3 , daan4 , daan5 , daan6} ;
        	
        	
       
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
    	       writer.write(wenti);
    	       writer.write("</pattern>\n");  
    	       writer.write("<template><random>\n");
    	       for (int i=0 ; i<daan.length ; i++){
    	       		if(!daan[i].isEmpty()){
    	       			writer.write("<li>" + daan[i] + "</li>\n");  
    	       		} 	       			
    	       		
    	       }
    	       writer.write("</random></template>\n");
    	       writer.write("</category>\n"); 
    	       writer.write("</aiml>"); 

               writer.close();
               stream.close();
           }
           catch(Exception e) 
           {
            	e.getStackTrace ();
           }
        	
        	
         %>
         <%= wenti %><br>
         <%= daan1 %><br>
         <%= daan2 %><br>
         <%= daan3 %><br>
         <%= daan4 %><br>
         <%= daan5 %><br>
         <%= daan6 %><br>


    	添加成功 <br>
    	<a href="index.jsp" >返回上一界面</a>
  </body>
</html>
