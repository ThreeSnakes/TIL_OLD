#1149번 문제#

**RGB 거리.**

> RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 집 i의 이웃은 집 i-1과 집 i+1이다. 처음 집과 마지막 집은 이웃이 아니다.

> 각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다.

**출력**
> 첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.

``` c
#include<stdio.h>
#define MAX_HOUSE_CNT 1001
#define MIN(X,Y) ((X < Y ) ? X : Y )

int main(void) {
	int _house_cnt;
	int _price_bucket[MAX_HOUSE_CNT][3];
	int i, j, sum = 0;

	scanf("%d", &_house_cnt);

	for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &_price_bucket[i][j]);
		}
	}

	/*for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			printf("[ %d ] ", _price_bucket[i][j]);
		}
		printf("\n");
	}*/

	if (_house_cnt == 1) {
		sum = MIN(_price_bucket[1][0], MIN(_price_bucket[1][1], _price_bucket[1][2]));
	}
	else {
		for (i = 2; i <= _house_cnt; i++) {
			for (j = 0; j < 3; j++) {
				if (j == 0) {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][1] + _price_bucket[i][j], _price_bucket[i - 1][2] + _price_bucket[i][j]);
				}
				else if (j == 1) {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][0] + _price_bucket[i][j], _price_bucket[i - 1][2] + _price_bucket[i][j]);
				}
				else {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][0] + _price_bucket[i][j], _price_bucket[i - 1][1] + _price_bucket[i][j]);
				}
			}
		}

		sum = MIN(_price_bucket[_house_cnt][0], MIN(_price_bucket[_house_cnt][1], _price_bucket[_house_cnt][2]));
	}
	

	/*printf("\n");
	for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			printf("[ %d ] ", _price_bucket[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", sum);
	return 0;
}
```

| No      | ID        | Quest.NO | Result  | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|---------|------------|------|-----------|-------------|
| 4648938 | select995 | 1149     | SUCCESS | 948 KB     | 0 MS | C         | 1445 B      |

> 엄청 쉽게 풀었다. DP로 그냥 푸니깐 나온다. 따로 생각할 것도 없었다. 근데 풀고나서 소스코드 길이가 유난히 작은 분 코드를 봤는데 하 진짜 내 소스에 딱 반 나온다. 불필요한 코드가 없었다. 내꺼는 약간 덕지덕지 붙어 있는 느낌이 많이 드는데.. 이런게 내공의 차이 인가 보다. 