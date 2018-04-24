#1932번 문제#

**숫자 삼각형.**

**문제**
```
         7
      3   8
    8   1   0
  2   7   4   4
 4   5   2   6   5
```
>위 그림은 크기가 5인 숫자 삼각형의 한 모습이다.

>맨 위층 7부터 시작해서 아래에 있는 수 중 하나를 선택하여 아래층으로 내려올 때, 이제까지 선택된 수의 합이 최대가 되는 경로를 구하는 프로그램을 작성하라. 아래층에 있는 수는 현재 층에서 선택된 수의 대각선 왼쪽 또는 대각선 오른쪽에 있는 것 중에서만 선택할 수 있다.

>삼각형의 크기는 1 이상 500 이하이다. 삼각형을 이루고 있는 각 숫자는 모두 정수이며, 범위는 0 이상 99 이하이다.

**입력**
> 첫째 줄에 삼각형의 크기 n(1≤n≤500)이 주어지고, 둘째 줄부터 n+1줄까지 숫자 삼각형이 주어진다.

**출력**
> 첫째 줄에는 최대가 되는 합을 출력한다.

``` c
#include<stdio.h>
#define MAX(X, Y) ((X > Y) ? X : Y)
#define MAX_NUMBER 501

int calc(int (*bucket)[MAX_NUMBER], int height);

int main(void) {
	int triangle_height, i, j, number_cnt = 0;
	int bucket[MAX_NUMBER][MAX_NUMBER] = { 0 };

	scanf("%d", &triangle_height);

	for (i = 1; i <= triangle_height; i++) {
		for (j = 1; j <= i; j++) {
			scanf("%d", &bucket[i][j]);
		}
	}
    
	// 배열에 잘 들어 갔는지 확인하는 용도.
	//for (i = 1; i <= triangle_height; i++) {
	//	for (j = 1; j <= i; j++) {
	//		printf("%d ", bucket[i][j]);
	//	}
	//	printf("\n");
	//}

	calc(bucket, triangle_height);
	
    // 계산이 잘 됬는지 확인하는 용도.
	//for (i = 1; i <= triangle_height; i++) {
	//	for (j = 1; j <= i; j++) {
	//		printf("%d ", bucket[i][j]);
	//	}
	//	printf("\n");
	//}

	return 0;
}

int calc(int (*bucket)[MAX_NUMBER], int height) {
	int i, j = 0, max_value = 0;

	for (i = 1; i <= height; i++) {
		if (i == 1) {
        	// i == 1일떄는 계산할 필요가 없다.
			continue;
		}

		if (i == 2) {
        	// i == 2일때는 그냥 값을 넣어줬다.
			bucket[i][1] = bucket[i - 1][1] + bucket[i][1];
			bucket[i][2] = bucket[i - 1][1] + bucket[i][2];
			continue;
		}

		for (j = 1; j <= i; j++) {
			if (j == 1) {
            	// 맨 앞은 계산할 수 있는 값이 윗 라인 맨 앞만 가능.
				bucket[i][j] = bucket[i][j] + bucket[i - 1][j];
			}
			else if (j == i) {
            	// 맨 뒷 값은 계산 할 수 있는 값이 윗 라인 맨 뒤만 가능.
				bucket[i][j] = bucket[i][j] + bucket[i - 1][j-1
			}
			else {
				//printf("bucket[%d][%d] = %d =====> bucket[%d][%d] = %d, bucket[%d][%d] = %d\n"
					//, i, j, bucket[i][j], i - 1, j-1, bucket[i - 1][j-1], i - 1, j, bucket[i - 1][j]);
				bucket[i][j] = MAX((bucket[i][j] + bucket[i - 1][j-1]), (bucket[i][j] + bucket[i - 1][j ]));
			}
		}
	}

	for (int i = 1; i <= height; i++) {
    	// 맨 마지막 라인에서 최대값을 뽑으면 된다.
		max_value = MAX(bucket[height][i], max_value);
	}
	printf("%d", max_value);
}
```

| No      | ID        | Quest.NO | Result  | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|---------|------------|-------|-----------|-------------|
| 4589498 | select995 | 1932     | SUCCESS | 1808 KB    | 20 MS | C         | 1653 B      |

> 이제야 DP가 몬지 감이 온다. 처음에 문제 풀때는 순환 함수로 풀어야지~ 라고 생각 했다가 풀다 보니 궂이 순환 함수로 풀 필요도 없을거 같아서 그냥 풀었더니 잘 풀렸다. 예제로 입력해서 정답이 잘 나왔는데 혹시 몰라서 내가 그림 그리면서 만든 예제 몇번 더 해봤더니 잘 풀려서 채점 했더니 한번에 맞췄다. 나도 실력이 느는 건가.. 싶기도 한데 다른 사람 소스랑 비교해보면 또 좌절.. OTL... 

> 하여튼 문제를 풀었다는거에 의미를 둬야겠다.!