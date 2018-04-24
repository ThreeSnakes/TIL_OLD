package Test;

import java.util.Scanner;

/**
 * Created by selec on 2016-10-07.
 */
public class Main {
    public static final int ASCII_NUMBER = 48;
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int testCase = input.nextInt();

        input.nextLine();

        for(int k = 0 ; k < testCase; k++) {
            String line = input.nextLine();
            int number = line.charAt(0) - ASCII_NUMBER;

            if(line.length() > 2) {
                for (int i = 2; i < line.length(); i++) {
                    for (int j = 0; j < number; j++) {
                        System.out.print(line.charAt(i));
                    }
                }
            }
            if(k != testCase-1) {
                System.out.println();
            }
        }
    }
}
