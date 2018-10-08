### Docker Cheat Sheet

`Docker`를 쓰면서 자주 쓰는 명령어나 가끔 쓰는 명령어를 기억하기 위한 파일이다. 쓸때마다 업데이트 해준다.

#### 컨테이너 확인
``` bash
# 실행중인 컨테이너 확인
docker ps

# 정지중인 컨테이너까지 확인
docker ps -a
```

#### 컨테이너 정지
``` bash
docker stop  '컨테이너ID'
```

#### 컨테이너 삭제
``` bash
#  기본 명령어
docker rm '컨테이너ID'

# 전체 컨테이너 삭제
docker rm $(docker ps -a -q)
```

#### 이미지 확인
``` bash
# 이미지 확인
docker images

#존채 이미지 확인
docker images -a
```

#### 이미지 삭제
``` bash
# 전체 이미지 삭제
docker rmi $(docker images -q) 
```

#### 컨테이너 접속하기
``` bash
# 컨테이너 접속
docker exec -i '컨테이너ID'
```

#### Docker 마법의 주문(!?)
```
# 컨테이너/이미지 전부 삭제. 이러면 다시 컨테이너를 구성하고 이미지 받는데 오래 걸림..
docker rm $(docker ps -a -q)
docker rmi $(docker images -q) 
```