# [TAG] display

`display` 속성은 요소를 어떻게 보여줄지 결정한다.

- 속성값
    - `none`: 보이지 않음
    - `block`: 블록 박스
    - `inline`: 인라인 박스
    - `inline-block`: `block`과 `inline` 중간 형태

### `none`
해당 태그가 보이지 않게 된다. `visibility` 속성은 `hidden` 으로 설정한 것과 달리 영역도 아예 차지하지 않는다.

### `block`
가로 길이가 기본적으로 `100%`이며, `block`인 태그를 이어서 사용하면 줄바꿈이 되어 보인다.
`width`, `height` 속성을 지정할 수 있으며, 레이아웃 배치시 주로 쓰인다.

### `inline`
`block`과 달리 줄바꿈이 되지 않고, `width`, `height` 속성을 지정할 수 없다.

### `inline-block`
`block`과 `inline`의 중간 형태라고 볼 수 있다. 줄바꿈이 되지 않지만 크기를 지정할 수 있다.

### 사용예
`div`안에서 `form`과 또다른 `div`가 있을 경우에 `form`으로 인하여 UI가 꺠지는 경우가 있었다.
이떄 `form`에 `style="dispaly: inline"`을 추가하니 UI가 꺠지지 않고 정상적으로 나왔었다. 

## 출처
[ofcourse](https://ofcourse.kr/css-course/display-%EC%86%8D%EC%84%B1)

## 보강 자료
[지구별 안내서](http://aboooks.tistory.com/85)