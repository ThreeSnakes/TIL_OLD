# DB에서 NULL 값, NULL이 아닌 값 검색.
DB에서 데이터를 찾는 도중에 데이터가 없는 경우를 찾아야 할 떄가 있다. 그럴 경우에는 다음과 같이 사용 하면 된다.

## NULL인 아닌 값 찾기.
``` sql
SELECT * FROM A WHERE id IS NOT NULL;

#EX )
SELECT * FROM A WHERE (SELECT * FROM B WHERE id2 = A.id2) IS NOT NULL;
```
다음 처럼 사용 하면 비어 있는 값일 경우에는 검색 대상에서 제외 해 버린다.
`(컬럼명) IS NOT NULL` 만 기억하자.

## NULL인 값 찾기..
``` sql
SELECT * FROM A WHERE id IS NULL;

#EX )
SELECT * FROM A WHERE (SELECT * FROM B WHERE id2 = A.id2) IS NULL;
```
다음 처럼 사용 하면 비어 있지 않는 값일 경우에는 검색 대상에서 제외 해 버린다.
`(컬럼명) IS NULL` 만 기억하자.

