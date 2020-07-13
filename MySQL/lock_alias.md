# lead/write lock 사용시 alias 설정

사내 같은 팀원분이 SQL 오류 찾기로 Help를 요청 하셨는데 나도 몰랐던 부분이라 이를 찾아보고 정리한다.

## 목차

- [배경](#배경)
- [원인](#원인)
- [해결](#해결)

### 배경

일단 같은 팀원분이 올려주신 SQL문은 다음과 같은 형태이다.

```sql
LOCK TABLES admin_db.A READ,
admin_db.B READ,
-- ... 생략 ...
admin_db.E READ;

SELECT
  cli.column1,
  cli.column2,
  -- ... 생략 ...
  b.column5
  FROM
  admin_db.A cli
  LEFT OUTER JOIN admin_db.B b ON cli.column1 = b.column1
WHERE
  a.client_id > 2;

-- ... 생략 ...

UNLOCK ALL UNLOCK TABLES;
```

위 코드는 실제 사용되는 코드라서 일부 변경하였다. 하여튼 테이블에 LOCK을 걸고 해당 테이블에서 데이터를 조회하는 쿼리가 존재한다. 약 5개의 쿼리로 특별히 이상이 있는 쿼리는 아니고 모두 조회 하는 쿼리이다.

문제는 안에 조회 쿼리를 하나씩 개별로 돌리면 잘 돌아가는데 LOCK을 거는 쿼리부터 순차적으로 돌리면 에러를 내뱉어서 진행이 안되는데 쿼리상 특별히 이상이 있는점을 못찾겠다라고 하셨다.

나도 조회쿼리를 개별로 돌려보니 딱히 문제가 없었는데 LOCK을 거는 쿼리부터 돌리면 바로 에러가 발생해서 왜 발생하는지 조사해보고 해결법을 정리해본다.

### 원인

사실 원인이라고도 할 만한게 없다. table plus에서 로그를 보니 cli를 찾을 수 없다고 나온다.

![lock_error](./images/lock.png)

여기서 cli는 조회쿼리에서 A 테이블을 alias한 이름이였는데 이 이름이 lock이 되지 않았다는 것이다.

관련해서 구글링을 해보았다.

MySQL 문서중 [lock-tables](https://dev.mysql.com/doc/refman/8.0/en/lock-tables.html)를 보면 관련 설명이 나와있다.

> If your statements refer to a table by means of an alias, you must lock the table using that same alias. It does not work to lock the table without specifying the alias:

정리하자면 만약 LOCK을 건 이후에 조회를 할때 테이블에 Alias를 걸면 LOCK을 걸때도 똑같이 Alias를 걸어줘야 한다는 것이다. 결국 개별 쿼리는 문제가 없었지만 LOCK을 걸때 alias된 테이블명으로 LOCK을 걸어야 하는데 걸지 않아서 생긴 문제였다.

### 해결

위에 있는 쿼리중 LOCK을 걸때 alias도 같이 걸어 주었다.

``` sql
LOCK TABLES admin_db.A AS cli READ,
admin_db.B AS b READ,
-- ... 생략 ...
admin_db.E READ;

SELECT
  cli.column1,
  cli.column2,
  -- ... 생략 ...
  b.column5
  FROM
  admin_db.A cli
  LEFT OUTER JOIN admin_db.B b ON cli.column1 = b.column1
WHERE
  a.client_id > 2;
```
