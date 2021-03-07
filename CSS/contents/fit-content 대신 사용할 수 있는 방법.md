# fit-content 대신 사용할 수 있는 방법

## 문제점
div의 특정 영역의 width를 div 안에 있는 엘리먼트의 너비 만큼만 설정하고 싶은 경우 **max-width**, **width**에 **fit-content**를 설정하면 된다. 하지만 이 방법의 경우 **IE**에서 지원을 하지 않는다. 

이럴때는 `display: table` 을 사용하면 간단하게 해결 된다.