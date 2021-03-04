# WHERE절에 NOT IN 과 IN이 같이 들어가는 경우

## 목차
- [WHY?](in_and_not_in.md#why)
- [TEST](in_and_not_in.md#test)
- [RESULT](in_and_not_in.md#result)

## WHY?

쿼리 수정 중 조건에 NOT IN () 절과 IN절을 같이 사용해야 하는 경우가 있었다.
그런데 각 IN절에 같은 조건이 들어갔을 경우 어떻게 처리되는지 궁금해저 실험해 보았다.

## TEST

### Only IN
``` sql
SELECT	COUNT(id)
FROM	  ad_stats.DAILY_CTR_4MEDIA_BY_SERVICE 
WHERE	  local_basic_time = '2020-08-31' and 
		    service_id IN ( 1, 2, 3);
		    
## COUNT(id) = 2
```

### Only NOT IN

``` sql
SELECT	COUNT(id)
FROM    ad_stats.DAILY_CTR_4MEDIA_BY_SERVICE 
WHERE   local_basic_time = '2020-08-31' and 
		    service_id NOT IN ( 1, 2, 3);
		    
## COUNT(id) = 2801
```

### NOT IN && IN 

``` sql
SELECT	COUNT(id)
FROM	  ad_stats.DAILY_CTR_4MEDIA_BY_SERVICE 
WHERE	  local_basic_time = '2020-08-31' and 
		    service_id IN ( 1, 2, 3) and 
		    service_id NOT IN ( 1, 2, 3);
		    
## COUNT(id) = 0
```

- WHERE 절에서 IN과 NOT IN의 순서를 바꿔도 결과는 똑같다.
- 사실 NOT IN과 IN이 같이 들어가는 것 자체가 조건에 부합하지 않는다.

## RESULT

WHERE 절에 NOT IN절과 IN절에 같은 조건이 들어가는 경우 쿼리 결과가 예상한것과는 다르게 나왔다.
IN 절과 NOT IN 절에 같은 값이 들어가는 경우 어떻게 처리할 것인지 고민이 필요하다.