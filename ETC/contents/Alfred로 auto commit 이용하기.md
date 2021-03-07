# Alfred로 auto commit 이용하기

알프레드 workflow로 git repo를 명령어 한번으로 commit, push할 수 있도록 하게 하는 방법이다.

## 1. workflow 생성
	![[스크린샷 2021-02-26 오전 6.27.48.png]]
		- 위 이미지에 처럼 `template -> Essentials -> Keyword to Script` 워크플로우를 생성한다. 그러면 기본 스크립트가 생성된다.

## 2. workflow 설정
	![[스크린샷 2021-02-26 오전 6.30.49.png]]
	- 왼쪽이 workflow  키워를 셋팅하는 아이콘이고, 오른쪽 스크립트가 terminal 명령어를 입력하는 아이콘이다.
		- 왼쪽 아이콘을 더블클릭한뒤 다음처럼 설정한다.
			- Keyword: 워크플로우 실행시 쓰고 싶은 명령어를 적당히 쓴다.
			- Argument: 인자는 필요 없으니 **No Argument**로 설정한다.
			- Title, Subtext도 적당히 쓴다.
		- 오른쪽 아이콘을 더블클릭한뒤 아래 내용을 복사해서 붙여 넣기 한다.
			```bash
			# cd 뒤에 commit && push를 원하는 dir를 넣어 준다.
			cd /Users/changhyunlim/Documents/Study/Obsidian_Note

			git pull

			git add .

			git commit -m "auto commit"

			git push origin master

			exit
			```
			- terminal을 bash, zsh중 사용하는것을 적당히 고른다.

## 3. workflow 동작 확인
- 등록한 워크 플로우가 키워드에 맞게 나오는지 확인한다.
	![[스크린샷 2021-02-26 오전 6.35.22.png]]
- 워크플로우를 실행시키고 잘 커밋되었는지 확인한다.
	![[스크린샷 2021-02-26 오전 6.40.20.png]]
- 끝