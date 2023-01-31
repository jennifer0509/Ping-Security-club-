
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
* 문자열의 끝과 앞의 문자를 교환하는 문제였음.

ex)

tmp 라는 변수를 하나 선언하고

tmp = 첫번째 변수

첫번째 변수 = 마지막 변수

마지막 변수 = tmp 대입


*/