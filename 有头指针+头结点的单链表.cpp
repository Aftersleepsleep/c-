#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
//���嵥����ṹ
typedef struct LNode
{
	int data;             //����������
	struct LNode *next;   //����ָ����
}LNode,*LinkList;	      //LinkListΪָ��ṹ��LNode��ָ������
//����������L
bool InitList_L(LinkList &L)
{
L=new LNode;
L->next=NULL;
return true;		
}
//�ж�L�Ƿ�Ϊ�ձ�
 bool ListEmpty(LinkList L)
 {
 	if(L->next){//�ǿ�
	 	return false;
	 }
	 else return true;
 }
// ���ٵ�����L
bool DestoryList_L(LinkList &L)
{
	LNode *p;
	while(L){
		p=L;
		L=L->next;
		delete p;
	}
	return true;
}
//���������L����Ϊ�ձ�
bool ClearList(LinkList &L)
{
	LNode*p,*q;//����LinkList p,q;
	p=L->next;
	while(p){//û����β����ִ��
		q=p->next;
		delete p;
		p=q;
		//����������ש����
	}
	L->next=NULL;
	return true;
}
//������L�ı�
int ListLength_L(LinkList L)
{int i;
LinkList p;
p=L->next;//pָ���һ�����
i=0;
while(p){  //����������ͳ�ƽ����
	i++;
	p=p->next;
}
	return i;
}
bool GetElem_L(LinkList L,int i,int &e)
{
	//��ȡ���Ա�L�е�ĳ������Ԫ�ص����ݣ�ͨ����������
		LinkList p;
		p=L->next;
		int j=1;
	while(p&&j<i){
		p=p->next;
		++j;
	}
	if(!p||j>i)	return false;
	e=p->data;
	return true;
		
}
//�����Ա�L�в���ֵΪe������Ԫ��
//�ҵ����򷵻�L��ֵΪe������Ԫ�صĵ�ַ������ʧ�ܷ���NULL
LNode* LocateElem_L(LinkList L,int e)
{
	LinkList p;
	p=L->next;
	while(p&&p->data!=e){
		p=p->next;	
	}
return p;	
}
//�����Ա�L�в���ֵΪe������Ԫ�ص�λ�����
int LocateElem_L2(LinkList L,int e)
{
	//����L��ֵΪe������Ԫ�ص�λ����ţ�����ʧ�ܷ���0
	LinkList p;
	p=L->next;
	int j=1;
	while(p&&p->data!=e)
	{
		p=p->next;
		j++;
	}
	if(p) return j;
	else return 0;
}
//����--�ڵ�i�����ǰ����ֵΪe�½��
bool LinkInsert_L(LinkList &L,int i,int e)
{
	LinkList p;
	p=L;
	int j=0;
	while(p&&j<i-1){p=p->next;++j;}
	if(!p||j>i-1){return false;}
	LinkList s;
	s=new LNode;
	s->data=e;
	s->next=p->next;
	p->next=s;
	return true;
}
//�����Ա�L�еĵ�i������Ԫ��ɾ��
bool ListDelete_L(LinkList &L,int i)
{
LinkList p=L;
int j=0;
while(p->next&&j<i-1){
	p=p->next;
	++j;
}	
if(!p->next||j>i-1)return false;
LinkList q;
q=p->next;
	p->next=q->next;
//	e=q->data;
	delete q;
	return true;	
}
//ͷ�彨������
 void CreatList_H(LinkList &L,int n)
 {
 	
 	LinkList p;
 	L=new LNode;
 	L->next=NULL;
 	for(int i=n;i>0;i++)
 	{
	 p=new LNode;
//	 	cin>>p->data;
p->data=rand()%100;
	 	p->next=L->next;
	 	L->next=p;
	 }
 }
 ///β�巨����������
 void CreatList_R(LinkList &L,int n)
 {
 	L=new LNode;
 	L->next=NULL;
 	LinkList r;
 	r=L;
 	LinkList p;
 	for(int i=0;i<n;i++)
 	{
	 	p=new LNode;
//	 	cin>>p->data;
p->data=rand()%10;
	 	p->next=NULL;
	 	r->next=p;
	 	r=p;
	 }
 }
 //��˳���ӡ������
 void PrintList(LinkList L,int len)
 {
 	LNode *p;
 	p=L->next;
 	for(int j=1;j<=len;j++){
	 	cout<<" "<<p->data<<" "<<endl;
	 	p=p->next;
	 }
	 	cout<<"�������������Ϊ"<<len<<"\n"<<endl;
 }
int main()
{
		srand(time(NULL));//���������
	LinkList L;
//	������ս��
	InitList_L(L);
	//β�巨��������
CreatList_R(L,10);
//��ӡ��������
PrintList(L,ListLength_L(L));
//ɾ����i��Ԫ��
cout<<"ɾ��������λ�õ�Ԫ�أ�"<<endl;
ListDelete_L(L,3);
//��ӡ��������
PrintList(L,ListLength_L(L));
//�ڵڶ���λ�ò���2
cout<<"�ڵڶ���λ�ò���2��"<<endl;
LinkInsert_L(L,2,2);
PrintList(L,ListLength_L(L));
cout<<"����2��λ�ã������ص�ַ��"<<endl;
//����2��λ�ã������ص�ַ
LNode* Locate=LocateElem_L(L,2);
cout<<Locate<<endl;
//����2��λ�ã�����λ�����
cout<<"����2��λ�ã�����λ����ţ�"<<endl;
int s=LocateElem_L2(L,2);
cout<<s<<endl;

	return 0;
}
