#2439번 문제#

**별찍기 - 2**

**문제**
> 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제

> 하지만, 오른쪽을 기준으로 정렬한 별 (예제 참고)을 출력하시오.

**입력**
> 첫째 줄에 N (1<=N<=100)이 주어진다.

**출력**
> 첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int num = input.nextInt();
        
        for(int Line_i = 1; Line_i <= num; Line_i++) {
            for(int Star_i = 1; Star_i <= num; Star_i++) {
                if(Star_i <= num-Line_i) {
                    System.out.print(" ");
                } else {
                    System.out.print("*");
                }
            }
            System.out.println("");
        }
    }
}
```

| No      | ID        | Quest.NO | Result        | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|--------|-----------|-------------|
| 2999137 | select995 | 2439     | SUCCESS!!     | 19032 KB   | 116 MS | Java      | 565 B       |
| 2999104 | select995 | 2439     | FAIL          | -          | -      | Java      | 672 B       |
| 2999096 | select995 | 2439     | COMPILE ERROR | -          | -      | Java      | 667 B       |
| 2999087 | select995 | 2439     | COMPILE ERROR | -          | -      | Java      | 667 B       |
| 2999077 | select995 | 2439     | COMPILE ERROR | -          | -      | Java      | 652 B       |

> 상당히 쉬운 문제인데... 어렵게 생각 했다. 비비 꼬아서 생각하지 말고 단순히 생각 하자. 그리고 오타 좀 조심하자. 오타로 에러가 많이 난다. 

