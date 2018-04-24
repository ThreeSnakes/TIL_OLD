#8393번 문제#

**합**

**문제**
> n이 주어졌을 때, 1부터 n까지 합을 구하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 n (1 ≤ n ≤ 10,000)이 주어진다.

**출력**
> 1부터 n까지 합을 출력한다.

``` java
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int num = input.nextInt();
        int sum = 0;
        
        for(int Sum_i = 1 ; Sum_i <= num ; Sum_i++) {
            sum += Sum_i;
        }
        System.out.println(sum);
    }
}
```
---
| No      | ID        | Quest.NO | Result         | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|----------------|------------|-------|-----------|-------------|
| 3028248 | select995 | 8393     | SUCCESS!!      | 18468 KB   | 80 MS | Java      | 357 B       |
| 3028244 | select995 | 8393     | COMPILIE ERROR | -          | -     | Java      | 355 B       |

> for문에서 변수 잘못줘서 compil Error 났었다. 코드 확인좀 잘 좀 하자. 
