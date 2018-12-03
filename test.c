#define _STD_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ������ ���� ������ node�� ����ü�� ����
struct node
{
	int value;
	struct node *next;
}

�������� �Է� �޴´�(CTRL_Z�� �Էµ� ������ �Է¹���)

�ԷµǴ� �������� linked list�� ���� �ϸ鼭 node�� ����
 Head��� struct node�� ����Ű�� pointer�� ����� ��
 
������ ������ ����Ͻÿ�
 �Է� �ڷḦ �Է� ������ ��� (1,2,3,4,5,6,7,8,9)
 �Էµ� �ڷ��� ������ ��� (9)
  �Է��ڷ��� �߰���ġ�� �ִ� �ڷ��� �� ���(�߰����� �ƴ�) (5)
  �Է��ڷḦ �Է� �������� ���(9 8 7 6 5 4 3 2 1)
  �Է��ڷῡ�� Ȧ����° �ڷḦ ��� ����
  ���� �ڷḦ ������� ���
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
	
	printf("�ڷḦ �Է��Ͻÿ�\n");
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
			//printf("Ȧ�� %d %d\n", i, nodes->value);
			mem = nodes;
			nodes = nodes->next;
			temp->next = nodes;
			free(mem);
		}
		else
		{
			//printf("¦�� %d %d\n", i, nodes->value);
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
	//�Է¼� ��� 
	printf("\n�Է� �� ��� : ");
	while(1)
	{
		printf("%d ", nodes->value);
		nodes = nodes->next;
		if(Tail->next == nodes) break;
	}
	
	//���� ���
	printf("\n�Էµ� �ڷ��� ���� ��� : %d\n", n);
	
	//�߰� �� ���
	i = n / 2;
	nodes = Head;
	while(i > 0)
	{
		nodes = nodes->next;
		i--;
	}
	printf("�߰� ��ġ �ڷ� �� ��� : %d\n", nodes->value);
	
	//�Է��ڷ� ���� ���
	i = n;
	printf("�Է� �ڷ� ���� ��� : ");
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
	
	//�Է� �ڷ� Ȧ����° �ڷ� ����
	processMemory();
	//printf("�ڷ� ó�� �Ϸ� \n");
	
	//���� �ڷ� ���� ���
	printf("\n���� �ڷ� ������� ��� : ");
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
	printf("Head ��: %u\n", head);
	printf("First node:          addr: %u      value: %d        next: %u\n", first, first->value, first->next);
	printf("Second node:         addr: %u      value: %d        next: %u\n", last, last->value, last->next);
	printf("Third node:          addr: %u      value: %d        next: %u\n", third, third->value, third->next);
}

void freeMemory()
{
	free(first), free(last), free(third);
}*/
