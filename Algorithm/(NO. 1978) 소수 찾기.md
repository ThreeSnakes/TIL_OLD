#1978번 문제#

**벌집**

**소수찾기**

> 주어진 숫자들 중 소수가 몇 개인지 찾아서 출력하는 프로그램을 작성하시오.

**입력**
> 첫 줄에 수의 개수 N이 주어진다. N은 100이하이다. 다음으로 N개의 수가 주어지는데 수는 1,000 이하의 자연수이다.

**출력**
> 주어진 수들 중 소수의 개수를 출력한다.

```
#include<stdio.h>

int main(void) {
	int cnt;
	int bucket[100];
	int prime_number_cnt = 0;
	int i = 0;
	
	scanf("%d", &cnt);

	//배열에 입력 받아서 저장해 놓는다.
	for (i = 0; i < cnt; i++) {
		scanf("%d", &bucket[i]);
	}

	//printf("cnt = %d\n", cnt);

	for (i = 0; i < cnt; i++) {
		for (int j = 2; j <= bucket[i]; j++) {
			// 1은 소수가 아니므로 제외, 1 이하도 제외.
			if (bucket[i] <= 1) {
				break;
			}
			
			// 2는 소수 이므로 prime_number_cnt 증가.
			if (bucket[i] == 2) {
				prime_number_cnt++;
				break;
			}
			// 나눠서 체크.
			if (bucket[i] % j == 0) {
				break;
			}

			// 자기 자신 -1 까지 무사통과 했으면 prime_number_cnt 증가.
			if (j == bucket[i] - 1) {
				//printf("add Prime_Number_Cnt bucket = %d, i = %d, j = %d \n", bucket[i], i, j);
				prime_number_cnt++;
			}
		}
	}

	//마지막으로 출력.
	printf("%d", prime_number_cnt);
	
	return 0;
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|------|-----------|-------------|
| 4555054 | select995 | 1978     | SUCCESS!! | 948 KB     | 0 MS | C         | 983 B       |
| 4555041 | select995 | 1978     | FAIL      |            |      | C         | 980 B       |
| 4555035 | select995 | 1978     | FAIL      |            |      | C         | 852 B       |

> 흠 처음에 소수라 해서 너무 어렵게 생각 했었다. 이걸 DP로 풀어야 하는건가.. 물론 DP는 아직 잘 모르지만 말이다.ㅋㅋㅋ 하여튼 너무 어렵게 생각 했다가 쉽게 가자라고 생각해서 풀었더니 풀렸다. 문제를 궂이 어렵게 생각할 필요가 없는거다. 2번 틀렸었는데 처음 틀린거는 2를 생각 안해서 2가 나왔을 경우 2를 더하질 않았었고 두번째에서는 debugging용 printf문을 주석처리를 안해서 틀렸다. 꼼꼼하게 잘 봤으면 됬을텐데 말이다. 
> 마지막으로 어렵게 생각하지말고 쉽게 생각해서 풀자. 겁먹지 말고.!