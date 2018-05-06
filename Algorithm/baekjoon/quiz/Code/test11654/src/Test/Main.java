package Test;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        char character;
        character = input.next().charAt(0);

        System.out.println(Integer.valueOf(character));
    }
}
