# Map

## 목차

- [정리](#정리)
  - [Map과 Object 비교](#map과-object-비교)
  - [추가 내용](#추가내용)
- [참조](#참조)

### 정리

Node.js 디자인 패턴을 공부하면서 1장에 Map에 대한 내용이 나와 있어 이를 정리한다. 항상 객체를 이용하여 Map을 만들어 사용하였는데 ES2015부터 보다 안전하고 유연하며 직관적인 방식으로 해시 맵 컬렉션을 사용할 수 설계 되었다고 한다.

``` js
const clients = new Map();
// 키 삽입
clients.set('1', 'jone');
clients.set('100', 'mary');
clients.set('111', 'david');

// Map 길이
clients.size;       // 3

// 해당 키값 존재 유무 확인
clients.has('1');   // true
clients.has('30');  // false

// 삭제
clients.delete('1');
clients.has('1');   // false

// 해당 키에 대한 value 꺼내기
clients.get('1');   // undefined

// 반목
for (const client of clients) {
  console.log(client)
}

// 함수를 키로도 사용 가능하다!!!!
const tests = new Map();
tests.set(() => 2+2, 4);
tests.set(() => 2*2, 4);
tests.set(() => 2/2, 1);

for (const entry of tests) {
  console.log((entry[0]() === entry[1] ? 'PASS' : 'FAIL'))
}
```

#### Map과 Object 비교

Object를 이용한 Map과 Map()을 이용해서 사용한것중 어느것이 더 좋을까.?

잦은 데이터 갱신과 적은 데이터 출력에는 Object를 이용한 Map이 좋고 많은 데이터를 출력할 경우에는 Map()을 이용하는 것이 좋다고 한다.

#### 추가내용

**2019.01.28 추가**
Object로 Map을 사용해서 할 경우 Object가 내림 차순으로 자동으로 정렬되어 버려서 Map을 쓰려 했는데... (키가 입력된 순서로 반복을 돌리고 싶었다) 이것도 꽤 까다롭다. 일단 반복을 위해서 `entries`를 메소드를 사용하려 했더니 이 메소드는 IE에서 지원안하는 경우가 많다. (11 이상 부터 지원 [링크](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Map))

또한 사내에서 `angularjs를` 사용하는데 Map을 ng-repeat에서 반복을 돌릴수가 없다. 사용하려면 별도의 라이브러리를 사용해야 하고...
조금 더 알아봐야 하긴 하겠지만 일단 front 단에서 Map을 사용하는 것은 조금 고민을 해봐야 할 것 같다.

### 참조

- [JeongTaekYu님 미디엄 블로그](https://medium.com/@wdjty326/javascript-es6-map-vs-object-performance-비교-7f98e30bf6c8)
- [MDN Map](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Map)
