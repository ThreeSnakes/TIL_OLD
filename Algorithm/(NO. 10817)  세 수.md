#10817번 문제#

**세 수**

**문제**
> 세 정수 A, B, C가 주어진다. 이 때, 두 번째로 큰 정수를 출력하는 프로그램을 작성하시오. 

**입력**
> 첫째 줄에 세 정수 A, B, C가 공백으로 구분되어 주어진다. (1 ≤ A, B, C ≤ 100)

**출력**
> 두 번째로 큰 정수를 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int[] Num = { 0, 0, 0 };
        int tmp;
        Num[0] = input.nextInt();
        Num[1] = input.nextInt();
        Num[2] = input.nextInt();
        
        if(Num[0] < Num[1]) {
            tmp = Num[0];
            Num[0] = Num[1];
            Num[1] = tmp;
        }
        
        if(Num[0] < Num[2]) {
            tmp = Num[0];
            Num[0] = Num[2];
            Num[2] = tmp;
        }
        
        if(Num[1] < Num[2]) {
            tmp = Num[1];
            Num[1] = Num[2];
            Num[2] = tmp;
        }
        
        System.out.println(Num[1]);
    }
}
```

| No      | ID        | Quest.NO | Result        | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|-------|-----------|-------------|
| 3047929 | select995 | 10817    | SUCCESS!!     | 18488 KB   | 76 MS | Java      | 795 B       |
| 3047928 | select995 | 10817    | COMPILE ERROR | -          | -     | Java      | 796 B       |
| 3047926 | select995 | 10817    | COMPILE ERROR | -          | -     | Java      | 798 B       |
| 3047923 | select995 | 10817    | COMPILE ERROR | -          | -     | Java      | 794 B       |
| 3047920 | select995 | 10817    | COMPILE ERROR | -          | -     | Java      | 794 B       |


> 컴파일 에러.. 아니 배열선언을 자꾸 잘못하면 어케하냐. 제일 쉬운건데.. 쫌 잘좀하자...
