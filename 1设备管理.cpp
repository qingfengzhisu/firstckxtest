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
	cout<<"�˵�����"<<endl;
	cout<<"1 (1)���� (2)��Ӽ�¼"<<endl;
	cout<<"2 (1)��ʾ (2)��ѯ��¼"<<endl;
	cout<<"3 �޸ļ�¼"<<endl;
	cout<<"4 д���ļ�"<<endl;
	cout<<"-1 �����˵�����"<<endl;
}
void xianshi()
{
	int t;
	for(p=head->next,t=0;p!=0;p=p->next)
				    {cout<<"�豸���:"<<p->a<<" "<<"��������:"<<p->yiqi<<" "<<"�ͺŹ��:"<<p->xinggui<<" "<<"����:"<<p->danj<<" "<<"��������:"<<p->gouq<<" "<<"������:"<<p->lr<<" "<<"ʹ��״���ͱ�ע:"<<p->bz<<endl;t++;}
			   if(t==0) cout<<"���豸��Ϣ"<<endl;
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
		cout<<"1 ����    2 ��Ӽ�¼    0 ���ز˵�"<<endl;
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
			cout<<"������"<<endl;
		}
		if(m==2)
		{
			cout<<"���������Ϣ:�豸���:";
			cin>>b;
			for(p=head->next,t=0;p!=0;p=p->next)
				if(strcmp(p->a,b)==0) {cout<<"�豸�����ʹ��"<<endl;t++;break;}
			if(t!=0) ;
			else
			{
            p=(k*)malloc(len);
			strcpy(p->a,b);
			cout<<"	     ��������:";
			cin>>p->yiqi;
			cout<<"	     �ͺŹ��:";
			cin>>p->xinggui;
			cout<<"	         ����:";
			cin>>p->danj;
			cout<<"	     ��������:";
			cin>>p->gouq;
			cout<<"	       ������:";
			cin>>p->lr;
			cout<<"	     ʹ��״���ͱ�ע:";
			cin>>p->bz;
			cout<<"������ӣ�"<<endl;
			l->next=p;
			l=p;
			}
			l->next=0;
		}
		}
	if(n==2)
		while(1)
		{
			cout<<"1 ��ʾ    2 ��ѯ��¼    0 ���ز˵�"<<endl;
			cin>>m;
			if(m==0) break;
		    if(m==1)
			   xianshi();
		    if(m==2)
		    {
			   cout<<"�����豸��Ϣ:"<<endl;
			   xianshi();
			   cout<<"�������ѯ�豸����Ϣ:";
			   cin>>b;
			   for(p=head->next,t=0;p!=0;p=p->next)
				   if(strcmp(p->a,b)==0||strcmp(p->yiqi,b)==0||strcmp(p->xinggui,b)==0||strcmp(p->danj,b)==0||strcmp(p->gouq,b)==0||strcmp(p->lr,b)==0||strcmp(p->bz,b)==0)  {cout<<"�豸���:"<<p->a<<" "<<"��������:"<<p->yiqi<<" "<<"�ͺŹ��:"<<p->xinggui<<" "<<"����:"<<p->danj<<" "<<"��������:"<<p->gouq<<" "<<"������:"<<p->lr<<" "<<"ʹ��״���ͱ�ע:"<<p->bz<<endl;t++;break;}
			   if(t==0) cout<<"�޴��豸"<<endl;
		    }
		}
	if(n==3)
	while(1)
	 {
		cout<<"1 �޸�    2 ɾ��    0 ���ز˵�"<<endl;
		cin>>m;
		if(m==0) break;
		if(m==1)
		{
			cout<<"�����豸��Ϣ:"<<endl;
			xianshi();
			cout<<endl<<"�����޸��豸���:";
			cin>>b;
			for(p3=head,p=head->next,t=0;p!=0;p3=p,p=p->next)
			if(strcmp(p->a,b)==0)
			{
				cout<<"�豸ԭ��Ϣ:"<<"�豸���:"<<p->a<<" "<<"��������:"<<p->yiqi<<" "<<"�ͺŹ��:"<<p->xinggui<<" "<<"����:"<<p->danj<<" "<<"��������:"<<p->gouq<<" "<<"������:"<<p->lr<<" "<<"ʹ��״���ͱ�ע:"<<p->bz<<endl;
				t++;
				cout<<"�޸���ԭ��Ϣ:"<<endl;
				cin>>b;
				    if(strcmp(p->a,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->a;}
					if(strcmp(p->yiqi,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->yiqi;}
					if(strcmp(p->xinggui,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->xinggui;}
					if(strcmp(p->danj,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->danj;}
					if(strcmp(p->gouq,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->gouq;}
					if(strcmp(p->lr,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->lr;}
					if(strcmp(p->bz,b)==0){ cout<<"�޸����޸ĺ���Ϣ:";cin>>p->bz;}
			        cout<<"�����޸ģ�"<<endl;
				    break;
			}
			if(t==0) cout<<"�޴��豸"<<endl;
		}
		if(m==2)
		{
			cout<<"�����豸��Ϣ:"<<endl;
			xianshi();
			cout<<endl<<"��ɾ���豸�ı��:";
			cin>>b;
			for(pre=head,p=pre->next,t=0;p!=0;pre=p,p=pre->next)
			if(strcmp(p->a,b)==0)
			{
				pre->next=p->next;
				cout<<"ɾ���ɹ�"<<endl;
				free(p);
				t++;
				break;
			}
			if(t==0) cout<<"�޴��豸"<<endl;
		}
	}

	if(n==4)
	{
		while(1)
		{
		cout<<"1 д���ļ�    0 ���ز˵�"<<endl;
		cin>>m;
		if(m==0)break;
		if(m==1)
		{
			for(p=head->next,t=0;p!=0;p=p->next)
			{fprintf(p2,"%s %s %s %s %s %s %s\n",p->a,p->yiqi,p->xinggui,p->danj,p->gouq,p->lr,p->bz);t++;}
			if(t==0) cout<<"���豸��Ϣ"<<endl;
			else 
				{
					cout<<"��д��"<<endl;
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
			cout<<"�����˵�����"<<endl;
			break;
		}
		zimeau(n);
		system("cls");
	}
	system("pause");
	return 0;
}
