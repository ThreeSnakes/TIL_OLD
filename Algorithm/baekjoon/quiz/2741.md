#2741번 문제#

**N찍기**

**문제**
> 자연수 N이 주어졌을 때, 1부터 N까지 한 줄에 하나씩 출력하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 100,000보다 작거나 같은 자연수 N이 주어진다.

**출력**
>첫째 줄부터 N번째 줄 까지 차례대로 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int num = input.nextInt();
        
        for(int i = 1; i <= num; i++) {
            System.out.println(i);
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 2961501 | select995 | 2741     | SUCCESS!! | 32648 KB   | 552 MS | Java      | 297 B       |
