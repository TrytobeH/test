#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct chengji{				//定义一个链表来储存学生信息
	char num[15];//学号
	char name[15];//姓名
	int math;
	int english;
	int gym;
	int history;
	int chinese;
	int total;//总成绩
	int aver;//平均成绩
	struct chengji * next;
};
struct chengji *p1,*p2,*head=0;
int i;
FILE *fp;
void input(void)//定义输入函数
{
	fp=fopen("1.txt","w");
	printf("输入学生信息(输入0代表结束输入)：\n");
	for(i=0;;i++)
	{
		p1=(struct chengji *)malloc(sizeof(struct chengji));
		if(i==0)
			head=p1;
		else
			p2->next=p1;
		scanf("%s",p1->num);
		if(p1->num[0]=='0')
			break;
		scanf("%s %d %d %d %d %d %d %d\n",p1->name,
			&p1->math,&p1->english,&p1->gym,&p1->history,
			&p1->chinese,&p1->total,&p1->aver);
		fprintf(fp,"%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			p1->math,p1->english,p1->gym,p1->history,
			p1->chinese,p1->total,p1->aver);
		//fwrite(p1,sizeof(struct chengji),1,fp);
		p2=p1;
	}
	fclose(fp);
}
void display(void)//定义显示函数
{
	fp=fopen("1.txt","r");
	p1=(struct chengji *)malloc(sizeof(struct chengji));
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			&p1->math,&p1->english,&p1->gym,&p1->history,
			&p1->chinese,&p1->total,&p1->aver);
		printf("%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			p1->math,p1->english,p1->gym,p1->history,
			p1->chinese,p1->total,p1->aver);
	}
	fclose(fp);
	system("pause");
}
void modify(void)//定义修改函数
{
	int a;
	struct chengji *p3,*p;
	p=(struct chengji *)malloc(sizeof(struct chengji));
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	char b[15];
	printf("你想要修改什么？\n");
	printf("修改学号：1，修改姓名：2，修改成绩：3\n");
	fp=fopen("1.txt","r");
	scanf("%d",&a);
	i=0;
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d %d %d %d %d\n",p2->num,p2->name,
			&p2->math,&p2->english,&p2->gym,&p2->history,
			&p2->chinese,&p2->total,&p2->aver);
		p1=(struct chengji *)malloc(sizeof(struct chengji));
		if(i==0)
			head=p1;
		else
			p3->next=p1;
		*p1=*p2;
		p3=p1;
		i++;
	}
	fclose(fp);
	fp=fopen("1.txt","w");
	for(;;)
	{
		p1=head;
		if(a==3)
		{
			printf("输入科目:\n");
			scanf("%s",b);
			printf("输入修改人姓名:\n");
			scanf("%s",p->name);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("输入正确成绩\n");
					if(b[0]=='m')
					{
						scanf("%d",&p->math);
						p1->math=p->math;
						break;
					}
					if(b[0]=='e')
					{
						scanf("%d",&p2->english);
						p1->english=p->english;
						break;
					}
					if(b[0]=='g')
					{
						scanf("%d",&p2->gym);
						p1->gym=p->gym;
						break;
					}
					if(b[0]=='c')
					{
						scanf("%d",&p2->chinese);
						p1->chinese=p->chinese;
						break;
					}
					if(b[0]=='h')
					{
						scanf("%d",&p2->history);
						p1->history=p->history;
						break;
					}
					p1=p1->next;
				}
			}
			p1->total=p1->math+p1->english+p1->gym+p1->history+p1->chinese;
			p1->aver=(p1->total)/5;
			break;
		}
		if(a==1)
		{
			printf("输入修改人姓名:\n");
			scanf("%s",p->name);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("输入正确学号\n");
					scanf("%s",p->num);
					strcpy(p1->num,p->num);
					break;
				}
				p1=p1->next;
			}
			break;
		}
		if(a==2)
		{
			printf("输入修改人学号:\n");
			scanf("%s",p->num);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("输入正确姓名\n");
					scanf("%s",p->name);
					strcpy(p1->name,p->name);
					break;
				}
				p1=p1->next;
			}
			break;
		}
		fprintf(fp,"%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			p1->math,p1->english,p1->gym,p1->history,
			p1->chinese,p1->total,p1->aver);
	}
	fclose(fp);
	system("pause");
}
void find(void)//定义查找函数
{
	fp=fopen("1.txt","r");
	p1=(struct chengji *)malloc(sizeof(struct chengji));
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	printf("查找人姓名:\n");
	scanf("%s",p2->name);
	while(feof(fp)==0)
	{
		fscanf(fp,"%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			&p1->math,&p1->english,&p1->gym,&p1->history,
			&p1->chinese,&p1->total,&p1->aver);
		if(strcmp(p1->name,p2->name)==0)
		{
			printf("%s %s %d %d %d %d %d %d %d\n",p1->num,p1->name,
			p1->math,p1->english,p1->gym,p1->history,
			p1->chinese,p1->total,p1->aver);
		}
	}
	fclose(fp);
	system("pause");
}
void add(void)//定义添加函数
{
	fp=fopen("1.txt","a");
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	printf("你想添加什么?(只能添加一组数据）\n");
	scanf("%s %s %d %d %d %d %d %d %d",p2->num,p2->name,
		&p2->math,&p2->english,&p2->gym,&p2->history,
		&p2->chinese,&p2->total,&p2->aver);
	fprintf(fp,"%s %s %d %d %d %d %d %d %d\n",p2->num,p2->name,
			p2->math,p2->english,p2->gym,p2->history,
			p2->chinese,p2->total,p2->aver);
	fclose(fp);
}
void main()
{
	char i;
	for( ; ;)     //循环执行功能菜单
	{
		system("cls");  //清屏幕
		printf("* * * * * *Menue* * * * * *\n");
		printf("*       a. Input      *\n");
		printf("*       b. Display    *\n");
		printf("*       c. Modify    *\n");
		printf("*       d. Find     *\n");
		printf("*       e. Add      *\n");
		printf("*       f. Exit      *\n");
		printf("    Please select a to f    *\n");
		printf("* * * * * * * * * * * * * *\n");
		i=getch();
		if(i=='f') break;
		else switch(i)
		{
		case 'a': input();break; //调用输入函数
		case 'b': display();break;//调用显示函数
		case 'c': modify();break;//调用修改函数
		case 'd': find();break;//调用查找函数
		case 'e': add(); break;//调用添加函数
		}
	}
}