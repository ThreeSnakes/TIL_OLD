# subtree 사용시 child 프로젝트에서 다른 branch가져오기.

현재 AWS `코드 디플로이`를 일부 프로젝트에 진행 중에 있는데 해당 프로젝트가 `Subtree`로 구성 되었있다. 일단 현재 `Subtree` 구조를 간략하게 보면 다음처럼 되어 있다.

```
가(Parent Project) ___ master 브런치 ___ A(child Project_1) master 브런치로 구성.
                                  |___ B(child Project_2) master 브런치로 구성.
                                  |___ C(child Project_3) master 브런치로 구성.
                                  |___ D(child Project_4) master 브런치로 구성.
```

왜 이렇게 구성 되어 있냐면 `B`, `C`, `D` 가 다른 프로젝트에서도 쓰이는 공통 모듈이다. `가` 를 돌리기
위해서는 `A` 프로젝트와 공통 모듈인 `B`, `C`, `D`를 모두 포함 해야 하기 때문이다. 
하여튼 현재 `가` 프로젝트의 `mater`브런치는 각각의 모듈에서 `master` 브런치를 땡겨와서 개발 서버로 구동하고 있다. 근데 이제 운영에서도 적용 하기 위해서 `가` 프로젝트에서 `release`브런치를 만들고  각각의 모듈에서 `release` 브런치를 땡겨와야 한다. 목표는 아래 모습처럼 되는게 목표다.

```
가(Parent Project) ___ master 브런치 __ A(child Project_1) master 브런치로 구성.
                   |             |___ B(child Project_2) master 브런치로 구성.
                   |             |___ C(child Project_3) master 브런치로 구성.
                   |             |___ D(child Project_4) master 브런치로 구성.
                   |
                   --- relese 브런치____ A(child Project_1) release 브런치로 구성.
                                  |____ B(child Project_2) release 브런치로 구성.
                                  |____ C(child Project_2) release 브런치로 구성.
                                  |____ D(child Project_2) release 브런치로 구성.
```

`가` 프로젝트에서 개별 브런치는 각각 `child Project`에서 다른 브런치로 구성 해야 하는 것이다. 처음에 `master` 브런치에서 새로운 브런치를 생성하다 보니 `master` 브런치의 코드가 섞여 있어서 빈 브런치를 만든다음 `git subtree pull --prefix=A A release` 형태로 땡겨와야 하나 헀는데 전혀 변하는게 없었다. 그래서 알아보니 그냥 새로운 브런치를 딴 후에 기존 `child Project`의 코드를 삭제한 후에 `child Project`의 새로운 브런치(`releae 브런치`)에서 `git subtree add --prefix=A A release` 추가 해주면 된다.

명령어로 간단히 보자.
``` bash
$ git checkout -b release ## release 브런치를 새로 딴다.

$ git checkout release ## release 브런치로 체크아웃.

$ rm -rf ./System ## System 디렉토리 안에 subtree의 child 프로젝트가 있었다. 이를 다 삭제해 준다.

$ git commit ## 삭제한뒤 commit 한다. 그래야 새로운 subtree 가 add 되는듯 하다.

$ git subtree add --prefix=System/A A release ## subtree의 child를 새로 등록해준다.

$ git subtree add --prefix=System/B B release ## subtree의 child를 새로 등록해준다.

$ git subtree add --prefix=System/C C release ## subtree의 child를 새로 등록해준다.

$ git subtree add --prefix=System/C C release ## subtree의 child를 새로 등록해준다.

$ git push origin release ## release에 변경 사항을 push한다.

## 이제 master와 release 브런치의 코드 상태를 비교해봐서 잘 가져왔는지 체크한다. 
```
