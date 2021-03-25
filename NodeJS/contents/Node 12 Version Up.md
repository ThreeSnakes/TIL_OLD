# Node 12 Version Up

사내 서버를 Node 12로 업데이트하면서 기록할만한 것들을 정리해 보았다.

1. node_modules 업데이트
	
	일단 기존 설치된 node_modules 중에서 Node12를 지원하는 module로 upgrade가 필요한 몇가지 모듈이 있다.
	
	- gulp
		- Node 12에서는 3.X.X 가 지원하지 않는다. 4.X.X로 업데이트 필요.
	- iconv
		- Node 12를 지원하는 2.3.5 이상의 버전이 필요하다.
	- gulp-shell
		- 이 모듈은 npm 명령어를 gulp상에서 동작하기 위한 모듈인데 별로 필요가 없어서 삭제 하였다. 다음처럼 child_process를 이용하면 쉽게 구현이 가능하다.
		
			```js
			const exec = require('child_process').exec;
			
			function build_ts() {
				return exec('npm run build-ts');
			}
			```
			
	- run-sequence
		- 이 모듈은 gulp task를 순차적으로 돌리기 위한 모듈인데, gulp 4.X.X 에서는 사용이 불가능하다. 대신 gulp에서 자체 지원하는 `gulp.parallel()`,`gulp.series()` 함수를 사용하자.

2. gulp 파일 수정
	
	gulp 4.X.X 에서는 task를 쓰는 대신 module.exports를 사용하는 것을 권장한다. 그래서 기존에 `gulp.task('태스크명', () => {})` 로 작성된 코드를 전부 함수형태로 작성한뒤 export 하는 형태로 변경 하였다.
	
	```js
	// 이전 버전
	gulp.task( 'clean', (cb) => {
		del.sync(`dist/**/*`);
		cb();
	});
	
	// 4.X.X 버전
	async function clean() {
		return await del([`dist/**/*`]);
	}
	
	moeuls.exports = {
		clean
	}
	
	// 수정할 때 module이나 gulp 함수가 동기인지 비동기인지 확인하자. 처음에 쓸데없이 동기 함수에 async를 넣었었다.
	```