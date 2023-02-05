#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;
void print_list(ListNode* head) // Ʋ��(�����ؾ�)
{
	ListNode* p;
	if (head == NULL) return;

	if (head->link == head)
		printf("%d->", head->data);
	else {
		p = head->link;
		do {
			printf("%d->", p->data);
			p = p->link;
		} while (p != head);
		printf("%d->", p->data); // ������ ��� ���
	}
	printf("����Ʈ�� ��");
	printf("\n");
}
ListNode* insert_first(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
	}

	return head;
}// ����� ��� �����͸� ��ȯ�Ѵ�. }
ListNode* insert_last(ListNode* head, element data)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	if (head == NULL) {
		head = node;
		node->link = head;
	}
	else {
		node->link = head->link; // (1)
		head->link = node; // (2)
		head = node; // (3)
	}

	return head;
}// ����� ��� �����͸� ��ȯ�Ѵ�. }
ListNode* delete_first(ListNode* head)
{
	ListNode* temp;

	if (head == NULL) {
		printf("����Ʈ�� ��� ������ ����\n");
		return NULL;
	}
	else if (head == head->link) { // �� �ϳ��� ��尡 ��������
		temp = head;
		head = NULL;
		free(temp);
	}
	else {
		temp = head->link;
		head->link = temp->link;
		free(temp);
	}
	return head;
}

ListNode* delete_last(ListNode* head)
{
	ListNode* temp;
	ListNode* p;
	ListNode* q;

	temp = head;

	if (head == NULL)
		head = NULL;
	else if (temp->link = head)
	{
		free(temp);
		head = NULL;
	}

	temp = temp->link;

	do {
        
		p = temp;
		temp = temp->link;
		
	} while (temp != head);
	
	p->link = head->link;
	head = p;
	free(temp);

	return head;
}

int get_size(ListNode* head)
{
	int total = 0;

	ListNode* p;

	p = head;

	if (p == NULL)
		total = 0;
	else if (p->link == head)
		total = 1;
	else
	{
		p = head->link; //ó���� ����Ű�� �ϴ� �������� 
		
		do {
			total++;
			p = p->link;
		} while (p != head);

		total++;
	
	}
	return total;

}

ListNode* search(ListNode* head, element data)
{
	ListNode* p;

	if (head == NULL)
		return NULL;
	if (head->data == data)
		return head;
	else
	{
		p = head->link;
		do {
			if (p->data == data)
				return p;
			p = p->link;
		} while (p != head);
		if (p->data == data)
			return p;
	}
	return NULL;
}

// ���� ���� ����Ʈ �׽�Ʈ ���α׷�
int main(void)
{
	ListNode* head = NULL;
	ListNode* p;
	// list = 10->20->30->40
	head = insert_last(head, 20);
	print_list(head);
	head = insert_last(head, 30);

	print_list(head);
	head = insert_last(head, 40);
	print_list(head);
	head = insert_first(head, 10);
	print_list(head);
	head = delete_first(head);
	print_list(head);

	
	head = delete_last(head);
	print_list(head);
	
	printf("���̴� %d\n", get_size(head));

	
	p = search(head, 30);
	if (p != NULL)
		printf("%d", p->data);
	else
		printf("���Ͻô� data�� �����ϴ�\n");
		
	

}