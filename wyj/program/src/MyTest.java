/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-12
 * Time: ÏÂÎç9:13
 * To change this template use File | Settings | File Templates.
 */

import org.alicebot.ab.*;
import org.alicebot.ab.utils.IOUtils;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;

public class MyTest {
        public static void main (String[] args) {
            MagicStrings.root_path = System.getProperty("user.dir");
            System.out.println("Working Directory = " + MagicStrings.root_path);
            AIMLProcessor.extension =  new PCAIMLProcessorExtension();

            String botName = "super";
            String action = "chat";
            Graphmaster.enableShortCuts = true;
            Timer timer = new Timer();
            Bot bot = new Bot(botName, MagicStrings.root_path, action);
            Chat chatSession = new Chat(bot);
//        bot.preProcessor.normalizeFile("c:/ab/bots/super/aiml/thats.txt", "c:/ab/bots/super/aiml/normalthats.txt");
            bot.brain.nodeStats();
            MagicBooleans.trace_mode = false;
            String textLine="";
            while (true) {
                System.out.print("Human: ");
                textLine = IOUtils.readInputTextLine();
                if (textLine == null || textLine.length() < 1)  textLine = MagicStrings.null_input;
                if (textLine.equals("q")) System.exit(0);
                else if (textLine.equals("wq")) {
                    bot.writeQuit();
                    System.exit(0);
                }
                else {
                    String request = textLine;
                    if (MagicBooleans.trace_mode) System.out.println("STATE="+request+":THAT="+chatSession.thatHistory.get(0).get(0)+":TOPIC="+chatSession.predicates.get("topic"));
                    String response = chatSession.multisentenceRespond(request);
                    while (response.contains("&lt;")) response = response.replace("&lt;","<");
                    while (response.contains("&gt;")) response = response.replace("&gt;",">");
                    System.out.println("Robot: "+response);



                }
            }
        }

}