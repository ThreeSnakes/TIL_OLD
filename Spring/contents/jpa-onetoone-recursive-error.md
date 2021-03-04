# OneToOne Mapping 시 recursive Error

OneToOne 매핑시에 무환 참조에 빠져 에러가 발생하는 경우가 생겼다.

Response로 보내는 데이터는 다음처럼 나오고 -_-;;
``` json
[{"id":1379726,"videoId":38255,"createdAt":1525308589000,"updatedAt":1525308589000,"videoJob":{"id":1,"videoId":38255,"status":"onWork","createdAt":1526263200000,"updatedAt":1526263200000,"sceneGroup":{"id":1379726,"videoId":38255,"createdAt":1525308589000,"updatedAt":1525308589000,"videoJob":{"id":1,"videoId":38255,"status":"onWork","createdAt":1526263200000,"updatedAt":1526263200000,"sceneGroup":{"id":1379726,"videoId":38255,"createdAt":1525308589000,"updatedAt":1525308589000,"videoJob":{"id":1,"videoId":38255,"status":"onWork","createdAt":1526263200000,"updatedAt":1526263200000,"sceneGroup":{"id":1379726,"videoId":38255,"createdAt":1525308589000,"updatedAt":1525308589000,"videoJob":{"id":1,"videoId":38255,"status":"onWork","createdAt":1526263200000,"updatedAt":1526263200000,"sceneGroup": ..... 생략
```

실제 에러는 아래와 같다.
``` bash
2018-05-14 14:08:54 [WARN ] [DefaultHandlerExceptionResolver.java]handleHttpMessageNotWritable(407) : Failed to write HTTP message: org.springframework.http.converter.HttpMessageNotWritableException: Could not write JSON: Infinite recursion (StackOverflowError); nested exception is com.fasterxml.jackson.databind.JsonMappingException: Infinite recursion (StackOverflowError) (through reference chain: com.fingerplus.tracker.model.SceneGroup["videoJob"]->com.fingerplus.tracker.model.VideoJob["sceneGroup"]->com.fingerplus.tracker.model.SceneGroup["videoJob"]-> 생략......
```

왜 이런 현상이 발생했냐면 -_-;;
`sceneGroup Table`과 `videoJob Table`간 OneToOne 매핑을 연결을 한 상황이었다. 이상황에서 씬 그룹 조회시 videoJob row를 가져온다.
그런데 videoJob에서 sceneGroup으로 다시 원래 row를 가져오고 다시 videoJob row를 가져오고... 무한 반복된다 ㅡㅡ;

찾아보니깐 `@JsonBackReference`를 사용면 이슈가 해결된다 해서 일단 기록으로 남겨 놓는다.

``` java
// sceneGroup Table 
    @OneToOne(fetch = FetchType.LAZY, mappedBy = "sceneGroup")
    @JoinColumn(name = "id", referencedColumnName = "group_id")
    @JsonManagedReference // 자식 객체에 추가 해준다.
    private VideoJob videoJob;
    
// videoJob Table
    @OneToOne(fetch = FetchType.LAZY)
    @JoinColumn(name = "group_id")
    @JsonBackReference // 부모 객체에 추가 해준다.
    private SceneGroup sceneGroup;
```

`Spring JPA`, `ORM`에 대한 이해가 부족한 상황에서 일단 개발을 진행하려 하다 보니깐 적은 내용도 엉성하고, 이게 확실한 해결책인지도 엉성하다. 해당 부분은 코드 리뷰할때 맞는 것인지 요청 드려야 봐야 할것 같다. 

## 참조

- [ORM Jpa @ResponseBody 재귀 memory error [한글창제의 기쁨] ](http://mycup.tistory.com/222)