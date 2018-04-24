#9465번 문제#

**스티커.**

> 상근이의 여동생 상냥이는 문방구에서 스티커 2n개를 구매했다. 스티커는 그림 (a)와 같이 2행 n열로 배치되어 있다. 상냥이는 스티커를 이용해 책상을 꾸미려고 한다.

> 상냥이가 구매한 스티커의 품질은 매우 좋지 않다. 스티커 한 장을 떼면, 그 스티커와 변을 공유하는 스티커는 모두 찢어져서 사용할 수 없게 된다. 즉, 뗀 스티커의 왼쪽, 오른쪽, 위, 아래에 있는 스티커는 사용할 수 없게 된다.

![Alt text](https://github.com/jonathan-lim/TIL/blob/master/Algorithm/img/9465.png)

> 모든 스티커를 붙일 수 없게된 상냥이는 각 스티커에 점수를 매기고, 점수의 합이 최대가 되게 스티커를 떼어내려고 한다. 먼저, 그림 (b)와 같이 각 스티커에 점수를 매겼다. 상냥이가 뗄 수 있는 스티커의 점수의 최대값을 구하는 프로그램을 작성하시오. 즉, 2n개의 스티커 중에서 점수의 합이 최대가 되면서 서로 변을 공유 하지 않는 스티커 집합을 구해야 한다.

> 위의 그림의 경우에 점수가 50, 50, 100, 60인 스티커를 고르면, 점수는 260이 되고 이 것이 최대 점수이다. 가장 높은 점수를 가지는 두 스티커 (100과 70)은 변을 공유하기 때문에, 동시에 뗄 수 없다.

**입력**
> 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스의 첫째 줄에는 n (1 ≤ n ≤ 100,000)이 주어진다. 다음 두 줄에는 n개의 정수가 주어지며, 각 정수는 그 위치에 해당하는 스티커의 점수이다. 연속하는 두 정수 사이에는 빈 칸이 하나 있다. 점수는 0보다 크거나 같고, 100보다 작거나 같은 정수이다.

**출력**
> 각 테스트 케이스 마다, 2n개의 스티커 중에서 두 변을 공유하지 않는 스티커 점수의 최대값을 출력한다.

```
#include<stdio.h>
#define MAX_NUMBER 100001
#define MAX(X,Y) ((X > Y) ? X : Y)

int main(void) {
	int test_case, number_cnt, test_cnt, i, j;
	// 정답을 저장할 배열.
	int calc_bucket[100] = { 0 };
	// 스티커 점수를 저장할 배열.
	int bucket[2][MAX_NUMBER] = { 0 };

	scanf("%d", &test_case);

	for (test_cnt = 0; test_cnt < test_case; test_cnt++ ){
		scanf("%d", &number_cnt);

			for (i = 0; i < 2; i++) {
				for (j = 1; j <= number_cnt; j++) {
					scanf("%d", &bucket[i][j]);
				}
			}

		if (number_cnt == 1) {
			calc_bucket[test_cnt] = MAX(bucket[0][1], bucket[1][1]);
			continue;
		}
		else {
			for (j = 1; j <= number_cnt; j++) {
				if (j == 1) {
					continue;
				}

				bucket[0][j] = MAX(bucket[0][j] + bucket[1][j - 1], MAX(bucket[0][j - 2], bucket[1][j - 2]) + bucket[0][j]);
				bucket[1][j] = MAX(bucket[1][j] + bucket[0][j - 1], MAX(bucket[0][j - 2], bucket[1][j - 2]) + bucket[1][j]);
			
			}
		}

		//for (i = 0; i < 2; i++) {
		//	for (j = 1; j <= number_cnt; j++) {
		//		printf("[ %d ]", bucket[i][j]);
		//	}
		//	printf("\n");
		//}
		calc_bucket[test_cnt] = MAX(bucket[0][number_cnt], bucket[1][number_cnt]);
	}

	for (i = 0; i < test_case; i++) {
		printf("%d\n", calc_bucket[i]);
	}

	return 0;
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time    | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|---------|-----------|-------------|
| 4625553 | select995 | 9465     | SUCCESS!! | 1612 KB    | 1316 MS | C         | 1347 B      |

> 계단 오르기, 포두주 시식을 풀고나서 풀었는데 앞에꺼와 비슷한 유형이라 그런지 쉽게 풀었다. 다만 정답을 저장하는 `calc_bucket`의 크기를 100으로 선언했는데 문제에서 `T`가 최대 몇인지 안나와 있어서 일단 100으로 잡았는데 문제없이 풀리는거 보니깐 상관 없나 보다.

> 메모리와 시간이 다른 사람들에 비해서 평균 정도 되는 듯 하다. 높지도, 낮지도 않고 평균 정도..? 뭐 나쁘지 않게 짠듯 한데.. 이거 정답맞추고 리팩토링 안해서 약간 지저분하기도 하다.

> 마지막에 `calc_bucket`에 계산 결과를 저장할 때 `MAX`로 배열의 마지막값을 비교해서 출력 하는데 마지막 이전 값에서 더 클수도 있지 않을까란 생각이 들었다.. 흠.. 일단 정답으로 나와서 맞춘거라 생각 하는데.. 찜찜하다. 예제에 모든 경우의 수가 포함되지 않을수도 있을거란 생각도 든다..;