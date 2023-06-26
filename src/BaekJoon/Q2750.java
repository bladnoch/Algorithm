package BaekJoon;

import java.util.ArrayList;
import java.util.Scanner;

/**
 * @category Q2750: working
 * @since 6/26/2023
 * @author doungukkim
 * @version V0.0.1
 */
public class Q2750 {
    private static ArrayList<Integer> numList=new ArrayList<>();
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);

        int count= sc.nextInt();
        int[] nums=new int[count];

        for (int i=0;i<count;i++){
            nums[i]=sc.nextInt();
        }
        quickSort(nums,0,count-1);
        partition(nums,0,count-1);
        printArray(nums);

    }
    public static void quickSort(int[] array, int low, int high) {
        if (low < high) {
            int pivot = partition(array, low, high);

            quickSort(array, low, pivot - 1);
            quickSort(array, pivot + 1, high);
        }
    }

    public static int partition(int[] array, int low, int high) {
        int pivot = array[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                i++;

                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        return i + 1;
    }

    public static void printArray(int[] array) {

        for(int i=0;i< array.length;i++){
            if(numList.isEmpty()){
                numList.add(array[i]);
            } else if (numList.get(numList.size()-1)==array[i]) {
                continue;
            } else{
                numList.add(array[i]);
            }
        }
        for (int i = 0; i < numList.size(); i++) {
            System.out.print(numList.get(i)+"\n");
        }
    }
}
