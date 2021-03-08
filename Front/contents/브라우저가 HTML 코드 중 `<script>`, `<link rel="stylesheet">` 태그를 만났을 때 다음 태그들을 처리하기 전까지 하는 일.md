# 브라우저가 HTML 코드 중 `<script>`, `<link rel="stylesheet">` 태그를 만났을 때 다음 태그들을 처리하기 전까지 하는 일

- 브라우저가 페이지를 렌더링 하려면 먼저 HTML 마크업을 파싱하여 DOM을 빌드하고, CSS도 CSSOM트리를 구성한다.
- DOM트리와 CSSOM트리를 구성하여 렌더트리를 생성한다.
- 렌더트리의 요소들을 배치한다.
- 렌더트리를 순회하면서 각 노드들을 paint()를 호출해 UI를 화면에 그린다.
- 만약 중간에 script나 link 태그를 만나게 되면 파서를 차단하고 해당 파일을 가져온다. 이 파일을 가져오다 보니 HTTP 요청이 들어가고 해당 시간만큼 렌더링이 늦어진다.
- JS와 CSS는 렌더링 차단 리소스이다. 

- 군우님 추가 설명
	- Script는 src가 있을 경우 외부, 없으면 inline Script.
		- inline Script의 경우 안에 있는 자바스크립트를 해석하고 실행한다. 자바스크립트는 싱글쓰레드라 해석, 실행하는 동안 브라우저는 아무것도 못한다.
		- src가 있는 경우에는 다운로드 하는 것도 들어가기 때문에 시간이 더 소요된다.
	- style시트도 마찬가지이다. 
	- Script는 parse를 블로킹하고, stylesheet는 렌더링을 블록한다.
- 관련 문서
	- https://developers.google.com/web/fundamentals/performance/critical-rendering-path/adding-interactivity-with-javascript
	- https://yceffort.kr/2020/07/critical-rendering-path

#Front