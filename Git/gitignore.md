# git ignore Setting 방법 정리해놓은 문서.
---

Algorithm 공부하면서 만든 파일을 github에 올리려고 하는데 Intellij에서 쓰잘데 없는 iml파일을 만들어 낸다.
그래서 git에 안올리려고 하는데 이왕 하는김에 git ignore 하는 setting 하는 방법 정리해 놓는다.

```
1. git
  git 에서는 간단하다.
  git repository로 이동한다음에 
  $ sudo vi .gitignore 입력후 제외할 파일을 넣어 주면 된다.
  그다음 iml 파일만을 제외 시킬 것이므로 다음과 같이 입력해준다.
  
  # IntelliJ except *.iml#
  *.iml
  
  그다음에 .gitignore 파일을 add 후에 commit까지 하면 적용 완료.!
  
2. global setting
  git 에서도 global로 설정 하는 방법도 있다.
  $ git config -- global core.excludesfile ~/.gitignore_global 입력해주면 git setting이 된다.
  그다음에 gitignore_global안에 위에처럼 입력해주면 된다. 
  
  vmware 에서 위치는 /home/[사용자]/.gitignore_global 이었다.
  흠 commit이 필요 했는지는 기억 안나는데 혹시 안되면 해보자.
  
```  

git hub에서 제공하는 [언어별 gitignore](https://github.com/github/gitignore) setting page도 있으니 필요하면 가보자.
