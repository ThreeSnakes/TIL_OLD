#1003번 문제#

**피보나치 함수**

> 다음 소스는 N번째 피보나치 함수를 구하는 함수이다.
``` c
int fibonacci(int n) {
    if (n==0) {
        printf("0");
        return 0;
    } else if (n==1) {
        printf("1");
        return 1;
    } else {
        return fibonacci(n‐1) + fibonacci(n‐2);
    }
}
```
> fibonacci(3)을 호출하면 다음과 같은 일이 일어난다.

> fibonacci(3)은 fibonacci(2)와 fibonacci(1) (첫 번째 호출)을 호출한다.

> fibonacci(2)는 fibonacci(1) (두 번째 호출)과 fibonacci(0)을 호출한다.

> 두 번째 호출한 fibonacci(1)은 1을 출력하고 1을 리턴한다.

> fibonacci(0)은 0을 출력하고, 0을 리턴한다.

> fibonacci(2)는 fibonacci(1)과 fibonacci(0)의 결과를 얻고, 1을 리턴한다.

> 첫 번째 호출한 fibonacci(1)은 1을 출력하고, 1을 리턴한다.

> fibonacci(3)은 fibonacci(2)와 fibonacci(1)의 결과를 얻고, 2를 리턴한다.

> 이 때, 1은 2번 출력되고, 0은 1번 출력된다. N이 주어졌을 때, fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

**입력**
> 첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 다음과 같이 구성되어있다.

> 첫째 줄에 N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

**출력**
> 각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

``` c
#include<stdio.h>

// 각 피보나치에서 N번계산할때 발생하는 
// fino(0)과 fibo(1)을 저장하는 Array.
int fibo_val0_cnt[41] = { 0 };
int fibo_val1_cnt[41] = { 0 };

//각 피보나치 결과를 저장하는 변수.
int val_0 = 0;
int val_1 = 0;

//fibonacci 함수.
int fibo(int n);

int main(void) {
	
	int test_num;
	int test_value, i;
	
	scanf("%d", &test_num);
	
	for (i = 0; i < test_num; i++) {
		scanf("%d", &test_value);
		fibo(test_value);
		printf("%d %d\n", fibo_val0_cnt[test_value], fibo_val1_cnt[test_value]);
		val_0 = 0;
		val_1 = 0;
	}
	
	return 0;
}

int fibo(int n) {
	if (n == 0) {
		//printf("0\n");
		val_0++;
		//return 0;
	}
	else if (n == 1) {
		//printf("1\n");
		val_1++;
		//return 1;
	}
	else {
		if (fibo_val0_cnt[n-1] != 0 && fibo_val1_cnt[n-1] != 0) {
			val_0 = val_0 + fibo_val0_cnt[n - 1];
			val_1 = val_1 + fibo_val1_cnt[n - 1];
		}
		else {
			fibo(n - 1);
		}

		if (fibo_val0_cnt[n - 2] != 0 && fibo_val1_cnt[n - 2] != 0) {
			val_0 = val_0 + fibo_val0_cnt[n - 2];
			val_1 = val_1 + fibo_val1_cnt[n - 2];
		}
		else {
			fibo(n - 2);
		}
	}

	//printf("0 = %d\n", val_0);
	//printf("1 = %d\n", val_1);
	
	fibo_val0_cnt[n] = val_0;
	fibo_val1_cnt[n] = val_1;
}
```

| No      | ID        | Quest.NO | Result  | Memory Use | Time | lanaguage | Code Length |
|---------|-----------|----------|---------|------------|------|-----------|-------------|
| 4564753 | select995 | 1003     | SUCCESS | 944 KB     | 0 MS | C         | 1234 B      |

> 왠일로 한코스에 맞췄다!

> 한번에 맞춰서 나도 놀래서 다른 사람 소스랑 비교해보았는데... 몬가 이상하다. 내가 제대로 한것인지 아니면 다른사람이 틀리게 한건지 잘 모르겠다. 다이나믹 프로그래밍이라면 기존에 한 계산은 안하는게 맞는 것일 텐데 다른 사람들 코드를 보면 기존에 한 계산을 다시 반복해서 한다.흠... 내가 아는게 틀린건가 싶다. 또 다른사람이 한것과 내가 한것을 비교 해서 다른점은 수행 시간이다. 나는 `0 MS`가 나오는데 어떤 분은 같은 C로 짠 프로그램인데 `1576 MS`가 나오기도 한다. 흠 내가 더 잘짠건가 싶기도 하고.... 그럴리는 없게지만 말이다..