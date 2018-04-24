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
