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

	//for (i = 1; i <= triangle_height; i++) {
	//	for (j = 1; j <= i; j++) {
	//		printf("%d ", bucket[i][j]);
	//	}
	//	printf("\n");
	//}

	calc(bucket, triangle_height);
	
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
			continue;
		}

		if (i == 2) {
			bucket[i][1] = bucket[i - 1][1] + bucket[i][1];
			bucket[i][2] = bucket[i - 1][1] + bucket[i][2];
			continue;
		}

		for (j = 1; j <= i; j++) {
			if (j == 1) {
				bucket[i][j] = bucket[i][j] + bucket[i - 1][j];
			}
			else if (j == i) {
				bucket[i][j] = bucket[i][j] + bucket[i - 1][j-1];
			}
			else {
				//printf("bucket[%d][%d] = %d =====> bucket[%d][%d] = %d, bucket[%d][%d] = %d\n"
					//, i, j, bucket[i][j], i - 1, j-1, bucket[i - 1][j-1], i - 1, j, bucket[i - 1][j]);
				bucket[i][j] = MAX((bucket[i][j] + bucket[i - 1][j-1]), (bucket[i][j] + bucket[i - 1][j ]));
			}
		}
	}

	for (int i = 1; i <= height; i++) {
		max_value = MAX(bucket[height][i], max_value);
	}
	printf("%d", max_value);
}