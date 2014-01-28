/*
* Jack Farzan
* problem 195 in java
*/

import java.io.*;
import java.util.*;

class Main
{
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        //String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }

    public static void main (String args[])
    {
        Main myWork = new Main();  // create a dynamic instance
        myWork.Begin();            // the true entry point
    }

    void Begin()
    {
        String input;
        StringTokenizer idata;
        int size, j;
        String[] args;

        while ((input = Main.ReadLn (255)) != null)
        {

            idata = new StringTokenizer(input);
            size = Integer.parseInt (idata.nextToken());
            System.out.println(size);
            //System.out.println(idata.nextToken());

            args = new String[size];
            for(j = 0; j < size; j++)
            {
                args[j] = idata.nextToken();
            }
            for(String ss : args)
                anagram(ss);
        }
    }

    //create anagrams of a given word through recursion
    //keeps cutting letters from the first substring and adding them to the second until the 1st ss is 0
    //once the 1st sub is 0, the second substring is returned

    private static void anagram(String s)
    {
        List<String> strings = new ArrayList<String>();
        List<String> grams = anagram(s, "", strings);
        Collections.sort(grams);
        for(String ana : grams)
            System.out.println(ana);
    }

    private static List<String> anagram(String s1, String s2, List<String> strings)
    {
        String news1, news2;
        if(s1.length() == 0)
            if(!strings.contains(s2))
                strings.add(s2);

        for(int i = 0; i < s1.length(); i++)
        {
            news1 = s1.substring(0, i) + s1.substring(i+1, s1.length());
            news2 = s1.charAt(i) + s2;
            anagram(news1, news2, strings);
        }

        return strings;
    }

}