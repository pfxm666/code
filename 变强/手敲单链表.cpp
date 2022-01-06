#include <stdio.h>
#include <stdlib.h>
#define ok 1;
#define error 0;
struct student{
	char name[10]; 
	int number; 
	char subject[20];
	int Class;	
};

struct node{
	struct student date;
	struct node* next;
};

typedef struct node* linklist;
linklist head=(linklist)malloc(sizeof(struct node));
typedef int status; 
status initlinklist(linklist* head);      							//��ʼ������ 
void creatlisthead(linklist* head,struct student date);				//ͷ�巨 
void creatlisttail(linklist* head,struct student date);				//β�巨 
void printlist(linklist head);										//��ӡ 
status getelem(linklist head,int i,int *e);							//����ĳ����������ֵ ����������λ�ã� 
void clearlist(linklist *head);										//����������� 
status instertlist(linklist *head,struct student date);				//ͷ�巨�������� 
void deletelist(linklist head,int posdate);							//ɾ��ĳ����� 
linklist searchlist(linklist head,int posnumber);					//����ĳ���������ݣ������������ݣ�
void makemenu();													//�˵� 
void keydown();
int main(void)
{
	head->next=NULL;
	while(1)
	{
		makemenu();
		keydown();
		system("pause");
		system("cls");
	}
	return 0;
} 

status initlinklist(linklist* head)
{
	*head=(linklist)malloc(sizeof(struct node));
	if(*head==NULL)
	return error;
	(*head)->next=NULL;
	return ok;
}

void creatlisthead(linklist* head,int n)
{	
	int i;
	linklist p;
	*head=(linklist)malloc(sizeof(struct node));
	(*head)->next=NULL;
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(struct node));
		p->date.number=i;
		p->next=(*head)->next;
		(*head)->next=p; 
	}	
}

void creatlisttail(linklist* head,int n)
{
	int i;
	linklist p,r;
	*head=(linklist)malloc(sizeof(struct node));
	(*head)->next=NULL;
	r=*head;
	for(i=0;i<n;i++)
	{
		p=(linklist)malloc(sizeof(struct node));
		p->date.number=i;
		r->next=p;
		r=p;
	}
	r->next=NULL;
}

void printlist(linklist head)
{
	linklist p=head->next;
	printf("����\tרҵ\tѧ��\t�༶\n");
	while(p)
	{
		printf("%s\t%s\t%d\t%d",p->date.name,p->date.subject,p->date.number,p->date.Class);
		p=p->next;
	}
}

//status getelem(linklist head,int i,int *e)
//{
	//linklist p=head->next;
	//int j=1;
//	while(p&&j<i)
//	{
		//p=p->next;
		//j++;
//	}
	//if(j>i||p==NULL)
//	return error;
//	*e=p->date;
//	return ok;
//}

void clearlist(linklist *head)
{
	linklist p,q;
	p=(*head)->next;
	while(p)
	{
		q=p->next;
		free(p);
		p=q;
	}
	(*head)->next=NULL;
}

status instertlist(linklist head,struct student date)
{
	linklist p=(linklist)malloc(sizeof(struct node));
	p->date=date;
	p->next=head->next;
	head->next=p;
}


void deletelist(linklist head,int posdate) 
{
	linklist posnode=head->next;
	linklist prenode=head;
	while(posnode!=NULL&&posnode->date.number!=posdate)
	{
		prenode=posnode;
		posnode=prenode->next;
	}
	if(posnode!=NULL)
	{
		prenode->next=posnode->next;
		free(posnode);
		printf("ɾ���ɹ���"); 
	}
}

linklist searchlist(linklist head,int posnumber)
{
	linklist p=head->next;
	while(p!=NULL&&p->date.number!=posnumber)
	{
		p=p->next;	
	}
	if(p==NULL)
	return NULL;
	else
	return p;
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
			scanf("%s%d%s%d",date.name,&date.number,date.subject,&date.Class);
			instertlist(head,date);
			printf("¼��ɹ���"); 
			break;
		case 2:
			printlist(head);
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
