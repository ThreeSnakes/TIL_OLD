#2293번 문제#

**동전1**

> n가지 종류의 동전이 있다. 각각의 동전이 나타내는 가치는 다르다. 이 동전들을 적당히 사용해서, 그 가치의 합이 k원이 되도록 하고 싶다. 그 경우의 수를 구하시오. (각각의 동전은 몇 개라도 사용할 수 있다.)

**입력**
> 첫째줄에 n, k가 주어진다. (1 ≤ n ≤ 100, 1 ≤ k ≤ 10,000) 다음 n개의 줄에는 각각의 동전의 가치가 주어진다.

**출력**
> 첫째 줄에 경우의 수를 출력한다. 경우의 수는 2^31보다 작다.

``` c
#include<stdio.h>
#define MAX_COIN_CNT 100
#define MAX_COIN_SUM 10001

int main(void) {	
	int _coin_cnt, _money;
	int _coin_bucket[MAX_COIN_CNT] = { 0 };
	int _calc_bucket[MAX_COIN_SUM] = { 0 };
	int i, j;

	scanf("%d %d", &_coin_cnt, &_money);

	for (i = 0; i < _coin_cnt; i++) {
		scanf("%d", &_coin_bucket[i]);
	}

	/*for (i = 0; i < _coin_cnt; i++) {
		printf("[ %d ]", _coin_bucket[i]);
	}*/

	_calc_bucket[0] = 1;

	for (i = 0; i < _coin_cnt; i++) {
		for (j = _coin_bucket[i]; j <= _money; j++) {
			_calc_bucket[j] = _calc_bucket[j] + _calc_bucket[j - _coin_bucket[i]];
		}
	}

	/*for (i = 0; i <= _money; i++) {
		printf("[ %d ]", _calc_bucket[i]);
	}*/
	printf("%d", _calc_bucket[_money]);
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|------|-----------|-------------|
| 4667943 | select995 | 2293     | SUCCESS!! | 944 KB     | 0 MS | C         | 733 B       |

> 엄청 어렵게 풀었다. 2일 걸린것 같다. 점화식을 잘못 세워서 예제로 나온 정답도 잘 안나왔는데 이유는 중복되는 경우를 제외하는 것을 생각하느라 오래 걸렸다.

> 동전이 `2 3 5` 가 있을때 5로 갈수 있는 방법은 `2 3`, `5` 두 가지 인데 `2 3`과 `3 2`를 중복으로 세는 것이었다. 결국 `2` 한번 `3` 한번으로 같은 것인데 너무 어렵게 풀려고 했다. 하.. 막상 풀고나니깐 약간 허탈하다. 쉽게 풀리는 건데... 

> 하여튼 풀긴 풀었는데.... 내 힘으로만 푼것 같은 느낌이 아니어서 허탈하고 짜증난다.....