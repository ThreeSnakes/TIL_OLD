# alias 명령어 사용법

회사에서 일을 하다보니 터미널에서 폴더 이동이 아주 빈번하다. 

근데 이동하려는 프로젝트마다 디렉토리가 다르고 이동하는 곳이 많다보니 시간이 오래걸리고

타이핑도 많아서 불편했다. 

그래서 한번에 해당 디렉토리까지 한번에 이동하려는 명령어를 만들려고 한다. 

``` bash
$ alias [만들 명령어] = "리눅스 명령어"
```
위 명령어로 하면 리눅스 명령어로 새로운 명령어로 만들어 준다. 

하지만 터미널에서 사용할 경우 터미널을 닫으면 해당 명령어는 사라진다.

그러면 지속적으로 사용하려면 어떻게 해야 하는가...?

`/etc/profile.d/alias.sh`에 해당 명령어를 저장해야 하면 된다. 여기에 등록하면 전체 사용자가 사용할수 있고,

`~/.bash_profile`에 등록하면 해당 사용자만 사용할 수 있다. 

어차피 회사 노트북은 나만 사용하니 `~/.bash_profile`에 등록해보자.

``` bash
sudo vi ~/.bash_profile

# vi로 진입하면 맨아래 다음 처럼 입력.
alias FingerMD="cd /Users/a/Documents/workspace/d/System/c"
alias FingerManager="cd /Users/a/Documents/workspace/d/System/c"
alias FingerStatWeb="cd /Users/a/Documents/workspace/d/System/c"
alias Blog="cd /Users/a/Documents/workspace/BLOG"

# 명령어 입려할때 "=" 사이에 띄어쓰기를 하면 안된다. 띄어쓰기 하니깐 안먹히네...
```

그다음 위 수정 내용 저장한 다음에

터미널 종료하고 새로 들어가면 위에서 만든 명령어 사용할 수 있다. 
