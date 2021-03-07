# 블랙홀 (/dev/null)

`codebuild`에서 빌드할때 로그가 죄다 `cloudwatch` 로그로 발생해서 이를 수정해달라는 요청이 왔다.

평소에 쓰기는 하지만 정확히 어떤것을 하는 넘이지 잘 몰라서 이를 알아보자. 

```
널장치 또는 널 디바이스는 운영체제에서 기록 대상이 되는 모든 데이터를 버리지만 쓰기 작업은 성공했다고 보고하는 장치 파일.
유닉스나 유닉스 계열 운영체제에서는 /dev/null이라고 불리운다. 
프로그래머들 사이에서는 비트 버킷 또는 블랙홀로 불리운다.
```
일단 자바 소스 코드중에 다음 코드가 있다.
``` bash
java -classpath ${CLASSPATH} com.ar.finger.tracker.main.Server > /dev/null &
```
뭐 해석하면 자바 컴파일 하는데 이때 발생하는 로그를 /dev/null로 보낸 다는 것이다.
즉 위에 쓰기 작업은 성공 헀다고 나오지만 실제로는 로그를 보지 않는것과 마찬가지이다.
또다른 예를 보면..
``` bash
npm install --production > /dev/null  ## npm install시 결과 안봄.
markoc . > /dev/null ## 마르코 컴파일 결과 안봄.
```
이정도로 이해 하면 될듯 하다. 

*참조*
- [위키백과:널 장치](https://ko.wikipedia.org/wiki/%EB%84%90_%EC%9E%A5%EC%B9%98)