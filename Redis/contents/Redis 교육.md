# Redis 교육

교육 주최: redisgate.kr

## Redis 소개
- 일반 Redis와 엘라스틱 서치와의 차이점
	- 자세하게 알지는 못함. 엘라스틱 서치에서도 일반 Redis를 쓰고 있는 것으로 알고 있다.
- Redis를 사용할때 멀티 코어를 쓰는게 의미가 있을까?
	- Redis는 단일 코어를 사용함. 멀티 코어를 쓰는게 의미가 없음.
	- 16Core 서버를 올리고 Redis를 여러개 올릴 경우에 필요.
- TTL을 걸었음에도 메모리, CPU 메모리가 빠르게 상승하다가 갑자기 내려가는데 어떻게 동작하는지 궁금하다.
	- 100ms 마다 크론잡이 돌면서 expire된 데이터를 처리함.
	- expire된 데이터가 많으면 문제가 될 수는 있음. 또한 expire된 데이터를 한번에 지우는 것은 아님. 남을수도 있음.
	- expire된 데이터는 getKey를 할때 데이터를 체크하고, 삭제하는 경우도 있음.
	- expire 때문에 CPU, 메모리가 올라간것인지 체크가 필요함.
- replica가 붙어 있을때, 마스터가 페일 오버될경우 데이터는 살아 있나..?
	- Master -> Replica로 데이터를 복사함
	- Mater가 다운이 되면, Replica를 Mater로 치환시켜준다.
	- replica가 없을 경우에는 AOF 파일에 저장되어 있으면, 이를 통해 복구를 하지만, 이 파일도 없으면 날라간다고 보면 된다.
- 클러스터 모드, 일반 모드를 다 사용함. 클러스터 모드 2대를 사용하고 있는데, 클러스터를 하나 더 추가한다면 데이터는 어떻게 분배 되는가.? [링크](http://redisgate.kr/redis/cluster/cluster_introduction.php)
	- M1, M2에서 M3를 추가하면 slot을 할당함(슬롯이 16384개 있다고 가정하자.) <<- 이부분 학습 필요.
	- M1(0 ~ 8000), M2(8001~16384) 할당하는데, key 값이 어디에 설정되는것에 따라서 M1, M2에 분배됨.
	- 만약 M3를 추가하면 key를 분배하는 작업을 수동으로 해야 한다.
	- M1(0~6000), M2(6001~12000), M3(12001~16384)로 슬롯을 할당하는 것이다.

## install

강사님은 linux 기준으로 이야기를 하는데.. 우리는 Mac을 씀.. 강사님이 Mac에서 동작하는지 모르심..
일단 `brew install redis`로 Mac에서 설치 가능.

redis 의 메모리 스토어는 용량을 늘려야 할 때 수kB 단위로 조금씩 요청해서 받아쓰기 때문에, 혹시 OS에서 메모리 페이지 사이즈를 수 MB 단위로 설정했다면 다시 작게 내리는 OS설정 변경이 필요하다. 이떄문에 redis를 사용하는 서버에서는 다른 RDB를 사용하는게 어려울 수 있다. 

~~redis를 위한 설정이 있다보니, redis를 다른 서버와 같이 띄우는 것은 좋지 않을 수 있다.~~ 베어메탈과 아닌게 큰 차이는 없으나 제대로 쓰려면 설정을 잘해서 쓰는게 좋다 정도 일 것 같네요.

## Persistence - 디스크 저장
[관련 링크](http://redisgate.kr/redis/configuration/redis_overview.php)

메모리에 있는 정보를 Disc로 저장하는 방법
- AOF 파일을 이용한 방법
	- appendonly.aof 파일을 이용한다
	- RDB 로그 파일이라 생각하면 도미.
	- Redis에 들어온 명령 자체를 저장한 파일이라고 생각 하면 된다.
	- 데이터 손실은 거의 없다.
- Snapshot 방법
	- 특정 이벤트가 발생할 때마다 메모리에 있는 레디스 데이터 전체를 디스크에 쓰는 방식
	- redis 초기 버전에는 해당 기능만 있었다. 해당 기능은 거의 사용되지 않는다.

- redis.conf에 다음과 같은 정보가 저장된다.
	- appendonly : yes
	- appendfilename
	- appendfsync
		- always: 명령 실행 시 마다 AOF에 기록한다. 데이터 유실의 염려는 없으나 성능이 매우 떨어진다.
		- everysec: 1초마다 AOF에 기록한다. 성능에 영향이 거의 없음. 권장하는 방법
		- no: AOF에 기록하는 시점을 OS가 결정한다. 일반적으로 리눅스는 30초 간견으로 저장한다. 데이터 유실이 있을수 있음.
- AOF Rewrite 설정
	- auto-aof-rewrite-pencentage 100
		- AOF 파일 사이즈가 100%이상 커지면 rewrite한다. 0으로 설정하면 rewrite 하지 않는다.
	- auto-aof-rewrite-min-size 64mb
		- AOF 파일 사이즈가 64mb이하면 rewrite하지 않는다. 파일이 작을 경우 rewrite하는것을 막으주는 설정
	- aof-use-rdb-preamble
		- Rewrite시 rdb 포맷으로 저장한다. 파일 사이즈를 줄이고 로딩 속도를 높이기 위해서 사용한다. 
