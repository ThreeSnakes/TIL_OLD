#2156번 문제#

**포도주 시식.**

>효주는 포도주 시식회에 갔다. 그 곳에 갔더니, 테이블 위에 다양한 포도주가 들어있는 포도주 잔이 일렬로 놓여 있었다. 효주는 포도주 시식을 하려고 하는데, 여기에는 다음과 같은 두 가지 규칙이 있다.

> 1. 포도주 잔을 선택하면 그 잔에 들어있는 포도주는 모두 마셔야 하고, 마신 후에는 원래 위치에 다시 놓아야 한다.
> 2. 연속으로 놓여 있는 3잔을 모두 마실 수는 없다.

>효주는 될 수 있는 대로 많은 양의 포도주를 맛보기 위해서 어떤 포도주 잔을 선택해야 할지 고민하고 있다. 1부터 n까지의 번호가 붙어 있는 n개의 포도주 잔이 순서대로 테이블 위에 놓여 있고, 각 포도주 잔에 들어있는 포도주의 양이 주어졌을 때, 효주를 도와 가장 많은 양의 포도주를 마실 수 있도록 하는 프로그램을 작성하시오. 

>예를 들어 6개의 포도주 잔이 있고, 각각의 잔에 순서대로 6, 10, 13, 9, 8, 1 만큼의 포도주가 들어 있을 때, 첫 번째, 두 번째, 네 번째, 다섯 번째 포도주 잔을 선택하면 총 포도주 양이 33으로 최대로 마실 수 있다.

**입력**
> 첫째 줄에 포도주 잔의 개수 n이 주어진다. (1≤n≤10,000) 둘째 줄부터 n+1번째 줄까지 포도주 잔에 들어있는 포도주의 양이 순서대로 주어진다. 포도주의 양은 1,000 이하의 정수이다.

**출력**
> 첫째 줄에 최대로 마실 수 있는 포도주의 양을 출력한다.

``` c
#include<stdio.h>
#define MAX_CNT 10001
#define MAX(X,Y) ((X > Y) ? X : Y)

int main(void) {
	int wine_cnt, i, j;
    // 포도주 양을 저장할 배열.
	int wine_bucket[MAX_CNT] = { 0 };
	// 포도주 더한 값을 저장 할 배열.
    // calc_bucket[i][j] 형태인데 calc_bucket[i][j]는
    // i번째 포도주를 마셨을 때까지의 총합이다. 1행은 i번이
    // 첫번째일때, 2행은 i번이 두번째 일때 값을 저장한다.
	int calc_bucket[2][MAX_CNT] = { 0 };
	int sum = 0, second_max_value;

	scanf("%d", &wine_cnt);

	for (i = 1; i <= wine_cnt; i++) {
		scanf("%d", &wine_bucket[i]);
	}

	if (wine_cnt < 3) {
		sum = wine_bucket[1] + wine_bucket[2];
		
		printf("%d", sum);

		return 0;
	}

	calc_bucket[0][1] = wine_bucket[1];
	calc_bucket[0][2] = wine_bucket[2];
	calc_bucket[1][2] = wine_bucket[1] + wine_bucket[2];
	second_max_value = calc_bucket[1][2];
	for (i = 3; i <= wine_cnt; i++) {
    	// 연속으로 두번 띄어넘을수도 있다. 이경우를 위해서 second_max_value에 두번째
        // 값중 가장 큰값을 저장해 놓는다.
		calc_bucket[0][i] = MAX(MAX(calc_bucket[0][i - 2] + wine_bucket[i], calc_bucket[1][i - 2] + wine_bucket[i]), second_max_value);
		calc_bucket[1][i] = calc_bucket[0][i - 1] + wine_bucket[i];
		if (second_max_value < calc_bucket[1][i]) {
			second_max_value = calc_bucket[1][i];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j <= wine_cnt; j++) {
			//printf("%d ", calc_bucket[i][j]);
			if (sum < calc_bucket[i][j]) {
				sum = calc_bucket[i][j];
			}
		}
		//printf("\n");
	}

	printf("%d", sum);

	return 0;
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|------|-----------|-------------|
| 4601672 | select995 | 2156     | SUCCESS!! | 948 KB     | 0 MS | C         | 1231 B      |
| 4601660 | select995 | 2156     | FAIL      |            |      | C         | 1185 B      |
| 4601516 | select995 | 2156     | FAIL      |            |      | C         | 997 B       |
| 4601512 | select995 | 2156     | FAIL      |            |      | C         | 959 B       |
| 4601486 | select995 | 2156     | FAIL      |            |      | C         | 1170 B      |

> 하 계단 오르기 계속 실패해서 일단 다음 문제로 넘어간거다. 문제 유형은 계단 오르기와 비슷 한데 난이도는 훨씬 쉽게 느껴진다. 그럼에도 `틀렸습니다`가 3번이나 나왔는데 계단오르기 처럼 1번만 건너 뛸 수 있다고 생각 했는데 연속으로 2번 띄어 넘을수 있는 상황도 있다. 이 상황을 생각하지 않아서 틀렸습니다가 3번이 나왔다. 흠.. 문제에는 연속으로 띄어 넘수 있다고 없었는데... 하여튼 어렵지 않게 풀었다. 계단오르기가 문제지....