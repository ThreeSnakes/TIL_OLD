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