#include<stdio.h>
#define MAX(X,Y) ((X > Y) ? X : Y)
#define MAX_NUMBER 301
int calc(int bucket[], int stair_cnt);

int main(void) {
	int stair_cnt = 0, i;
	int score_bucket[MAX_NUMBER] = { 0 };

	scanf("%d", &stair_cnt);
	for (i = 1; i <= stair_cnt; i++) {
		scanf("%d", &score_bucket[i]);
	}

	printf("%d", calc(score_bucket, stair_cnt));
	
	return 0;
}

int calc(int bucket[], int stair_cnt) {
	int sum = 0, i, step_1, step_2, j;	
	int calc_bucket[2][MAX_NUMBER] = { 0 };

	calc_bucket[0][1] = bucket[1];
	calc_bucket[0][2] = bucket[2];
	calc_bucket[1][2] = bucket[1] + bucket[2];
	
	for (i = 3; i <= stair_cnt; i++) {
		calc_bucket[0][i] = MAX(calc_bucket[0][i - 2] + bucket[i], calc_bucket[1][i-2] + bucket[i]) ;
		calc_bucket[1][i] = calc_bucket[0][i - 1] + bucket[i];
	}

	//for (i = 0; i < 2; i++) {
	//	for (j = 1; j <= stair_cnt; j++) {
	//		printf("%d  ", calc_bucket[i][j]);
	//	}
	//	printf("\n");
	//}

	return MAX(calc_bucket[0][stair_cnt], calc_bucket[1][stair_cnt]);
}