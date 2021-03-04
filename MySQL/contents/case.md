# 컬럼값을 다른 값으로 변경해서 출력하기.

``` SQL
SELECT *,
        ( CASE status
            WHEN 0 THEN '대기'
            WHEN 1 THEN '시작'
            WHEN 2 THEN '중지'
            WHEN 3 THEN '완료'
          END
        ) AS 상태
FROM DATA
WHERE create '2017-01-01 00:00:00' AND '2017-11-01 00:00:00'
```
처럼 하면 된다. 그러면 `IF`문을 쓰는것과 동일한 효과를 줄수 있고!!!
훨씬 보기 쉽다. 삽질하지 말고 기억하자.