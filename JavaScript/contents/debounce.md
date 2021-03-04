# Debounce

## 목차

- [배경](debounce.md#%EB%B0%B0%EA%B2%BD)
  - [Debounce](debounce.md#debounce%EB%9E%80)
  - [Example](debounce.md#example)
- [결론](debounce.md#%EA%B2%B0%EB%A1%A0)
- [참조](debounce.md#%EC%B0%B8%EC%A1%B0)

## 배경

요즘 공부도 하고 긴장감의 끈을 놓치 않기 위해서 알고리즘, 코딩 테스트 문제를 풀어보고 있다. 지난 토요일 과제를 푸는데 **Debounce** 개념을 이용해서 푸는 문제가 나와서 이를 연구 및 정리를 하기 위해서 이번 포스트를 작성한다.

### debounce란?

Debounce는 자바스크립트의 성능을 향상시기 위해서 사용되는 기법으로 이벤트를 제어하는 여러가지 방법중 하나이다. 어떤 기법이냐 하면.. **같은 함수(이벤트) 또는 다양한 함수(이벤트)가 여러번 호출 될 경우 마지막또는 처음에 들어온 함수(이벤트)만을 실행 시키는 것**을 말한다.

과제에서는 어떠한 영역이 있고, 해당 영역 값이 변경되면 API Call이 발생해야 했다. 그런데 영역이 Drag 이벤트로 연달아서 변경되는데, Drag를 해서 이벤트가 연달아 발생해서 API Call을 수십번 요청하게 되버렸다. 이를 막기 위해서 가장 마지막 위치를 기준으로 API Call을 해야 했기 때문에 Debounce 기법을 사용하게 되었다.

### Example

예시가 이게 맞을지는 잘 모르곘는데 일단 한번 보자. 아래 예제는 버튼을 클릭하면 1씩 증가하는 간단한 HTML이 구현되어 있다.

[코드펜링크](https://codepen.io/threesnakes/pen/gOPwYaq)

여기서 버튼을 클릭하면 숫자가 1씩 증가하는 것을 볼수 있는데 사용자가 버튼을 연달아서 클릭해도 1번만 동작하게 하고 싶은 경우가 있다. 이럴 경우에 debounce를 사용하는 것이다. ( **다시 말하지만 적당한 예제는 아닐 수 있다.** )다음 코드를 클릭이 발생했을때 무조건 마지막 클릭을 기준으로만 동작하도록 하는 코드로 변경하면 다음과 같아진다.

[코드펜링크](https://codepen.io/threesnakes/pen/wvMzwyB)

코드를 보면 클릭이 발생했을 경우 이벤트를 작성해주었는데, 기존 debounce 변수가 비어 있지 않을 경우에 Timeout을 초기화 시켜주고, 반대로 비어 있는 경우에는 timeout을 설정해준다. 1초 사이에 이벤트가 새로 들어오면 기존 debounce의 Timeout은 초기화가 되고, 다시 Timeout을 설정해주는 형태이다. 결국 마지막 클릭 이후 1초동안 클릭이 없으면 1이 증가되는 형태가 되는 것이다.

## 결론

사실 되게 간단한 개념이고 많이 쓰이는 기법이다. 다음 코드 형태만 잊지말고 snippet으로 만들어놓으면 편하게 사용 할 수 있을 것이다.

``` js
let debounce = null;

div.addEventListener('click', (evt)=> {
  if (debounce) clearTimeout(debounce);
  debounce = setTimeout(() => {
    count += 1;
    div.innerHTML = return_span(count);
  }, 1000)
})
```

[ZeroCho님의 블로그](https://www.zerocho.com/category/JavaScript/post/59a8e9cb15ac0000182794fa)를 보면 lodash를 추천하긴 하는데, 내 경우 바닐라 스크립트만으로 작성해야하는 과제라서 그냥 기억해두는게 좋을 것 같다.

쓰로틀링 기법도 있는데 이거는 나중에 정리해 봐야겠다.

## 참조

- [ZeroCho님의 블로그](https://www.zerocho.com/category/JavaScript/post/59a8e9cb15ac0000182794fa)