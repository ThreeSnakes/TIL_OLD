# Scanner함수에서 nextLine() 쓸 때 주의 할점
---

[(NO. 8958) OX퀴즈]() 문제를 풀때 nextLine()을 쓰면서 찜찜한점이 있다고 말했었다.

위에 들어가서 코드를 보면 알 수 있는데 `nextLine()`을 한번 더 돌려야지 내가 원하는 입력값을 받는 것을 볼 수 있는데 검색해보니 이유를 찾았다.

``` java
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
```
위에 코드를 보자.

코드를 보면 `Scanner`를 선언하고 `nextInt()`를 쓰고 그 다음에 `nextLine()`을 쓰고 있다.

여기서 `nextInt()`가 문제의 원인이다. 

`number` 변수에 숫자를 입력하고 `Enter`를 누르면 `\r\n`이라는 개행문자가 남아 있게 된다.

그다음에 `nextLine()`을 실행하는데 `nextLine()`이 이 개행문자를 읽어 버려서 결국 아무 값도 안읽어 버리는 현상이

발생 되는 것이다. 결국 이 개행문자를 한 번 읽어버리면 해결 되는 형상인데 아래 코드처럼 nextInt()가 쓰이고 나서 

`nextLine()`을 한번더 수행시켜서 개행문자를 읽어 버리자.

아래 코드처럼 하면 된다.

``` java
  Scanner input = new Scanner(System.in);

        int number;
        int maxLength = 80;
        String line = null;

        number = input.nextInt();

        char[][] bucket = new char[number][maxLength];

        input.nextLine();

        for(int i = 0 ; i < number ; i++) {
            line = input.nextLine();
            for(int j = 0; j < line.length() ; j++) {
                bucket[i-1][j] = line.charAt(j);
            }
        }
```
