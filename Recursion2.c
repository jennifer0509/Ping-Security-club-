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
* �� ������ ���丮���� ��� ������ �����ִ� ��������. ���⼭ �߿��Ѱ��� n �� 1���� Ŭ�������� ����ϰ� �������� 1�� ����ϴ� ����. ���� ���������� void �� ����̱� ������ return �ϴ� ���� ������ ���ǿ��� �ɷ�����.


*/