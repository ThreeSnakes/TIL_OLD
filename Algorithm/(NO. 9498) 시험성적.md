#9498번 문제#

**시험성적**

**문제**
> 시험 점수를 입력받아 90 ~ 100점은 A, 80 ~ 89점은 B, 70 ~ 79점은 C, 60 ~ 69점은 D, 나머지 점수는 F를 출력하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 시험 점수가 주어진다. 시험 점수는 0보다 크거나 같고, 100보다 작거나 같은 자연수이다.

**출력**
> 시험 성적을 출력한다.

``` java
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int judge = input.nextInt();
        
        if(judge >= 90 ) {
            System.out.println("A");
        } else if( judge >= 80 && judge < 90) {
            System.out.println("B");
        } else if( judge >= 70 && judge < 80) {
            System.out.println("C");
        } else if( judge >= 60 && judge < 70 ) {
            System.out.println("D");  
        } else {
            System.out.println("F");
        }
    }
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|-------|-----------|-------------|
| 2969973 | select995 | 9498     | SUCCESS!! | 18496 KB   | 72 MS | Java      | 607 B       |
