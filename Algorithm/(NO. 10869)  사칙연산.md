#10869번 문제#

사칙연산
두 자연수 A와 B가 주어진다. 이 때, A+B, A-B, A*B, A/B(몫), A%B(나머지)를 출력하는 프로그램을 작성하시오. 

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int num1 = input.nextInt();
        int num2 = input.nextInt();

        System.out.println(num1 + num2);
        System.out.println(num1 - num2);
        System.out.println(num1 * num2);
        System.out.println(num1 / num2);
        System.out.println(num1 % num2);
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|-------|-----------|-------------|
| 2956466 | select995 | 10869    | SUCCESS!! | 18488 KB   | 80 MS | Java      | 441 B       |
