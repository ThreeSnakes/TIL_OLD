# git cheatSheet

---

## 목차

- [새로운 브런치 생성](#새로운-브런치-생성)
- [git commit 합치기](#git-commit-합치기)
- [git Stash(현재 작업중인 작업을 잠시 멈출 때)](#git-stash)

### 새로운 브런치 생성

``` bash
git checkout -b [ 브런치 명 ]

## EX
git checkout -b feature/slack_lang_condition
```

### git commit 합치기

``` bash
git rebase -i [ 조건 ]

## EX
git rebase -i HEAD~2
```

### git Stash

``` bash
# 아래 명령어를 치면 현재 작업중인 작업을 스택에 잠시 저장한다.
# 아직 완료 되지 않은 작업을 commit하지 않고 나중에 꺼내서 다시 작업 하면 된다.
git stash

# stash 리스트 보기
git stash list

# stash로 저장한 작업 다시 꺼내오기
git stash apply # 최근 저장한 작업, Staged 상태로 되돌리진 않는다.
git stash apply [stash 이름] # 해당 이름으로 저장한 작업 꺼내온다
git stash apply --index # staged 상태였던 파일을 자동으로 다시 Staged 상태로 되돌린다.

# stash 리스트 삭제
git stash drop  # 가장 최근 stash를 제거한다.
git stash drop [stash 이름] # 해당 stash 작업을 제거한다.

# 꺼내면서 동시에 stash 삭제하기
git stash pop # 가장 최근 stash를 가져오면서 이를 stash 리스트에서 삭제한다.
```
