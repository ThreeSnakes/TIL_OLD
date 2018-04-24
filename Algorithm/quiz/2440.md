#2440번 문제#

**별찍기 - 3**

**문제**
> 첫째 줄에는 별 N개, 둘째 줄에는 별 N-1개, ..., N번째 줄에는 별 1개를 찍는 문제

**입력**
> 첫째 줄에 N (1<=N<=100)이 주어진다.

**출력**
> 첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.

``` java
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        
        int star = num;
        
        for(int Line_i = 1 ; Line_i <= num ; Line_i++) {
            for(int Star_i = star ; Star_i >= 1; Star_i--) {
                System.out.print("*");
            }
            star--;
            System.out.println("");
        }
    }
}
```

| No      | ID        | Quest.NO | Result        | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|--------|-----------|-------------|
| 3020490 | select995 | 2440     | SUCCESS!!     | 18804 KB   | 112 MS | Java      | 477 B       |
| 3020484 | select995 | 2440     | FAIL          | -          | -      | Java      | 477 B       |
| 3020472 | select995 | 2440     | COMPILE ERROR | -          | -      | Java      | 440 B       |


> 마찬가지로 쉬운문제인데.. 확인없이 막 돌려보니 에러가 난다. 돌려보기전에 생각 한번 하고 하자.
