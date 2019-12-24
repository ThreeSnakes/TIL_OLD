# HTTP METHOD

허허허허허. 월 목표를 하면서 **DELETE** method에 **payload**를 넣어서 보내도록 코드를 작성했는데... **DELETE Method는 payload를 지원하지 않는다.** 정리 하는 김에 HTTP Method에 대해서 간단히 정리한 표를 찾았는데 이를 정리 한다. 일전에 rest-api 정리하면서 공부 했던거 같은데 기억을 못하네..

## HTTP Method 간단 정리

|메소드|RFC|요청에 Body 유무|응답에 Body 유무|안전|멱등(Idempotent)|캐시 가능 여부|
|-----|---|--------------|--------------|---|----------------|-----------|
| GET | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 아니오 | 예 | 예 | 예 | 예 |
| HEAD | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 아니오 | 아니오 | 예 | 예 | 예 |
| POST | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 예 | 예 | 아니오 | 아니오 | 예 |
| PUT | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 예 | 예 | 아니오 | 예 | 아니오 |
| DELETE | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 아니오 | 예 | 아니오 | 예 | 아니오 |
| CONNECT | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 예 | 예 | 아니오 | 아니오 | 아니오 |
| OPTION | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 선택 사항 | 예 | 예 | 예 | 아니오 |
| TRACE | [RFC 7231](https://tools.ietf.org/html/rfc7231) | 아니오 | 예 | 예 | 예 | 아니오 |
| PATCH | [RFC 5789](https://tools.ietf.org/html/rfc5789) | 예 | 예 | 아니오 | 아니오 | 예 |

- **멱등(Idempotent)**
  - 멱등의 의미는 같은 작업을 계속 반복해도 같은 결과가 나오는 것을 의미
  - 동일한 자원에 대해서 같은 요청을 반복하면 반환되는 모든 응답은 동일해야 한다는 것

- **참조**
  - [자바공작소](https://javaplant.tistory.com/18)