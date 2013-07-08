/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-12
 * Time: ����9:13
 * To change this template use File | Settings | File Templates.
 */
package test;

import org.alicebot.ab.utils.IOUtils;

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