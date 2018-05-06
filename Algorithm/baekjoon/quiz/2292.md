#2292번 문제#

**벌집**

**문제**

![Alt text](https://github.com/select995/TIL/blob/master/algorithm/img/image.png)

> 위의 그림과 같이 육각형으로 이루어진 벌집이 있다. 그림에서 보는 바와 같이 중앙의 방 1부터 시작해서 이웃하는 방에 돌아가면서 1씩 증가하는 번호를 주소로 매길 수 있다. 숫자 N이 주어졌을 때, 벌집의 중앙 1에서 N번 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나가는지(시작과 끝을 포함하여)를 계산하는 프로그램을 작성하시오. 예를 들면, 13까지는 3개, 58까지는 5개를 지난다.

**입력**
> 첫째 줄에 N(1 ≤ N ≤ 1,000,000,000)이 주어진다.

**출력**
> 입력으로 주어진 방까지 최소 개수의 방을 지나서 갈 때 몇 개의 방을 지나는지 출력한다.

``` c
#include<stdio.h>

int main(void) {
	// 1 -> 6 -> 12 -> 18 -> 24... 6의 배수개로 늘어남.
	// 1 -> 13 3번, 1 -> 58 5번.
	int num;
	int hexagon_cnt = 1;
	int increas_cnt = 1;
	scanf("%d", &num);

	while (1) {
		if (num <= hexagon_cnt) {
			break;
		}
		hexagon_cnt = hexagon_cnt + (increas_cnt * 6);
		increas_cnt++;
	}

	printf("%d", increas_cnt);
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|------|-----------|-------------|
| 4543923 | select995 | 2292     | SUCCESS!! | 944 KB     | 0 MS | C         | 377 B       |

> 생각보다 많이 쉬웠다. 그런데 풀고나서 다른 사람들의 소소를 보니 계차 방정식을 이용해서
> 푸는 것알 알았다. 사실 어떻게 보면 중, 고등학교 때 배운 것을 이용하면 더 빨리 풀수 있는 
> 문제였는데 나만 어렵게 푼거 같다. 이래서 수학을 열심히 해야 하나보다..