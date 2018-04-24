# 누구나 쉽게 배우는 파이썬 프로그래밍
---

**Chapter 7**

**Chapter 7. 함수와 모듈로 코드를 재사용하기.**

*1. 함수 사용하기.*
함수 사용하기는 기존의 `C`나 `JAVA`처럼 `function`을 사용하면 된다.
``` py
>>> list(range(0,5))
[0,2,3,4,5]
```

*2. 함수의 구조.*
`함수`는 `이름`, `매개변수`, `내용` 3가지로 이루어 진다.
``` py
	# 함수 선언.
>>> def HelloWorld(myname):
	print('hello World %s' % myname)
	# 함수 이용 부분.
>>> HelloWorld('NaroQ')
hello World NaroQ
```
`C`나 `JAVA`에서 작성하는 것처럼 이용하면 된다. 다른게 없고 틀린 부분이라면 문법에 주의하자.

*3. 변수와 영역.*
마찬 가지로 `C`나 `JAVA`와 크게 다른점은 엇지만 `scope`가 조금 틀리다.
python에서는 함수 안의 변수는 밖에서 이용 못하지만 밖의 ~~변수는 이용 가능하다.!!!~~
~~전역변수 아니면 이용 못하는 타 언어와는 다르다.~~
python도 결국 전역 변수가 아니면 읽어 오는 것만 된다. 값을 변경하거나 수정하는 것은 안된다.

** 추가 **
`puzzle_03`을 풀다가 다음과 같은 경우 함수 밖에 있는 변수를 못 쓸 경우가 있다.
처음 코드를 짤때 다음과 같이 작성했다.
``` py
import sys

def input_value():
    return (sys.stdin.readline())

def moon_weight():
    for x in range(0, max_year):
        print(weight * (1 + 0.165))
        weight = Earth_weight + increase_weight
    
print("Please enter your current Earth weight")
weight = float(input_value())
print("Please enter the amount your weight might increase each year")
increase_weight = float(input_value())
print("Please enter the number of years")
max_year = int(input_value())

moon_weight()

# 수행 결과.
Please enter your current Earth weight
88.1
Please enter the amount your weight might increase each year
10
Please enter the number of years
10
Traceback (most recent call last):
  File "C:/Users/selec/Desktop/Develop/Python/Chapter 7/Puzzle_03.py", line 18, in <module>
    moon_weight()
  File "C:/Users/selec/Desktop/Develop/Python/Chapter 7/Puzzle_03.py", line 8, in moon_weight
    print(weight * (1 + 0.165))
UnboundLocalError: local variable 'weight' referenced before assignment
```
위에서 보다시피 error가 발생한다. 이유를 보니깐 변수를 읽을수는 있지만 변수에 새값을 할당은 안된다. 오로지 `readonly`만 된다는 것이다. 책에서는 이러한 설명이 없어서 혹시 함수 선언 위치나 변수 사용 위치때문에 그런가 순서도 바꿔보고 그러다가 안되서 검색해 봤더니 그렇다고 한다. 다음 문제를 고치는 방법은 2가지가 있는듯 하다.


1. 그냥 함수안에 지역 변수를 만들어 줘서 거기다가 값을 저장한뒤 이를 사용하는 방법.

``` py
import sys

def input_value():
    return (sys.stdin.readline())

def moon_weight():
    Earth_weight = weight
    for x in range(0, max_year):
        print(Earth_weight * (1 + 0.165))
        Earth_weight = Earth_weight + increase_weight
    
print("Please enter your current Earth weight")
weight = float(input_value())
print("Please enter the amount your weight might increase each year")
increase_weight = float(input_value())
print("Please enter the number of years")
max_year = int(input_value())

moon_weight()
```

2. `global`을 선언해 줘서 사용하는 해당 변수가 global 변수라는 것을 함수에 알려주는 방법.

``` py
import sys

def input_value():
    return (sys.stdin.readline())

def moon_weight():
    for x in range(0, max_year):
        global weight
        print(weight * (1 + 0.165))
        weight = weight + increase_weight
    
print("Please enter your current Earth weight")
weight = float(input_value())
print("Please enter the amount your weight might increase each year")
increase_weight = float(input_value())
print("Please enter the number of years")
max_year = int(input_value())

moon_weight()
```

책이 비 프로그래머 대상이라 그런가 어려운 거는 설명을 뛰어 넘는 경향이 있는듯 하다... 주의 해야겠다.

*4. 모듈 사용하기.*
`모듈(Module)` 사용하는 법은 `import`를 시켜주면 된다.
``` py
>>> import time
>>> print(time.timezone)
-32400
>>> print(time.asctime())
Thu Oct 27 14:34:34 2016
```
`module`을 `import`하고 나서 `ctrl + space`를 누르면 사용할 수 있는 `function`이 나온다. 자동 완성 기능이라 보면 된다.

*5. 사용자 입력 받기.*
책에서는 모듈 사용하기에 같이 나와 있는데 사용자 입력 받는 부분은 중요한듯 하여 따로 정리한다.
사용자에게서 입력을 받기 위해서는 `sys`라는 module을 이용해야 한다.
``` py
>>> import sys
>>> print(sys.stdin.readline())
NaroQ	# 입력한 값.
NaroQ	# 출력된 값.
```
`readline()`은 엔터를 누르기 전까지 키보드로 입력한 텍스트를 읽는데 사용된다.
주의할 점은 문자열로 저장된다는 것이다. 만약에 숫자를 입력 해서 `int`로 사용해야 한다면 `casting`을 해줘야 한다.
``` py
import sys
age = int(sys.stdin.readline())

#age는 int로 이용되고 있으므로 형변환 필요.
if (age > 18):
    print(" you can buy beer")
else:
    print(" you can not buy beer")
```