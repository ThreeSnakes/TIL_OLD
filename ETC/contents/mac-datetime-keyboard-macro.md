### [Mac] 현재 시간 자동 입력 키도브 매크로 등록하기.

현재 시간을 입력하는 매크로 등록하기.

#### 방법
1. `Automator`를 실행 시킨다. 
2. `서비스가 받는 선택 항목`은 `입력 없음`, `선택 항목 위치`는 `모든 응용 프로그램` 선택한다. 그다음 `출력이 선택한 텍스트를 대치함` 체크 박스를 체크 한다. 
3. 왼쪽 검색창에서 `AppleScript 실행`을 선택한다. ( 아래 스샷 참조 )
	
	![스크린샷](https://user-images.githubusercontent.com/36795031/43989657-7a3d396c-9d89-11e8-9bf6-83d7d45aba41.png)

4. 그러면 하단에 코드 입력창이 나오는데 다음 코드 입력.
	```text
		tell application "System Events"
		set _Date to (current date)
		keystroke ¬
			(year of _Date as text) & "." & ¬
			text -2 thru -1 of ("00" & ((month of _Date) as integer)) & "." & ¬
			(day of _Date as text) & " " & ¬
			(hours of _Date as text) & ":" & ¬
			(minutes of _Date as text) & ":" & ¬
			(seconds of _Date as text)
		end tell
	```
5. `Cmd` + `s`로 저장.
6. `시스템 환경설정` -> `키보드` -> `단축키` 창으로 이동.
7. `Service` 탭으로 가면 오른쪽에 위에 저장한 파일명으로 Service 생성 되어 있다. 단축키 등록하고 사용하면 된다. 