# `<link rel="stylesheet">`에 media attribute를 넣는게 왜 좋을까?

- 만약 media attribute를 넣지 않는 다면 모든 경우에 적용된다, 하지만 media attribute를 사용하게 된다면 특정 환경에서만 CSS가 적용될수 있다. 만약 특정환경에서만 동작하도록 media쿼리를 작성한다면 해당 환경에서만 CSS를 다운로드 받아서 진행하고, 해당 환경이 아닐 경우 렌더링이 차단되는 것을 막을 수 있는 것이다. 즉 필요할때만 CSS를 다운로드 받아서 사용할 수 있게 되는 것이다. 
	- 렌더링 트리에 필요한 것만 일단 다운로드 받아서 적용시키고, 나머지 CSS는 백그라운드에서 다운받아 놓고, 적용되는 경우에 사용된다고 한다.
	
	- 관련 문서
		- https://developers.google.com/web/fundamentals/performance/critical-rendering-path/render-blocking-css

#Front