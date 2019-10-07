# git cheatsheet
---

1. 새로운 브런치 생성

``` bash
git checkout -b [ 브런치 명 ]

## EX
git checkout -b feature/slack_lang_condition
```

2. git commit 합치기

``` bash
git rebase -i [ 조건 ]

## EX
git rebase -i HEAD~2
```