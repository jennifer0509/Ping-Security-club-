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
* ���丮���� ����� ����ϴ� ��������. ���⿡�� �߿��Ѱ��� ��ʹ� �׻� ������ ������ �ۼ��ؾ���.

�׷��� n==0 �϶� ������ �ϹǷ� 1�� return �Ͽ�����.

*/