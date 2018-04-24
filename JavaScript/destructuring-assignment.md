# 비구조 할당.
`Lint`를 적용한지가 꽤나 지났지만 아직도 기존 코드에는 고쳐져 있지 않는 부분이 있다. 수정사항이 들어 올때마다 해당 코드를 `Lint`에 맞춰서 작업을 진행하고 있었는데, 오랜만에 관리자쪽 코드를 손보고 있었는데 평소에 못보던 `Lint`에러가 있어서 어떤건지 조사를 해보다가 `비구조 할당`이라는 것에 대해서 알게되서 정리 해본다.

일단 `Lint` 에서는 다음 에러(!?)가 나왔다.
`[esLint] Use Object Destructuring. (Prefer Destructuring)`
흠 `Destructuring`이 무엇인가... -_-;;

일단 검색해 보니 `exploringJS` 에서 다음처럼 설명을 써놨다.
`Destructuring is a convenient way of extracting multiple values from data stored in (possibly nested) objects and Arrays. It can be used in locations that receive data (such as the left-hand side of an assignment). How to extract the values is specified via patterns (read on for examples).`

안되는 영어 실력으로 번역해 보자면 `Destructuring`은 `배열이나 객체에 저장되어 있는 데이터에서 여러개의 값을 추출하는 편리한 방법이라고 한다`. 즉 배열이나 객체에서 값을 빼내는 편리한 방법(!?)이라고 한다. ~~흠.. 지금 쓰는게 더 편리한데...~~

하여튼 `Destructuring` 배열의 값이나 객체의 속성을 별개의 변수로 추출할 수 있게 하는 자바스크립트 식(expression)이다(`MSDN`).

## ES6에서 비구조 할당 사용법.

기존에는 배열이나 객체에서 값을 뽑아 낼때 다음처럼 사용 했었다.
( 값을 뽑아내는 것을 `비구조 할당`이라 한다. )
``` JS
`use strict`;

const arr = [1, 2, 3, 4, 5];
const tmp = arr[0];
const tmp2 = arr[2];

console.log(tmp, tmp2);

const obj = {
    a: 1,
    b: 2,
    c: 3,
};

const tmp3 = obj.a;
const tmp4 = obj.c;

console.log(tmp3, tmp4);
```
위에 코드처럼 변수를 선언 한뒤 해당 변수에 배열의 몇번 인덱스나 오브젝트의 프로퍼티를 할당하는 방법으로 작성 했었다.

하지만 `ES6`에서는 배열의 비구조화 할당을 다음처럼 처리 할 수 있다.

``` JS
'use strict'

const arr = [1, 2, 3, 4, 5];
const [a1, a2, a3 ] = arr;
console.log(a1, a2, a3) // a1, a2, a3 에 arr 배열에 각각 0,1,2 번째 인덱스의 값이 들어 온것을 볼 수 있다.

const [b1, , , b4 ] = arr;
console.log(b1, b4)     // 중간에 ,, 처럼 빈칸을 두면 해당 인덱스를 뛰어 넘을 수 있다. 결국 b1, b4에 0, 3번째 인덱스의 값이 들어 온것을 볼 수 있다.

const [c1, c2, ...c3] = arr;    // 이렇게 하면 c1과 c2에는 각각 0,1 번째 인덱스를 삽입하고 나머지는 모두 c3에 때려 박을수 있다!!! 신기하다!!
console.log(c1) // 1출력
console.log(c2) // 2출력
console.log(c3) // [2, 3, 4, 5] 출력.
```
또한 `ES6`에서 객체의 비구조화 할당은 다음처럼 처리 할 수 있다.
``` JS
'use strict'

const obj = {
    a: 1,
    b: 2,
    c: 3,
    d: 4,
    e: 5,
};

const {a, d} = obj;
console.log(a, d) // 1 4 출력. 이렇게 객체의 각각 a, d의 값을 가져 오는 것이다.

const {a, f} = obj; // f는 obj 객체에 없는 프로퍼티명이다. 어떻게 출력되는지 확인해보자.
console.log(a, f) // 1 undefined 출력. 객체의 프로퍼티의 이름이 다를 경우에는 해당 값을 가져오지 못한다. 주의 하자.

// obj에 없는 프로퍼티명으로 가져오려 하면 udefined가 뜨는데.. 변수 명을 바꿔야 할 떄가 있다. 이럴 경우에는 이렇게 사용한다.
const { a:A, d:D} = obj;
console.log(A, D);  // 1 4출력, a를 A로 , d를 D로 바꿔서 사용할 수 있다.

//또한 객체에서 가져올때 값이 undefined 일 경우 여기에 기본값을 줄 수 있다. ( 요청 들어 왔을때 파라미터에 이거 쓰면 좋을듯 하다. )
const {
    a = 10,
    b = 20,
    f = 60
} = obj;

console.log(a, b, f);   // 1, 2, 60 출력이 된다..라고 해야 하는데 nodeJS에서는 안된다.. a가 이미 선언되어 있다고 나온다... ㅠㅠ

// 객체 이름 바꿔서 가져오기와 객체 기본값을 같이 사용 할 수 도 있다. 그런데 이건 nodeJS에서 된다!?
const {
    a: A = 10,
    b: B = 20,
    f: F = 30,
} = obj;

console.log(A, B, F); // 1, 2, 60 출력 성공.. 뭐지.. 위에는 안되는데 왜 이건되지..? 흠흠....
```

`비구조 할당`에 대해서 정리해 봤고 이제 실제로 써보는 일만 남았다.
몇개는 바로 사용 할 수 있을 정도니 바로 적용 해 봐야겠다.
근데 사실 저게 더 사용하기 힘들것 같은 느낌이 많이 들고 안되는게 있긴 한데..
왜 안되는지는 잘 모르겠다. -_-;;
아 그리고 `nodeJS 4.6.2` 에서 맨 처음 테스트 할때는 새로운 비구조 할당 방법이 동작을 안했다.
`6.10.0`에서는 잘 동작 한다. 이게 노드 버전 마다 지원하는 것도 있고 안하는 것도 있는것 같다.
[이곳](http://node.green/#ES2015-syntax-destructuring--parameters-with-astral-plane-strings)에서 확인해 보자.

### 참조
* [exploringJS](http://exploringjs.com/es6/ch_destructuring.html)
* [MSDN](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Operators/Destructuring_assignment)
* [Park Charyum 님 블로그](http://memory.today/dev/post/10)
