#1152번 문제#

**단어의 개수**

**문제**
> 영어 대소문자와 띄어쓰기만으로 이루어진 문장이 주어진다. 이 문장에는 몇 개의 단어가 있을까? 이를 구하는 프로그램을 작성하시오. 단, 단어는 띄어쓰기 하나로 구분된다고 생각한다.

**입력**
> 첫 줄에 영어 대소문자와 띄어쓰기로 이루어진 문장이 주어진다. 이 문장의 길이는 1,000,000을 넘지 않는다.

**출력**
> 첫째 줄에 단어의 개수를 출력한다.

''' java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String message = input.nextLine();

        message = message.trim();

        int cnt = 0;
        char[] bucket = new char[1000000];
        boolean checkWordFlag = false;
        for(int i = 0; i < message.length() ; i++) {
            bucket[i] = message.charAt(i);
        }

        for(int i = 0; i < message.length() ; i++) {
            if(bucket[i] == ' ') {
                if(bucket[i+1] != ' ') {
                    cnt++;
                }
            } else {
                if(!checkWordFlag) {
                    if (('a' <= bucket[i] && bucket[i] <= 'z') || ('A' <= bucket[i] && bucket[i] <= 'Z')) {
                        checkWordFlag = true;
                    }
                }
            }
        }

        if(checkWordFlag) {
            System.out.print(cnt+1);
        } else {
            System.out.print(cnt);
        }

    }
}
'''

| No        | ID        | Quest.NO  | Result  | Memory Use | Time   | lanaguage | Code Length |
|-----------|-----------|-----------|---------|------------|--------|-----------|-------------|
| 4422711   | select995 | 1152      | SUCCESS | 34340 KB   | 556 MS | Java      | 1058 B      |
| 4422706   | select995 | 1152      | FAIL    |            |        | Java      | 1114 B      |
| 4422648   | select995 | 1152      | FAIL    |            |        | Java      | 990 B       |
| 4422603   | select995 | 1152      | FAIL    |            |        | Java      | 753 B       |
| 4422567   | select995 | 1152      | FAIL    |            |        | Java      | 674 B       |
| 4422090   | select995 | 1152      | FAIL    |            |        | Java      | 841 B       |
| 4422060   | select995 | 1152      | FAIL    |            |        | Java      | 850 B       |
| 4422045   | select995 | 1152      | FAIL    |            |        | Java      | 813 B       |
| 4421953   | select995 | 1152      | FAIL    |            |        | Java      | 346 B       |
| 4421814   | select995 | 1152      | FAIL    |            |        | Java      | 593 B       |
| 4421770   | select995 | 1152      | FAIL    |            |        | Java      | 301 B       |


> 하 쉬운 문제였는데... 왜이렇게 틀렸는지 원.. 일단 많이 틀린 원인은 조건에 대해서 까다롭게 생각 하지 않았다. 
> space가 연속으로 올꺼라 생각 못했고 또한 처음에 올수 있다고 생각 못했다. 그러다 보니 계속 맞는 소스코드 계속 돌려보는 경우가 생겼다.
> 또 공백이 오고나서 바로 한단어만 올 수 있는 경우 처리를 안했었다. 그래서 중간에 flag를 둬서 한단어만 있을 경우를 검사했다.
> 하여튼 문제 자체는 되게 쉽다라고 생각했는데 푸는 시간도 오래 걸렸고.. 많이 틀렸다..
> 생각좀 하면서 살자.
