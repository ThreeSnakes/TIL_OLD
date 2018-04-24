#include<stdio.h>

int main(void) {
	int input_number;

	int parent, child;
	
	int count = 1;
	int add = 2;

	scanf("%d", &input_number);

	if (input_number == 1) {
		printf("1/1");
		return 0;
	}

	while (1) {
		count = count + add;
		add++;
		if (input_number <= count) {
	//		printf("Count = %d, Last Add value = %d\n", count, add-1);
			break;
		}
	}

	if (add % 2 == 0) {
		parent = (add - 1) - (count-input_number);
		child = add - parent;
	}
	else {
		child = (add - 1) - (count - input_number);
		parent = add - child;
	}
	printf("%d/%d", child, parent);
	

	return 0;
}