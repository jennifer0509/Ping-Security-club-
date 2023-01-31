#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
void print_fact_exp(int n)
{
	if (n > 1)
	{
		printf("%d *", n);
		print_fact_exp(n - 1);
	}
	else
		printf("1");
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	printf("%d! = ", n);
	print_fact_exp(n);
	printf("\n");
}

/*
* 이 문제는 팩토리얼의 계산 과정을 보여주는 문제였음. 여기서 중요한것은 n 이 1보다 클때까지만 출력하고 나머지는 1을 출력하는 것임. 또한 주의할점은 void 의 재귀이기 때문에 return 하는 것이 끝나는 조건에만 걸려있음.


*/