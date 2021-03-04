# Scanner함수 next()와 nextLine() 차이점
---

Java에서 입력을 받을 때 사용하는 `Scanner`에서 `next()`와 `nextLine()` 둘다 String을 return 한다.
같은 듯 하면서 다른데 이 둘의 차이점은 다음과 같다.

> `next()`를 할 경우 입력받은 문자 혹은 문자열에서 공백을 기준으로 입력을 받는다.

> 결국 `3 ABC` 를 입력했을 경우 이를 `System.out.pirntln()` 할 경우 아래처럼 출력한다.
```
3
ABC
```
> `nextLine()`은 문자 또는 한 라인 전체를 입력 받는다.

> 위와 같이 `3 ABC`를 입력 할 경우 `System.out.pritln()` 할 경우 아래처럼 출력한다.
```
3 ABC
```


