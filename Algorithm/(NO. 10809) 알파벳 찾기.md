#10809번 문제#

**알파벳 찾기**

**문제**
> 알파벳 소문자로만 이루어진 단어 S가 주어진다. 각각의 알파벳에 대해서, 단어에 포함되어 있는 경우에는 처음 등장하는 위치를, 포함되어 있지 않은 경우에는 -1을 출력하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 단어 S가 주어진다. 단어의 길이는 100을 넘지 않으며, 알파벳 소문자로만 이루어져 있다.

**출력**
> 각각의 알파벳에 대해서, a가 처음 등장하는 위치, b가 처음 등장하는 위치, ... z가 처음 등장하는 위치를 공백으로 구분해서 출력한다.

> 만약, 어떤 알파벳이 단어에 포함되어 있지 않다면 -1을 출력한다. 단어의 첫 번째 글자는 0번째 위치이고, 두 번째 글자는 1번째 위치이다.

``` java
import java.util.Scanner;

/**
 * Created by selec on 2016-10-07.
 */
public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        String charater = input.next();

        int[] bucket = new int[26];

        if(charater.length() > 100) {
            return;
        }

        for(int i = 0; i < bucket.length ; i++) {
            bucket[i] = -1;
        }

        for(int j = 0; j < charater.length() ; j++) {
            for(int k = 'a' ; k <= 'z' ; k++) {
                if(charater.charAt(j) == k) {
                    if(bucket[k-'a'] == -1) {
                        bucket[k-'a'] = j;
                    }
                }
            }
        }

        for(int l = 0 ; l < bucket.length ; l++) {
            System.out.print(bucket[l]);
            if(l != bucket.length -1) {
                System.out.print(" ");
            }
        }

    }
}

```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 4441052 | select995 | 10809    | SUCCESS!! | 17776 KB   | 148 MS | Java      | 966 B       |


> 맨처음에 case로 a~z 까지 다 할려고 했는데 그렇게 하면 코드도 길어지고 멍청한 짓 같아서 위에처럼 바꿨다. 잘 돌아간다.
