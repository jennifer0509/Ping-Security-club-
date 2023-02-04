#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
typedef int element;
typedef struct ListNode { // ��� Ÿ��
	element data;
	struct ListNode* link;
} ListNode;
// ���� ó�� �Լ�
void error(char* message)
{
	fprintf(stderr, "%s\n", message);
	
}
// ��� pre �ڿ� ���ο� ��� ����
ListNode* insert_next(ListNode* head, ListNode* pre, element value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; //(2)
	p->link = pre->link; //(3)
	pre->link = p; //(4)
	return head; //(5)
}
ListNode* insert_first(ListNode* head, int value)
{
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value; // (2)
	p->link = head; // ��� �������� ���� ���� //(3)
	head = p; // ��� ������ ���� //(4)
	return head; // ����� ��� ������ ��ȯ
}
ListNode* insert_last(ListNode* head, int value)
{
	ListNode* temp = head;
	ListNode* p = (ListNode*)malloc(sizeof(ListNode)); //(1)
	p->data = value;
	p->link = NULL;
	// (2)
	if (head == NULL) // ���� ����Ʈ�̸�
		head = p;
	else {
		while (temp->link != 0)
			temp = temp->link;
		temp->link = p;
	}
	return head; // ����� ��� ������ ��ȯ
}
ListNode* delete_next(ListNode *head, ListNode *pre)
{
	ListNode* removed;
	removed = pre->link;
	pre->link = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
ListNode* delete_first(ListNode* head)
{
	ListNode* removed;
	if (head == NULL) error("������ �׸��� ����");
	removed = head; // (1)
	head = removed->link; // (2)
	free(removed); // (3)
	return head; // (4)
}
ListNode* delete_last(ListNode* head)
{
	ListNode* temp = head;
	ListNode* prevTemp = NULL;
	ListNode* removed;
	if (head == NULL) error("������ �׸��� ����");
	if (temp->link == NULL) { // �ϳ��� ���
		removed = temp->link;
		temp->link = NULL;
		free(removed);
		return NULL;
	}
	else { // �� �̻��� ���
		while (temp->link != NULL) {
			prevTemp = temp;
			temp = temp->link;
		}
		removed = temp;
		prevTemp->link = NULL;
		free(removed);
		return head; // �״��
	}
}
void print_list(ListNode* head)
{
	ListNode* p;
	for (p = head; p != NULL; p = p->link)
		printf("%d->", p->data);
	printf("NULL \n");
}
ListNode* search(ListNode* head, int x)
{
	ListNode* p;
	p = head;
	while (p != NULL) {
		if (p->data == x) return p; // Ž�� ����
		p = p->link;
	}
	return NULL; // Ž�� ������ ��� NULL ��ȯ
}
ListNode* concat(ListNode* head1, ListNode* head2)
{
	ListNode* p;
	if (head1 == NULL) return head2;
	else if (head2 == NULL) return head1;
	else {
		p = head1;
		while (p->link != NULL)
			p = p->link;
		p->link = head2;
		return head1;
	}
}
ListNode* reverse(ListNode* head)
{
	// ��ȸ �����ͷ� p, q, r�� ���
	ListNode* p, * q, * r;
	p = head; // p�� �������� ���� ����Ʈ
	q = NULL; // q�� �������� ���� ���
	while (p != NULL) {
		r = q; // r�� �������� �� ����Ʈ. r�� q, q�� p�� ���ʷ� ���󰣴�. q = p ;
		q = p;
		p = p->link;
		q->link = r; // q�� ��ũ ������ �ٲ۴�. }
	 // q�� �������� �� ����Ʈ�� ��� ������
	}
	return q;
}
int is_in_list(ListNode* head, element item)
{
	ListNode* tmp;

	tmp = head;
	while (tmp != NULL)
	{
		if (tmp->data == item)
			return 1;
		tmp = tmp->link;
	}

	return 0;
}
int get_length(ListNode* head)
{
	int total = 0;
	ListNode* tmp;

	tmp = head;
	while (tmp != NULL)
	{
		total++;
		tmp = tmp->link;
	}
	return total;
}
int get_total(ListNode* head)
{
	int total = 0;

	ListNode* t;

	t = head;

	while (t != NULL)
	{
		total += t->data;
		t = t->link;
	}

	return total;
}
element get_entry(ListNode* head, int pos)
{
	int i, j;

	ListNode* tmp = head;

	for (i = 0; i < pos; i++)
	{
		tmp = tmp->link;
	}

	return tmp->data;
}
ListNode* delete_by_key(ListNode* head, int key)
{
	int k;
	ListNode* t;
	t = head;

	k = is_in_list(head, key);

	if (k == 1)
	{
		if (t->data == key)
			delete_first(t);
		else
		{
			while (t->link != NULL)
			{
				if (t->link->data == key)
				{
					delete_next(head, t);
					break;
				}
				t = t->link;
			}
		}
	}


}
ListNode* insert_pos(ListNode* head, int pos, element value)
{
	ListNode* tmp;

	tmp = head;
	int i;

	if (pos == 0)
	 head =	insert_first(head, value);
	else
	{
		for (i = 0; i < pos - 1; i++)
		{
			tmp = tmp->link;
		}
		head = insert_next(head, tmp, value);
	}

	return head;



}
ListNode* delete_pos(ListNode* head, int pos)
{
	ListNode* tmp;
	int i;

	tmp = head;

	if (pos == 0)
		head = delete_first(head);
	else
	{
		for (i = 0; i < pos - 1; i++)
		{
			tmp = tmp->link;
		}

		head = delete_next(head, tmp);
	}
	
	return head;
	

}
	int main(void)
	{
		ListNode* list1 = NULL, * list2 = NULL, * list3;
		//list1 = 30->20->10->�� �����. �̶� 10, 20, 30�� ������ ��带 �����Ѵ�. 
		list1 = insert_first(list1, 10);
		list1 = insert_first(list1, 20);
		list1 = insert_first(list1, 30);
		// list1�� ��� 
		printf("list1 = ");
		print_list(list1);

		//list1�� �� �� ��带 �����Ѵ� ��, list1 = 20->30-> 
		list1 = delete_first(list1);
		// list1�� ��� 
		printf("list1 = ");
		print_list(list1);
		//list2 = 11->22->33->44->�� �����. �̶� 11, 22, 33, 44�� ������ ��带 �����Ѵ�. 
		list2 = insert_last(list2, 11);
		list2 = insert_last(list2, 22);
		list2 = insert_last(list2, 33);
		list2 = insert_last(list2, 44);

		// list2�� ��� 
		printf("list2 = ");
		print_list(list2);
		// list2�� �� �� ��带 �����Ѵ�. ��, list2 = 11->22->33-> 
		list2 = delete_last(list2);
		// list2�� ��� 
		printf("list2 = ");
		print_list(list2);
		//list2�� �������� �ٲ� ����Ʈ�� list3�� ����Ű�� �Ѵ�. list3 = 33->22->11->�� �����. 
		list3 = reverse(list2);
		//list3�� ����Ѵ�. 
		printf("list3 = ");
		print_list(list3);
		// list1 = 20->30->33->22->11->�� �����. ��, list1�� list3�� ���ļ� list1�� ����Ű�� �Ѵ�. 
		list1 = concat(list1, list3);
		//list1�� ����Ѵ�. 
		printf("list1 = ");
		print_list(list1);

	
		
		printf("item�� ����Ʈ�� ������ 1�� �ƴϸ� 0�� ��ȯ: %d\n", is_in_list(list1, 22));
		
		printf("����� ���� ��ȯ: %d\n", get_length(list1));
		
		printf("��� ������ ���� ���� ���� ��ȯ: %d\n", get_total(list1));
		
		printf("pos��ġ�� �ִ� ��� �����͸� ��ȯ: %d\n", get_entry(list1, 2));
		
		printf("���ϴ� ���� ã�Ƽ� �����ϴ� �Լ�\n");
		list1 = delete_by_key(list1, 20);
		print_list(list1);
		
		printf("pos ��ġ�� value�� ���� ��带 �߰�\n");
		list1 = insert_pos(list1, 1, 90);
		print_list(list1);
		
		printf("pos ��ġ�� ��带 ����\n");
		list1 = delete_pos(list1, 0);
		print_list(list1);

	}