package BaekJoon;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Q18258 {
    private static Scanner sc=new Scanner(System.in);
    private static List<Integer>tempNum=new ArrayList<>();
    private static List<Integer>num=new ArrayList<>();

    public static void main(String[] args){

        int loop=sc.nextInt();
        looper(loop);

    }
    public static void looper(int loop){
        checker(sc.nextLine());
        for (int i=0;i<loop;i++){

        }
    }
    public static void push(String item){
        String[] ogItem=item.split(" ");
        tempNum.add(Integer.parseInt(ogItem[1]));
        num.add(Integer.parseInt(ogItem[1]));
    }
    public static void front(){
        if(tempNum.isEmpty()){
            tempNum.add(-1);
        } else {
            num.add(tempNum.get(0));
        }

    }
    public static void back(){
        if(tempNum.isEmpty()){
            tempNum.add(-1);
        }
        else{
            num.add(tempNum.get(tempNum.size()-1));
        }
    }
    public static void pop(){
        if(num.isEmpty()){
            num.add(-1);
        } else {
            num.
        }
    }
    public static void mySize(){

    }
    public static void myEmpty(){

    }

    public static void checker(String item){
        if (item.equals("front")){

        }else if (item.equals("back")){

        } else if (item.equals("pop")) {

        } else if (item.equals("size")) {

        } else if(item.equals("empty")){

        } else {

        }
    }
}
