#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>
struct chengji{				//����һ������������ѧ����Ϣ
	char num[15];//ѧ��
	char name[15];//����
	int math;
	int english;
	int gym;
	int history;
	int chinese;
	int total;//�ܳɼ�
	int aver;//ƽ���ɼ�
	struct chengji * next;
};
struct chengji *p1,*p2,*head=0;
int i;
FILE *fp;
void input(void)//�������뺯��
{
	fp=fopen("1.txt","w");
	printf("����ѧ����Ϣ(����0�����������)��\n");
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
void display(void)//������ʾ����
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
void modify(void)//�����޸ĺ���
{
	int a;
	struct chengji *p3,*p;
	p=(struct chengji *)malloc(sizeof(struct chengji));
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	char b[15];
	printf("����Ҫ�޸�ʲô��\n");
	printf("�޸�ѧ�ţ�1���޸�������2���޸ĳɼ���3\n");
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
			printf("�����Ŀ:\n");
			scanf("%s",b);
			printf("�����޸�������:\n");
			scanf("%s",p->name);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("������ȷ�ɼ�\n");
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
			printf("�����޸�������:\n");
			scanf("%s",p->name);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("������ȷѧ��\n");
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
			printf("�����޸���ѧ��:\n");
			scanf("%s",p->num);
			for(;;)
			{
				if(strcmp(p1->name,p->name)==0)
				{
					printf("������ȷ����\n");
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
void find(void)//������Һ���
{
	fp=fopen("1.txt","r");
	p1=(struct chengji *)malloc(sizeof(struct chengji));
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	printf("����������:\n");
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
void add(void)//������Ӻ���
{
	fp=fopen("1.txt","a");
	p2=(struct chengji *)malloc(sizeof(struct chengji));
	printf("�������ʲô?(ֻ�����һ�����ݣ�\n");
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
	for( ; ;)     //ѭ��ִ�й��ܲ˵�
	{
		system("cls");  //����Ļ
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
		case 'a': input();break; //�������뺯��
		case 'b': display();break;//������ʾ����
		case 'c': modify();break;//�����޸ĺ���
		case 'd': find();break;//���ò��Һ���
		case 'e': add(); break;//������Ӻ���
		}
	}
}