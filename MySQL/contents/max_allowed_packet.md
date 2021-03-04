# max_allowed_packet 설정

정산 배치를 돌리는데 쿼리가 너무 길어서 다음과 같은 에러메세지가 발생 하였다.

``` bash
insertServiceRevenue Fail. ERROR: Error: ER_NET_PACKET_TOO_LARGE: Got a packet bigger than 'max_allowed_packet' bytes
``` 

이를 해결하는 방법을 정리해보고자 한다.

## 목차

- [배경](max_allowed_packet.md#%EB%B0%B0%EA%B2%BD)
- [원인](max_allowed_packet.md#%EC%9B%90%EC%9D%B8)
- [해결](max_allowed_packet.md#%ED%95%B4%EA%B2%B0)

### 배경

정산 배치를 돌리면 약 6000개의 row를 2개의 테이블에 나눠서 삽입한다.

그런데 정산 데이터이다 보니깐 row마다 컬럼의 갯수가 꽤 되고, 이를 트랜잭션을 이용해서 하나의 쿼리로 실행한다.

이러다보니 쿼리의 byte수가 기본 설정인 4MB를 넘어서서 위에 에러를 내뱉으면서 실행이 되지 않는다.

### 원인

일단 현재 쓰고있는 DB의 max_allowed_packet 설정을 어떻게 확인하는지 알아보자.

```sql
SHOW VARIABLES LIKE 'max_allowed_packet';
```

위 쿼리를 조회하면 허용하면 packet Byte수를 볼수 있다.

내가 조회했을때는 4MB까지로 제한되어 있었다. ( 아무래도 mysql 기본값인듯 싶다. )

더많은 데이터를 넣을 수 있도록 이 설정을 변경해야 한다.

### 해결

현재 회사의 경우 AWS RDS를 쓰고 있기 때문에 AWS Console에 가서 설정을 변경해야 한다.

[링크](https://aws.amazon.com/ko/premiumsupport/knowledge-center/rds-mysql-server-gone-away/)에 보면 설명이 잘 되어 있는데 나중에 기록을 위해서 약간의 스샷을 추가한다.

파라미터 그룹을 들어가면 아래와 같이 파라미터를 검색할 수 있는 화면이 나온다.

![max_allowed_packet](https://github.com/ThreeSnakes/TIL/raw/master/MySQL/images/max_allowed_packet.png)

여기서 `max_allowed_packet`를 검색한뒤 값을 수정해주면 된다.

내가 직접 수정하지는 않았고, 회사 시니어분께 변경을 요청 드렸었고, 옆에서 하는 것을 기록한 것이다.

혹시나 나중에 써먹을 수도 있으니 잊지 말자.
