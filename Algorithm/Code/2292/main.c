#include<stdio.h>

int main(void) {
	// 1 -> 6 -> 12 -> 18 -> 24... 6의 배수개로 늘어남.
	// 1 -> 13 3번, 1 -> 58 5번.
	int num;
	int hexagon_cnt = 1;
	int increas_cnt = 1;
	scanf("%d", &num);

	while (1) {
		if (num <= hexagon_cnt) {
			break;
		}
		hexagon_cnt = hexagon_cnt + (increas_cnt * 6);
		increas_cnt++;
	}

	printf("%d", increas_cnt);
}