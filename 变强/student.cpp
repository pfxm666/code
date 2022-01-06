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
linklist head=(linklist)malloc(sizeof(struct node));

void makemenu();													//�˵� 
void keydown();														//�û����� 
status initlinklist(linklist head);                					//��ʼ������ 
void instertlist(linklist head,struct student date);			   //ͷ�巨�������� 
void printlist(linklist head);									  //��ӡ
void deletelist(linklist head,int posdate);						//ɾ��ָ��ѧ�ŵ�ѧ�� 
linklist searchlist(linklist head,int posnumber);				//����ָ��ѧ�ŵ�ѧ�� 

void readfile(linklist head,const char*fileurl)
{
	FILE* fp=fopen(fileurl,"r");
	if(fp==NULL)
	{
		fp=fopen(fileurl,"w+");
		fclose(fp);
		return ;
	}
	struct student date;
	while(fscanf(fp,"%s\t%d\t%s\t%d\n",date.name,&date.number,date.major,&date.banji)!=EOF)
	{
		instertlist(head,date);
	}
	fclose(fp);
}

void savefile(linklist head,const char* fileurl)
{
	FILE* fp=fopen(fileurl,"w");
	linklist p=head->next;
	while(p!=NULL)
	{
		fprintf(fp,"%s\t%d\t%s\t%d\n",p->date.name,p->date.number,p->date.major,p->date.banji);
		p=p->next;
	}
	fclose(fp);	
} 

int main(void)
{	
	head->next=NULL;
	readfile(head,"s.txt");
	while(1)
	{	
		makemenu();
		keydown();
		system("pause");
		system("cls");
	}
	return 0;
} 

void makemenu()
{
	printf("--------------��ѧ������ϵͳ��--------------\n");
	printf("\t\t0.�˳�ϵͳ\n");
	printf("\t\t1.¼����Ϣ\n");
	printf("\t\t2.�����Ϣ\n");
	printf("\t\t3.ɾ����Ϣ\n");  
	printf("\t\t4.������Ϣ\n"); 
	printf("\t\t5.�޸���Ϣ\n"); 
	printf("---------------------------------------------\n");
	printf("���������ѡ��0-5����"); 
} 

void keydown()
{
	int userkey;
	linklist p=NULL;
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
			savefile(head,"s.txt");
			break;
		case 2:
			printlist(head);
			break;
		case 3:
			printf("������Ҫɾ��ѧ����ѧ��\n");
			scanf("%d",&date.number);
			deletelist(head,date.number);
			savefile(head,"s.txt");
			break;
		case 4:
			printf("������Ҫ����ѧ����ѧ��\n");
			scanf("%d",&date.number);
			p=searchlist(head,date.number);
			if(p==NULL)
			printf("δ���ҵ����ѧ����Ϣ");
			else
			printf("%s\t%d\t%s\t%d\n",p->date.name,p->date.number,p->date.major,p->date.banji);
			break;
		case 5:
			printf("������Ҫ�޸�ѧ����ѧ��\n");
			scanf("%d",&date.number);
			p=searchlist(head,date.number);
			if(p==NULL)
			printf("δ���ҵ����ѧ����Ϣ���޷��޸�\n");
			else
			{	printf("������Ҫ�޸�ѧ������Ϣ��name��number��major��banji)\n");
				scanf("%s%d%s%d",p->date.name,&p->date.number,p->date.major,&p->date.banji);
				savefile(head,"s.txt");
				printf("�޸ĳɹ�\n");
			}
			break;
		default:
			printf("������󡣡������������룺"); 
			break;
	}
}

void instertlist(linklist head,struct student date)
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
		printf("%s\t%d\t%s\t%d\n",p->date.name,p->date.number,p->date.major,p->date.banji);
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
		printf("ɾ���ɹ���\n"); 
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
