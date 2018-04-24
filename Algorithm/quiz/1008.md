
#1008번 문제#

**A/B**

**문제**
> A/B를 계산하시오.

**입력**
> 첫째 줄에 A와 B가 주어진다. (0 < A,B < 10)

**출력**
> 첫째 줄에 A/B를 소수점 9자리 이상 출력한다. 절대/상대 오차는 10-9 까지 허용한다.


``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        double num1 = input.nextInt();
        double num2 = input.nextInt();

        System.out.println( num1 / num2 );      
    }
}

```

| No      | ID        | Quest.NO | Result  | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|---------|------------|-------|-----------|-------------|
| 2961474 | select995 | 1008     | SUCCESS | 18544 KB   | 76 MS | Java      | 287 B       |