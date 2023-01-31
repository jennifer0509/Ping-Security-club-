#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int fact(int n)
{
	if (n == 0)
		return 1;
	else
		return n * fact(n - 1);
}
int main(void)
{
	int n;
	printf("Enter a number:");
	scanf("%d", &n);
	printf("%d! = ", n);
	printf("%d\n", fact(n));
}

/*
* 팩토리얼의 결과를 출력하는 문제였음. 여기에서 중요한것은 재귀는 항상 끝나는 조건을 작성해야함.

그래서 n==0 일때 끝내야 하므로 1로 return 하여야함.

*/