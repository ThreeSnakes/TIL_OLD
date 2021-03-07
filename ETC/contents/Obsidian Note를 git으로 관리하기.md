# Obisidian Note를 Git으로 관리하기

## 개인 repository 생성

- **git**으로 관리를 하려면 **github**나 기타 다른 온라인 서비스를 이용해서 일단 개인 **repository**를 만든다.
	- 중요한 문서나 공개되는 문서가 있을수 있으니 **Private**로 만들기를 권장.
- **repository**가 만들어지면 주소를 복사해 놓는다.

## 옵시디안 노트 구성

- 옵시디안 노트의 경우 아래 이미지처럼 폴더 형태로 구성되는데, 이 노트 내용만 불러올 수 있다면 어떤 PC에서도 같은 내용을 볼 수 있다. (window 테스트 X)
- 이 폴더에 **git**을 연결 시켜주면 된다.
```bash
# 옵시디안 노트 root 폴더로 이동
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

## 완료된 이후
**Obsidian** 노트를 작성한 다음에 이를 주기적으로 **commit && push** 해주면 이 노트를 다른 PC에서도 동기화를 맞추면서 사용할 수 있다.

## 추가 Tip
  - [[Alfred로 auto commit 이용하기]]