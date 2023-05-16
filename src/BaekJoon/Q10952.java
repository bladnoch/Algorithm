package BaekJoon;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Q10952 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int[] temp=new int[2];
        List<Integer> total=new ArrayList<>();
        int count=0;
        boolean rotate=true;

        while(true){
            if (rotate){
                temp[0]=sc.nextInt();
//                System.out.println("if "+temp[0]);
                rotate=false;
            }
            else{
                temp[1]=sc.nextInt();
//                System.out.println("else "+temp[1]);
                if(!rotate){
                    if (temp[0]+temp[1]==0){
                        break;
                    }
                    else{
                        total.add(temp[0]+temp[1]);
                        rotate=true;
                        count++;
                    }
                }
            }

        }
        for (int i=0;i<count;i++){
            System.out.println(total.get(i));
        }

    }
}
