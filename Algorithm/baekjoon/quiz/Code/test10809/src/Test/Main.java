package Test;

import java.util.Scanner;

/**
 * Created by selec on 2016-10-07.
 */
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String charater = input.next();

        int[] bucket = new int[26];

        if(charater.length() > 100) {
            return;
        }

        for(int i = 0; i < bucket.length ; i++) {
            bucket[i] = -1;
        }

        for(int j = 0; j < charater.length() ; j++) {
            for(int k = 'a' ; k <= 'z' ; k++) {
                if(charater.charAt(j) == k) {
                    if(bucket[k-'a'] == -1) {
                        bucket[k-'a'] = j;
                    }
                }
            }
        }

        for(int l = 0 ; l < bucket.length ; l++) {
            System.out.print(bucket[l]);
            if(l != bucket.length -1) {
                System.out.print(" ");
            }
        }

    }
}
