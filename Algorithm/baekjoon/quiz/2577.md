#2577번 문제#

**숫자의 개수**

**문제**
> 세 개의 자연수 A, B, C가 주어질 때 A×B×C를 계산한 결과에 0부터 9까지 각각의 숫자가 몇 번씩 쓰였는지를 구하는 프로그램을 작성하시오.

> 예를 들어 A = 150, B = 266, C = 427 이라면 

> A × B × C = 150 × 266 × 427 = 17037300 이 되고, 

> 계산한 결과 17037300 에는 0이 3번, 1이 1번, 3이 2번, 7이 2번 쓰였다.

**입력**
> 첫째 줄에 A, 둘째 줄에 B, 셋째 줄에 C가 주어진다. A, B, C는 모두 100보다 같거나 크고, 1,000보다 작은 자연수이다.

**출력**
> 첫째 줄에는 A×B×C의 결과에 0 이 몇 번 쓰였는지 출력한다. 마찬가지로 둘째 줄부터 열 번째 줄까지 A×B×C의 결과에 1부터 9까지의 숫자가 각각 몇 번 쓰였는지 차례로 한 줄에 하나씩 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        final int arrayMaxValue = 10;

        int A, B, C, sum;

        int maxValue = 999* 999 * 999;

        A = input.nextInt();
        B = input.nextInt();
        C = input.nextInt();

        if(!(100 <= A && A < 1000)) {
            return;
        }
        if(!(100 <= B && B < 1000)) {
            return;
        }
        if(!(100 <= C && C < 1000)) {
            return;
        }

        sum = A * B * C;

        int[] bucket = new int[arrayMaxValue];

        for(int i = 0; i < String.valueOf(sum).length() ; i++) {
            if(String.valueOf(sum).charAt(i) == '0') {
                bucket[0] += 1;
            } else if(String.valueOf(sum).charAt(i) == '1') {
                bucket[1] += 1;
            } else if(String.valueOf(sum).charAt(i) == '2') {
                bucket[2] += 1;
            } else if(String.valueOf(sum).charAt(i) == '3') {
                bucket[3] += 1;
            } else if(String.valueOf(sum).charAt(i) == '4') {
                bucket[4] += 1;
            } else if(String.valueOf(sum).charAt(i) == '5') {
                bucket[5] += 1;
            } else if(String.valueOf(sum).charAt(i) == '6') {
                bucket[6] += 1;
            } else if(String.valueOf(sum).charAt(i) == '7') {
                bucket[7] += 1;
            } else if(String.valueOf(sum).charAt(i) == '8') {
                bucket[8] += 1;
            } else if(String.valueOf(sum).charAt(i) == '9') {
                bucket[9] += 1;
            }
        }

        for(int j = 0; j < arrayMaxValue ; j++) {
            System.out.println(bucket[j]);
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 4434257 | select995 | 2577     | SUCCESS!! | 17828 KB   | 148 MS | Java      | 1805 B      |


> 쉬운문제..
> 풀고나니깐 초등학생 올림피아드 문제네...
