# Rest API 조사

회사에서 이번달 Open Lab 발표로 `Rest API`를 조사하도록 되었다. `Rest API`가 무엇인지 알아보고 이를 토대로 발표를 해보자.

## Rest API란..?

Rest는 `Representational State Transfer`의 약자로 2000년도에 로이 필딩(Roy Fielding)의 박사 학위 논문인 `Architectural Styles and the Design of Network-based Software Architectures`에서 처음으로 소개 되었다. 여기서 로이 필딩은 HTTP의 주요 저자 중 한사람으로 웹(`HTTP`)을 창시한 사람중 한명입니다. `REST API`는 `SOA`와 달리 `자원지향구조(ROA: Resource Oriented Architecture)`로 웹사이트의 컨텐츠( Text, 이미지, 동영상 등), DB 결과물 등  웹의 모든 것을 하나의 자원으로 파악하여 각 자원의 고유한 `URI(Uniform Resource Identifier)`를 부여하고, 해당 자원에 대한 `CRUD(Create, Read, Update, Delete)` 작업을 HTTP의 기본 명령어인 `POST`, `GET`, `PUT`, `DELETE` 를 통해서 처리 하는 것을 말합니다.

## Method,CRUD,SQL 비교.

|Method|CRUD|SQL|역활|
|------|----|---|----|
|POST|Create|INSERT|POST로 해당 URI로 요청이 들어오면 데이터를 생성한다.|
|GET|Read|SELECT|GET으로 해당 URI로 요청이 들어오면 해당 자원을 조회한다.|
|PUT|Update|UPDATED|PUT으로 해당 URI로 요청이 들어오면 해당 자원을 수정한다.|
|DELETE|Delete|DELETE|DELETE으로 해당 URI로 요청이 들어오면 해당 자원을 삭제한다.|

## REST API 특징

### 1. Uniform (유니폼 인터페이스)

  Uniform Interface는 URI로 지정한 자원에 대한 조작을 통일되고 한정적인 인터페이스로 수행하는 설계 구조를 말합니다. 이로 인해서 개발자는 해당 API가 어떤 역활을 하는지 고민 할 필요 없이 직관적으로 알게 되며, 구현도 쉬워집니다.

### 2. Stateless (무상태성)

  상태를 갖지 않는다. 쉽게 말해서 상태관리를 위해서 세션이나 쿠키정보를 별도로 관리하지 않고 , 단순히 API를 통해서 들어오는 요청만을 처리 하는 것을 뜻합니다. 이는 컨텍스트 정보를 신경쓸 필요가 없어져 구현이 쉬워지며 설계또한 간단해지는 효과를 갖습니다.

### 3. Cacheable (캐시)

  캐시 기능, `REST API`는 `HTTP`라는 웹 표준을 그대로 사용하기 때문에, 웹에서 사용하는 기존 기능을 사용 할 수 있습니다. `Last-Modified` 태그 또는 `E-Tag`를 사용하면 캐싱 기능을 사용 할 수 있습니다. 캐싱 기능을 사용하면 서버에 트랜젝션을 발생 시키지 않기 때문에 응답시간 향상, 서버의 자원 사용률을 낮출수 있습니다.

### 4. Self-descriptiveness (자체 표현 구조 )

  API 자체만 보고도 해당 API가 어떤 역활을 하는지 직관적으로 알 수 있습니다.

### 5. Client - Server 구조

  `REST API`는 Clinet, Server의 각가의 역활이 명확하기 때문에 서로가 개발 해야 하는 내용이 명확해지며, 의존성이 줄어 들게 됩니다. Client는 사용자 인증 또는 컨택스트 관리등을 하며 Server는 API를 제공하고, 해당 API의 비즈니스 로직을 처리하는 역활을 맡게 됩니다.

### 6. 계층형 구조

  `REST API`에서 Server는 다중 계층으로 구성 될 수 있어 보안, 로드 밸런싱등을 추가해 구조의 유연성을 둘 수 있고, PROXY, GATEWAY 같은 네트워크 기반의 중간 매체를 사용할 수 있게 합니다.

## REST API 디자인 가이드

`REST API`를 설계할때 크게 고려해야 할점 두가지가 있다.

### 1. URI는 정보의 자원을 표현해야 한다.

### 2. 자원에 대한 행위는 HTTP Method(GET, POST, PUT, DELETE)로 표현한다.

