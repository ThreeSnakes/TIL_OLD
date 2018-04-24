# Bunyan
bunyan을 사용하면서 기억해야하거나 다시 찾을때 사용할 것들을 저장해 놓은 곳.

## 설치
``` bash
npm install bunyan 
npm install -g bunyan #CLI를 쓰기 위해서는 전역 설치를 해야 한다. 전역 설치를 하지 않을 경우 shell 명령어를 이용하지 못한다. 
```

## 사용
``` js
// hi.js
var bunyan = require('bunyan');
var log = bunyan.createLogger({name: 'myapp'});
log.info('hi');
log.warn({lang: 'fr'}, 'au revoir');
```

## log Level
- `fatal`
    - 서비스/앱이 정지하거나 당장 쓸수 없을때 사용.  
- `error`
    - 특정 요청이 심각할때, 하지만 서비스/앱은 다른 요청에 대해서 지속적으로 사용할수 있을때 사용.
- `warn`
    - 운영자가 꼭 봐야하는 로그를 기록할때 사용.   
- `info`
    - 일반적인 요청에대한 상세 설명. 
- `debug`
    - 어떤 것이든 사용... 그냥 쓰면 된다.   
- `trace`
    - 외부 라이브러리에서 사용하거나 상세한 로그를 남길때 사용하면 된다. 

## npm 시작시 short으로 보기.
``` bash
npm start | bunyan -o short
```

## 실시간 로그 보기.
``` bash
tail -f 로그파일 | bunyan -o short 
```

## 로그파일에서 데이터 찾기.
``` bash
grep -n "찾을 데이터" 로그파일
```