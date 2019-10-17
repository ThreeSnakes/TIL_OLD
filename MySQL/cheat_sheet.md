# MySQL CheatSheet

## 목차

- [컬럼 추가](#컬럼-추가)
- [컬럼 수정](#컬럼-수정)
- [DB 커넥션 개수 체크 및 상태 확인](db-커넥션-개수-체크-및-상태-확인)
- [유니크 키 삽입](#유니크-키-삽입)
- [유니크/인덱스 삭제](#유니크/인덱스-삭제)
- [ROW 업데이트](#ROW-업데이트)

### 컬럼 추가

```sql
ALTER TABLE `테이블명` add `컬럼명` `타입` `옵션`

-- EX: 
ALTER TABLE `ACCOUNT_REQUEST` ADD `memo` text COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '보류/삭제시 사유를 기록하기 위한 컬럼' AFTER `disapproval_reason`;
```

### 컬럼 삭제

``` sql
alter table [테이블명] drop [컬럼명];

-- EX:
ALTER TABLE `BILLING_SETTING` DROP "pkid";
```

### 컬럼 수정

``` sql
ALTER TABLE `테이블명` CHANGE `기존컬럼명` `새컬럼명` 기존 자료형

-- EX:
ALTER TABLE `CLIENT_MAILING_SETTING` CHANGE `client_mailng_setting_id` `client_mailing_setting_id` int(11) NOT NULL AUTO_INCREMENT;
```

### DB 커넥션 개수 체크 및 상태 확인

``` sql
-- 전체 커넥션 상태 확인
SELECT * FROM information_schema.processlist;
-- 또는
show full processlist;

-- SLEEP 상태로 오래 남아있는 커넥션 정보 확인
SELECT * FROM information_schema.processlist where COMMAND ="Sleep" ORDER BY TIME DESC;

-- 현재 커넥션 개수 확인
show status where `variable_name` = 'Threads_connected';

-- 타임아웃 설정 값 확인
show variables like '%timeout';
```

### 유니크 키 삽입

``` sql
ALTER TABLE tablename ADD UNIQUE INDEX indexname (column1, column2);

-- EX:
ALTER TABLE `APPROVAL_CATEGORY_BY_SERVICE` ADD UNIQUE INDEX category_key(service_id, approval_category_id, grade);
```

### 유니크/인덱스 삭제

``` sql
ALTER TABLE tablename DROP INDEX indexname;

-- EX:
ALTER TABLE `APPROVAL_CATEGORY_BY_SERVICE` DROP INDEX service_id;

```

### ROW 업데이트

``` sql
-- EX:
UPDATE ad_admin.MEZZO_CHANNEL_REQUEST
SET status = 2, manager_name = 'Yeseul Seo', manager_message = '4/2'
WHERE status = 0;
```
