#2742번 문제#

**기찍 N**

**문제**
> 자연수 N이 주어졌을 때, N부터 1까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.

**출력**
>첫째 줄부터 N번째 줄 까지 차례대로 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int num1 = input.nextInt();
        
        for(int i = num1; i >= 1; i--) {
            System.out.println(i);
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 2961537 | select995 | 2742     | SUCCESS!! | 32644 KB   | 592 MS | Java      | 299 B       |