- 여기서 `URI(Uniform Resource Identifier)`을 간단히 설명 하자면, 인터넷 상의 자원을 식별하기 위한 문자열의 집합(!?)이라고 할 수 있습니다. 즉 자원(텍스트, 동영상, 페이지, 사진 등등 인테넛에 모든 자원)을 식별 또는 표현하는 주소입니다.

  ``` text
  // REST API 기본 적인 사용 예.
  POST    http://localhost:3000/info/people/gildong // gildong이라는 사람을 생성한다.
  GET     http://localhost:3000/info/people/gildong // gildong이라는 사람정보를 가져온다.
  PUT     http://localhost:3000/info/people/gildong // gildong이라는 사람의 정보를 수정한다.
  DELETE  http://localhost:3000/info/people/gildong // gildong이라는 사람의 정보를 삭제한다.
  ```

  - 위 코드 처럼 REST API는 HTTP의 Method를 사용합니다. 그렇다면 URI 정보의 자원을 표현 한다라는 말은 무엇을 뜻하냐..?

  ``` text
  // 현재 개발하고 있는 서버에 있는 코드 중 일부 입니다.
  POST    http://localhost:3000/product/modify_info_point // modify_info_point 정보를 생성한다..?
  POST    http://localhost:3000/product/delete_music // delete_music 정보를 생성한다..?
  POST    http://localhost:3000/product/add_music // add_music 정보를 생성한다..?
  GET     http://localhost:3000/product/music // music 정보를 조회한다. (한개를 조회하는 것인가? 리스트를 조회하는 것인가.?)
  ```

  - 위 코드를 보면 무언가 이상하다. `POST` Method는 데이터를 삽입할 때 사용 하는 것인데 실제 로직과 다르다. 또한 `POST` 메소드로 수정, 삭제가 이루어지며 `POST`로 데이터를 추가 한다는 것이 명확한데 `post`라는 동사가 또 들어가 있습니다. `REST API`는 자원을 표현하는데 중점을 두어야 하며, `modify`, `delete`, `add`와 같은 행위에 대한 표현이 들어가서는 안됩니다. 이는 해당 API의 의미를 불명확하게 할 뿐만 아니라, 같은 표현의 중복이 될 수 있습니다. 그렇기 때문에 URI(자원)은 `동사`가 아닌 `명사`가 들어가야 합니다. 또한 명사를 사용할떄 `단수형` 보다는 `복수형`을 사용하는 것이 좋다고 합니다.

  ``` text
  // 위에 잘못된 내용을 바로 잡자면 아래처럼 될 것입니다. 
  POST  http://localhost:3000/product/music // music정보를 새로 생성한다.
  UPDATE  http://localhost:3000/product/info_point/{InfoId} // info_point정보 중 InfoId에 해당하는 데이터를 수정한다.
  DELETE  http://localhost:3000/product/music/{musicId} // music정보 중 musicId에 해당하는 데이터를 삭제한다.
  GET     http://localhost:3000/product/musics    // music 목록을 조회한다. 
  ```

## URI 설계시 주의 할점

1. 슬래시(/)는 계층관리를 나타낼때 사용한다.
2. URI 마지막 문자에 슬래시(/)는 포함하지 않는다.
3. 하이픈(-)은 URI 가독성을 높이는데 사용한다.
4. 밑줄(_)은 URI에 사용하지 않는다.
5. URI 경로에는 소문자만을 사용한다.
6. 파일 확장자는 URI에 포함시키지 않는다.

``` text
// 그러면 위에서 잘못된 URI도 다시 아래처럼 수정 될 수 있습니다. 
POST  http://localhost:3000/product/music // music정보를 새로 생성한다.
UPDATE  http://localhost:3000/product/info-point/{infoId} // info_point정보 중 3310번 데이터를 수정한다.
DELETE  http://localhost:3000/product/music/{musicId} // music정보 중 3310번 데이터를 삭제한다.
GET     http://localhost:3000/product/musics    // music 목록을 조회한다. 
```

## URI 설계시 자원간의 관계를 표현 하는 방법.

URI 자원간에는 서로 연간관계가 있을 수 있습니다. 예를 들면, MD사이트에서 인물과 해당 프로그램의 매칭 데이를 예로 들을 수 있습니다.

``` text
GET http://localhost:3000/info      // 인물 정보리스트틀 리턴합니다. (이것도 REST API 설계에는 잘못 되었습니다. http://localhost:3000/info/peoples 가 되야 맞겠지요.)
GET http://localhost:3000/program   // 프로그램 정보리스트를 리턴합니다.
GET http://localhost:3000/programDetail // 한 프로그램의 정보를 리턴합니다. (이것도 잘못 설계ㅠ.ㅜ http:localhost:3000/program/{program_id}가 되어야 하겠지요. ㅠ.ㅜ

// 프로그램은 여러개의 인물을 가질 수 있습니다. 이럴 경우에는
GET http://localhost:3000/program/{program_id}/peoples          // 해당 방송이 가지고 있는 인물 리스트를 조회할때.
GET http://localhost:3000/program/{program_id}/has/{peopleId}   // 해당 방송이 가지고 있는 특정 인물 하나를 조회할떄.

// 처럼 작성 할 수 있을 것입니다.
```

## HTTP 응답 상태 코드

`REST API` 설계시 응답의 상태코드도 정확히 설계되어 있어야 합니다. 복잡한 응답 메세지보다는 간단한 응답 코드가 더 명확한 정보를 내려주기 때문입니다. 일반적으로 사용하는 응답코드만을 정리하였습니다.

### 성공 상태 코드

|상태코드|설명|
|--------|----|
|200|클라이언트의 요청을 정상적으로 수행|
|201|클라이언트의 리소스 생성 요청을 정상적으로 수행|

