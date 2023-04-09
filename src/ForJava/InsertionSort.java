package ForJava;

/*
        InsertionSort.java
        Study of insertion sort (복사본)
        3-31-2023
        Dounguk Kim
 */

//    타겟 데이터는 4(인덱스5번). 변수에 타겟 데이터를 저장합니다.
//    내부루프의 최대 반복횟수는 외부루프의 반복횟수와 타겟 데이터의 크기에 따라 바뀝니다.
//    타겟 테이터가 0보다 크거나 같고 타켓 데이터가 타겟 데이터의 전 인덱스의 값보나 작으면 내부 루프가 반복됩니다.
//    이번 경우 타겟 데이터의 전 인덱스의 값은 9다(인덱스4번).
//    내부 루프가 시작됩니다. 내부 루프가 값 9를 인덱스5번에 저장합니다.
//    내부 루프가 돕니다. 이번엔 4와 6을 비교합니다. 루프가 6을 인덱스4번에 저장합니다.
//    내부 루프가 비교를 합니다. 이번엔 4와 3을 비교합니다. 내부 루프가 멈춥니다.
//    루프를 나와 4를 3이 있던 인덱스 보다 하나 뒤에 있는 인덱스에 저장합니다. 타겟 데이터를 위한 반복이 끝났습니다.
//    타겟 데이터의 반복 종료 후: [0, 1, 3, 6, 9, 4, 7, 5, 2, 8]



public class InsertionSort {
    public static int[] insertion(int[] num){
//        {6,1,3,0,9,4,7,5,2,8}

        for (int i = 1; i < num.length; i++){ //i=5
            int t=num[i];   //4
            int j;

            for (j=i-1;j>=0 && t<num[j];j--){ //j=3; (3,2,1,0) && 4<num[3]; big-oh(3-2-1-0)
                num[j+1]=num[j];
            }
            num[j+1]=t;
        }
        return num;
    }


    public static void printArray(int[] num){

        for (int i=0;i<num.length;i++){
            System.out.print(num[i]+" ");
        }
        System.out.println(" ");
    }

    public static void main(String[] args){
        System.out.println("Study of insertion sort");
        int[] num={6,1,3,0,9,4,7,5,2,8};

        printArray(num);
        insertion(num);
        System.out.println(" ");
        printArray(num);

    }



}
