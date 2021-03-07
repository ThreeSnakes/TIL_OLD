# DISTINCT와 GROUP BY 차이점

**DISTINCT**: Unique한 컬럼이나 중복된값을 제외하고 조회할때 사용.

**GROUP BY**: 데이터를 그룹핑해서 그 결과를 가져오는 경우에 사용.

DISTICNT <---> GROUP BY  일부 쿼리에서는 서로 바꿔서 사용할 수 있다.

내부적으로 동일한 코드 사용.

다만 DISTINCT는 결과가 정렬된 결과가 아니지만, GROUP BY는 정렬된 결과를 보여준다. 

GROUP BY는 그룹핑 + 정렬, DISTCINT는 그룹핑 작업만 하는 것이다. 

만약 정렬 기능이 필요 없다면 DISTINCT를 사용하는 것이 더 좋다고 할 수 있다. 

DISTICNT <---> GROUP BY  가 불가능한 경우가 있다. 
``` SQL
# DISTINCT
SELECT COUNT(DISTINCT fd1) FROM tab;

# GROUP BY
SELECT fd1, MIN(fd2), MAX(fd2) FROM tab GROUP BY fd1;
```