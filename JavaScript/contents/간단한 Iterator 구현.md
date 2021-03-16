# 간단한 Iterator 구현

특정 조건을 만족하는 Row를 조회한뒤 해당 row에 있는 JSON 컬럼 두개를 obj로 parse하는 로직이 있었는데, 위 조건을 만족하는 Row가 33000개 가량 되고, 컬럼에 있는 데이터의 양도 상당하다보니 해등 스크립트를 돌리면 메모리가 터지는 경우가 발생 하였다.

이 경우 노드 메모리를 올리면 되지만 해당 스크립트를 돌리는데 메모리를 많이 사용하고 싶지 않아서 리스트를 나눠서 처리하는 방향으로 수정 하였다.

기존 Logic을 최대한 적게 수정하는 방향으로 하였는데 이때 iterator를 사용하였는데, 메모리도 적게 먹고, 기존 Logic도 큰 수정 필요없이 잘 동작하였다. 나중에 또 쓸 수도 있으니 간단하게 iterator를 만드는 법을 적어 놓는다.


```js
// 간단 구현.
// array에 iterator 심볼을 달아주면 된다.
// 근데 array이는 이미 iterable 객체여서 궂이 이렇게 할 필요가 없다.
const array = [0, 1, 2, 3, 4, 5];
const iter = offsets[Symbol.iterator]();

return iter;

// 예제
// 해당 함수를 동작하면 iterator가 반환된다.
const makeOffsetIterator = (total_count = 0) => {
  const JOB_PER_OFFSET = 500;
  const offsets = _.range(0, Math.ceil(total_count / JOB_PER_OFFSET) * JOB_PER_OFFSET, JOB_PER_OFFSET);
  const iter = offsets[Symbol.iterator]();

  return iter;
};

// Test 코드
// 반환된 iterator의 value와 예상되는 결과를 비교하는 방식으로 테스트를 작성하였다.
describe('Test makeOffsetIterator()', () => {
  const topic = rewire('../../../ci_jobs/cron_widget_multiarmed_bandit/service');
  const makeOffsetIterator = topic.__get__('makeOffsetIterator');
  const JOB_PER_OFFSET = topic.__get__('JOB_PER_OFFSET');

  it('Case 1. total_count가 0일 경우', () => {
    const result = makeOffsetIterator(0);
    const empty_arr = [];
    const empty_iter = empty_arr[Symbol.iterator]();

    result.should.eql(empty_iter);
  });

  it('Case 2. JOB_PER_COUNT 보다 작을 경우', () => {
    const enabled_widget_count = 500;
    const result_iter = makeOffsetIterator(enabled_widget_count);
    const arr = _.range(0, Math.ceil(enabled_widget_count / JOB_PER_OFFSET) * JOB_PER_OFFSET, JOB_PER_OFFSET);

    const result = [];

    for (const offset of result_iter) {
      result.push(offset);
    }

    result.should.eql(arr);
  });

  it('Case 3. JOB_PER_COUNT 보다 클 경우', () => {
    const enabled_widget_count = 5222;
    const result_iter = makeOffsetIterator(enabled_widget_count);
    const arr = _.range(0, Math.ceil(enabled_widget_count / JOB_PER_OFFSET) * JOB_PER_OFFSET, JOB_PER_OFFSET);

    const result = [];

    for (const offset of result_iter) {
      result.push(offset);
    }

    result.should.eql(arr);
  });
});
```

## 참조

[MDN - Array.prototype[@@iterator]()](https://developer.mozilla.org/ko/docs/Web/JavaScript/Reference/Global_Objects/Array/@@iterator)