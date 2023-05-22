package BaekJoon;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * 오름차순 정렬
 * @author Dounguk Kim
 * @since 5/22/2023
 * @version v0.0.1
 */
public class Q2751 {
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        int loop=sc.nextInt();
        System.out.println(loop);
        int[] number=new int[loop];
        int temp=0;

        for (int i=0;i<loop;i++){
            number[i]=sc.nextInt();
        }

        for(int i=1; i<loop;i++){
            temp=number[i];   //4
            int j;
            for (j=i-1;j>=0 && temp<number[j];j--){ //j=3; (3,2,1,0) && 4<num[3]; big-oh(3-2-1-0)
                number[j+1]=number[j];
            }
            number[j+1]=temp;
        }

        for (int i=0;i<loop;i++){
            System.out.print(number[i]+"  ");
        }

    }
}
