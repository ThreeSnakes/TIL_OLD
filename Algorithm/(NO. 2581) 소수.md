#2581번 문제#

**소수**

> 자연수 M과 N이 주어질 때 M이상 N이하의 자연수 중 소수인 것을 모두 골라 이들 소수의 합과 최소값을 찾는 프로그램을 작성하시오.

> 예를 들어 M=60, N=100이 경우 60이상 100이하의 자연수 중 소수는 61, 67, 71, 73, 79, 83, 89, 97 총 8개가 있으므로, 이들 소수의 합은 620이고, 최소값은 61이 된다.

**입력**
> 입력의 첫째 줄에 M이, 둘째 줄에 N이 주어진다.

> M과 N은 10,000이하의 자연수이며, M은 N보다 같거나 작다.

**출력**
> M이상 N이하의 자연수 중 소수인 것을 모두 찾아 첫째 줄에 그 합을, 둘째 줄에 그 중 최소값을 출력한다. 

> 단, M이상 N이하의 자연수 중 소수가 없을 경우는 첫째 줄에 -1을 출력한다.

``` c
#include<stdio.h>

int main(void) {
	int min, max, sum = 0, min_primary_number = 0, i;
	
	scanf("%d", &min);
	scanf("%d", &max);

	for (min; min <= max; min++) {
		for (i = 2; i <= min; i++) {		
			if (min == 2) {
				min_primary_number = 2;
				sum = sum + 2;
				break;
			}

			if (min%i == 0) {
				break;
			}

			//마지막 전까지 통과한거면 그값은 소수.
			if (i == min - 1) {
				// min 값 등록. for문으로 돌기 때문에 처음 값이 입력되면
				// 그 이후로는 값 입력 X.
				if (min_primary_number == 0) {
					min_primary_number = min;
				}

				//printf("prime_number = %d\n", min);
				sum = sum + min;

				// 한번 더 돌필요 없다. break문으로 탈출.
				break;
			}
		}
	}

	if (sum != 0) {
		printf("%d\n", sum);
		printf("%d\n", min_primary_number);
	}
	else {
		printf("-1");
	}

	return 0;
}
```

| No      | ID        | Quest.NO | Result    | Memory Use | Time  | lanaguage | Code Length |
|---------|-----------|----------|-----------|------------|-------|-----------|-------------|
| 4555928 | select995 | 2581     | SUCCESS!! | 948 KB     | 20 MS | C         | 903 B       |
| 4555915 | select995 | 2581     | FAIL      |            |       | C         | 828 B       |
| 4555883 | select995 | 2581     | FAIL      |            |       | C         | 683 B       |

> 앞서 풀었던 [소수찾기](https://github.com/jonathan-lim/TIL/blob/master/Algorithm/(NO.%201978)%20%EC%86%8C%EC%88%98%20%EC%B0%BE%EA%B8%B0.md)문제 참고해서 풀었다. 그다지 어려운 문제는 아니었는데 소수가 없을 경우 `-1`을 리턴하라는 설명을 자세히 읽지 않아서 틀렸다. 흠 자꾸 틀리는 비율 늘어나는데 문제좀 잘 읽어야 겠다...