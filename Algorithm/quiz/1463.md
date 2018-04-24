#1463번 문제#

**1로 만들기.**

> 정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

> 1. X가 3으로 나누어 떨어지면, 3으로 나눈다.
> 2. X가 2로 나누어 떨어지면, 2로 나눈다.
> 3. 1을 뺀다.
 
>정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만드려고 한다. 연산을 사용하는 횟수의 최소값을 출력하시오.

**입력**
> 첫째 줄에 1보다 크거나 같고, 1000000보다 작거나 같은 자연수 N이 주어진다.

**출력**
> 첫째 줄에 연산을 하는 횟수의 최소값을 출력한다.

``` c
#include<stdio.h>
#define max_number 1000001
#define MIN(X,Y) ((X) < (Y) ? (X) : (Y))  

int calc_number(int* bucket, int N);

int main(void) {
	int calc_num;
	//각 숫자를 계산할때 각 숫자에서 1로 가는 최소값을 저장하는 배열 선언.
	int *bucket = (int*)malloc(sizeof(int)*max_number);
	int i, cnt = 0;

	

	for (i = 0; i < max_number; i++) {
		bucket[i] = -1;
	}
	scanf("%d", &calc_num);

	bucket[0] = 0;
	bucket[1] = 1;
	bucket[2] = 1;
	bucket[3] = 1;

	calc_number(bucket, calc_num);

	if (calc_num == 1) {
		printf("%d", 0);
	}
	else {
		//for (i = 0; i <= calc_num; i++) {
		//		printf("%d\n", bucket[i]);
		//	}

		printf("%d", bucket[calc_num]);
	}

	return 0;
}

int calc_number(int* bucket, int N) {
	int mod_3 = 0, mod_2 = 0, minus_1 = 0;
	
	if (bucket[N] != -1) {
		//printf("==============bucket[%d] = %d\n", N, bucket[N]);
		return bucket[N];
	}

	if (N % 3 == 0) {
		//printf("run Mod 3\n");
		mod_3 = calc_number(bucket, N / 3) + 1;
	}
	else {
		mod_3 = N + 1;
	}

	if (N % 2 == 0) {
		//printf("run Mod 2\n");
		mod_2 = calc_number(bucket, N / 2) + 1;
	}
	else {
		mod_2 = N + 1;
	}

	if (N > 3) {
		//printf("run Minus 1 \n");
		minus_1 = calc_number(bucket, N - 1) + 1;
	}

	bucket[N] = MIN(mod_3, MIN(mod_2, minus_1));
	//printf("N = %d, mod_3 = %d, mod_2 = %d, minus_1 = %d, === bucket[%d] = %d===\n", N, mod_3, mod_2, minus_1, N, bucket[N]);

	return bucket[N];
}
```

| No      | ID        | Quest.NO | Result           | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|------------------|------------|-------|-----------|-------------|
| 4570985 | select995 | 1463     | SUCCESS          | 28168 KB   | 48 MS | C         | 1483 B      |
| 4427755 | select995 | 1463     | TIME OUT         |            |       | Java      | 4428 B      |
| 3072170 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1649 B      |
| 3072169 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1651 B      |
| 3070473 | select995 | 1463     | FAIL             |            |       | Java      | 1683 B      |
| 3070467 | select995 | 1463     | FAIL             |            |       | Java      | 1679 B      |
| 3070466 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1683 B      |
| 3070436 | select995 | 1463     | FAIL             |            |       | Java      | 1400 B      |
| 3070434 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1406 B      |
| 3070413 | select995 | 1463     | FAIL             |            |       | Java      | 1407 B      |
| 3070410 | select995 | 1463     | FAIL             |            |       | Java      | 1450 B      |
| 3070389 | select995 | 1463     | FAIL             |            |       | Java      | 1360 B      |
| 3057176 | select995 | 1463     | FAIL             |            |       | Java      | 1487 B      |
| 3057138 | select995 | 1463     | FAIL             |            |       | Java      | 1325 B      |
| 3057128 | select995 | 1463     | FAIL             |            |       | Java      | 1325 B      |
| 3057127 | select995 | 1463     | COMPILE ERROR    |            |       | Java      | 1326 B      |
| 3057113 | select995 | 1463     | COMPILE ERROR    |            |       | Java      | 1265 B      |
| 3057094 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1270 B      |
| 3057090 | select995 | 1463     | RUNTIME ERROR    |            |       | Java      | 1256 B      |
| 3057027 | select995 | 1463     | MEMORY OVER FLOW |            |       | Java      | 1272 B      |

> 드디어 풀었다.!!!!! 위에 시도한 횟수만 봐도 어마어마하다. `JAVA`로 푼거는 처음 이 문제를 도전 했을 때인 4개월전에 풀었던 결과이다. 아무런 공부도 안하고 그냥 막무가내로 풀었을 때 나온 결과물 들이다. 이래야 사람은 공부를 해야 한다는 것을 느낀다. dp가 무엇인지, 알고리즘에 대해서 깊이 생각도 안하고 풀었을때는 죄다 오답인데. 하나씩 차근 차근 공부하고 풀다보니 쉽게는 아니지만 기어코 정답을 풀었다. 

> 풀었다는 것에는 의의를 두나 아직 멀었구나도 많이 느꼈다. 내 소스 같은 경우 필요 없는 부분이 상당히 많다. 물론 디버깅 하려고 작성한 `printf`문을 제외 하더라도 상당히 지저분하다. 다른 어떤분이 작성한 것은 상당히 깔끔하고 보기도 편했다. 거기다 심지어 시간도 `8MS`나 차이도 났다. 나는 언제 저렇게 되나.. 생각도 드는데 하니씩 공부하다 보면 나아질것라 생각한다.