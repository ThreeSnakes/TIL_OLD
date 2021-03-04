# MySQL CheatSheet

## 목차

- [테이블 추가](cheat_sheet.md#%ED%85%8C%EC%9D%B4%EB%B8%94-%EC%B6%94%EA%B0%80)
- [테이블 삭제](cheat_sheet.md#%ED%85%8C%EC%9D%B4%EB%B8%94-%EC%82%AD%EC%A0%9C)
- [컬럼 추가](cheat_sheet.md#%EC%BB%AC%EB%9F%BC-%EC%B6%94%EA%B0%80)
- [컬럼 수정](cheat_sheet.md#%EC%BB%AC%EB%9F%BC-%EC%88%98%EC%A0%95)
- [유니크 키 삽입](cheat_sheet.md#%EC%9C%A0%EB%8B%88%ED%81%AC-%ED%82%A4-%EC%82%BD%EC%9E%85)
- [외래키 삽입](cheat_sheet.md#%EC%99%B8%EB%9E%98%ED%82%A4-%EC%82%BD%EC%9E%85)
- [유니크/인덱스 삭제](cheat_sheet.md#%EC%9C%A0%EB%8B%88%ED%81%AC/%EC%9D%B8%EB%8D%B1%EC%8A%A4-%EC%82%AD%EC%A0%9C)
- [ROW 추가](cheat_sheet.md#ROW-%EC%B6%94%EA%B0%80)
- [ROW 업데이트](cheat_sheet.md#ROW-%EC%97%85%EB%8D%B0%EC%9D%B4%ED%8A%B8)
- [DB 커넥션 개수 체크 및 상태 확인](cheat_sheet.md#db-%EC%BB%A4%EB%84%A5%EC%85%98-%EA%B0%9C%EC%88%98-%EC%B2%B4%ED%81%AC-%EB%B0%8F-%EC%83%81%ED%83%9C-%ED%99%95%EC%9D%B8)

## 테이블 추가

``` sql
CREATE TABLE `테이블 명` (
  `컬럼명` 컬럼 타입
  PRIMARY KEY (`컬럼명`)
) 테이블 설정

-- EX
CREATE TABLE `SERVICE_TYPE_HAS_CATEGORY` (
  `service_type_has_category_id` bigint(20) NOT NULL AUTO_INCREMENT COMMENT 'primary key',
  `service_type_id` int(11) NOT NULL DEFAULT 0 COMMENT 'SERVICE_TYPE pkid',
  `service_category_id` int(11) NOT NULL DEFAULT 0 COMMENT 'SERVICE_CATEGORY pkid',
  `c_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP COMMENT '생성 시간',
  `m_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP COMMENT '수정 시간',
  PRIMARY KEY (`service_type_has_category_id`),
  UNIQUE KEY `type_category_maaping` (`service_type_id`, `service_category_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8 COLLATE=utf8_bin COMMENT '코멘트~~~';
```

## 테이블 삭제

``` sql
DROP TABLE `테이블명`

-- EX
DROP TABLE `SERVICE_TYPE_HAS_CATEGORY`;
```

## 컬럼 추가

```sql
ALTER TABLE `테이블명` add `컬럼명` `타입` `옵션`

-- EX: 
ALTER TABLE `ACCOUNT_REQUEST` ADD `memo` text COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '보류/삭제시 사유를 기록하기 위한 컬럼' AFTER `disapproval_reason`;
```

## 컬럼 삭제

``` sql
alter table [테이블명] drop [컬럼명];

-- EX:
ALTER TABLE `BILLING_SETTING` DROP "pkid";
```

## 컬럼 수정

``` sql
ALTER TABLE `테이블명` CHANGE `기존컬럼명` `새컬럼명` 기존 자료형

-- EX:
ALTER TABLE `CLIENT_MAILING_SETTING` CHANGE `client_mailng_setting_id` `client_mailing_setting_id` int(11) NOT NULL AUTO_INCREMENT;
```

## 유니크 키 삽입

``` sql
ALTER TABLE TableName ADD UNIQUE INDEX IndexName (column1, column2);

-- EX:
ALTER TABLE `APPROVAL_CATEGORY_BY_SERVICE` ADD UNIQUE INDEX category_key(service_id, approval_category_id, grade);
```

## 외래키 삽입

``` sql
ALTER TABLE TableName ADD CONSTRAINT ConstraintKeyName FOREIGN KEY('columnName') REFERENCES ParentTableName ('ParentPKKeyName') [ON DELETE CASCADE / ON UPDATE CASCADE];

-- EX:
ALTER TABLE WIDGET__MAP ADD CONSTRAINT `option_id` FOREIGN KEY(`option_id`) REFERENCES WIDGET_OPTION (`option_id`) ON DELETE CASCADE ON UPDATE CASCADE
```

## 유니크/인덱스 삭제

``` sql
ALTER TABLE TableName DROP INDEX IndexName;

-- EX:
ALTER TABLE `APPROVAL_CATEGORY_BY_SERVICE` DROP INDEX service_id;
```

## ROW 추가

``` sql
INSERT INTO 테이블명(COLUMN_LIST)
VALUES (Values);

-- EX:
-- 1. 데이터 1개만 삽입할 때
INSERT INTO WIDGET_TYPE_PRESET_INDEX(name) VALUES ('inventory'), ();

-- 2. 데이터 여러개 삽입할 때
INSERT INTO WIDGET_TYPE_PRESET_INDEX(name) VALUES ('placement'), ('shape for PC');
```

## ROW 업데이트

``` sql
-- EX:
UPDATE ad_admin.MEZZO_CHANNEL_REQUEST
SET status = 2, manager_name = 'Yeseul Seo', manager_message = '4/2'
WHERE status = 0;
```

## DB 커넥션 개수 체크 및 상태 확인

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
