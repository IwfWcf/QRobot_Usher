/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-12
 * Time: ÏÂÎç9:13
 * To change this template use File | Settings | File Templates.
 */

import com.sun.org.apache.xpath.internal.functions.FuncFalse;
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
            ChatSession chat = new ChatSession();

            while (true) {
                System.out.print("Human: ");
                String textLine = IOUtils.readInputTextLine();
                if (textLine.equals("q")) System.exit(0);
                else if (textLine.equals("wq")) {
                    chat.WriteRecord();
                    System.exit(0);
                }
                else {
                    System.out.println("Robot: "+chat.getResponse(textLine));
                }
            }
        }
}