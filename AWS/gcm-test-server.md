# AWS GCM Test Sever.
-
GCM Server Test 용으로 Setting 한것을 정리한 문서이다.

1. putty로 접속.
  - putty로 접속하기 위해서는 puttygen으로 ppk key를 만들어야 한다. 만드는 방법으 뭐 쉬우니깐 따로 적진 않겠다.
  - AWS 실행할때 `Security Group`에서 `inbound` `80포트` 열어주는거 잊지 말자. ! 
2. ubuntu 14.04 Setting.
  - `sudo apt-get update` 진행.
  - `sudo apt-get upgrade` 진행.
  - `vim` 설치 및 셋팅. [리눅스 setting](https://github.com/jonathan-lim/TIL/blob/master/Linux/1.%20Linux%20Setting.md) 참고하자. 
  
3. node.js 설치 및 setting.
  - [nodesource](https://github.com/nodesource/distributions) 접속하면 설치 방법 자세히 설명 되있다.
  - `sudo apt-get install curl` => `curl` 설치 하자. aws ubuntu14.04에는 이미 설치 되어있다.
  - `curl -sL https://deb.nodesource.com/setup_6.x | sudo -E bash -` 입력. => 알아서 진행됨.
  - `apt-get install -y nodejs` 으로 `nodejs`설치 진행.
  - 설치가 완료되면 `nodejs`와 `npm` 설치 완료 된다. 이후부터는 `npm`으로 모듈 다운로드가 가능하다.
  - `sudo npm install fs`, `sudo npm install node-gcm` 설치하고 아래 코드로 파일 만들자.
  ```
  var gcm = require('node-gcm');
  var fs = require('fs');

  var message = new gcm.Message();

  var message = new gcm.Message({
    collapseKey: 'demo',
    delayWhileIdle: true,
    timeToLive: 3,
    data: {
        title: 'saltfactory GCM demo',
        message: 'Google Cloud Messaging 테스트’,
        custom_key1: 'custom data1',
        custom_key2: 'custom data2'
    } 
  });

  var server_api_key = ‘GCM 앱을 등록할때 획득한 Server API Key’;
  var sender = new gcm.Sender(server_api_key);
  var registrationIds = [];

  var token = ‘Android 디바이스에서 Instance ID의 token’;
  registrationIds.push(token);

  sender.send(message, registrationIds, 4, function (err, result) {
    console.log(result);
  });
  ```
  > 위 코드는 다음 [블로그](http://blog.saltfactory.net/android/implement-push-service-via-gcm.html)에서 참고 했다. api_key는 google Develloper 에서 확인 가능하다. 
  
  - 입력 다했으면 `sudo node gcm_provider.js`로 실행하자. 
