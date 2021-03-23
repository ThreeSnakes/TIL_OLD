# 사내 웹 성능 개선 Study

- [2021_03_08](사내%20웹%20성능%20개선%20Study/contents/2021_03_08.md)
	- 브라우저가 HTML 코드 중 `<script>`, `<link rel="stylesheet">` 태그를 만났을 때 다음 태그들을 처리하기 전까지 하는 일
	- defer와 async attribute는 어떤 역할을 할까?
	- `<script>`가 `<head>`에 들어가면 왜 안좋을까?
	- `<link rel="stylesheet">`에 media attribute를 넣는게 왜 좋을까
- [2021_03_15](contents/2021_03_15.md)
	- jpg/gif/png 등 웹에서 쓸 수 있는 다양한 포맷. 어느 상황에 어떤 포맷이 적절할까?
	- webp/avif 등 비교적 최근에 등장한 이미지 포맷은 어떻게 활용해야 할까?
  - vector image(ex: SVG)란? 어떤 경우 좋을까?
	- img의 srcset, sizes attribute는 어떤 역할을 할까? (문서 내의 https://web.dev/serve-responsive-images/ 참고)
	- Image CDN이란?
- [2021_03_22](contents/2021_03_22.md)
	- Image CDN이란?
	- JPG의 Compression Level, HTTP 응답 크기 줄이기 (이미지 크기 최소화)
	- `<picture>` element, srcset과의 차이점
	- HTTP 응답 크기 줄이기 (CSS)
	- HTTP 응답 크기 줄이기 (JS)