# [Module] NVM 이용해서 Node 버전 올리기

마찬가지로 Node Version을 변경하는 방법이 한가지 더 있다.

`nvm` 즉 , `Node Version Manager`를 이용해서 하는 방법이다. [NVM 링크](https://github.com/creationix/nvm)

`n 모듈`이랑은 약간 성격이 다른듯 하다. 

일단 `nvm`으로 설치시 전역 모듈위치가 변경되서 다시 설치해줘야 한다.

무슨 말이냐 하면 `nvm` 으로 `node 6.10.0`을 설치한뒤 환경을 `6.10.0`으로 변경하면

`6.10.0`에 쓰일 전역 모듈을 다시 설치해줘야 한다. 즉 버전별로 전역 모듈을 다시 설치해줘야 한다.

`n` 같은 경우에는 이럴 필요가 없었는데 `nvm` 같은 경우 전역 모듈이 저장되는 위치가 변경 된다. 

``` bash
/usr/local/lib/node_modules # 원래 전역 모듈이 설치 되는 곳.

/Users/Limchanghyeon/.nvm/versions/node/v6.10.0/lib # nvm 설치 후
```

이렇게 기존 node에서 쓰이는 전역 모듈 위치와 `nvm`을 이용해서 쓸때 전역 모듈 위치가 완전 변경되어 버린다.

하여튼 차이점은 더 있겠으나 내가 쓰면서 가장 크게 바뀐점은 위와 같은 것 같다.

그러면 사용법을 알아보자.

## 설치 방법.

``` bash
curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.6/install.sh | bash
```
로 설치 한 다음에

`~/.bash_profile`, 만약 `zshrc`를 쓴다면 에 다음 코드를 추가해준다.

```
export NVM_DIR="$HOME/.nvm"
[ -s "$NVM_DIR/nvm.sh" ] && . "$NVM_DIR/nvm.sh" # This loads nvm
```

다만 `nvm` 홈페이지 `zshrc`에도 추가하라고 되어 있긴 한데 따로 추가가 되어있어 추가하진 않았고

`~/.bash_profile`에만 추가해줬다.

## 사용 방법.
``` bash
#### 여기서 부터 차례대로 하자 ####
# nvm 설치.
$ curl -o- https://raw.githubusercontent.com/creationix/nvm/v0.33.6/install.sh | bash

# 명령어 실행(!?) 무슨 역활인지 확인은 안해봤다. 
$ . ~/.nvm/nvm.sh

# nvm 설치 확인
$ nvm

# node 버전별 설치.
$ nvm install [ node version ]  # ex) nvm install 6.10.0

# 설치된 Node 버전 확인.
$ nvm ls

$ nvm alias default system # ex ) nvm alias default 6.10.0

# 이제 전역 모듈을 다시 설치해주자 ㅠㅠㅠㅠ

#### 여기까지만 차례대로 ####

# nvm 체크
$ nvm ls

# node 버전 체크
$ node -v

# node 버전 교체
$ nvm use [ node version ]  # ex) nvm use 6.10.0

# node 버전 삭제
$ nvm uninstall [ node version ] $ ex) nvm uninstall 6.10.0
```


