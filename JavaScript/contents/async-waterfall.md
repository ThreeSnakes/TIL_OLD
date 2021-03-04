# Async Module waterfall Method

Async 모듈은 node.js 에서 순차 실행을 도와주는 모듈이다.
여러가지 method가 있는데 그중에 일단 waterfall을 정리해본다.

```JS
var async = require('async');

findListByKeyword : function(paging, keyword) {
		return new Promise(function(resolve, reject) {
			async.waterfall([
				function(callback) {
                	// 첫번째 수행되어야 할 함수 내용 작성.
                    callback(null, arg1)
				},
				function(arg1, callback) {
                	// 두번째 수행되어야 할 함수 내용 작성.
                    callback(null, arg2, arg3)
				},
				function(arg2, arg3, callback) {
                	// 세번째 수행되어야 할 함수 내용 작성.
                    callback(null, arg4, arg5)
				},
				function(arg4, arg5, callback) {
                	// 네번째 수행되어야 할 함수 내용 작성.
                    callback(null, arg6)
				},
                function(arg6, callback) {
					// 5번쨰 수행되어야 할 함수 내용 작성.
                    callback(null, arg6)
				}
			], function(arg6, result) {
					// 마지막으로 수행되어야 할 함수 내용 작성.
			});
		}).catch(function(err) {
			throw(err);
		});
	},
```

async.waterfall([순차적으로 수행되어야할 함수를 차례대로 삽입], 마지막으로 수행되어야 할 함수) 로 작성하면 된다. 