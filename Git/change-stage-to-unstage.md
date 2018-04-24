# git file 상태 Unstage로 변경하기.
---

IntelliJ 폴더를 그대로 넣은 다음 `git add -A` 해버렸더니 `*.iml` 파일까지 해버렸다.
git ignore 하기 전에 add 된 파일 Unstage로 되돌리는 방법부터 정리하자.


`$ git status` 를 입력하면 밑에 처럼 쏼라쏼라 나온다.
``` bash
$ git status
On branch master
Changes to be committed:
  (use "git reset HEAD <file>..." to unstage)

    renamed:    README.md -> README
    modified:   benchmarks.rb
```
여기서 `git reset HEAD <file>`을 치면 unstage로 변한다고 친절하게 설명 되어있다.
위에처럼 하면 unstage로 변경 된다.
``` bash
# iml 파일 unstage로 변경 하는 예제.
git reset HEAD Algorithm/Code/test2557/test2557.iml
```
