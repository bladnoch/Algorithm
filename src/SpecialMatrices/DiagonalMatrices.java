package SpecialMatrices;

public class DiagonalMatrices {
    final static int SIZE=4;
    public static void main(String[] args){
        int[][] diagnal=new int[SIZE][SIZE];

        for (int i=0;i<SIZE;i++){
            for(int j=0;j<SIZE;j++){
                if(i==j){
                    diagnal[i][j]=1;
                }
                else{
                    diagnal[i][j]=0;
                }
                System.out.print("  "+diagnal[i][j]);
            }
            System.out.println(" ");
        }
    }
}
