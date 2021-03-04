# index

## INDEX 확인
``` SQL
SHOW INDEX FROM 테이블명
```

## INDEX 추가
``` SQL
# 기존 테이블에 인덱스 추가하기.
CREATE INDEX 인덱스명 ON 테이블명(필드명)
```

## FULL TEXT INDEX 추가
``` SQL
# FULL TEXT 인덱스는 MySQL의 기본 저장 엔진 타입인 MyISAM 테이블에만 사용된다.
ALTER TABLE 테이블명 ENGINE = MyISAM;
# FULL TEXT 인덱스는 CHAR과 VARCHAR, TEXT 열로만 생성 가능.
# FULL TEXT 인덱스 추가하기.
ALTER TABLE 테이블명 ADD FULLTEXT(필드명)
```

## 인덱스 삭제
``` SQL
ALTER TABLE 테이블명 DROP INDEX 인덱스명
```