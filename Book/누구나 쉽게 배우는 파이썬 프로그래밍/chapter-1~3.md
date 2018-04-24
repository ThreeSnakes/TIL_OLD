# 누구나 쉽게 배우는 파이썬 프로그래밍
---
그동안 흥미가 있었던 파이썬을 공부해 보기로 하였다.
책은 오래전에 사놨었는데 이제서야 읽어 본다.
조금씩 조금씩 공부하면서 정리해 놓도록 해야 겠다.

**Chapter 1 ~ 3**

*1. python 설치하기.*

[python.org](http://www.python.org)에 들어가면 설치 할 수 있다.
최신 버전( 3.5 Version ) 설치 하였다.

*2. 계산과 변수.*

파이썬 연산자는 일반적인 `JAVA`나 `C` 와 같다고 생각 하면 된다. 다를게 없다.
흠 너무 쉬운 책을 샀나 싶기도 하네..

*3. 변수 사용법.*

`shell`에서 아래와 같이 그냥 입력 하면 된다. 그러면 자동으로 왼쪽 변수에 오른쪽 값이 들어 간다.
``` py
>>> found_coins = 20
>>> found_coins = 10
>>> print(found_coins)
10
```
`JAVA`나 `C`처럼 사용 하면 된다. 한데 `int`나 `String`과 같은 데이터형이 없는 듯하다. 일단 책에서는 따로 나와 있지 않다. 원래 있는데 안나와 있는 것인지 아니면 없는 것인지는 조금 더 조사해봐야 할 듯 하다.

*4. 문자열.*

문자열을 표현 하는 방법은 아래와 같이 3가지 방법이 있다.
``` py
>>> talk_1 = 'do you know korean singer.?'
>>> talk_2 = "do you know korean singer.?"
>>> talk_3 = '''do you know korean singer.?'''
>>> print(talk_1)
do you know korean singer.?
>>> print(talk_2)
do you know korean singer..?
>>> print(talk_3)
do you know korean singer...?
```
위에처럼 문자열을 표현하는 방법에 3가지 방식이 있는데 첫번째(홀 따옴표)와 두번째(겹 따옴표)는 차이가 없다. 하지만 세번째 방법은 조금 다르다. 아래와 같이 입력해보자.
``` py
>>> test = 'He said, "Aren't can't shouldn't wouldn't."'
SyntaxError: invalid syntax
```
위처럼 `SyntaxError`가 발생 하는 것을 볼 수 있다. 이 경우 파이썬이 인식하는 문자열은 `He said, "Aren` 까지 뿐이다. 그 뒤에 다른 글자들이 있다고 기대하지 않으며 있어서도 안되는 것이다.

그렇다면 겹따옴표(")를 사용할 경우 인식하는 곳은 어디까지 일까.?
``` py
>>> test = "He said, "Aren't can't shouldn't wouldn't.""
SyntaxError: invalid syntax
```
마찬가지로 `SyntaxError`가 발생하며 이 경우 파이썬이 인식하는 문자열은 `He said, `까지이다.
이런 문제를 해결책은 멀티라인 문자열을 입력받는 세번째 방법(''')를 사용하는 것이다.
위에서 친 문장을 세번째 방법으로 입력해보자.
``` py
>>> test = '''He said, "Aren't can't shouldn't wouldn't."'''
>>> print(test)
He said, "Aren't can't shouldn't wouldn't."
```
위와 같이 정상적으로 출력되는 것을 볼 수 있다. 이 방법 말고도 `이스케이프 문자`인 `백슬래시(\)`를 사용해도 되나 코드를 읽는데 복잡해지므로 그냥 멀티라인 문자열로 입력 하자.

*5. 문자열에 값 표시하기.*

``` py
값이 하나 일 경우.
>>> my_name = 'NaroQ'
>>> message = 'Hello. my name is %s'
>>> print(message % my_name)
Hello. my name is NaroQ
```
``` py
값이 두개 이상일 경우.
first_name = "chang hyun"
last_name = "Lim"
String = "Hi there, %s %s"
print(String % (first_name, last_name))
```
값이 두개 이상일 경우에는 위와 같이 대체할 값들을 괄호()로 묶어야 하며 값의 순서는 문자열에 사용될 순서를 나타낸다.

*6. 리스트*

``` py
>>> game_list = ['war craft', 'star craft', 'diablo3']
>>> print(game_list)
['war craft', 'star craft', 'diablo3']
```
위와 같이 리스트로 나타낼 때는 대괄호(`[]`)를 사용하면 된다.
`JAVA`나 `C`처럼 특정 위치에 있는 값을 출력한다고 한다면 다음과 같이 사용하면 된다.
``` py
>>> print(game_list[1])
star craft
```
또는 다음과 같이도 사용할 수 있다.
``` py
>>> print(game_list[0:2])
['war craft', 'star craft']
```
이렇게 한다면 리스트의 인덱스 0 부터 인덱스 2까지 값을 출력한다. 하지만 인덱스 2의 값은 포함 되지 않는다.!!! 인덱스의 끝 값을 더 큰수를 넣어도 상관없이 돌아간다. `JAVA`나 `C` 일 경우 `OutOfArray~`이런 Error 발생 할텐데 파이선은 발생하지 않는다. 또한 리스트에 숫자와 문자열을 섞어서 담을 수도 있으며 리스트 안에 리스트를 저장할 수 있다.
만들어진 리스트에 항목을 추가하기 위해서는 `append` 함수를 사용하면 된다.
``` py
>>> game_list.append(1942)
>>> print(game_list)
['war craft', 'star craft', 'diablo3', 1942]
```
만들어진 리스트에서 항목을 삭제하기 위해서는 `del` 명령어를 사용한다.
``` py
>>> del game_list[0]
>>> print(game_list)
['star craft', 'diablo3', 1942]
```
리스트는 리스트끼리 `+` 연산을 수행할 수 있다.

*7. 튜플.*

``` py
>>> coin = ( 10, 50, 100, 500)
>>> print(coin)
(10, 50, 100, 500)
```
튜플은 위와같이 `괄호()`를 사용하는 리스트라고 생각 하면 된다.
리스트와 다른점은 한번 생성하면 수정할 수 없다는 것이다.
보통 상수 사용할때 사용한다.

*8. 맵.*

`맵(map)`은 리스트나 튜플처럼 어떤 것들의 집합이다. 맵이 리스트나 튜플과 다른 차이점은 맵에 있는 각각의 항목들은 `키(key)`와 그에 대응하는 `값(value)`를 갖는다는 것이다.
``` py
>>> game_list = { 'war craft' : 'blizard',
	      'diablo3' : 'blizard',
	      'LOL' : 'riot',
	      'KOF' : 'konami'}
>>> print(game_list)
{'war craft': 'blizard', 'LOL': 'riot', 'diablo3': 'blizard', 'KOF': 'konami'}
>>> print(game_list['war craft'])
blizard
```
리스트와 마찬가지로 삭제 할 경우에는 `del` 을 사용한다.
``` py
>>> del game_list['LOL']
>>> print(game_list)
{'war craft': 'blizard', 'diablo3': 'blizard', 'KOF': 'konami'}
```
맵은 리스트와 많이 비슷하지만 더하기 연산자(`+`)를 사용할 수 없다.


`JAVA`나 `C`와 많이 다르지 않아서 쉽게 쉽게 넘어갈수 있었다.
솔직히 말하면 공부하는 시간보다 이 글 작성하는 시간이 2배는 넘게 걸린것 같다.
이제 첫 걸을 뛰었다. 차근차근 해보자.

2016.10.18
