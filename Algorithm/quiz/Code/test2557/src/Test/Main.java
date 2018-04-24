package Test;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        final int arrayMaxValue = 10;

        int A, B, C, sum;

        int maxValue = 999* 999 * 999;

        A = input.nextInt();
        B = input.nextInt();
        C = input.nextInt();

        if(!(100 <= A && A < 1000)) {
            return;
        }
        if(!(100 <= B && B < 1000)) {
            return;
        }
        if(!(100 <= C && C < 1000)) {
            return;
        }

        sum = A * B * C;

        int[] bucket = new int[arrayMaxValue];

        for(int i = 0; i < String.valueOf(sum).length() ; i++) {
            if(String.valueOf(sum).charAt(i) == '0') {
                bucket[0] += 1;
            } else if(String.valueOf(sum).charAt(i) == '1') {
                bucket[1] += 1;
            } else if(String.valueOf(sum).charAt(i) == '2') {
                bucket[2] += 1;
            } else if(String.valueOf(sum).charAt(i) == '3') {
                bucket[3] += 1;
            } else if(String.valueOf(sum).charAt(i) == '4') {
                bucket[4] += 1;
            } else if(String.valueOf(sum).charAt(i) == '5') {
                bucket[5] += 1;
            } else if(String.valueOf(sum).charAt(i) == '6') {
                bucket[6] += 1;
            } else if(String.valueOf(sum).charAt(i) == '7') {
                bucket[7] += 1;
            } else if(String.valueOf(sum).charAt(i) == '8') {
                bucket[8] += 1;
            } else if(String.valueOf(sum).charAt(i) == '9') {
                bucket[9] += 1;
            }
        }

        for(int j = 0; j < arrayMaxValue ; j++) {
            System.out.println(bucket[j]);
        }
    }
}
