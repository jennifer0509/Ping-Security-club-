#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1) typedef���� Score�� ����
typedef struct {
	int midterm;
	int final;
}Score;
void printScore(Score* p) {
	printf("�߰���� ������ %d\n", p->midterm);
	printf("�б⸻��� ������ %d\n", p->final);
} //2)
Score* biggerScore(Score* p1, Score* p2) {

	Score* s = (Score*)malloc(sizeof(Score));

	if (p1->midterm + p1->final > p2->midterm + p2->final)
		return p1;
	else
		return p2;
} //3)
Score* totalScore(Score* p1, Score* p2) {

	Score* p = (Score*)malloc(sizeof(Score));

	p->midterm = p1->midterm + p2->midterm;
	p->final = p1->final + p2->final;

	return p;
} //4)
Score* createScore(int m, int f) {
	Score* t = (Score*)malloc(sizeof(Score));

	t->midterm = m;
	t->final = f;

	return t;

} //5)
int main(void) {

	Score s1, s2;
	//1) p1, p2�� ���� �޸� �Ҵ��� �� ��

	Score* p3;

	// ����Ű�� ������ �� ����

	s1.midterm = 50;
	s1.final = 100;
	s2.midterm = 70;
	s2.final = 70;

	printScore(&s1);
	printScore(&s2);
	printf("-----------------------------\n");
	printf("���� ������ ���� ����:\n");
	printScore(biggerScore(&s1, &s2));
	printf("-----------------------------\n");
	printf("�� ������ �� ��:\n");
	printScore(totalScore(&s1, &s2));
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);

}

/*
* �� �������� �߿��Ѱ��� �ּҸ� �Ѱ��ִ� �κ��̴�. ���� �Լ������� �����ͷ� �ް� �ֱ� ������ ����ü�� �ּҸ� �Ѱ��־�� �Ѵ�.

*/