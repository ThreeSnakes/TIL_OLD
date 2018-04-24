#2441번 문제#

**별찍기 - 4**

**문제**
> 첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

**입력**
> 첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

> 하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.

**출력**
> 첫째 줄에 N (1<=N<=100)이 주어진다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        
        for(int Line_i = 1 ; Line_i <= num ; Line_i++) {
            for(int Space_i = 1 ; Space_i < Line_i  ; Space_i++) {
                System.out.print(" ");
            }
            for(int Star_i = 0; Star_i <= num - Line_i ; Star_i++) {
                System.out.print("*");
            }
            System.out.println("");
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 3024330 | select995 | 2441     | SUCCESS!! | 19032 KB   | 136 MS | Java      | 553 B       |

> 생각좀 하니깐 쉽게 풀린다. 
