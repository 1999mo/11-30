#define _STD_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* 다음과 같은 구조의 node를 구조체로 정의
struct node
{
	int value;
	struct node *next;
}

정수값을 입력 받는다(CTRL_Z가 입력될 때까지 입력받음)

입력되는 정수값은 linked list를 구성 하면서 node에 저장
 Head라는 struct node를 가리키는 pointer를 사용할 것
 
다음의 내용을 출력하시오
 입력 자료를 입력 순으로 출력 (1,2,3,4,5,6,7,8,9)
 입력된 자료의 개수를 출력 (9)
  입력자료의 중간위치에 있는 자료의 값 출력(중간값이 아님) (5)
  입력자료를 입력 역순으로 출력(9 8 7 6 5 4 3 2 1)
  입력자료에서 홀수번째 자료를 모두 삭제
  남은 자료를 순서대로 출력
*/

struct node
{
	int value;
	struct node *next;
};

void inputMemory();
void processMemory();
void printMemory();
void freeMemory();

typedef struct node list;
list *Head = NULL;
list *nodes = NULL;
list *Tail = NULL;
list *createMemory();
int n = 0;

int main(void)
{
	inputMemory();
	printMemory();
	freeMemory();
	system("pause");
	return 0;
}
	   
void inputMemory()
{
	int num = 0;
	
	printf("자료를 입력하시오\n");
	fflush(stdin);
	num = getch();
	while(num != 26)
	{
		nodes = createMemory();
		if(Tail != NULL) Tail->next = nodes;
		
		if(Head == NULL)
		{
			Head = nodes;
		}
		
		num -= 48;
		nodes->value = num;
		
		Tail = nodes;
		nodes = NULL;
		
		n++;
		num = getche();
	}
}

void processMemory()
{
	int i = 1;
	list *mem, *temp;
	nodes = Head;
	temp = Head;
	Head = Head->next;
	
	while(1)
	{
		if(i % 2 == 1)
		{
			//printf("홀수 %d %d\n", i, nodes->value);
			mem = nodes;
			nodes = nodes->next;
			temp->next = nodes;
			free(mem);
		}
		else
		{
			//printf("짝수 %d %d\n", i, nodes->value);
			temp = nodes;
			Tail = nodes;
			nodes = nodes->next;
		}
		i++;
		if(i == n + 1)
		{
			break;
		}
	}
}

void printMemory()
{
	int i, j;
	
	nodes = Head;
	//입력순 출력 
	printf("\n입력 순 출력 : ");
	while(1)
	{
		printf("%d ", nodes->value);
		nodes = nodes->next;
		if(Tail->next == nodes) break;
	}
	
	//개수 출력
	printf("\n입력된 자료의 개수 출력 : %d\n", n);
	
	//중간 값 출력
	i = n / 2;
	nodes = Head;
	while(i > 0)
	{
		nodes = nodes->next;
		i--;
	}
	printf("중간 위치 자료 값 출력 : %d\n", nodes->value);
	
	//입력자료 역순 출력
	i = n;
	printf("입력 자료 역순 출력 : ");
	while(1)
	{
		nodes = Head;
		
		j = 1;
		while(j < i)
		{
			nodes = nodes->next;
			
			j++;
		}
		
		printf("%d ", nodes->value);
		
		i--;
		
		if(i == 0) break;
	}
	
	//입력 자료 홀수번째 자료 삭제
	processMemory();
	//printf("자료 처리 완료 \n");
	
	//남은 자료 순서 출력
	printf("\n남은 자료 순서대로 출력 : ");
	nodes = Head;
	while(1)
	{
		printf("%d ", nodes->value);
		nodes = nodes->next;
		if(nodes == Tail->next) break;
	}
}

void freeMemory()
{
	list *mem;
	nodes = Head;
	
	while(1)
	{
		//printf("Freed memory\n");
		mem = nodes;
		nodes = nodes->next;
		free(mem);
		
		if(nodes == Tail)
		{
			free(nodes);
			break;
		}
	}
}

list *createMemory()
{
	list *mem;
	
	mem = (list *)malloc(sizeof(mem));
	return mem;
}
/*#define _STD_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int value;
	struct node *next;
};


typedef struct node list;
list *giveMemory();
void setMemory();
void printMemory();
void freeMemory();
list *first = NULL, *last = NULL, *third = NULL, *head = NULL;

int main(void)
{
	setMemory();
	printMemory();
	freeMemory();
	system("pause");
	return 0;
}

list *giveMemory()
{
	list *Node;
	Node = (list *)malloc(sizeof(list));
	return Node;
}

void setMemory()
{
	first = giveMemory();
	last = giveMemory();
	third = giveMemory();
	
	first->value = 11;
	last->value = 99;
	third->value = 50;
	
	first->next = last;
	last->next = third;
	
	head = first;
}

void printMemory()
{
	printf("Head 값: %u\n", head);
	printf("First node:          addr: %u      value: %d        next: %u\n", first, first->value, first->next);
	printf("Second node:         addr: %u      value: %d        next: %u\n", last, last->value, last->next);
	printf("Third node:          addr: %u      value: %d        next: %u\n", third, third->value, third->next);
}

void freeMemory()
{
	free(first), free(last), free(third);
}*/
