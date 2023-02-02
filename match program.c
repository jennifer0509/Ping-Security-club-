#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3 //3���� ����
#define MAX_STRING 100 // �߰�

typedef struct { //����
    char name[MAX_STRING];
} element;

typedef struct {
    element  queue[MAX_QUEUE_SIZE];
    int  front, rear;
} QueueType;
//
void error(char* message)
{
    fprintf(stderr, "%s\n", message);
    exit(1);
}
// �ʱ�ȭ �Լ�
void init(QueueType* q)
{
    q->front = q->rear = 0;
}
// ���� ���� ���� �Լ�
int is_empty(QueueType* q)
{
  
    return (q->front == q->rear);
}
// ��ȭ ���� ���� �Լ�
int is_full(QueueType* q)
{
    return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);

}
// ���� �Լ�
void enqueue(QueueType* q, element item)
{
    if (is_full(q))
        error("ť�� ��ȭ�����Դϴ�");
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->queue[q->rear] = item;
}
// ���� �Լ�
element dequeue(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->queue[q->front];
}
// ���� �Լ�
element peek(QueueType* q)
{
    if (is_empty(q))
        error("ť�� ��������Դϴ�");
    return q->queue[(q->front + 1) % MAX_QUEUE_SIZE];
}

int get_count(QueueType* q)
{
    return ((q->rear) - (q->front));
}

void print_queue(QueueType* q) // �߰�, 20141016 ����
{
    //�ڿ��� ���� ���� ������ �ȴ� 

    int i;

    for (i = (q->front) + 1; i <= q->rear; i++)
        printf("%s ", q->queue[i].name);

    printf("\n");

}
void try_match(element m, QueueType* partnerQ, QueueType* myQ) //�߰� �κ�: �� ���� �Լ� �̸�??
{
    
     
    if (!is_empty(partnerQ))
        printf("Ŀ���� ź���߾��ϴ�! %s�� %s\n", m.name,dequeue(partnerQ).name);
    else {

        if (is_full(myQ))
            printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�. ����ڰ� ��á���� ���ȸ�� �̿�\n");
        else
        {
            enqueue(myQ, m);
            printf("���� ����ڰ� �����ϴ�. ��ٷ��ֽʽÿ�.\n");
        }



    }
 
}
int main(void)
{
    QueueType manQ, womanQ;
    char choice;
    element newPerson;
    char gender;

    init(&manQ);
    init(&womanQ);

    printf("���� �ּ� ���α׷��Դϴ�.\n");

    printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit):");
    scanf("%c", &choice);

    while (choice != 'q') {
        switch (choice) {
        case 'i':
            printf("�̸��� �Է�:");
            scanf("%s", &newPerson.name);
            fflush(stdin);
            printf("������ �Է�(m or f):");
            scanf(" %c", &gender);
            if (gender == 'm')
                try_match(newPerson, &womanQ, &manQ);
            else
                try_match(newPerson, &manQ, &womanQ);
            break;

        case 'c':
            printf("���� ����� %d��: ", get_count(&manQ));
            print_queue(&manQ);
            printf("���� ����� %d��: ", get_count(&womanQ));
            print_queue(&womanQ);
        }
        fflush(stdin);
        printf("i(nsert, ���Է�), c(heck, ����� üũ), q(uit):");
        scanf("%c", &choice);
    }
}
/*
 �߿��Ѱ��� ��Ī�� �ϴ� ���α׷� �κ��̴�
 �� ����� �Է� �޾Ƽ� �ٸ� ����� ��Ī�� ��ų���� �̹� ������ �����Ѵٸ� 
 ���� �Է� ���� �ڽ��� ���� �ʾƵ� �ٷ� ����� �����ϴ�. 

 ������ ������ ���� ���¶�� �ڽ��� �ֱ� ���� ť�� �� á������ ���θ� Ȯ���ϰ� �־��־�� �Ѵ�. 
*/
