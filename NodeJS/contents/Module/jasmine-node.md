# Jasmine-node 사용법 정리
`Jasmine`은 `BDD(Behaviour-Driven Development)` 툴로서 `BDD`를 구현하기 위한 툴이다. `Jasmine-Node`를 프로젝트에 일부 붙여 보면서 후일을 위해 기록한 글이다. 

## BDD와 TDD의 차이점.
`BDD`와 `TDD`는 `애자일 소프트 웨어 개발 방법론`에서 가장 많이 쓰이는 개념이다. 둘의 차이는 거의 없다고 한다.
차이가 있다고 하면 `TDD`는 `테스트 자체에 집중하여 개발하는 방법`인 반면, `BDD`는 `비즈니스 요구사항에 집중하여 테스트 케이스를 개발` 한다는 것.
참조 : [Introducing BDD, 번역 이홍주](http://eulipion.tistory.com/319)

## 설치법
바로 테스트를 진행해 보자.

``` bash
$ npm install jasmine -g # jasmine을 인스톨 한다. 
$ npm install jasmine-node -g # jasmin-node 를 인스톨 한다.

# 주의 ! jasmine을 설치해야 jasmine-node를 쓸 수 있는지는 확인 해보지는 않았다. 다만 jasmin을 지우고 jasmine-node를 돌려보니 동작하는 것으로 보아서 상관 없는 듯하다.
```

## Test 진행
IM 사이트를 기준으로 말하겠다.
IM 사이트는 현재 다음처럼 구성 되어 있다.
```
Project  ----- routes   ------ adproduct.js
         |              |_____ .. 기타 등등 ...
         |____ modules  ------ adproduct.modules.js
         |              |_____ .. 기타 등등 ...
         |              |_____ custom
         |____ bin
         |____ config
         .... 등등
```
이 있는데. routes는 말그대로 routes이다. API가 정리되어 있는 곳인데 해당 routes는 각 API마다 modules에 개별 router 마다 module 파일이 존재 한다. 각 개별 `이름.module.js`은 각 routes가 
쓰고 있는 펑션들이 있으며 해당 펑션으로만 구성 되어 있다. 말로 설명하기 어려운데 그냥 한번 가서 보자.
하여튼 여러가지가 있는데 그중에 modules 안에 custom.js 라는 파일이 있다. 이 파일은 여러 모듈에서 공통으로 쓰이는 펑션을 정의해 놓은 곳인데 현재 2가지 펑션밖에 없다.
`isEmpty`와 `stringLengthCheck` 이 두개가 존재한다.
`isEmpty`는 말그대로 해당 객체가 비었는지 체크하고 비었으면 `true`를 리턴하고 안비었으면 `false`를 리턴한다.
`stringLengthCheck`는 인자를 2개 받는데 `( 문자열, 최대길이 )` 형태로 받는다. 문자열의 길이가 최대 길이( 영어, 특수문자 1, 한글 2로 계산해서)를 넘는지 안넘는지 계산해서 넘으면 `false`를 안넘으면 `true`를 리턴한다. 
역시서 BDD를 테스트 해볼 펑션은 `stringLengthCheck` 이다.

일단 위에서 `jasmine-node`를 설치 했으니 spec 파일을 만들어 보자.

```
Project  ----- routes   ------ adproduct.js
         |              |_____ .. 기타 등등 ...
         |____ modules  ------ adproduct.modules.js
         |              |_____ .. 기타 등등 ...
         |              |_____ custom
         |____ bin
         |____ config
         |____ spec # 이 폴더를 새로 생성한다.!!!!
         .... 등등
```
위 구조처럼 `spec` 폴더를 새로 생성 한다음 안에 `custom.spec.js` 파일을 추가한다. 그다음 아래 내용을 넣어본다.

``` js
const custom = require('../modules/custom');

describe('stringLengthCheck TEST', () => {
    it('문자열 길이를 리턴한다. ', () => {
        expect(custom.stringLengthCheck('aaa', 5)).toBe(true);
        expect(custom.stringLengthCheck('aaa', 3)).toBe(true);
        expect(custom.stringLengthCheck('aaa', 2)).toBe(false);
        expect(custom.stringLengthCheck('가나다라마바사', 22)).toBe(true);
    });
});
```
여기서 `describe` 를 `Suite`라고 한다. 일반적으로 함수가 된다. 이 `Suite`는 `stringLengthCheck TEST` 라고 부른다. `Suite`안에 `it()`함수를 가지고 있는데 이것을 `Spec`이라고 한다. `Suite`안에는 수만은 `Spec`을 가질수 있다. `expect`가 실제 테스트를 진행하는 함수라고 할수 있는데 `expect(custom.stringLengthCheck('aaa', 5)).toBe(true);` 는 말 그대로 `custom.stringLengthCheck('aaa', 5)`를 넣을떄 `true`가 되야 한다는 뜻입니다. 만약 실행 결과가 달라지면 이는 테스트가 실패 한것입니다. `expect`와 같은 것을 `Matcher`라고 합니다.

풀어서 보면 `custom.stringLengthCheck('aaa', 5)`를 실행 했을때 `true`가 나와야 성공인 것이고 `false`가 나오면 해당 테스트는 실패 하는 것입니다. `custom.stringLengthCheck('aaa', 2)` 를 실행 했을떄는 `false`가 나와야 하는 것입니다.  이렇게 테스트 코드를 작성 후에 `jasmine-node`를 실행 해 봅니다.

``` bash
$ jasmine-node spec/ | bunyan -o short  # stringLengthCheck 안에 bnuyan으로 로그를 호출해서 해당 명령어 pipe로 실행.
raven@2.2.1 alert: no DSN provided, error reporting disabled
09:39:20.641Z  INFO Project: string byte length is  3 (loggerName=modules/custom.js)
.

Finished in 0.01 seconds
1 test, 4 assertions, 0 failures, 0 skipped


09:39:20.645Z  INFO Project: string byte length is  3 (loggerName=modules/custom.js)
09:39:20.646Z  INFO Project: string byte length is  3 (loggerName=modules/custom.js)
09:39:20.646Z  INFO Project: string byte length is  14 (loggerName=modules/custom.js)
```
test가 1개가 진행 됬고 4개의 `assertions(it)`이 진행 됬으며 실패한 건은 0건이라고 나옵니다.
이렇게 테스트를 진행 할 수 있습니다.

## 참조
[outsider님의 글](https://blog.outsider.ne.kr/673)  - 이 글을 보고 정리해서 올린 블로그이다.

