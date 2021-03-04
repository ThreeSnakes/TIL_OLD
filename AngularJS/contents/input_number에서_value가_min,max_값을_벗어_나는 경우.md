# input number에서 value가 min, max 값을 벗어 나는 경우

## 목차

- [개요](input_number%EC%97%90%EC%84%9C_value%EA%B0%80_min,max_%EA%B0%92%EC%9D%84_%EB%B2%97%EC%96%B4_%EB%82%98%EB%8A%94%20%EA%B2%BD%EC%9A%B0.md#%EA%B0%9C%EC%9A%94)
- [해결 방법](input_number%EC%97%90%EC%84%9C_value%EA%B0%80_min,max_%EA%B0%92%EC%9D%84_%EB%B2%97%EC%96%B4_%EB%82%98%EB%8A%94%20%EA%B2%BD%EC%9A%B0.md#%ED%95%B4%EA%B2%B0%EB%B0%A9%EB%B2%95)
- [참조](input_number%EC%97%90%EC%84%9C_value%EA%B0%80_min,max_%EA%B0%92%EC%9D%84_%EB%B2%97%EC%96%B4_%EB%82%98%EB%8A%94%20%EA%B2%BD%EC%9A%B0.md#%EC%B0%B8%EC%A1%B0)

### 개요

하.. 사내 기능 개발중에 input값에 숫자만 넣도록 하는 기능이 있어 이를 개발하고 있는데 해당 input의 model이 init에서는 제대로 값이 잡히는데 프로세스 도중에 값이 자꾸 undefined로 변경되버리는 일이 생겼다. 해당 변수의 값을 할당하는 부분이 전혀 없는데 자꾸 어띠서 변경되는 것인지 찾아봤는데.. 찾아보니.. 완전 뻘짓을 했다.

``` html
<input
  type="number" class="form-control"
  min="1000000"
  name="fixed_credit_amount"
  ng-model="c.amount"
/>
```

일단 위 HTML 코드처럼 선언을 해놨는데 해당 amount값이 init할때는 정상값이 들어오는데, view에서 해당 값이 들어오지 않는 것이다.
거기다 해당 값을 찍어 보면 *undefined*로 나오고.. 해당 변수를 할당하는 코드가 존재하지 않아서 한참을 해메다가 페어프로그래밍을 요청했다.
허허허 팀장님이 오시더니 view쪽을 한번 보라고 하셔서 봤는데.. 갑자기 min값이 의심이 되서 min을 삭제하니 잘나온다.

이유는 이렇다. 해당 변수의 값이 DB에는 800000이 들어가 있는데 *input태그*에서 *min* 값이 1000000으로 DB에 저장된 값보다 크다. 이럴 경우 *input.$error*가 발생하게 되고 결국 해당 *model*에는 *undefined*가 들어가게 되는 것이다.

아.. 완전 스트레스 받는다. JS 파일쪽을 암만 찾아도 당연히 안나온다. *angularjs*에 많이 익숙해지고 알고 있다고 생각했는데 이런거에서 막혀버리니 시간은 시간대로 써버리고 참 허탈하다. 아오..

### 해결방법

- html에서 min을 삭제하고 JS에서 동적으로 에러 처리를 할 수 있도록 수정하였다.
- min, max를 쓸 경우 model값이 범위를 넘어가면 *undefined*가 나올 수 있다는 것을 꼭 기억하자.

### 참조

- [angualrjs input number](https://docs.angularjs.org/api/ng/input/input%5Bnumber%5D)