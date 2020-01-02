# Insert 할 때 value에 케이스 조건 주기

특정 테이블에 값을 넣을때 Parent 테이블의 ID 가 같은 경우일때 특정 값이 하나로 통일되야 하는 경우가 생겼다.

코드로 관리하자니 조금 까다로운거 같아서 일단 INSERT 쿼리에 조건을 줘서 값이 같지 않을 경우에 NULL을 주는 형태로 처리 하였다.

이러면 해당 컬럼 값은 NOT NULL로 정의 되어 있는데 NULL이 들어오니 해당 쿼리를 수행하면 ERROR가 나도록 되어 있다.

좋은 형태는 아닌거 같은데 다른 다양한 방법을 찾아봐야 할 것같다. 일단은 이런 형태의 쿼리도 된다는 것을 기억하기 위해 저장해 놓는다.

``` sql
INSERT INTO Table_name(name, type, parent_id, is_requirement)
  VALUES ( ?,
    (
      CASE
        -- 첫번째 WHEN의 경우 같은 부모의 카테고리가 하나로 통일 되었다는 가정하에 넣었다.
        -- 이러면 코드로 실행 되는 경우에는 문제가 없어 보이는데 DB에 값을 직접 넣었을 경우 문제가 생길 수 있다.
        WHEN (SELECT type FROM Table_name PT WHERE parent_id = ? LIMIT 1) = ? THEN ?
        -- 두번째 WHEN의 경우 같은 부모의 카테고리가 하나도 없는 경우를 가정하에 넣었다.
        -- 하위 카테고리로 처음 넣는 경우 첫번째 조건에 맞지 않기 때문에 이 조건으로 하나도 없는 경우를 충족 시킨다.
        WHEN (SELECT COUNT(type) FROM Table_name PT WHERE parent_id = ?) = 0 THEN ?
        -- 아래는 위 2가지 경우가 아닌 경우 null을 넣도록 하여 쿼리 수행시 에러가 발생하도록 한다.
        ELSE null
      END
    )
  , ?, ? );
```

좋은 방법은 아닌것 같아서 상당히 찜찜하다.
