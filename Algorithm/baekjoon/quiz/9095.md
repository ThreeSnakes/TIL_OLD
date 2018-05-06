#9095번 문제#

**1,2,3 더하기**

**문제**
> 정수 4를 1, 2, 3의 조합으로 나타내는 방법은 총 7가지가 있다.

   - 1+1+1+1
   - 1+1+2
   - 1+2+1
   - 2+1+1
   - 2+2
   - 1+3
   - 3+1

> 정수 n이 주어졌을 때, n을 1,2,3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

**입력**
> 첫쨰 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

**출력**
> 각 테스트 케이스마다, n을 1,2,3의 합으로 나타내는 방법의 수를 출력한다.

``` c
#include<stdio.h>
#define MAX_NUM 12

int _bucket[MAX_NUM] = { 0 };

int calc(int num);

int main(void) {
	int _num, _test_cnt;
	int i;

	scanf("%d", &_test_cnt);

	for (i = 0; i < _test_cnt; i++) {
		scanf("%d", &_num);
		printf("%d\n", calc(_num));
	}


}

int calc(int num) {
	int i, cnt = 0;

	_bucket[0] = 1;
	_bucket[1] = 1;
	_bucket[2] = 2;
	
	if (_bucket[num] == 0) {
		for (i = 3; i <= num; i++) {
			if (_bucket[i] != 0) {
				continue;
			}

			if (_bucket[i - 1] != 0 || i - 1 == 0) {
				cnt = cnt + _bucket[i - 1];
			}
			
			if (_bucket[i - 2] != 0 || i - 2 == 0) {
				cnt = cnt + _bucket[i - 2];
			}

			if (_bucket[i - 3] != 0 || i - 3 == 0) {
				cnt = cnt + _bucket[i - 3];
			}
			_bucket[i] = cnt;
			cnt = 0;
		}
		return _bucket[num];
	}
	else {
		return _bucket[num];
	}
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|------|-----------|-------------|
| 4705759 | select995 | 9095     | SUCCESS!! | 1116 KB    | 0 MS | C         | 852 B       |
| 4705731 | select995 | 9095     | FAIL      |            |      | C         | 835 B       |

> [동전1](https://github.com/jonathan-lim/TIL/blob/master/Algorithm/(NO.%202293)%20%EB%8F%99%EC%A0%841.md) 문제와 비슷했다. 아니 오히려 동전1 문제는 중복되거를 없애는것이 관건 이었는데 이번 문제는 중복된거를 지우지 않는게 문제였다. 동전1 풀때 기억으로 푸니깐 금발 풀렸다. 그런데 틀렸습니다. 가 한버 나왔는데 이거는 출력할때 라인 바꿈을 안해줬다.;; 그래서 틀렸습니다 나온거였다. 아끕네. 