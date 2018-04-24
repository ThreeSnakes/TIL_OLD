### push한 commit 하나로 합치기.

stg 환경 구성을 진행하면서 수정 변경 사항들이 엄청많았는데 -_-

정리가 되질 않았다. 그래서 git log가 아주 흉물스럽게 되었다.

![스크린샷 2018-03-02 오전 11.32.49.png](https://user-images.githubusercontent.com/36795031/36881683-bba784c6-1e12-11e8-8bf7-a37e8d355960.png)

이 흉물 스럽게 변경된 것을 바꾸기 위해서 이 commit들을 합칠 필요가 생겼다.

이 방법을 정리해 본다.

일단 commit을 합칠때에는 일반적으로 `Squash` 명령어를 사용한다.

일단 합치고 싶은 commit들을 `rebase` 명령어로 되돌린다.

``` bash
git rebase -i HEAD~44 // HEAD에서 부터 44개의 commit을 되돌린다라는 의미.
```

무려 45개(*Head에서부터 44개*)의 commit들을 합쳐야 한다. ... -_-;;;

위 명령어를 입력하니 다음 화면 처럼 나온다.

![스크린샷 2018-03-02 오전 11.42.02.png](https://user-images.githubusercontent.com/36795031/36881684-bee562b6-1e12-11e8-9efc-239e71147c60.png)

시간 순( 과거 ~ 최신) 순으로 commit들이 나오게 되는데

여기서 가장 처음을 제외한 commit의  `pick`을 `squash` 로 변경해준다.

![스크린샷 2018-03-02 오전 11.52.14.png](https://user-images.githubusercontent.com/36795031/36881689-c536f6d4-1e12-11e8-9bbb-58a81bda75f3.png)

그다음 저장 하면 다음 화면이 또 나온다.

![스크린샷 2018-03-02 오전 11.52.48.png](https://user-images.githubusercontent.com/36795031/36881691-c9d02274-1e12-11e8-8724-e413bed1d9c8.png)

여기서 commit 메세지를 수정 할 수있다. 화면에 나온 것에서 주석을 제외한 모든 메세지가 commit 메시지로 출력 된다.

이를 수정 하면 된다. 따로 기존 메세지는 삭제 하지 않고 메세지만 추가 했다.

![스크린샷 2018-03-02 오전 11.53.48.png](https://user-images.githubusercontent.com/36795031/36881695-cf1d068e-1e12-11e8-9f76-c90375b79a2a.png)

그다음 저장 한다. 그다음에 잘 됬는지 확인 해 보자.

![스크린샷 2018-03-02 오전 11.57.57.png](https://user-images.githubusercontent.com/36795031/36881700-d439544c-1e12-11e8-8d69-42445be448b0.png)

우왕 굳. 잘됬다. 이제 push만 하면 된다. 그런데 주의 할게 있는데... 

그런데 위에서 보다시피 `remote 브런치`랑, `local 브런치`랑 작업 내역이 다르다.

기존에 rebase로 합친 브런치를 누군가 pull하고 다시 작업을 하게되면 git이 꼬일수 있다.

그러니 꼭 다른사람이 작업한게 있는지 확인하고 합치기 작업 진행한다.

push는 다음 명령어로 해주면 된다.

``` bash
git push origin stage --force
```

![스크린샷 2018-03-02 오후 12.01.25.png](https://user-images.githubusercontent.com/36795031/36881704-d93c8f18-1e12-11e8-9a38-0ae1b9cde77e.png)

우왕 굳! 완전 깔끔해졌다. 

*출처 및 참조*
    - [JinKyou Son님의 블로그](https://json.postype.com/post/209499)


