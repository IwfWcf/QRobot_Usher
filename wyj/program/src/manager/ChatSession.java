package manager;

import org.alicebot.ab.*;
import org.alicebot.ab.utils.IOUtils;

/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-16
 * Time: ����7:02
 * To change this template use File | Settings | File Templates.
 */
public class ChatSession {
    private String botName;
    private String action;
    private Chat chatSession;
    private Bot bot;
    public static String message;

    private int init(){
        MagicStrings.root_path = "D:\\myeclipse\\.metadata\\.me_tcat\\webapps\\program\\WEB-INF\\";
        AIMLProcessor.extension =  new PCAIMLProcessorExtension();
        botName = "super";
        action = "chat";
        Graphmaster.enableShortCuts = true;
        bot = new Bot(botName, MagicStrings.root_path, action);
        //bot.preProcessor.normalizeFile(MagicStrings.root_path+"bots/super/aiml/thats.txt", MagicStrings.root_path+"bots/super/aiml/normalthats.txt");
        return 0;
    }

    public ChatSession(){
        init();
        chatSession = new Chat(this.bot);
    }

    public ChatSession(Bot bot){
        init();
        chatSession = new Chat(bot);
    }

    public String getResponse(String message){
        if (message == null || message.length() < 1)  message = MagicStrings.null_input;

        String request = message;
        String response = chatSession.multisentenceRespond(request);
        while (response.contains("&lt;")) response = response.replace("&lt;","<");
        while (response.contains("&gt;")) response = response.replace("&gt;",">");
        return response;
    }

    public boolean WriteRecord(){
        bot.writeQuit();
        return true;
    }
}
