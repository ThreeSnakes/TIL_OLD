# jest

## 실행 옵션
- watch
	- 테스트가 변경됨을 감지해서 실행을 알아서 해준다.
	``` bash
	jest --watch
	```
	
## 기능

- paramerterizse Test
	- 동일한 테스트 코드를 여러개의 파라미터로 테스트를 지원하는 것.
	- jest 에서는 `decribe.each`를 사용하면 된다.
		```js
		describe.each`
			a    | b    | expected
			${1} | ${1} | ${2}
			${1} | ${2} | ${3}
			${2} | ${1} | ${3}
		`('$a + $b', ({a, b, expected}) => {
			test(`returns ${expected}`, () => {
				expect(a + b).toBe(expected);
			});

			test(`returned value not be greater than ${expected}`, () => {
				expect(a + b).not.toBeGreaterThan(expected);
			});

			test(`returned value not be less than ${expected}`, () => {
				expect(a + b).not.toBeLessThan(expected);
			});
		});
		```

## 개별 테스트마다 import되는 Class를 mocking하는 방법

Service Class는 dao Class를 최소 하나 의존하고 있는 상태로 코드를 작성하고 있다. 테스트마다 dao에서 호출하는 함수의 리턴값을 각각 다르게 mocking해야 하는 경우가 있는데 이럴 경우 사용하는 방법을 정리해 본다.

``` js
import * as HistoryType from '../../../src/type/media/HistoryType';
import HistoryService from '../../../src/services/media/HistoryService';
import HistoryDao from '../../../src/dao/media/HistoryDao';

const MOCK = {
  CLIENT: {
    history_id: 174761,
    client_id: 1,
    client_name: "한겨레신문(주)",
    service_id: 2,
    service_name: "m.hani.co.kr",
    action: "수동입금",
    accumulated_cost: 10000.00,
    withdraw_cost: 0.00,
    balance: 40000.00,
    manager: "Dabler",
    memo: "test_memo",
    local_basic_time: "2021-04-16 10:59:57",
    edit_form_json: null,
    is_edited: 0,
    is_migrated: 0,
    is_hidden: 0,
    edit_time: null,
    c_time: new Date("2021-04-16 10:59:58")
  },
  CLIENT2: { history_id: 111 },
}

describe('Test HistoryService', () => {
  beforeEach(() => {
    // 개별 테스트마다 HistoryDao를 다르게 mocking하기 위해서 Test가 끝난후에 reset해준다.
    jest.resetModules();
  })

  describe('Test getHistory()', () => {
    it('works', async () => {
      HistoryDao.prototype.getHistory = jest.fn().mockImplementation(() => {
        return MOCK.CLIENT;
      });
      const historyService = new HistoryService();
      const result = await historyService.getHistory(1);
      expect(result).toEqual(MOCK.CLIENT);
    });

    it('works2', async () => {
      HistoryDao.prototype.getHistory = jest.fn().mockImplementation(() => {
        return MOCK.CLIENT2;
      });
      const historyService = new HistoryService();
      const result = await historyService.getHistory(2);
      expect(result).toEqual(MOCK.CLIENT2);
    });
  });

  describe('Test getHistory2()', () => {
    it('works2', async () => {
      console.log(HistoryDao.prototype.getHistory(30))
      HistoryDao.prototype.getHistory = jest.fn().mockImplementation(() => {
        return MOCK.CLIENT;
      });
      const historyService = new HistoryService();
      const result = await historyService.getHistory(2);
      expect(result).toEqual(MOCK.CLIENT);
    });
  });
});
```