#10871번 문제#

**X보다 작은 수**

**문제**
> 정수 N개로 이루어진 수열 A와 정수 X가 주어진다. 이 때, A에서 X보다 작은 수를 모두 출력하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 N과 X가 주어진다. (1 ≤ N, X ≤ 10,000) 

> 둘째 줄에 수열 A를 이루는 정수 N개가 주어진다. 주어지는 정수는 모두 1보다 크거나 같고, 10,000보다 작거나 같은 정수이다.

**출력**
> X보다 작은 수를 입력받은 순서대로 공백으로 구분해 출력한다. X보다 작은 수는 적어도 하나 존재한다.

``` java
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int max = input.nextInt();
        int num = input.nextInt();
        
        int[] bucket;
        bucket = new int[max];
        
        for(int input_i = 0; input_i < max ; input_i++) {
            bucket[input_i] = input.nextInt();
        }
        
        for(int compare_i = 0; compare_i < max ; compare_i++) {
            if(bucket[compare_i] < num) {
                System.out.print(bucket[compare_i] + " ");
            }
        }
    }
}
```

| No      | ID        | Quest.NO | Result        | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|--------|-----------|-------------|
| 3051803 | select995 | 10871    | SUCCESS!!     | 27856 KB   | 184 MS | Java      | 631 B       |
| 3051801 | select995 | 10871    | FAIL          | -          | -      | Java      | 632 B       |
| 3051797 | select995 | 10871    | FAIL          | -          | -      | Java      | 568 B       |
| 3051794 | select995 | 10871    | COMPILE ERROR | -          | -      | Java      | 554 B       |



> 컴파일 에러는 자꾸 배열 선언하는데서... 배열 선언좀 잘 하자... 틀릴데도 없는데구먼.. 틀렸습니다는 문제를 잘못 일었다 작거나 같은 수인줄 알고 계속 돌렸는데.. 문제 잘읽자.
