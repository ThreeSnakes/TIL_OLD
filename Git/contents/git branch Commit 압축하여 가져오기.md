# git branch Commit 압축하여 가져오기

**Commit**이 매우 많은 브런치에서 이 **Commit**을 모두 하나로 합쳐서 가져오는 경우에 사용한다.

``` bash
git merge --no-commit --squash "가져올 원래branch명"
```