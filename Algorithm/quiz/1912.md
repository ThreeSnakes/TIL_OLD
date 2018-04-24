#1912번 문제#

**연속 합.**

**문제**
> n개의 정수로 이루어진 임의의 수열이 주어진다. 우리는 이 중 연속된 몇 개의 숫자를 선택해서 구할 수 있는 합 중 가장 큰 합을 구하려고 한다. 단, 숫자는 한 개 이상 선택해야 한다.

> 예를 들어서 10, -4, 3, 1, 5, 6, -35, 12, 21, -1 이라는 수열이 주어졌다고 하자. 여기서 정답은 12+21인 33이 정답이 된다.

**입력**
> 첫째 줄에 정수 n(1≤n≤100,000)이 주어지고 둘째 줄에는 n개의 정수로 이루어진 수열이 주어진다. 수는 -1,000보다 크거나 같고, 1,000보다 작거나 같은 정수이다.

**출력**
> 첫째 줄에 답을 출력한다.

``` c
#include<stdio.h>

#define MAX_INPUT 100000
#define MAX(x,y) ((x > y) ? x:y)

void main() {
	int _input_cnt;
	int _number_bucket[MAX_INPUT];
	int i, _ret = -9999;

	scanf("%d", &_input_cnt);

	for (i = 0; i < _input_cnt; i++) {
		scanf("%d", &_number_bucket[i]);
	}

	// 배열에 잘 들어갔는지 확인용 출력.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	/*printf("\n");*/

	// 끝에서 부터 풀면 쉽게 풀린다.
	// 연속된 숫자를 선택 하므로. 맨 마지막은 자기 자신만 선택할 수 있다.
	// 뒤에서 두번째 숫자는 자기 자신과 마지막 숫자를 선택 할 수 있는데
	// 여기서 자기 자신 + 마지막, 자기 자신을 비교해서 더 큰값을 저장하면
	// 그 수터 연속으로 선택할때 가장 큰 수를 저장하게 되는 것이다.
	for (i = _input_cnt - 2; i >= 0; i--) {
		_number_bucket[i] = MAX(_number_bucket[i], _number_bucket[i] + _number_bucket[i + 1]);
	}

	// 계산이 잘 됬는지 확인용 출력.
	/*for (i = 0; i < _input_cnt; i++) {
		printf("[ %d ]", _number_bucket[i]);
	}*/

	for (i = 0; i < _input_cnt; i++) {
		_ret = MAX(_ret, _number_bucket[i]);
	}

	printf("%d", _ret);
	
}
```

| No      | ID        | Quest.NO | Result  | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|---------|------------|------|-----------|-------------|
| 4702029 | select995 | 1912     | SUCCESS | 1388 KB    | 8 MS | C         | 1258 B      |

> 한 15분만에 푼거 같다. 깊게 생각할 필요도 없었다. 그냥 거꾸로 계산하면 풀리는 쉬운 문제 였다. 흠.. 한문제 더 풀어야 겠다.