package ForJava;
/**
 * BubbleSort.java
 * bubble sort, sort out biggest to smallest
 * @since 2023-4-12
 * @author Dounguk kim
 */

import java.util.InputMismatchException;
import java.util.Scanner;

public class BubbleSort {

    final static int ARRLEN=8;
    public static void bubbleSort(int[] arr){
        bubbleSort(arr, ARRLEN-1);
    }
    public static void bubbleSort(int[] arr, int lastArr){
        int temp=0;
        if (lastArr>0){
            for(int i=1;i<=lastArr;i++){
                if(arr[i-1]>arr[i]){
                    temp=arr[i-1];
                    arr[i-1]=arr[i];
                    arr[i]=temp;
                }
            }
            bubbleSort(arr,lastArr-1);
        }

    }
    public static void printArr(int[] arr){
        for (int i=0;i<ARRLEN;i++){
            System.out.print(arr[i]+" ");
        }
    }
    public static int[] makeArr(){
        int[] arr=new int[ARRLEN];
        Scanner sc=new Scanner(System.in);

        for (int i= 0;i<ARRLEN;i++){
            try{
                System.out.print("정수 입력 : ");
                arr[i]=sc.nextInt();
            } catch (InputMismatchException e){
                System.out.println("Input value is not Integer, Please try it again!");
                sc.nextLine();
                i--;
            }
        }
        return arr;
    }

    public static void main(String[] args){
        int[] arr=makeArr();
        bubbleSort(arr);
        printArr(arr);

    }
}
