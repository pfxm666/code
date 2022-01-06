#include <stdio.h>
#include <stdlib.h>
#define ok 1;
#define error 0;
struct student{
	char name[10]; 
	int number; 
	char major[20];
	int banji;	
};
struct node{
	struct student date;
	struct node* next;  
};
typedef int status; 
typedef struct node* linklist;
linklist head;

void makemenu();													//�˵� 
void keydown();														//�û����� 
status initlinklist(linklist* head);                				//��ʼ������ 
status instertlist(linklist *head,struct student date);				//ͷ�巨�������� 
void printlist(linklist head);

int main(void)
{
	head->next=NULL;
	void makemenu();
	keydown();
	return 0;
} 

void makemenu()
{
	printf("--------------------��ѧ������ϵͳ��--------------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");  
	printf("\t\t4.������Ϣ\n"); 
	printf("\t\t5.�޸���Ϣ\n"); 
	printf("---------------------------------------------------------\n");
	printf("���������ѡ��0-5����"); 
} 

void keydown()
{
	int userkey;
	struct student date;
	scanf("%d",&userkey);
	switch(userkey)
	{
		case 0:
			printf("�˳��ɹ���\n");
			system("pasue");
			exit(0);
			break;
		case 1:
			printf("������ѧ����Ϣ(name,number,subject,class)��\n");
			scanf("%s%d%s%d",date.name,&date.number,date.major,&date.banji);
			instertlist(head,date);
			printf("¼��ɹ���"); 
			break;
		case 2:
			printlist(*head);
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			break;
		default:
			printf("������󡣡������������룺"); 
			break;
	}
}

status instertlist(linklist head,struct student date)
{
	linklist p=(linklist)malloc(sizeof(struct node));
	p->date=date;
	p->next=head->next;
	head->next=p;
}

void printlist(linklist head)
{
	linklist p=head->next;
	printf("����\tѧ��\tרҵ\t�༶\n");
	while(p)
	{
		printf("%s\t%s\t%d\t%d",p->date.name,p->date.number,p->date.major,p->date.banji);
		p=p->next;
	}
}

status initlinklist(linklist head)
{
	head=(linklist)malloc(sizeof(struct node));
	if(head==NULL)
	return error;
	head->next=NULL;
	return ok;
}
