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

void makemenu();													//菜单 
void keydown();														//用户交互 
status initlinklist(linklist head);                					//初始化链表 
void instertlist(linklist head,struct student date);			   //头插法插入数据 
void printlist(linklist head);									  //打印
void deletelist(linklist head,int posdate);						//删除指定学号的学生 
linklist searchlist(linklist head,int posnumber);				//查找指定学号的学生 

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
	printf("--------------【学生管理系统】--------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.删除信息\n");  
	printf("\t\t4.查找信息\n"); 
	printf("\t\t5.修改信息\n"); 
	printf("---------------------------------------------\n");
	printf("请输入你的选择（0-5）："); 
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
			printf("退出成功！\n");
			system("pasue");
			exit(0);
			break;
		case 1:
			printf("请输入学生信息(name,number,subject,class)：\n");
			scanf("%s%d%s%d",date.name,&date.number,date.major,&date.banji);
			instertlist(head,date);
			printf("录入成功！");
			savefile(head,"s.txt");
			break;
		case 2:
			printlist(head);
			break;
		case 3:
			printf("请输入要删除学生的学号\n");
			scanf("%d",&date.number);
			deletelist(head,date.number);
			savefile(head,"s.txt");
			break;
		case 4:
			printf("请输入要查找学生的学号\n");
			scanf("%d",&date.number);
			p=searchlist(head,date.number);
			if(p==NULL)
			printf("未查找到相关学生信息");
			else
			printf("%s\t%d\t%s\t%d\n",p->date.name,p->date.number,p->date.major,p->date.banji);
			break;
		case 5:
			printf("请输入要修改学生的学号\n");
			scanf("%d",&date.number);
			p=searchlist(head,date.number);
			if(p==NULL)
			printf("未查找到相关学生信息，无法修改\n");
			else
			{	printf("请输入要修改学生的信息（name，number，major，banji)\n");
				scanf("%s%d%s%d",p->date.name,&p->date.number,p->date.major,&p->date.banji);
				savefile(head,"s.txt");
				printf("修改成功\n");
			}
			break;
		default:
			printf("输入错误。。。请重新输入："); 
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
	printf("姓名\t学号\t专业\t班级\n");
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
		printf("删除成功！\n"); 
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
