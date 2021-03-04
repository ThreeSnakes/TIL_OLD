# MySQL에서 DELETE사용시 쿼리 속도가 엄청 안나올 경우

이럴 경우 `DELETE` 쿼리에서 `IN (SELECT ... )` 구문을 사용 하는지 확인해보자.

`DELETE`쿼리에서 `IN (SELECT ... )` 구문을 사용 할 경우 인덱스를 타지 않아서 속도가 엄청 느리게 나온다.

이럴경우 `IN (SELECT ... )`을 사용하지 말고 `JOIN`구문으로 수정한뒤 비교해 보자.

``` SQL
DELETE
FROM A
WHERE A.a IN ( SELECT id FROM B WHERE y = 6235 );

# ===> JOIN 구문으로 변경.

DELETE TmpA
FROM A TmpA
LEFT OUTER JOIN B TmpB ON TmpB.id = TmpA.info_id
WHERE TmpB.y = 6235;
```

### 결론.
DELETE 할때 `IN ( SELECT .... )` 구문 쓰지 말고 `JOIN` 해서 쓰자(!?).
