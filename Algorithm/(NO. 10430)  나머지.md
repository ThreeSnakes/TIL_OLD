#10430번 문제#

나머지

(A+B)%C는 (A%C + B%C)%C 와 같을까?

(A×B)%C는 (A%C × B%C)%C 와 같을까?

세 수 A, B, C가 주어졌을 때, 위의 네가지 값을 구하는 프로그램을 작성하시오.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int num3 = input.nextInt();

        System.out.println( ( num1 + num2 ) % num3 );
        System.out.println( ( ( num1 % num3 ) + ( num2 % num3 ) ) % num3 );
        System.out.println( ( num1 * num2 ) % num3 );
        System.out.println( ( ( num1 % num3) * ( num2 % num3 ) ) % num3 );            
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|-------|-----------|-------------|
| 2956492 | select995 | 10430    | SUCCESS!! | 18496 KB   | 84 MS | Java      | 543 B       |
