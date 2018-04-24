#include<stdio.h>
#define MAX_COIN_CNT 100
#define MAX_COIN_SUM 10001

int main(void) {	
	int _coin_cnt, _money;
	int _coin_bucket[MAX_COIN_CNT] = { 0 };
	int _calc_bucket[MAX_COIN_SUM] = { 0 };
	int i, j;

	scanf("%d %d", &_coin_cnt, &_money);

	for (i = 0; i < _coin_cnt; i++) {
		scanf("%d", &_coin_bucket[i]);
	}

	/*for (i = 0; i < _coin_cnt; i++) {
		printf("[ %d ]", _coin_bucket[i]);
	}*/

	_calc_bucket[0] = 1;

	for (i = 0; i < _coin_cnt; i++) {
		for (j = _coin_bucket[i]; j <= _money; j++) {
			_calc_bucket[j] = _calc_bucket[j] + _calc_bucket[j - _coin_bucket[i]];
		}
	}

	/*for (i = 0; i <= _money; i++) {
		printf("[ %d ]", _calc_bucket[i]);
	}*/
	printf("%d", _calc_bucket[_money]);
}


