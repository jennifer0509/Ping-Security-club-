
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
void reverse_string(char *str, int s, int e) 
{ 
	char tmp;
	
	if (s >= e)
		return;
	else 
	{
		tmp = str[s];
		str[s++] = str[e];
		str[e--] = tmp;
		reverse_string(str, s, e);
		}


}
int main()
{
	char str[100];
	printf("Enter any string:");
	scanf("%s", str);
	reverse_string(str, 0, strlen(str) - 1);
	printf("\nReversed String is: %s", str);
	return 0;

} 

/*
* ���ڿ��� ���� ���� ���ڸ� ��ȯ�ϴ� ��������.

ex)

tmp ��� ������ �ϳ� �����ϰ�

tmp = ù��° ����

ù��° ���� = ������ ����

������ ���� = tmp ����


*/