# apiDocJs

apiDocJs을 사용하면서 기억해야하거나 다시 찾을때 사용할 것들을 저장해 놓은 곳.

회사에서 서버단을 계속 작업 하다 보니깐 API의 문서화가 필요해서 쉽게 하는 방법을 찾아 보았었다.
Jin이 추천해준 것이 `Swagger`였는데 이게 은근 사용하는게 까다롭고 불편 했다.
사용해보려고 시도해보다가 `npm`이 날라가기도 헀고 ( -_-? 왜날라갔지) 해서 짜증나서 그냥 `apiDocJs`로 수행했다.
`Swagger`보다는 기능이 적긴 하지만 사용이 더 간편했고 보기에도 괜찮아 보였다.

## 설치
``` bash
$ npm install apidoc -g 
# CLI를 사용하기 위해서는 전역 설치를 해줘야 한다.
```

## 사용
### 1. apidoc.json 추가. 
먼저 apidoc을 만들 프로젝트의 루트로 가서 `apidoc.json`을 추가 해준다. 내용은 간단한데 `apidoc`에 대표 내용과 같은 것이다. 
``` JS
{
	"name": "FINGER MD API DOC",
	"version": "0.0.0",
	"description": "Finger MD Api Documentation",
	"url": "localhost:3000",
	"order": [
		"adproduct",
		"brand",
		"category",
		"group",
		"index",
		"info",
		"inven",
		"job",
		"point",
		"product",
		"tags",
		"tc"
	]
}
```
### 2. app.js에 router 추가.
개발 서버에서만 해당 API 페이지를 보여줄것이기 때문에 아래처럼 코딩 하였다. 별로 좋은 코드는 아닌것처럼 보이지만 개발서버에서만 사용하니 그냥 사용하였다.
`apiDoc`을 Run 시키면 localhost:3000/doc 에 문서 페이지가 route 되는것을 볼수 있다. 
``` JS
if (app.get('env') === 'development') {
  app.use('/doc', express.static('apidoc'));
}
```

### 3. 코드에 주석으로 doc을 만들자.
밑에 처럼 api위에 주석으로 달면 된다. 그러면 화면으로 만들어 준다.
``` JS
/**
 * @api {get} /inven/list/:program_id& 상품 조회 API
 * @apiName getInventoryList
 * @apiGroup inven
 * @apiVersion 0.0.0
 * @apiDescription 포인트 등록 화면에서 오른쪽 상품탭에 표시할 아이템을 조회하는 API이다.
 * 
 * @apiParam {String} program_id 프로그램의 유니크 아이디
 * @apiParam {String} keyword 검색시 찾을 데이터
 * @apiParam {String} date_type 등록날짜(product) or 수정날짜(work) 선택. 
 * @apiParam {String} from 검색 시작 날짜 YYYY.MM.DD 형식, 전체 검색일 경우 ALL
 * @apiParam {String} to 검색 종료 날짜 YYYY.MM.DD 형식, 전체 검색일 경우 ALL
 * @apiParam {String} main_category 메인 카테고리 유니크 코드값, 전체 검색일 경우 ALL
 * @apiParam {String} sub_category 서브 카테고리 유니크 코드값, 전체 검색일 경우 ALL
 * @apiParam {Number} page 검색 시작 페이지 번호. 
 * 
 * @apiParamExample {json} Request-Example: 
 *  {
 *      "program_id": "S01_V0000330171",
 *      "keyword": "",
 *      "date_type": "product",
 *      "from": "ALL",
 *      "to": "ALL",
 *      "main_category": "ALL",
 *      "sub_category": "ALL",
 *      "page": "0"
 *  }
 * 
 * @apiSuccessExample {json} Success-Respoonse:
 *  HTTP/1.1 200 OK
 *  {
 *      {
 *          "code": 200,
 *          "msg": "OK",
 *          "paging": {
 *              "page": 0,
 *              "row_count": 3,
 *              "total_page": 0,
 *              "row_per_page": 20,
 *              "page_per_list": 10,
 *              "start_page": 0,
 *              "end_page": 0,
 *              "start": 0,
 *              "next": 0,
 *              "prev": 0
 *          }
 *      }
 *  }
 */
```

### 4. apiDoc Run
주석으로 apiDoc을 만들었으면 해당 프로젝트에서 다음 명령어를 실행 시킨다.
``` bash
$ apidoc -i routes/ -o apidoc/
# apidoc -i [주석이 달린 폴더] -o [생성할 폴더 위치]
```
이 명령어를 입력 하면 문서가 html로 생성된다.

## 기본 포맷 저장
api를 입력 할 떄마다 일일이 칠순 없으니 포맷을 저장해 놓자. 밑에 말고도 더 들어 갈순 있으나 시간이 너무 오래 걸릴꺼 같다. 일단 이거라도 추가해놓자.
``` JS
/**
 * @api {get} /inven/list/:program_id& 상품 조회 API
 * @apiName getInventoryList
 * @apiGroup inven
 * @apiVersion 0.0.0
 * @apiDescription 포인트 등록 화면에서 오른쪽 상품탭에 표시할 아이템을 조회하는 API이다.
 * 
 * @apiParam {String} program_id 프로그램의 유니크 아이디
 * 
 * @apiParamExample {json} Request-Example: 
 *  {
 *      "program_id": "S01_V0000330171",
 *  }
 * 
 * @apiSuccessExample {json} Success-Respoonse:
 *  HTTP/1.1 200 OK
 *  {
 *      {
 *          "code": 200,
 *      }
 *  }
 */
```
