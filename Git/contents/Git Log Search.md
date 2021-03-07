# Git Log Search

``` bash
# 커밋 변경(추가/삭제) 내용 안의 텍스트를 검색
git log -S "검색 문자"

# 커밋 메세지 안의 텍스트를 검색한다.
git log --grep "검색 문자"

# 해당 author의 커만만 검색한다.
git log --author "검색 문자"
```