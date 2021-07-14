# Git Subtree 조사
IM Site CI&CD 적용을 위해서 우선적으로 Git Subtree를 조사한다.

## Git Submodule
현재 `FingerProject`에서 쓰이고 있는 방식. Git 저장소 안에 또 다른 저장소가 들어가 있는 개념이다.
원래 `FingerProject`안에는 `FingerWeb`, `FingerMD`... 등 약 30개의 저장소가 들어 있다. 맨처음 입사했을때는 이를 하나의 저장소로 쓰고 있었는데 이를 `submodule`형태로 나눈것이다. 

여기서 `FingerProject`는 *슈퍼프로젝트*가 되는 것이고 `FingerWeb`, `FingerMD`등은 `submodule`이 되는것이다.

## Git Subtree.?
`Subtree`는 한 저장소가 여러 저장소를 통합하는 개념이다(?). 어떻게 보면 `submodule`과 반대 되는 개념 같은데 `submodule`은 큰 프로젝트를 여러개의 프로젝트로 나누는 것이고, `subtree`는 여러개의 프로젝트를 하나로 합치는 것이다. 결과로 보면 프로젝안에 여러 프로젝트가 있는 것이므로 똑같은데 차이점이 조금 있다. 밑에서 계속 설명.

## Git Subtree VS Submodule
[스택오버플로우](https://stackoverflow.com/questions/31769820/differences-between-git-submodule-and-subtree)에서 같은 질문이 있다.
내용을 요약 하면 다음과 같다.

- `Submoule`
    - `Submodule`은 CBD(component-based development)에 적합한 모델이며, 메인 프로젝트는 다른 컴포넌트들에 의존적이다.
    - `Submodule`은 링크이다.
    - `Submoudle`은 저장소를 여러개의 작은 저장소로 나눌떄 사용한다. 만약 서브 모듈에서 변경을 한다면 서브 모듈 안에서 커밋/푸쉬를 한 후에 메인 저장소(슈퍼프로젝트)에서 한번 더 커밋/푸쉬를 해야 한다. 
    
- `Subtree`
    - `Subtree`는 SBD(system-based development)에 더욱 가까우며, 모든 저장소는 모든것을 포함하고 있으며 각 부분을 수정 가능하다.
    - `Subtree` copy이다.(?)
    - `Subtree`를 사용하면 다른 저장소를 하나의 저장소로 이력과 함께 통합할수 있다. 통합을 하게 된다면 저장소의 크기는 커지지만 코드와 이력을 재사용하기에는 더욱 좋습니다. 결국 히스토리를 관리하기에 좋다.
        
## `subtree` 추가 방법
``` bash
#1. test directory 생성 후 이동.
mkdir test
cd test

#2. git clone.
git clone [git 주소]

#3. 현재 프로젝트에 git remote 추가. 
git remote add [단축이름(저장소 명)] [URL(저장소URL)]

# 원격 저장소가 추가 되었는지 확인 해보자.
git remote -v

#4. subtree 명령어로 subtree 추가. 
git subtree add --prefix=[로컬 디렉토리명] [저장소 명] [child에서 pull할 branch명]

#5. child tracking branch 생성.
git checkout --treac [저장소명][브런치명] -b [새로 사용한 브런치명]
# git checkout -b [브런치명] [원격 저장소명]/[브런치명] ==> 이건 쓰지 말자.
# 위 옵션으로 만든 브런치에서 pull/push를 하면 해당 원래의 저장소에 데이터를 보내거나 가져온다.
# push 할때 잘 보자. 아무생각 없이 git push origin master 하지말고
# git push [저장소명][브런치명] [새로 사용한 브런치명] 으로 하자. 잘못쓰면 원래 child project에서 브런치 하나 더생긴다. -_-;;
# 이것때문에 헷갈려서 고생함.
```

## subtree branch 구성 예시.
- `master` branch로 체크 아웃하고 `ls -al` 할 경우.
![master branch](https://github.com/select995/TIL/blob/master/tmp/img/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-07-13%20%EC%98%A4%ED%9B%84%206.07.01.png)

- `blog` branch로 체크 아웃하고 `ls -al` 할 경우.
![blog branch](https://github.com/select995/TIL/blob/master/tmp/img/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202017-07-13%20%EC%98%A4%ED%9B%84%206.09.37.png)
위에서 보다시피 `checkout` 한 브런치에 따라서 보이는 파일이 달라진다. 

## subtree push/pull 방법. 
기존에 있던 브런치를 master(parent), subtree(child)로 추가한 브런치를 blog라고 하자. 만약 master 브런치에서 작업을 하고 push를 한다면 master branch에서는 반영이 되지만 blog 브런치에서는 반영이 안되있다. 이럴때 사용하는 것이 subtree push 명령어이다. 

### parent에서의 방법.
parent는 일반적인 git pull, git push 사용하면 된다.
``` bash
git pull origin master
```

### child에서의 방법.
child는 어떻게 보면 전혀 별개의 프로젝트이다. 결국 원격에 있는 리모트 저장소와 데이터 싱크를 맞추려면 `subtree push, pull` 명령어를 써야 한다. `--prefix=[로컬 디렉토리명] [저장소 명칭] [저장소 branch] `을 기억해야 하는것을 잊지 말자.
``` bash
#push
git subtree push --prefix=[로컬 디렉토리명] [저장소 명칭] [저장소 branch]

#pull
git subtree pull --prefix=[로컬 디렉토리명] [저장소 명칭] [저장소 branch]
```

### 테스트 작업 내역
``` bash
# directory 생성.
mkdir Subtree

# Parent Project 생성후 git clone.
git clone https://github.com/select995/subtree.git

# parent Proejct로 이동.
cd subtree

# branch 확인.
git branch

# test로 `README.md` 수정 후 commit, push.
vi README.md
git commit .
git push origin master

# TIL Project remote 추가.
git remote add til https://github.com/select995/TIL.git

# 원격 저장소 확인.
git remote -v

# TIL project subtree로 추가.
git subtree add --prefix=TIL til master
# 이렇게 하면 TIL project가 추가 된다. commit에 TIL projectd의 commit도 보이기 시작한다.

# child tracking branch 생성.
git checkout -b til_master til/master
# 새로운 브런치가 생성 되면서 til_master 브런치로 checkout 된다.

# branch 생성 체크.
git branch
# branch를 보면 [ master ] 와 [ til_master ] 브런치가 생성된것을 볼수 있다.

# master branch로 체크아웃한뒤 push하자.
git checkout master
git push origin master
# subtree를 추가 했어도 푸쉬하기 전에는 commit들이 보이지 않는다. push 이후에 보이기 시작할 것이다.

# til_master 지우자. 뭔가 이상하다.
git branch -d til_master

# til_master를 새로 딴다. 다만 track 옵션으로..
git chekcout --track til/master -b til_master
# 이러면 til_master가 생성 된것을 볼수 있다. 이놈으로 들어가서 ls를 해보면 TIL project 내용만이 보일 것이다.
# 이걸로 생성한 til_master 브런치는 TIL project의 master 브런치이다. TIL project에서 master 브런치로 수정을 한뒤 push하면
# 이 til_project에서 pull 하면 변경 내역을 받을 수 있다. 결국 이놈은 TIL project에서 master 브런치인 것이다.

# master 브런치로 이동후 pull 해보자.
# 변경 내역이 없다. 바로 위에서 TIL project에서 일부를 수정 했는데 master 브런치에서 pull을 해봐도 변경 내역이 없다.
# 결국 이렇게 생각하면 된다. subtree에서 복사한 TIL 브런치는 말그대로 복사다. TIL project에서 암만 수정해도 subtree의 til에서는
# 반영 되지 않는다. 그러면 TIL project에서 수정반영 된것을 subtree의 til project에 가져오려면 어떻게 하느냐? 바로 subtree 명령어를 이용해야 한다.
git subtree pull --prefix=TIL til master
# 이명령어를 사용하면 원래의 프로젝트에서 수정된 것을 subtree child 프로젝트에 가져 올 수 있다.

# 그러면 반대로 subtree projectd에서 수정된것을 원래의 project로 반영 시키는법을 알아 보자. 
# 일단 master branch로 이동 후에 subtree til에서 아무거나 수정해보자.
git checkout master
cd TIL
vi test.md 
git add .
git commit
git push origin master
# 위 명령어를 차례로 하면 subtree에서 master 브런치는 수정된 것을 알수 있다. 하지만 원래의 TIL 프로젝트에서는 수정이 반영되지 않았다. 이를 반영하기 위해서는 마찬가지로 subtree 명령어를 이용하면 된다.
git subtree push --prefix=TIL til master
# 이러면 원래의 TIL project에서 test.md가 추가된것을 볼수 있다. 

# 그러면 다시 보자 subtree에서 TIL project의 master 브런치를 딴 til_master가 있다. 이 브런치는 어떻게 됬을까.?
# 체크아웃 한뒤 확인해보면 til_master의 헤드는 아직 test.md를 반영 전이다. 결국 최신의 TIL의 master 브런치가 이니다. 이를 최신으로
# 덮어 씌어 주려면 그냥 pull 하면 된다.
git pull
# 이러면 위에서 추가한 test.md가 생기며 materd 마지막 commit 으로 이동되는 것을 볼수 있다. 

# 종합해보면
# subtree는 복사 개념이다. subtree를 추가하면 해당 저장소의 코드를 복사한 것이 된다. 
# parent에서 수정 한것으르 원래의 저장소로 반영 시켜주려면 subtree push 명령어를 쓰면된다.
# 원래의 저장소에서 수정된 코드를 parent에 반영 시키려면 subtree pull 명령어를 쓰면 된다.
# 다만 주의 해야 할것이 명령어 뒤에 옵션을 기억 해야 한다는 것과 위 명령어를 쓸때는 parent의 root에서 실행시켜야 한다는 것이다. 
```

- 참조
    - ~~http://readme.skplanet.com/?p=8542~~ 현재는 블로그가 사라졌다.
    - [http://homoefficio.github.io/2015/07/18/git-subtree/](http://homoefficio.github.io/2015/07/18/git-subtree/)