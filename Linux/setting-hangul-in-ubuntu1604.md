# Ubuntu 16.04 한글 입력 셋팅
---
vmware 설치하고 ubuntu 16.04 사용하는데 한글을 쓸일이 없었는데 github 에 글 올리려고 보니깐 한글이 필요하게 되었다. 그래서 한글 셋팅하는 법도 정리해 놓자.

* 한글 설치

```
1. 우분투 바탕화면에서 오른쪽 상단에 System Settings 클릭.
2. Laguange Support 클릭하면 다운로드 받아야 한다고 알림창 뜬다. 다운로드 실행.
3. 설치 다 된다음에 하단에 보면 Install / Delete Language 가 있는데 클릭 한 다음 Korean 을 install 해준다.
4. 그다음 맨 하단에 보면 keyboard input method system을 fcitx로 변경한다. 
```

* 단축키 설정.

```
1. 우분투 바탕화면에서 오른쪽 상단에 System Settings 클릭. --> Keyboard 클릭. --> Shortcuts Tab 클릭 --> Typing을 클릭한다.
2. Switch to Next source, Switch to Previous sourc, Compose Key, Alternative Characters Key를 모두 Disabled로 바꾸준다. Disabled로 바꾸기 위해서는 backspace를 누른다.
3. Compose Key의 Disable로 설정된 값을 Right Alt로 바꿔준다.
4. Switch to next source는 Right Alt를 눌러서 Multikey로 바꿔준다. 위에 3번이 반드시 먼저 되 있어야지 Multikey로 셋팅되는 것을 볼수 있다. 
5. Termianl 에서 바뀌는거 확인하자.
```

