#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_CHAR_PER_LINE 100 
typedef struct {
	char line[MAX_CHAR_PER_LINE];
} element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;
ListNode* insert_last(ListNode* head, element value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 
	p->data = value;
	p->link = NULL;
	// (2)
	if (head == NULL) // ���� ����Ʈ�̸�
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head; // ����� ��� ������ ��ȯ
}
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	//exit(1);
}
int get_length(ListNode* head)
{
	int k = 0;
	while (head != NULL)
	{
		k++;
		head = head->link;
	}
	return k;
}
ListNode* insert_pos(ListNode* head, int pos, element value)
{

	if (pos<0 || pos>get_length(head))
		error("pos ���� ����");
	else
	{
		if (pos == 0)
		{
			ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 
			p->data = value; // (2) 
			p->link = head; // ��� �������� ���� ���� //(3) 
			head = p; // ��� ������ ���� //(4) 
			// ����� ��� ������ ��ȯ
		}
		else
		{
			ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 
			p->data = value; //(2) 
			ListNode* pre = head;
			ListNode* q = head;
			int i;

			for (i = 0; i < pos; i++)
			{
				pre = q;
				q = q->link;
			}
			pre->link = p;
			p->link = q;
		}
	}
	return head;

}

void display_te(ListNode* head) // text editor �� ���� ���� // 2)
{
	ListNode* p;
	int lineNb = 0;
	printf("--------------------text edited--------------\n");
	for (p = head; p != NULL; p = p->link)
		printf("(%d) %s\n", ++lineNb, p->data.line);
}
element get_entry(ListNode* head, int pos)//pos ��ġ(0 �� ù ��° ���)�� �ִ� ����� data �� ��ȯ
{
	ListNode* p = head;
	int i;
	if (pos >= get_length(head))
	{
		error("��ġ����\n");
	}
	else
	{
		for (i = 0; i < pos; i++)
		{
			p = p->link;
		}
		return p->data;
	}
}
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* removed;
	int i;
	ListNode* p = head;
	ListNode* pre = head;

	if (head == NULL)
		error("����ִ� ����Ʈ�Դϴ�");
	else if (pos < 0 || pos >= get_length(head))
		error("pos ���� ����");
	else
	{
		for (i = 0; i < pos; i++)
		{
			pre = p;
			p = p->link;
		}
		removed = p;
		pre->link = removed->link;
		free(removed);
		return head;
	}
}
// ������ �Լ��� ���Ǹ� �״�� ���⿡ 
char askChoice(void) {
	char choice;
	printf("---------------------------------------------\n");
	printf("a: �ؽ�Ʈ ���� ���� �߰�\n");
	printf("i: ���� ��ȣ�� ���� �߰�\n");
	printf("d: ���� ��ȣ�� ���� ����\n");
	printf("v: ���� ��ȣ�� �ش� ���� ���\n");
	printf("p: ��ü �ؽ�Ʈ ���\n");
	printf("q: ��\n");
	printf("�޴� ����:");
	scanf("%c", &choice);
	return choice;
}
int main(void) // 3) 
{
	ListNode* list = NULL;
	ListNode* p;
	char choice;
	int lineNb;
	element newElement;
	while ((choice = askChoice()) != 'q') {
		switch (choice) {
		case 'a':
			printf("�ؽ�Ʈ ���� ������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, 100, stdin);
			newElement.line[strlen(newElement.line) - 1] = '\0';
			list = insert_last(list, newElement);
			display_te(list);
			break;

		case 'i':
			printf("������ ���� ��ȣ: ");
			scanf("%d", &lineNb);
			printf("������ ����: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
			newElement.line[strlen(newElement.line) - 1] = '\0';
			list = insert_pos(list, lineNb - 1, newElement);
			display_te(list);
			break;
		case 'd':
			printf("������ ���� ��ȣ: ");
			scanf("%d", &lineNb);
			while (getchar() != '\n');
			list = delete_pos(list, lineNb - 1);
			display_te(list);
			break;
		case 'v':
			printf("����� ���� ��ȣ: ");
			scanf("%d", &lineNb);
			while (getchar() != '\n');
			newElement = get_entry(list, lineNb - 1);
			printf("(%d) %s\n", lineNb, newElement.line);
			break;
		case 'p':
			while (getchar() != '\n');
			display_te(list);
			break;
		}

	}
}