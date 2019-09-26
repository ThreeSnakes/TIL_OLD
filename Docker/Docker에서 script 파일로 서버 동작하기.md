### Docker에서 Script 파일로 서버 동작하기.

기존 ec2에서 동작하는 웹서버를 ecs와 docker로 이주하는 작업을 진행 중이다.

그런데 그 중에 java로 된 서버가 있는데 이를 script 파일로 동작시키고 있다.

docker 명령어에서 해당 스크립트를 실행 시키면 잘 동작은 하는데....

``` bash
EXIT(0)
```

을 뱉으면서 자꾸 컨테이너가 죽으면서 다시 재시작 되는 것이다.

알고보니 스크립트로 java 서버를 동작시키고 서버는 백그라운드로 진행되고

실행시킨 스크립트 파일은 종료 되면서 프로세스가 죽는다고 한다. -_- (이것때문에 삽질만....)

그래서 검색해봤더니 스크립트가 종료 되지 않도록 하면 된다고 한다. (종료만 안되면 된다.)

``` bash
java -classpath ${CLASSPATH} com.ar.xxxxx.xxxxx.xxxxx.xxxxx > /dev/null &

// 아래 코드로 스크립트가 죽지 않는다.
while true;
  do echo "still live";
  sleep 600;
done
```

다만 이렇게 할 경우 -_- 로그 보기가 애매 한데 해당 자료를 찾은 글쓴이는 표준 출력으로 출력 되도록 하였다고 한다.

일단 로그는 옮기는게 먼저 보다 보니 생각 못하고 있는데 로그도 마저 생각이 필요 할듯 하다.

*참조*

- [개발자가 처음 Docker 접할때 오는 멘붕 몇가지](http://www.popit.kr/%EA%B0%9C%EB%B0%9C%EC%9E%90%EA%B0%80-%EC%B2%98%EC%9D%8C-docker-%EC%A0%91%ED%95%A0%EB%95%8C-%EC%98%A4%EB%8A%94-%EB%A9%98%EB%B6%95-%EB%AA%87%EA%B0%80%EC%A7%80/)

---
2018.03.06 내용 추가.

로그를 어떻게 볼것인가 고민 하다가 간단히 해결방법을 찾아서 다시 작성한다.

사실 해당 프로젝트에서 로그를 파일로 남기고 있는데 있었는데 이걸 tail로 계속 뿌려주면 되는것이다.

그런데 해당 app이 실행 될때 까지의 시간이 조금 소요 되므로 로그 파일이 생성되기 전인데 -_-;;

해당 로그 파일을 먼저 생성 시킨 다음에 tail 명령어로 계속 읽으면 된다.


``` bash
java -classpath ${CLASSPATH} com.ar.finger.tracker.main.Server > /dev/null &

mkdir -p /root/xxxxxx/logs ## 로그 디렉토리 생성.
touch "${LOG_HOME}/xxxxxx.log" ## 로그 파일 미리 생성해 놓는다.
tail -f "${LOG_HOME}/xxxxxx.log" ## 해당 로그 파일을 계속 추적한다.

while true; ## 이부분 코드가 쓸모 없어졌다.
  do echo "still live";
  sleep 600;
done
```

이렇게 수정 됬는데 tail로 로그 파일을 계속 읽어서 while문도 사실상 필요가 없어 졌다.

하지만 또다른 이슈가 있다. 로그 파일이 로테이트로 일마다 생성이 되는데.... 해당 일에 맞추어서 읽고 있는지 확인은 아직 못해 봤다. -_-

이부분은 다시 찾아 봐야 겠다.