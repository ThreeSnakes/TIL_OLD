#2438번 문제#

**별찍기 - 1**

**문제**
> 첫째 줄에는 별 1개, 둘째 줄에는 별 2개, N번째 줄에는 별 N개를 찍는 문제.

**입력**
> 첫째 줄에 N (1<=N<=100)이 주어진다.

**출력**
> 첫째 줄부터 N번째 줄 까지 차례대로 별을 출력한다.

```
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();
        
        for(int Line_i = 1; Line_i <= num; Line_i++ ) {
            for(int Star_i = 1; Star_i <= Line_i; Star_i++ ) {
                System.out.print("*");
            }
            System.out.println("");
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 2995071 | select995 | 2438     | SUCCESS!! | 18816 KB   | 108 MS | Java      | 423 B       |