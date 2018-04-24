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