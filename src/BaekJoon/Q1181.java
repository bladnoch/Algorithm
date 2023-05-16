package BaekJoon;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 * S5 organaize words
 *
 */
public class Q1181 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int count=sc.nextInt();
        List<String> words=new ArrayList<>();

        for (int i=0;i<count;i++){
            if(!words.isEmpty()){
                words.add(sc.next());
            }

        }

    }
}
