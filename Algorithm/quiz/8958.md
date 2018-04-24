#8958번 문제#

**OX퀴즈**

**문제**
> "OOXXOXXOOO"와 같은 OX퀴즈의 결과가 있다. O는 문제를 맞은 것이고, X는 문제를 틀린 것이다. 문제를 맞은 경우 그 문제의 점수는 그 문제까지 연속된 O의 개수가 된다. 예를 들어, 10번 문제의 점수는 3이 된다.

> "OOXXOXXOOO"의 점수는 1+2+0+0+1+0+0+1+2+3 = 10점이다.

> OX퀴즈의 결과가 주어졌을 때, 점수를 구하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 길이가 0보다 크고 80보다 작은 문자열이 주어진다. 문자열은 O와 X만으로 이루어져 있다.

**출력**
> 각 테스트 케이스마다 점수를 출력한다.

``` java
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int number;
        int maxLength = 80;
        String line = null;

        number = input.nextInt();

        char[][] bucket = new char[number][maxLength];

        for(int i = 0 ; i <= number ; i++) {
            line = input.nextLine();
            for(int j = 0; j < line.length() ; j++) {
                bucket[i-1][j] = line.charAt(j);
            }
        }

//        for(int a = 0 ; a < number ; a++) {
//            for(int b = 0 ; b < 80 ; b++) {
//                System.out.print("[" + bucket[a][b] + "]");
//            }
//            System.out.println();
//        }

        int count = 0;
        int sum = 0;

        for(int i = 0 ; i < number ; i++) {
            for(int j = 0 ; j < maxLength ; j++ ) {
                if(bucket[i][j] == 'O') {
                    if(count == 0) {
                        count = 1;
                    } else {
                        count += 1;
                    }
                    sum = sum + count;
                } else if(bucket[i][j] == 'X') {
                    count = 0;
                } else {
                    continue;
                }
            }
            System.out.println(sum);
            count = 0;
            sum = 0;
        }
    }
}

```

| No      | ID        | Quest.NO | Result    | Memory Use | Time   | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|--------|-----------|-------------|
| 4434593 | select995 | 8958     | SUCCESS!! | 18204 KB   | 172 MS | Java      | 1439 B      |


> 어렵지 않았으나.. 뭔가 찜찜하다.
> 입력값을 Scanner로 받았는데 for문으로 입력 갯수만큼 돌리고 nextLine()으로 String을 읽었다.
> 근데 코드에서 보면 알수 있다시피 for문을 한번 더돌리고 배열에 넣을때는 -1을 해준다음에 넣어 줬다. 
> 중간에 디버깅 해보면 첫번째 nextLine()에서 아무 값도 못 읽어 오고 있다. 흠...
> 약간 찜찜한데 돌아가긴 하는데....
