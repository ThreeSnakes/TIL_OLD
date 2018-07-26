# URL encode/decode 함수 종류 및 설명

URL을 인코딩 하는 함수에 대해서 정리.

## escape
- USE
    ```escpae(str)```
- 설명
    - 문자열의 각 문자들을 `%16진수 코드값`으로 변경
    - 1바이트 문자는 `%XX` 형태로 변경
    - 일반적으로 한글이 깨지는 것을 방지하기 위해 사용
    - 한글, 한자등(2바이트)는 `%u16진수4자리`로 변경
    - 영문 알파벳과, 숫자, 일부 특수문자(`@`, `*`, `-`, `_`, `+`, `.`, `/`)를 제외 문자만  인코딩

## unescape
- USE
    ```unescape("%16진수 코드값")```
- 설명
    - 코드 값에 맞는 문자로 변경(`escape` 함수의 반대로 생각하자.)

## encodeURI
- USE
    ```encodeURI(url)```
- 설명
    - 인터넷 주소에 사용되는 일부 특수문자(`:`, `;`, `/`, `=`, `?`, `&` 등)를 제외 문자만 인코딩한다.

## decodeURI
- USE
    ```decodeURI(url)```
- 설명
    - encodeURI로 인코딩한 값을 되돌린다.

## encodeURIComponent
- USE
    ```encodeURIComponent(url)```
- 설명
    - encdoeURI가 제외하는 특수문자도 인코딩
    - URL전체가 파라미터로 전송될 경우 사용가능

## decodeURIComponent
- USE
    ```decodeURIComponent(url)```
- 설명
    - encodeURIComponent로 인코딩한 값을 다시 원래대로 되돌린다.  