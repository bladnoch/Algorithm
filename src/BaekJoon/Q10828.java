package BaekJoon;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

/**
 *  study stack with baekjoon
 *
 */

public class Q10828 {
    private static List<Integer> target=new ArrayList<>();
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int times=sc.nextInt();
        repeat(times, sc);

    }
    public static void repeat(int times, Scanner sc){
        for( int i=1;i<times+1;i++){
            String[] input =sc.nextLine().split(" ");

            if(input[0].equals("push")){
                target.add(Integer.parseInt(input[1]));
            } else if (input[0].equals("pop")) {
                if(target.isEmpty()) {
                    System.out.println(-1);
                } else {
                    System.out.println(target.get(target.size()-1));
                    target.remove(target.size()-1);
                }
            } else if (input[0].equals("size")) {
                System.out.println(target.size());

            } else if (input[0].equals("empty")) {
                System.out.println((target.isEmpty())?1:0);
            } else if (input[0].equals("top")) {
                if(target.isEmpty()){
                    System.out.println(-1);
                }   else
                    System.out.println(target.get(target.size()-1));
            } else{
                i--;
            }
        }
    }
}
