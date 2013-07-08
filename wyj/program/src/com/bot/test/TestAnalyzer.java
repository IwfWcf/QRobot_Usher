package com.bot.test;

import com.bot.action.MyIkAnalyzer;
import net.reduls.sanmoku.Morpheme;
import net.reduls.sanmoku.Tagger;
import org.alicebot.ab.MagicBooleans;

import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-27
 * Time: 下午2:21
 * To change this template use File | Settings | File Templates.
 */
public class TestAnalyzer {
    public static void main(String[] args){
          String testContent = "<category><pattern>NEW CONTACT TEST ONE</pattern>" +
                  "<template>Adding a new contact." +
                  "<addinfo>" +
                  "<displayname>Alan Turing</displayname>" +
                  "<dialnumber>212-1912</dialnumber>" +
                  "<phonetype>mobile</phonetype>" +
                  "<emailaddress>alan.turing@manchester.edu</emailaddress>" +
                  "<emailtype>work</emailtype>" +
                  "<birthday>June 23, 1912</birthday>" +
                  "</addinfo></template>" +
                  "</category>"  ;
        String result = morphSentence(testContent);
        System.out.println(result);
    }

    static final Pattern tagPattern = Pattern.compile("(<.*>.*</.*>)|(<.*/>)");
    static MyIkAnalyzer analyzer = MyIkAnalyzer.GetInstance();

    /*
    public static String morphSentence(String sentence){
        if(!MagicBooleans.cn_morphplogical_analysis) return sentence;
        String result = "";
        Matcher matcher = tagPattern.matcher(sentence);
        while(matcher.find()){
            int i = matcher.start();
            int j = matcher.end();
            String prefix, tag;
            if (i > 0) prefix = sentence.substring(0,i-1);
            else prefix = "";
            tag = sentence.substring(i,j);
            result += " " + analyzer.deal(prefix).trim() + " " + tag;
            if( j < sentence.length()) sentence = sentence.substring(j,sentence.length());
            else sentence = "";
        }
        result += " " + analyzer.deal(sentence).trim();
        while (result.contains("$ ")) result = result.replace("$ ","$");
        while (result.contains("  ")) result = result.replace("  "," ");
        return result.trim();
    }

    */

    public static String buildFragment(String fragment) {

        String result = "";
        for(Morpheme e : Tagger.parse(fragment)) {
            result += e.surface+" ";
            //
             System.out.println("Feature "+e.feature+" Surface="+e.surface);
        }
        return result.trim();
    }

    /**
     * Morphological analysis of an input sentence that contains an AIML pattern.
     *
     * @param sentence
     * @return       morphed sentence with one space between words, preserving XML markup and AIML $ operation
     */
    public static String morphSentence (String sentence) {
        if (!MagicBooleans.jp_morphological_analysis) return sentence;
        String result = "";
        Matcher matcher = tagPattern.matcher(sentence);
        while (matcher.find()) {

            int i = matcher.start();
            int j = matcher.end();
            System.out.println("段："+sentence.substring(i,j));
           /* String prefix, tag;
            if (i > 0) prefix = sentence.substring(0, i-1); else prefix = "";
            tag = sentence.substring(i, j);
            result += " "+buildFragment(prefix)+" "+tag;
            if (j < sentence.length()) sentence = sentence.substring(j, sentence.length()); else sentence = "";
            //System.out.print("Start index: " + matcher.start());
            //System.out.print("End index: " + matcher.end() + " ");
            //System.out.println(matcher.group());
        }
        result += " "+buildFragment(sentence);
        while (result.contains("$ ")) result = result.replace("$ ", "$");
        while (result.contains("  ")) result = result.replace("  "," ");
        return result.trim();
        */
        }
            return "";
    }

}
