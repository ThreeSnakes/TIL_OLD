#1924번 문제#

**2007년**

**문제**
> 오늘은 2007년 1월 1일 월요일이다. 그렇다면 2007년 x월 y일은 무슨 요일일까? 이를 알아내는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 빈 칸을 사이에 두고 x(1≤x≤12)와 y(1≤y≤31)이 주어진다. 참고로 2007년에는 1, 3, 5, 7, 8, 10, 12월은 31일까지, 4, 6, 9, 11월은 30일까지, 2월은 28일까지 있다.

**출력**
> 첫째 줄에 x월 y일이 무슨 요일인지에 따라 SUN, MON, TUE, WED, THU, FRI, SAT중 하나를 출력한다.

``` java
import java.util.Scanner;

public class Main{
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        int[] Month = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
        int month = input.nextInt();
        int day = input.nextInt();
        
        int Day_sum = 0;
        
        if(month > 1) {
            for(int Month_i = 0; Month_i < month-1 ; Month_i++) {
                Day_sum += Month[Month_i];
            }
        } else {
          
        }
        Day_sum += day;
 
        if(Day_sum % 7 == 1) {
            System.out.println("MON");
        } else if(Day_sum % 7 == 2) {
            System.out.println("TUE");
        } else if(Day_sum % 7 == 3) {
            System.out.println("WED");
        } else if(Day_sum % 7 == 4) {
            System.out.println("THU");
        } else if(Day_sum % 7 == 5) {
            System.out.println("FRI");
        } else if(Day_sum % 7 == 6) {
            System.out.println("SAT");
        } else {
            System.out.println("SUN");
        }
    }
}
```
---
| No      | ID        | Quest.NO | Result        | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|---------------|------------|-------|-----------|-------------|
| 3036276 | select995 | 1924     | SUCCESS       | 18488 KB   | 76 MS | Java      | 1112 B      |
| 3036269 | select995 | 1924     | FAIL          | -          | -     | Java      | 1110 B      |
| 3036263 | select995 | 1924     | FAIL          | -          | -     | Java      | 1110 B      |
| 3036107 | select995 | 1924     | FAIL          | -          | -     | Java      | 1111 B      |
| 3036101 | select995 | 1924     | FAIL          | -          | -     | Java      | 1033 B      |
| 3036091 | select995 | 1924     | FAIL          | -          | -     | Java      | 1032 B      |
| 3036088 | select995 | 1924     | COMPILE ERROR | -          | -     | Java      | 1032 B      |
| 3036084 | select995 | 1924     | COMPILE ERROR | -          | -     | Java      | 1026 B      |
| 3036074 | select995 | 1924     | COMPILE ERROR | -          | -     | Java      | 1028 B      |

> 컴파일 에러야.. 오타 나고 변수이름 잘못 쳐서 날수 있다고 치자.. 근데 틀렸습니다는 그냥 아예 알고리즘 자체가 틀렸었다. 하나 고치고 돌리고 하나고치고 돌리고 보다는 전체를 다시 확인한후 수정 하는 버릇을 길러야 되겠다.
