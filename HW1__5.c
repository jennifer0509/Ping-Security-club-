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
	if (head == NULL) // 공백 리스트이면
		head = p;
	else {
		while (temp->link != NULL)
			temp = temp->link;
		temp->link = p;
	}
	return head; // 변경된 헤드 포인터 반환
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
		error("pos 범위 오류");
	else
	{
		if (pos == 0)
		{
			ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1) 
			p->data = value; // (2) 
			p->link = head; // 헤드 포인터의 값을 복사 //(3) 
			head = p; // 헤드 포인터 변경 //(4) 
			// 변경된 헤드 포인터 반환
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

void display_te(ListNode* head) // text editor 를 위해 변경 // 2)
{
	ListNode* p;
	int lineNb = 0;
	printf("--------------------text edited--------------\n");
	for (p = head; p != NULL; p = p->link)
		printf("(%d) %s\n", ++lineNb, p->data.line);
}
element get_entry(ListNode* head, int pos)//pos 위치(0 이 첫 번째 노드)에 있는 노드의 data 를 반환
{
	ListNode* p = head;
	int i;
	if (pos >= get_length(head))
	{
		error("위치오류\n");
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
		error("비어있는 리스트입니다");
	else if (pos < 0 || pos >= get_length(head))
		error("pos 범위 오류");
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
// 나머지 함수들 정의를 그대로 여기에 
char askChoice(void) {
	char choice;
	printf("---------------------------------------------\n");
	printf("a: 텍스트 끝에 라인 추가\n");
	printf("i: 라인 번호로 라인 추가\n");
	printf("d: 라인 번호로 라인 삭제\n");
	printf("v: 라인 번호로 해당 라인 출력\n");
	printf("p: 전체 텍스트 출력\n");
	printf("q: 끝\n");
	printf("메뉴 선택:");
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
			printf("텍스트 끝에 삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, 100, stdin);
			newElement.line[strlen(newElement.line) - 1] = '\0';
			list = insert_last(list, newElement);
			display_te(list);
			break;

		case 'i':
			printf("삽입할 라인 번호: ");
			scanf("%d", &lineNb);
			printf("삽입할 라인: ");
			while (getchar() != '\n');
			fgets(newElement.line, MAX_CHAR_PER_LINE, stdin);
			newElement.line[strlen(newElement.line) - 1] = '\0';
			list = insert_pos(list, lineNb - 1, newElement);
			display_te(list);
			break;
		case 'd':
			printf("삭제할 라인 번호: ");
			scanf("%d", &lineNb);
			while (getchar() != '\n');
			list = delete_pos(list, lineNb - 1);
			display_te(list);
			break;
		case 'v':
			printf("출력할 라인 번호: ");
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