### 실패 상태 코드

|상태코드|설명|
|--------|----|
|400|클라이언트가 잘못된 요청을 하였을때. |
|401|권한이 없을 경우. EX) 로그인이 필요한 페이지에 로그인을 하지 않고 접근 했을 경우 |
|403|금지. 클라인트의 요청을 금지 할 때. EX) 상위 권한이 필요한 페이지에 접근 했을 경우 |
|404|클라이언트가 요청한 자원이 존재하지 않을 경우|
|405|해당 자원에 해당하지 않는 Method를 요청했을 경우|
|500|서버 내부 오류|
|501|서버에 요청을 수행할 수 없는 기능일 경우 EX) 클라이언트의 요청 메소드를 구현 하지 않았을 경우|

## GraphQL

`facebook`에서 만든 어플리케이션 레이어 쿼리 언어 이다. 말이 복잡한데 간단히 설명하자면 `서버-클라이언트간의 api를 위한 쿼리 언어`라고 할 수 있다.
만약 클라이언트에서 어떤 추가 데이터가 필요 하다면 서버 개발자에게 해당 데이터추가 요청을 해야 하며, 서버개발자는 그에 맞게 다시 API를 수정해야 한다. 결국 `REST API`는 일종의 약속으로 추가적인 데이터가 필요 한다든가, 다른 데이터가 필요하다면 이를 위해서 클라이언트, 서버 모두 수정이 필요하며 해당 API의 문서또한 수정해야 합니다. 하지만 `GraphQL`을 사용하면 이러한 문제를 조금이나마 해소 할 수 있다고 한다.

### 장단점

- 장점
  - 단일 요청으로 원하는 데이터를 한번에 가져올 수 있다.
  - Type시스템을 지원한다.
  - 확장이 용이하다.
- 단점
  - 러닝커브가 있다.
  - GraphQL의 type을 정의한 코드, mutation을 정의한 코드가 추가되면서 단순한 App에서는 코드가 더 복잡해진다.

### 사용 예

IM사이트에서 인물정보를 검색한다고 가정 하면 요청은 다음처럼 해야 합니다.

``` text
GET http://localhost:3000/info/people/{peopleId}

{
    "contentdata": {
        "result": [
            {
                "id": 3889,
                "image_id": 4181,
                "name": "여진구",
                "birth": "1988-07-22T14:00:00.000Z",
                "agency": null,
                "url1": null,
                "url2": null,
                "url3": null,
                "gender": "M"
            }
        ],
    }
}

```

위에는 이미 API로 딱 정해져 있는 것입니다. 해당 API로 요청이 들어오면 비지니스 로직을 타서 위 데이터를 내려주도록 설계가 된것입니다. 만약에 저기서 해당 인물이 매핑된 프로그램의 리스트도 필요하다면 이는 서버 개발자가 이를 수정하고 클라이언트 개발자가 이를 받아서 다시 알맞게 수정해야 하며 마지막엔 해당 API 문서도 수정해야 됩니다. 하지만 `GraphQL`을 사용 한다고 가정하면 다음처럼 쓸수 있을 것입니다.

``` text
query {
    people(id: "3889") {
        id,
        image_id,
        name,
        birth,
        agency,
        url1,
        url2,
        url3,
        gender
    }
}

{
    "data": {
        "people": {
            "id": 3889,
            "image_id": 4181,
            "name": "여진구",
            "birth": "1988-07-22T14:00:00.000Z",
            "agency": null,
            "url1": null,
            "url2": null,
            "url3": null,
            "gender": "M"
        }
    }
}
```

위에 문장처럼 데이터를 전송 하게 되면 아래처럼 응답 데이터를 받을수 있습니다. 그렇다면 만약에 name필드가 필요 없으면..? 어떻게 하느냐..? 클라이언트에서 서버로 데이터를 전송할때 name필드만 지우면 됩니다. 그러면 name 필드가 응답데이터에는 오지 않는 것입니다.

### 활용예

현재 IM사이트에서 상품등록 프로세스에서는 엄청나게 많은 API를 호출 하고 있습니다.

1. 인벤토리 목록 호출. - 1개
2. 4대정보 호출(인물, 장소, 음악, 음식) - 4개.
3. 협찬 정보 호출. - 1개
4. 브랜드 정보 호출 - 1개
.... 등 거의 10개에 가까운 API 호출이 이루어집니다. 이를 `GraphQL`을 사용한다면 필요한 데이터만을 호출 하면 된다.

``` text
// REST API
GET http://localhost:3000/info/people
GET http://localhost:3000/info/food
GET http://localhost:3000/info/place
GET http://localhost:3000/info/music
GET http://localhost:3000/adprodct/
GET http://localhost:3000/brand/
```

``` text
// GraphQL
query {
    pelples {
    ... 생략 ...
    },
    foods {
    ... 생략 ...
    },
    places {
    ... 생략 ...
    },
    musics {
    ... 생략 ...
    },
    adproducts {
    ... 생략 ...
    },
    brand{
    ... 생략 ...
    },
}
```
