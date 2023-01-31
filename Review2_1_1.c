#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
//1) typedef으로 Score를 정의
typedef struct {
	int midterm;
	int final;
}Score;
void printScore(Score* p) {
	printf("중간고사 성적은 %d\n", p->midterm);
	printf("학기말고사 성적은 %d\n", p->final);
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

	Score* p1, * p2, * p3;
	//1) p1, p2를 각각 메모리 할당을 한 후
	
	p1 = (Score*)malloc(sizeof(Score));
	p2 = (Score*)malloc(sizeof(Score));

	// 가리키는 변수에 값 대입

	p1->midterm = 50;
	p1->final = 100;
	p2->midterm = 70;
	p2->final = 70;

	printScore(p1);
	printScore(p2);
	printf("-----------------------------\n");
	printf("둘중 성적이 좋은 점수:\n");
	printScore(biggerScore(p1, p2));
	printf("-----------------------------\n");
	printf("두 성적의 총 합:\n");
	printScore(totalScore(p1, p2));
	printf("-----------------------------\n");
	p3 = createScore(100, 100);
	printScore(p3);
	
}

/*
* 이 문제에서 중요한 것은 말록 함수를 할당하는 것임

Score *p = (Score*)malloc(sizeof(Score));
*/