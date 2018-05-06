package teset;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String message = input.nextLine();

        message = message.trim();

        int cnt = 0;
        char[] bucket = new char[1000000];
        boolean checkWordFlag = false;
        for(int i = 0; i < message.length() ; i++) {
            bucket[i] = message.charAt(i);
        }

        for(int i = 0; i < message.length() ; i++) {
            if(bucket[i] == ' ') {
                if(bucket[i+1] != ' ') {
                    cnt++;
                }
            } else {
                if(!checkWordFlag) {
                    if (('a' <= bucket[i] && bucket[i] <= 'z') || ('A' <= bucket[i] && bucket[i] <= 'Z')) {
                        checkWordFlag = true;
                    }
                }
            }
        }

        if(checkWordFlag) {
            System.out.print(cnt+1);
        } else {
            System.out.print(cnt);
        }

    }
}
