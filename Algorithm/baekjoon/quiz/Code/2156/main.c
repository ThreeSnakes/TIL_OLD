#include<stdio.h>
#define MAX_CNT 10001
#define MAX(X,Y) ((X > Y) ? X : Y)

int main(void) {
	int wine_cnt, i, j;
	int wine_bucket[MAX_CNT] = { 0 };

	int calc_bucket[2][MAX_CNT] = { 0 };
	int sum = 0, second_max_value;

	scanf("%d", &wine_cnt);

	for (i = 1; i <= wine_cnt; i++) {
		scanf("%d", &wine_bucket[i]);
	}

	if (wine_cnt < 3) {
		sum = wine_bucket[1] + wine_bucket[2];
		
		printf("%d", sum);

		return 0;
	}

	calc_bucket[0][1] = wine_bucket[1];
	calc_bucket[0][2] = wine_bucket[2];
	calc_bucket[1][2] = wine_bucket[1] + wine_bucket[2];
	second_max_value = calc_bucket[1][2];
	for (i = 3; i <= wine_cnt; i++) {
		calc_bucket[0][i] = MAX(MAX(calc_bucket[0][i - 2] + wine_bucket[i], calc_bucket[1][i - 2] + wine_bucket[i]), second_max_value);
		calc_bucket[1][i] = calc_bucket[0][i - 1] + wine_bucket[i];
		if (second_max_value < calc_bucket[1][i]) {
			second_max_value = calc_bucket[1][i];
		}
	}

	for (i = 0; i < 2; i++) {
		for (j = 0; j <= wine_cnt; j++) {
			//printf("%d ", calc_bucket[i][j]);
			if (sum < calc_bucket[i][j]) {
				sum = calc_bucket[i][j];
			}
		}
		//printf("\n");
	}

	printf("%d", sum);

	return 0;
}

