# 누구나 쉽게 배우는 파이썬 프로그래밍
---

**Chapter 4 ~ 6**

**Chapter 4. 거북이로 그림기.**

*1. python `turtle` 모듈 사용하기.*

``` py
>>> import turtule
```
파이썬에서 `모듈`을 사용할때는 import를 사용하면 된다.

*2. 캔버스 생성하기.*
``` py
>>> t = turtle.Pen()
```
입력하면 중앙에 화살표가 있는 빈 상자(캔버스)가 생성 된다. 파이썬 shell에 명령어를 입력하면 이 화살표를 움직일수가 있다.!!!!(잼난다.)

*3. 거북이 움직이기.*
``` py
>>> t.forward(100)			#전진
>>> t.backward(100) 		#후진
>>> t.left(90)				#왼쪽으로 90도 꺽기.
>>> t.right(90)				#오른쪽으로 90도 꺾기.
>>> t.up()					#Pen에서 손떼기?라고 이해 하자.
>>> t.down()				#Pen 다시 canvas에 내리기.
```

**Chapter 5. IF와 ELSE로 물어보자.**

*1. 블록은 프로그래밍 구문들을 모아둔 것.*
파이썬에서 `TAB`키를 눌렀을 때 추가되는 탭이나 스페이스바를 눌렀을 때 추가되는 빈칸인 `공백(whitespace)`은 의미가 있는 것이다. 동일한 위치(왼쪽에서 동일한 개수의 공백으로 들여쓴 위치)에 있는 코드는 하나의 블록으로 그룹지어진 것이며, 이전에 있던 공백보다 더 많은 공백을 가지고 새로운 코드 줄을 시작하는 것은 이전 블록에 속한 블록을 시작하는 것이다.
``` py
코드줄									|
코드줄									|
코드줄									|
	코드줄						|	   |
    코드줄						|       |
    코드줄						|       |
    	코드줄		|	   	|       |
        코드줄		블록3	 블록2    블록1
        코드줄		|		   |       |
    코드줄						|       |
    코드줄						|       |
```
즉. 들여쓰기 간격을 바꾸면 일번적으로 그것은 새로운 블록을 생성한다는 것이다.
``` py
>>> if pizza = 3000;
>>> if pizza > 1000:
	print('it is too expensive')  #print1
      print('not eating')         #print2
```
위와 같이 코드를 작성한다고 가정하자. pirnt1과 print2의 앞에 공백의 개수가 다르다. 이럴 경우 `들여쓰기 에러`가 발생한다. 파이썬은 한 블록에 있는 모드 코드줄은 모두 동일한 공백을 가질 것이라 예상하고 있기 때문에 같은 공백 개수를 가져야 한다.

*2. IF-THEN-ELSE문.*
``` py
>>> pizza = 12000
>>> if pizza == 12000:
	print(" wow pizza!!)
else:
	print("woo. no pizza)
    
 wow pizza!!
```
처럼 if else문 쓰면 된다. `세미콜론(:)` 사용하는거 잊지 말자.

*3. IF문과 ELIF문.*
``` py
>>> money = 1000
>>> if money == 1000:
	print('you can buy pizza')
elif money == 3000:
	print('you can buy hamberger')
elif money == 5000:
	print('you can buy galbi')
else:
    print('nothing')
```
위와 같이 else if문도 사용할 수 있다. java나 c랑 다른건 없으나 `else if`가 아니라 줄임말인 `elif`라는 것만 잊지 말자.

*4. 조건문 조합하기.*

`and`와 `or`를 사용하여 조건문을 조합할 수 있다. 사용하는 방법은 `java`나 `c`와 같다. 다만 `&&` 나 `||`가 아닌고 `and`와 `or`라는 것만 기억하자.

*5. 아무런 값이 없는 변수 NONE.*

`None` == `NULL`이라 생각 하자. 어렵게 생각하지 말자.
``` py
>>> car = None
>>> print(car)
None
```

*6. 문자열과 숫자와의 차이점.*

파이썬에서 사용자 입력은 `문자열`로 간주 된다. 즉. 키보드로 10을 입력할 경우 파이썬은 숫자 10이 아닌 문자열 `'10'`으로 저장한다는 것이다. 그래서 값을 비교할때 형변환을 해줘야 한다.
``` py
#문자열을 int로
>>> pizza = '5000'
>>> converted_pizza = int(pizza)

#int를 문자열로
>>> pizza = 5000
>>> converted_pizza = str(pizza)
```
또한 소수점 숫자를 사용할때는 `float`를 사용한다.
``` py
>>> pi = '3.14'
>>> converted_pi = float(pi)
>>> pirnt(converted_pi)
3.14

```

**Chapter 6. 빙글빙글 돌기.**

*1. `for`루프 사용하기.*
``` py
>>> for x in range(0,5):
	print('hello')
hello
hello
hello
hello
hello
```
기본적인 사용법은 `java`난 `c`와 같다. 그런데 약간 다르게 생긴것을 주의 하자.
`range`함수를 사용하면 시작 숫자부터 끝에 있는 숫자 바로 앞까지의 숫자 리스트를 생성할 때 사용 할수 있다. 즉 위 코드로 생성되는 숫자 리스트는 `[0, 1, 2, 3, 4]`이다. 끝 숫자 바로 앞까지 생성된다는 것에 주의 하자.
또한 `for`을 사용할때 위에처럼 리스트를 사용한다는 것을 알 수 있는데, 숫자 리스트 뿐만 아니라 이미 만들어진 리스트도 사용 할 수 있다. 예제를 보는게 훨씬 쉽다.
``` py
>>>game_list = ['KOF', 'WarCraft', 'StarCraft', 'Diablo3']
>>>for i in game_list:
	pirnt(i)
    
KOF
WarCraft
StarCraft
Diablo3
```
game_list에 있는 각 항목에 대하여 변수 i에 그값을 저장하고 그 값을 `print`를 통해서 출력하는 것이다.

*2. `while`루프 사용하기.*

`java`나 `c`랑 같다. 그냥 예제만 한번 보자.
``` py
>>> age = 0
>>> while age < 5:
	print(age)
    age = age+1
    
0
1
2
3
4
```

기본적인 문법이 비슷해서 배우기 쉽다. 그냥 중간 중간 다르게 사용한다는 점만 주의하면 될것 같다. 

turtle 이용하는거는 처음해봤는데 완전 신기하네...
