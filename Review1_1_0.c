#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h> 
void print_reverse(char* str, int end)
{

	char tmp;

	printf("%c", str[end]);

	if (end == 0)
		return;
	else
		print_reverse(str, end-1);

}
int main()
{
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);
	printf("Reversed String is: ");
	print_reverse(str, strlen(str) - 1);
	return 0;
}

/*
�� ������ ���ڿ��� �Ųٷ� ����ϵ� ��ͷ� ȣ���ϴ� ��������. �߿��Ѱ��� �� ������ return ���� void �̱� ������ ���������� �ƴ� �ٸ� ���ǹ������� �׳� �θ��⸸ �ϸ� ��. ���ڿ��̱� ������ ���� ������ְ� ���� ���ǹ����� �θ��� ��
*/