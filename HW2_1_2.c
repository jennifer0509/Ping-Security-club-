#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK_SIZE 3
#define MAX_STRING_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_STACK_SIZE];
	char stackName[MAX_STRING_SIZE][MAX_STRING_SIZE];
	int top;
}StackType;

// ���� �ʱ�ȭ �Լ�
void init(StackType* s)
{
	s->top = -1;
}
// ���� ���� ���� �Լ�
int is_empty(StackType* s)
{
	return (s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType* s)
{
	return (s->top == (MAX_STACK_SIZE - 1));
}
// �����Լ�
void push(StackType* s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else
		s->data[++(s->top)] = item;
}
// �����Լ�
element pop(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[(s->top)--];
}
// ��ũ�Լ�
element peek(StackType* s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
		return s->data[s->top];
}
void stack_print(StackType* s)
{
	int i;

	if (is_empty(s) == 1)
		printf("<empty>\n");
	else
	{
		for (i = s->top; i >= 0; i--)
		{
			printf("%d %s", s->data[i],s->stackName[i]);

			if (i == s->top)
				printf("<- top");
			printf("\n");
		}
	}
	printf("--\n");
}

// ���Լ�
void main()
{
	StackType s;

	init(&s);
	stack_print(&s);
	push(&s, 10);
	strcpy(s.stackName[0], "ten");
	stack_print(&s);
	push(&s, 20);
	strcpy(s.stackName[1], "twenty");
	stack_print(&s);
	push(&s, 30);
	strcpy(s.stackName[2], "thirty");
	stack_print(&s);
	push(&s, 40);
	strcpy(s.stackName[3], "forty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	push(&s, 50);
	strcpy(s.stackName[2], "fifty");
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);
	pop(&s);
	stack_print(&s);

}

/*
* strcpy �� ���ؼ� ���ڿ� �������ֱ�



����ü������ �迭�� 2�� ���� ����� �����ϴ�. ���ڵ� �ְ� ���ڿ��� ���� �� ����

*/