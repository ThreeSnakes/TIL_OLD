# hook에서 2개의 변수가 동시에 수정 될때

날짜 필터를 개발하는데 아래처럼 **시작일**, **종료일**과 같이 2개의 데이터가 동시에 변경되는 경우가 있었다.

![날짜 필터](attach/%EC%8A%A4%ED%81%AC%EB%A6%B0%EC%83%B7%202021-03-05%20%EC%98%A4%ED%9B%84%207.05.51.png)

사용자가 **시작일**, **종료일**을 선택한뒤 apply를 클릭하면 이벤트가 발생하고, 거기서 startTime, endTime을 이용해 fetch를 하는 간단한 코드였다.

처음에는 변수를 다음처럼 선언해서 개발을 진행했었는데 날짜를 변경하면 조회가 두번이 진행되는 것을 확인할 수 있었다.

```js
const [startDate, setStartDate] = useState(dayjs().add(\-7, 'day'));
const [endDate, setEndDate] = useState(dayjs().add(0, 'day'));

const setDateRange = () => {
// 사용자가 선택한 startDate, endDate를 얻어온다.

startDate && setStartDate(startDate);
endDate && setEndDate(endDate);
}
```

```text
## log
app_1    | [0] GET URL/ALL?limit=10&offset=0&author=ALL&search_start_date=2021-03-04%2000:00:00&search_end_date=2021-03-05%2023:59:59 304 118.875 ms - -
app_1    | [0] GET URL/ALL?limit=10&offset=0&author=ALL&search_start_date=2021-03-04%2000:00:00&search_end_date=2021-03-06%2023:59:59 304 124.286 ms - -
```

대충 보니깐 처음 로그는 `setStartDate()`를 하면서 바뀐 state로 fetch를 한것이고, 두번째 로그는 `setEndDate()` 수행하면서 바뀐 state로 fetch를 하는 것이다.

결국 한번 수행해야할 fetch를 2번 하는것이며, 심지어 첫번째는 의도하지 않은 fetch가 되는 것이다.

이를 해결하기 위해서 state를 object로 만들어서 처리해주니 변경이 되어도 한번만 잘 수행되었다.

```js
const [searchDate, setSearchDate] = useState({ searchStartDate: dayjs().add(-7, 'day'), searchEndDate: dayjs().add(0, 'day') });

const setDateRange = () => {
// 사용자가 선택한 startDate, endDate를 얻어온다.
startDate && endDate && setSearchDate({ searchStartDate: startDate, searchEndDate: endDate });
};
```

```text
## log
app_1    | [0] GET URL/ALL?limit=10&offset=0&author=ALL&search_start_date=2021-02-26%2000:00:00&search_end_date=2021-03-05%2023:59:59 304 1177.118 ms - -
```

## 결론
- state 여러개가 동시에 변경되야 하는 경우라면 이를 object로 만들어서 동작하도록 하자.

#react
#hook