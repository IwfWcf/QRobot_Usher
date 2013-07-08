package com.bot.test;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.analysis.tokenattributes.OffsetAttribute;
import org.wltea.analyzer.lucene.IKAnalyzer;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;

/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-25
 * Time: 下午8:17
 * To change this template use File | Settings | File Templates.
 */
@WebServlet(name = "IKTestServlet")
public class IKTestServlet extends HttpServlet {
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String requestText= request.getParameter("text");
        if(requestText == null)
        {
            requestText = "test cheada24235" ;
        }
        //构建
        Analyzer analyzer = new IKAnalyzer();

        TokenStream ts = null;
        try{
            ts = analyzer.tokenStream("myField",new StringReader(requestText));
            OffsetAttribute offset = ts.addAttribute(OffsetAttribute.class);
            CharTermAttribute term = ts.addAttribute(CharTermAttribute.class);
            ts.reset();
            String responseText = null;
            while(ts.incrementToken()){
               responseText += offset.startOffset()+" - "+offset.endOffset()+" : "+term.toString()+"\r\n";
            }
            System.out.print(responseText);
            response.setContentType("application/x-javascript;charset=UTF-8");
            PrintWriter out = response.getWriter();
            out.print(responseText);
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            //释放TokenStream的所有资源
            if(ts != null){
                try {
                    ts.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }

    }
}
