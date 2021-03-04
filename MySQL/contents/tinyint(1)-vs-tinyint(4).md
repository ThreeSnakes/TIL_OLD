# tinyint(1) vs tinyint(4)

## 목차

- [정리](tinyint(1)-vs-tinyint(4).md#%EC%A0%95%EB%A6%AC)
  - [tinyint(1) vs tinyint(4)](tinyint(1)-vs-tinyint(4).md#tinyint1-vs-tinyint4)
  - [ZEROFILL](tinyint(1)-vs-tinyint(4).md#zerofill)
  - [결론](tinyint(1)-vs-tinyint(4).md#%EA%B2%B0%EB%A1%A0)
- [참조](tinyint(1)-vs-tinyint(4).md#%EC%B0%B8%EC%A1%B0)

### 정리

사내에서 MySql을 사용하고 있는데 때때로 On/Off 용도의 컬럼을 추가할 일이 생겼다.
이런 컬럼을 선언할 때 나는 일반적으로 다음처럼 사용하였다.

``` sql
`use_fixed_amount` tinyint(4) DEFAULT NULL COMMENT '불라불라불라',
```

위와 같은 형태로 사용을 하였는데 Code Review를 받았는데 `tinyint(1)` 로 쓰면 좋을 것 같다라는 내용을 리뷰로 받아서 2개의 차이점을 정리해 보았다.

#### tinyint(1) vs tinyint(4)

- 사실 정수 타입의 데이터를 선언할 때 뒤의 길이 지정은 `ZEROFILL` 옵션이 없으면 아무런 의미가 없다고 한다. `tinyint(1)`로 선언하나 `tinyint(4)`로 선언하나 해당 값에 들어갈 수 있는 데이터는 `-127 ~ 127`까지의 숫자로 데이터에는 영향을 미치지 않는다.
- 즉, **정수 타입에서는 아무런 의미가 없다.**

#### ZEROFILL

- `ZEROFILL` 옵션은 실질 숫자 값의 앞쪽에 0을 패딩해서 가져올 것인지를 설정하는 옵션이다.
- 다만 ZEROFILL 옵션을 사용한다는 것은 해당 컬럼은 **UNSINGED 타입**이 되버려 양수만 저장할 수 있다.

``` sql
mysql> SELECT * FROM test;
+------------+-------------+
| a          | b           |
+------------+-------------+
|         30 | 00000000030 |
| 1234567890 | 01234567890 |
|     111111 | 00000111111 |
+------------+-------------+
```

#### 결론

- 결론적으로 `tinyint(1)`을 쓰나 `tinyint(4)`를 쓰나 큰차이가 없어서 이를 말씀드렸고, 리뷰 주신분도 크게 의미있게 드린 리뷰가 아니라고 하셔서 그냥 넘어가도록 하였다. 사실 해당 테이블은 내가 처음에 만든 테이블이 아니고 기을을 추가하면서 새로운 컬럼이 생긴 것이라 처음 작성한 사람의 포맷을 따르는게 좋은 것 같아서 그냥 `tinyint(1)`로 수정하지 않고 그대로 작성하였다.

#### 참조

- [Real MySql](http://www.yes24.com/Product/Goods/6960931?Acode=101)
  - 887p. 정수 타입의 컬럼을 생성할 때의 주의사항