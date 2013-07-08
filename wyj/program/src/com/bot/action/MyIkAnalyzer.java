package com.bot.action;

import org.apache.lucene.analysis.Analyzer;
import org.apache.lucene.analysis.TokenStream;
import org.apache.lucene.analysis.tokenattributes.CharTermAttribute;
import org.apache.lucene.analysis.tokenattributes.OffsetAttribute;
import org.apache.lucene.analysis.tokenattributes.TypeAttribute;
import org.wltea.analyzer.lucene.IKAnalyzer;

import java.io.IOException;
import java.io.StringReader;

/**
 * Created with IntelliJ IDEA.
 * User: Johng
 * Date: 13-6-25
 * Time: 下午9:43
 * To change this template use File | Settings | File Templates.
 */
public class MyIkAnalyzer {
    private static MyIkAnalyzer instance = null;
    private MyIkAnalyzer(){
        //构建IK分词器，使用smart分词模式
        analyzer = new IKAnalyzer(true);
    }

    public static MyIkAnalyzer GetInstance(){
        if(instance == null)
        {
            instance = new MyIkAnalyzer();
        }
        return instance;
    }

    private Analyzer analyzer;
    private TokenStream tokenStream;
    private OffsetAttribute offset;
    private CharTermAttribute term;

    public String deal(String content){
        String result = "";
        if(content == null)
            return result;
        else{
            //获取Lucene的TokenStream对象
            TokenStream ts = null;
            try {
                ts = analyzer.tokenStream("myAnalyzer", new StringReader(content));
                //获取词元位置属性
                OffsetAttribute offset = ts.addAttribute(OffsetAttribute.class);
                //获取词元文本属性
                CharTermAttribute term = ts.addAttribute(CharTermAttribute.class);
                //获取词元文本属性
                TypeAttribute type = ts.addAttribute(TypeAttribute.class);


                //重置TokenStream（重置StringReader）
                ts.reset();
                //迭代获取分词结果

                while (ts.incrementToken()) {
                    result += term.toString() + " ";
                }
                //关闭TokenStream（关闭StringReader）
                ts.end();   // Perform end-of-stream operations, e.g. set the final offset.
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
        return result;
    }

}
