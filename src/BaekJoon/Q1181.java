package BaekJoon;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * S5 organaize words
 * @version v0.0.1
 * @since 5/16/2023
 * @author Dounguk Kim
 */
public class Q1181 {
    public static List<String> words=new ArrayList<>();

    public static void compare(String a, String b,int intA,int intB){
        int loop=a.length();
        char[] aChar=a.toCharArray();
        char[] bChar=b.toCharArray();
        for (int i=0;i<loop;i++){
            if (aChar[i]<bChar[i]) {
                words.set(intA,b);
                words.set(intB,a);
            }
        }
    }
    public static void wordLength(){

    }

    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int count=sc.nextInt();
        int loopCount=0;
        String temp;

        for (int i=0;i<count;i++){
            if(!words.isEmpty()){
                words.add(sc.next());
                for (int j=0;j<loopCount;j++){
                    if(words.get(loopCount).length()<words.get(j).length()){ //새로 들어온 단어 위치 찾기
                        temp=words.get(loopCount);
                        words.set(loopCount,words.get(j));
                        words.set(j,temp);
                    } else if (words.get(loopCount).length()==words.get(j).length()) { //단어 길이 같을경우
                        compare(words.get(loopCount),words.get(j),loopCount,j);
                    }
                }
                loopCount++;
            }
            else{
                words.add(sc.next());
                loopCount++;
            }
        }
        for(int i=0;i<count;i++){
            System.out.println(words.get(i));
        }

    }
}
