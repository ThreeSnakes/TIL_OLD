#include<stdio.h>
#define MAX_HOUSE_CNT 1001
#define MIN(X,Y) ((X < Y ) ? X : Y )

int main(void) {
	int _house_cnt;
	int _price_bucket[MAX_HOUSE_CNT][3];
	int i, j, sum = 0;

	scanf("%d", &_house_cnt);

	for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			scanf("%d", &_price_bucket[i][j]);
		}
	}

	/*for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			printf("[ %d ] ", _price_bucket[i][j]);
		}
		printf("\n");
	}*/

	if (_house_cnt == 1) {
		sum = MIN(_price_bucket[1][0], MIN(_price_bucket[1][1], _price_bucket[1][2]));
	}
	else {
		for (i = 2; i <= _house_cnt; i++) {
			for (j = 0; j < 3; j++) {
				if (j == 0) {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][1] + _price_bucket[i][j], _price_bucket[i - 1][2] + _price_bucket[i][j]);
				}
				else if (j == 1) {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][0] + _price_bucket[i][j], _price_bucket[i - 1][2] + _price_bucket[i][j]);
				}
				else {
					_price_bucket[i][j] = MIN(_price_bucket[i - 1][0] + _price_bucket[i][j], _price_bucket[i - 1][1] + _price_bucket[i][j]);
				}
			}
		}

		sum = MIN(_price_bucket[_house_cnt][0], MIN(_price_bucket[_house_cnt][1], _price_bucket[_house_cnt][2]));
	}
	

	/*printf("\n");
	for (i = 1; i <= _house_cnt; i++) {
		for (j = 0; j < 3; j++) {
			printf("[ %d ] ", _price_bucket[i][j]);
		}
		printf("\n");
	}*/

	printf("%d", sum);
	return 0;
}