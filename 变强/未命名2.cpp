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

void makemenu();													//菜单 
void keydown();														//用户交互 
status initlinklist(linklist* head);                				//初始化链表 
status instertlist(linklist *head,struct student date);				//头插法插入数据 
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
	printf("--------------------【学生管理系统】--------------------\n");
	printf("\t\t0.退出系统\n");
	printf("\t\t1.录入信息\n");
	printf("\t\t2.浏览信息\n");
	printf("\t\t3.删除信息\n");  
	printf("\t\t4.查找信息\n"); 
	printf("\t\t5.修改信息\n"); 
	printf("---------------------------------------------------------\n");
	printf("请输入你的选择（0-5）："); 
} 

void keydown()
{
	int userkey;
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
			printf("输入错误。。。请重新输入："); 
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
	printf("姓名\t学号\t专业\t班级\n");
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
