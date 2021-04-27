#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define len sizeof(struct k)
#include<iostream>
using namespace std;
typedef struct k
{
	char a[9],yiqi[100],xinggui[100],danj[100],gouq[100],lr[100],bz[100];
	struct k *next;
}k;
k  *head=(k*)malloc(len),*p,*pre,*l=head,*p3;
void meau()
{
	cout<<"菜单功能"<<endl;
	cout<<"1 (1)输入 (2)添加记录"<<endl;
	cout<<"2 (1)显示 (2)查询记录"<<endl;
	cout<<"3 修改记录"<<endl;
	cout<<"4 写入文件"<<endl;
	cout<<"-1 结束菜单功能"<<endl;
}
void xianshi()
{
	int t;
	for(p=head->next,t=0;p!=0;p=p->next)
				    {cout<<"设备编号:"<<p->a<<" "<<"仪器名称:"<<p->yiqi<<" "<<"型号规格:"<<p->xinggui<<" "<<"单价:"<<p->danj<<" "<<"购入日期:"<<p->gouq<<" "<<"领用人:"<<p->lr<<" "<<"使用状况和备注:"<<p->bz<<endl;t++;}
			   if(t==0) cout<<"无设备信息"<<endl;
}
void zimeau(int n)
{
	int m,t;
	char b[9];
	FILE *p1,*p2;
	p1=fopen("dazuoye.txt","r");
	p2=fopen("xieru.txt","w");
	if(n==1)
		while(1)
		{
		cout<<"1 输入    2 添加记录    0 返回菜单"<<endl;
		cin>>m;
		if(m==0) break;
		if(m==1)
		{
			while(!feof(p1))
			{   p=(k*)malloc(len);
				fscanf(p1,"%s %s %s %s %s %s %s",p->a,p->yiqi,p->xinggui,p->danj,p->gouq,p->lr,p->bz);
				l->next=p;
			    l=p;
			}
			l->next=0;
			cout<<"已输入"<<endl;
		}
		if(m==2)
		{
			cout<<"输入添加信息:设备编号:";
			cin>>b;
			for(p=head->next,t=0;p!=0;p=p->next)
				if(strcmp(p->a,b)==0) {cout<<"设备编号已使用"<<endl;t++;break;}
			if(t!=0) ;
			else
			{
            p=(k*)malloc(len);
			strcpy(p->a,b);
			cout<<"	     仪器名称:";
			cin>>p->yiqi;
			cout<<"	     型号规格:";
			cin>>p->xinggui;
			cout<<"	         单价:";
			cin>>p->danj;
			cout<<"	     购入日期:";
			cin>>p->gouq;
			cout<<"	       领用人:";
			cin>>p->lr;
			cout<<"	     使用状况和备注:";
			cin>>p->bz;
			cout<<"（已添加）"<<endl;
			l->next=p;
			l=p;
			}
			l->next=0;
		}
		}
	if(n==2)
		while(1)
		{
			cout<<"1 显示    2 查询记录    0 返回菜单"<<endl;
			cin>>m;
			if(m==0) break;
		    if(m==1)
			   xianshi();
		    if(m==2)
		    {
			   cout<<"已有设备信息:"<<endl;
			   xianshi();
			   cout<<"输入需查询设备的信息:";
			   cin>>b;
			   for(p=head->next,t=0;p!=0;p=p->next)
				   if(strcmp(p->a,b)==0||strcmp(p->yiqi,b)==0||strcmp(p->xinggui,b)==0||strcmp(p->danj,b)==0||strcmp(p->gouq,b)==0||strcmp(p->lr,b)==0||strcmp(p->bz,b)==0)  {cout<<"设备编号:"<<p->a<<" "<<"仪器名称:"<<p->yiqi<<" "<<"型号规格:"<<p->xinggui<<" "<<"单价:"<<p->danj<<" "<<"购入日期:"<<p->gouq<<" "<<"领用人:"<<p->lr<<" "<<"使用状况和备注:"<<p->bz<<endl;t++;break;}
			   if(t==0) cout<<"无此设备"<<endl;
		    }
		}
	if(n==3)
	while(1)
	 {
		cout<<"1 修改    2 删除    0 返回菜单"<<endl;
		cin>>m;
		if(m==0) break;
		if(m==1)
		{
			cout<<"已有设备信息:"<<endl;
			xianshi();
			cout<<endl<<"输入修改设备编号:";
			cin>>b;
			for(p3=head,p=head->next,t=0;p!=0;p3=p,p=p->next)
			if(strcmp(p->a,b)==0)
			{
				cout<<"设备原信息:"<<"设备编号:"<<p->a<<" "<<"仪器名称:"<<p->yiqi<<" "<<"型号规格:"<<p->xinggui<<" "<<"单价:"<<p->danj<<" "<<"购入日期:"<<p->gouq<<" "<<"领用人:"<<p->lr<<" "<<"使用状况和备注:"<<p->bz<<endl;
				t++;
				cout<<"修改项原信息:"<<endl;
				cin>>b;
				    if(strcmp(p->a,b)==0){ cout<<"修改项修改后信息:";cin>>p->a;}
					if(strcmp(p->yiqi,b)==0){ cout<<"修改项修改后信息:";cin>>p->yiqi;}
					if(strcmp(p->xinggui,b)==0){ cout<<"修改项修改后信息:";cin>>p->xinggui;}
					if(strcmp(p->danj,b)==0){ cout<<"修改项修改后信息:";cin>>p->danj;}
					if(strcmp(p->gouq,b)==0){ cout<<"修改项修改后信息:";cin>>p->gouq;}
					if(strcmp(p->lr,b)==0){ cout<<"修改项修改后信息:";cin>>p->lr;}
					if(strcmp(p->bz,b)==0){ cout<<"修改项修改后信息:";cin>>p->bz;}
			        cout<<"（已修改）"<<endl;
				    break;
			}
			if(t==0) cout<<"无此设备"<<endl;
		}
		if(m==2)
		{
			cout<<"已有设备信息:"<<endl;
			xianshi();
			cout<<endl<<"需删除设备的编号:";
			cin>>b;
			for(pre=head,p=pre->next,t=0;p!=0;pre=p,p=pre->next)
			if(strcmp(p->a,b)==0)
			{
				pre->next=p->next;
				cout<<"删除成功"<<endl;
				free(p);
				t++;
				break;
			}
			if(t==0) cout<<"无此设备"<<endl;
		}
	}

	if(n==4)
	{
		while(1)
		{
		cout<<"1 写入文件    0 返回菜单"<<endl;
		cin>>m;
		if(m==0)break;
		if(m==1)
		{
			for(p=head->next,t=0;p!=0;p=p->next)
			{fprintf(p2,"%s %s %s %s %s %s %s\n",p->a,p->yiqi,p->xinggui,p->danj,p->gouq,p->lr,p->bz);t++;}
			if(t==0) cout<<"无设备信息"<<endl;
			else 
				{
					cout<<"已写入"<<endl;
					fclose(p2);
			    }
		}
		}
	}	
}
int main()
{
	int n;
	head->next=0;
	while(1)
	{   
		meau();
		scanf("%d",&n);
		if(n==-1)
	    {
			cout<<"结束菜单功能"<<endl;
			break;
		}
		zimeau(n);
		system("cls");
	}
	system("pause");
	return 0;
}
