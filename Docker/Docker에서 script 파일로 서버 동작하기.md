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