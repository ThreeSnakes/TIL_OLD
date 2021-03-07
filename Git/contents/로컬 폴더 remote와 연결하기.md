# 로컬 폴더 remote와 연결하기

로컬 폴더를 remote와 연결할때 사용하는 방법이다.

```bash
# 연결하기를 원하는 folder로 이동.
cd /Users/changhyunlim/Documents/study/Obsidian_Note

# git initializing
# 로컬 폴더에 git을 초기화
git init

# 개인 레포를 생성하면서 만들어진 remote 주소 등록
git remote add origin "git 주소"

# master를 일단 한벙 땡겨온다.
git pull origin master

# 기존 작성된 내용을 staging에 추가한다.
git add .

# init commit
git commit -m "INIT"

# git push
git push origin master
```