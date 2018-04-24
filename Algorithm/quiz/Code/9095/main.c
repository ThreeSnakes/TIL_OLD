#include<stdio.h>
#define MAX_NUM 12

int _bucket[MAX_NUM] = { 0 };

int calc(int num);

int main(void) {
	int _num, _test_cnt;
	int i;

	scanf("%d", &_test_cnt);

	for (i = 0; i < _test_cnt; i++) {
		scanf("%d", &_num);
		printf("%d\n", calc(_num));
	}


}

int calc(int num) {
	int i, cnt = 0;

	_bucket[0] = 1;
	_bucket[1] = 1;
	_bucket[2] = 2;
	
	if (_bucket[num] == 0) {
		for (i = 3; i <= num; i++) {
			if (_bucket[i] != 0) {
				continue;
			}

			if (_bucket[i - 1] != 0 || i - 1 == 0) {
				cnt = cnt + _bucket[i - 1];
			}
			
			if (_bucket[i - 2] != 0 || i - 2 == 0) {
				cnt = cnt + _bucket[i - 2];
			}

			if (_bucket[i - 3] != 0 || i - 3 == 0) {
				cnt = cnt + _bucket[i - 3];
			}
			_bucket[i] = cnt;
			cnt = 0;
		}
		return _bucket[num];
	}
	else {
		return _bucket[num];
	}
}