package Test;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int number;
        int maxLength = 80;
        String line = null;

        number = input.nextInt();

        char[][] bucket = new char[number][maxLength];

        for(int i = 0 ; i <= number ; i++) {
            line = input.nextLine();
            for(int j = 0; j < line.length() ; j++) {
                bucket[i-1][j] = line.charAt(j);
            }
        }

//        for(int a = 0 ; a < number ; a++) {
//            for(int b = 0 ; b < 80 ; b++) {
//                System.out.print("[" + bucket[a][b] + "]");
//            }
//            System.out.println();
//        }

        int count = 0;
        int sum = 0;

        for(int i = 0 ; i < number ; i++) {
            for(int j = 0 ; j < maxLength ; j++ ) {
                if(bucket[i][j] == 'O') {
                    if(count == 0) {
                        count = 1;
                    } else {
                        count += 1;
                    }
                    sum = sum + count;
                } else if(bucket[i][j] == 'X') {
                    count = 0;
                } else {
                    continue;
                }
            }
            System.out.println(sum);
            count = 0;
            sum = 0;
        }
    }
}
