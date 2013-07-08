package com.bot.servlet;

import org.alicebot.ab.*;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.net.URLDecoder;

/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-18
 * Time: 上午9:36
 * To change this template use File | Settings | File Templates.
 */
@WebServlet(name = "GetMessageServlet")
public class GetMessageServlet extends HttpServlet {
    private String botName;
    private String action;
    private Chat chatSession;
    private Bot bot;

    @Override
    public void init() throws ServletException {
        super.init();    //To change body of overridden methods use File | Settings | File Templates.
        MagicStrings.root_path = this.getServletConfig().getServletContext().getRealPath("/");
        AIMLProcessor.extension =  new PCAIMLProcessorExtension();
        botName = "小Q";
        action = "chat";
        Graphmaster.enableShortCuts = true;
        bot = new Bot(botName, MagicStrings.root_path, action);
        bot.brain.printgraph();
        chatSession =new Chat(bot);
    }

    @Override
    public void destroy() {
        super.destroy();    //To change body of overridden methods use File | Settings | File Templates.
        //bot.writeQuit();
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
         doGet(request,response);
    }

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        String requestText= request.getParameter("message");
        int len = requestText.length();

        System.out.println("接收到的message:"+requestText);
        if (requestText == null || requestText.length() < 1)  requestText = MagicStrings.null_input;
        String responseText = chatSession.multisentenceRespond(requestText);
        while (responseText.contains("&lt;")) responseText = responseText.replace("&lt;","<");
        while (responseText.contains("&gt;")) responseText = responseText.replace("&gt;",">");
        System.out.printf("response:%s\n",responseText);
        response.setContentType("application/x-javascript;charset=UTF-8");
        PrintWriter out = response.getWriter();
       out.print(requestText);
    }
}
