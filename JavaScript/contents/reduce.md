# reduce

정산 리팩토링을 하면서 reduce에 대해 몰랐던 것과 새롭게 알게 된것이 있어서 이를 정리한다.

## 일반적인 사용법

``` js
const numbers = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
const total = numbers.reduce((total, current, index) => {
  return total += current;
}, 0)
console.info(total)     // 55
```

기존에는 이렇게 합계를 구하는데 많이 사용 했었다. 예를 들면 전체 client의 남은 잔액 합계 같은 것을 구할 때 사용했었는데 파트장님이 작성하신 코드중에 이를 **비동기 프로그래밍** 할 때 사용하신 코드(모든 Client에게 순차적으로 메일 발송 하는 기능)가 있었다. 이거를 보고 어떻게 동작하는지 확인하고 공부해 보았다.

## 비동기 프로그래밍할때 사용하는 법

``` js
const func = () => {
  // .. 서버에 post 호출하는 코드
};

const list = []; // 대상
list.reduce((p, current, index) => {
  return p.then(() => {
    return func();
  })
}, Promise.resolve(true)).then(() => {
  // 전체 리스트를 모두 POST하고 난뒤 실행할 코드
})
```

이게 어떻게 진행되는지 하나씩 살펴 보자.

1. 초기값은 **Promise.resolve(true)** 가 되는데 이는 결국 **Promise**를 리턴하는것이다.
2. reduce를 진행하면서 return 된 **p(Promise)**에 **then**을 붙이고 이를 **return**한다.
3. list가 끝날때까지 2번 항목을 반복하게 된다.
4. list가 끝나면 **reduce**가 종료되고 **reduce**뒤에 붙어 있는 **.then** 이 실행되면서 마지막에 실행할 코드가 진행된다.

이를 잘보면 3번에는 최종적으로 다음과 같은 코드가 리턴되는 것이다.

``` js
Promise.resolve(true).then(() => {
  return func()
}).then(() => {
  return func()
})....
}).then(() => {
  return func()
}).then(() => {
  // 전체 리스트를 모두 POST하고 난뒤 실행할 코드
})
```

이거 처음 했을때 완전 신기 하였다. 이런 방법도 있구나 라는것은 알고 있었는데 실제 사용해보니 신통방통하다. reduce를 절대 잊으면 안될것 같다. 위에 하는 법은 그냥 외워놓는게 좋을것 같다.