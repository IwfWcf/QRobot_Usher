package org.alicebot.ab;


import com.bot.action.MyIkAnalyzer;
import net.reduls.sanmoku.Morpheme;
import net.reduls.sanmoku.Tagger;

import java.util.HashSet;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.Set;
/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-27
 * Time: 上午10:36
 * To change this template use File | Settings | File Templates.
 */

//处理中文分词
public class ChineseTokenizer {
    static final Pattern tagPattern = Pattern.compile("(<.*>.*</.*>)|(<.*/>)");
    static MyIkAnalyzer analyzer = MyIkAnalyzer.GetInstance();


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
       System.out.println(result);
        return " "+result.trim()+" ";
    }


}
