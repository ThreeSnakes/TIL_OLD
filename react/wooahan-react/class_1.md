
# 우아한 React && TypeScript
## 목차
- [TypeScript 기본 문법](#TypeScript-기본-문법)
  - [타입선언](#타입선언)
  - [Type Alias와 변수 선언](#type-alias와-변수-선언)
- [React](#react)
  - [create-react-app](#create-react-app)
  - [트랜스파일러](#트랜스파일러)
  - [간단한 리액트앱 작성해보기](#간단한-리액트앱-작성해보기)
  - [상태 관리](#상태-관리)

### TypeScript 기본 문법

#### 타입선언

```tsx
let foo1 = 10;  // foo는 타입이 number가 된다. 타입은 암묵적으로 작성.
let foo2: number = 10;  // 타입을 명시적으로 작성.

foo = false;   // 다른 타입을 넣으니 에러가 발생한다.
```

- JS도 새로운 기능이 추가되고 있는데, 명시적으로 작성하는 방법으로 개발 되고 있다.
- 암묵적인 코드는 좋지 않으며 명시적인 방법으로 이전되고 있다.

#### Type Alias와 변수 선언

```tsx
// 일반 변수 설정
let age: number = 10;차
let weight: number = 72;

// Type Alias를 통한 변수 설정
type Age = number;
type Weight = number;

let age: Age = 10;
let weight: Weight = 72;

// 객체 Type 설정
type Foo1 = {
  age: number;
  name: string;
}

// 객체 Type && Type Alias 선언
type Foo2 = {
  age: Age;
  weight: Weight;
  name: string;
}

// 객체 Type선언을 통한 변수 설정
const foo: Foo = {
  age: 10,
  weight: 72,
  name: 'lim'
}

// Interface 선언
interface Bar {
  age: Age;
  name: string;
}

const foo: Bar = {
  age: 10,
  name: 'lim'
}

```

- Type Alias는 단순히 기본형 데이터를 다른 이름 사용하도록 해주는 것이다.
- 이를 통해서 코드의 가독성을 향상 시킬 수 있다.
- Type 관련 코드는 컴파일 될 경우 모두 사라진다.
  - TypeScript에는 컴파일 할 때만 남는 문법 요소와 컴파일 이후에도 남는 runtime 요소 두가지가 존재한다.
  - 인터페이스, 제네릭, 타입 등이 컴파일에만 동작하는 문법요소이다.
- Type Alias과 Interface중 어느것을 써야 할까.?
  - 나중에 조금 더 자세하게 할 예정. 일단 쓰는법을 익혀두자.

### React

#### [create-react-app](https://create-react-app.dev/)

- 리액트앱을 구성할 수 있는 가장 빠른 방법

  ```bash
  # 그냥 JavaScript로 할 경우 다음 명령어로 react app을 만들 수 있다.
  npx create-react-app my-app

  # 다음 명령어로 타입스크립트로 셋팅된 react app을 만들 수 있다.
  npx create-react-app my-app --template typescript
  ```

- CRA는 production용으로는 사용하지 않는 것이 좋다.
  - CRA가 구성하지 않는 세팅을 추가하려고 하는게 굉장히 어렵다.
  - 다양한 환경에 대한 대응이 어렵다.
  - eject로 환경을 빼낼 순 있으나 헬게이트를 여는 느낌이다. ( 그냥 하지 말아라 )
  - CRA는 학습용으로 쓰고 실제 개발 환경에서는 웹팩으로 구성해라.

#### 트랜스파일러

- react 트랜스파일러는 babel이다. [링크](https://babeljs.io/repl#?browsers=defaults%2C%20not%20ie%2011%2C%20not%20ie_mob%2011&build=&builtIns=false&spec=false&loose=false&code_lz=GYVwdgxgLglg9mABAQQA6oBQEpEG8BQiiATgKZQjFIaFGIA8AFgIwB8AEqQDZdyIAqpCI3oB6Fq1pZ8AXyA&debug=false&forceAllTransforms=false&shippedProposals=false&circleciRepo=&evaluate=false&fileSize=false&timeTravel=false&sourceType=module&lineWrap=true&presets=env%2Creact%2Cenv&prettier=false&targets=&version=7.11.5&externalPlugins=)에서 어떻게 트랜스파일링 되는지 확인할 수 있다.

```js
import React from 'react';

function App() {
	return (
		<h1 id="header">Hello Tech</h1>
	)
}

--> 트랜스파일링

"use strict";

var _react = _interopRequireDefault(require("react"));

function _interopRequireDefault(obj) { return obj && obj.__esModule ? obj : { default: obj }; }

function App() {
  return /*#__PURE__*/_react.default.createElement("h1", {
    id: "header"
  }, "Hello Tech");
}
```

- `<h1>Hello Tech</h1>`는 JavaScript 문법이 아니다. 바벨이 이를 `createElement` 형태로 바꿔주는 것이다.
- react component를 만들기 위해서는  react 패키지를 import 해야 한다.
  - `import React from 'react'`

#### 간단한 리액트앱 작성해보기

- CodeSandBox에 작성. [링크](https://codesandbox.io/s/uahan-tech-react-typescript-6rpzv)
- StrictMode는 개발 환경에서 에러, alert을 보여주기 위한 tag이다. Production Level에서는 동작하지 않는다.  [한번 살펴보자.](https://ko.reactjs.org/docs/strict-mode.html)
- ReactDom.render는 처음 한번만 동작한다. 최상위에서 한번만 호출한다.

#### 상태 관리

- 여러 component에서 공유해야 하는 전역 상태를 어떻게 관리할 것인가? 라는 관점에서 보는 것이다.
- 상태 관리에는 여러가 솔루션이 존재한다.
  - flux
  - redux
    - flux 아키텍처를 더 정형화하고 심플하게 만든 것이다.
    - react 기본으로 들어가 있으며 굉장히 많이 쓰고 있다.
    - 굉장히 간단하다. 간단해서 더 어렵게 느껴 질 수 있다.
  - mobx
    - redux의 대체품이 아니다. 상태 관리의 패러다임이 다르다.
    - mobx는 여러 형태로 사용 할 수 있다.  다양한 사용법, 아키텍처가 나올 수 있어서 개발자마다 이를 이용하는 방법이 다를 수 있다. redux는 간단한 형태여서 하나의 아키텍처로 통합할 수 있으나 mobx는 여러 방법이 있어서 통합하기 어렵다.
    - 굉장히 유연하고 기능은 많으나 그만큼 실수할 여지가 많아질 수 있다.