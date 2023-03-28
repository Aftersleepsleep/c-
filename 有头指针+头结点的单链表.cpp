#include <iostream>
#include <stdio.h>
#include <ctime>
using namespace std;
//定义单链表结构
typedef struct LNode
{
	int data;             //结点的数据域
	struct LNode *next;   //结点的指针域
}LNode,*LinkList;	      //LinkList为指向结构体LNode的指针类型
//创建单链表L
bool InitList_L(LinkList &L)
{
L=new LNode;
L->next=NULL;
return true;		
}
//判断L是否为空表
 bool ListEmpty(LinkList L)
 {
 	if(L->next){//非空
	 	return false;
	 }
	 else return true;
 }
// 销毁单链表L
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
//清空链表，将L重置为空表
bool ClearList(LinkList &L)
{
	LNode*p,*q;//或者LinkList p,q;
	p=L->next;
	while(p){//没到表尾反复执行
		q=p->next;
		delete p;
		p=q;
		//类似用两块砖过河
	}
	L->next=NULL;
	return true;
}
//求单链表L的表长
int ListLength_L(LinkList L)
{int i;
LinkList p;
p=L->next;//p指向第一个结点
i=0;
while(p){  //遍历单链表，统计结点数
	i++;
	p=p->next;
}
	return i;
}
bool GetElem_L(LinkList L,int i,int &e)
{
	//获取线性表L中的某个数据元素的内容，通过变量返回
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
//在线性表L中查找值为e的数据元素
//找到，则返回L中值为e的数据元素的地址，查找失败返回NULL
LNode* LocateElem_L(LinkList L,int e)
{
	LinkList p;
	p=L->next;
	while(p&&p->data!=e){
		p=p->next;	
	}
return p;	
}
//在线性表L中查找值为e的数据元素的位置序号
int LocateElem_L2(LinkList L,int e)
{
	//返回L中值为e的数据元素的位置序号，查找失败返回0
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
//插入--在第i个结点前插入值为e新结点
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
//将线性表L中的第i个数据元素删除
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
//头插建立链表
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
 ///尾插法建立单链表
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
 //按顺序打印单链表
 void PrintList(LinkList L,int len)
 {
 	LNode *p;
 	p=L->next;
 	for(int j=1;j<=len;j++){
	 	cout<<" "<<p->data<<" "<<endl;
	 	p=p->next;
	 }
	 	cout<<"链表数据域个数为"<<len<<"\n"<<endl;
 }
int main()
{
		srand(time(NULL));//随机数种子
	LinkList L;
//	开辟虚空结点
	InitList_L(L);
	//尾插法创建链表
CreatList_R(L,10);
//打印出来看看
PrintList(L,ListLength_L(L));
//删除第i个元素
cout<<"删除第三个位置的元素："<<endl;
ListDelete_L(L,3);
//打印出来看看
PrintList(L,ListLength_L(L));
//在第二个位置插入2
cout<<"在第二个位置插入2："<<endl;
LinkInsert_L(L,2,2);
PrintList(L,ListLength_L(L));
cout<<"查找2的位置，并返回地址："<<endl;
//查找2的位置，并返回地址
LNode* Locate=LocateElem_L(L,2);
cout<<Locate<<endl;
//查找2的位置，并返位置序号
cout<<"查找2的位置，并返位置序号："<<endl;
int s=LocateElem_L2(L,2);
cout<<s<<endl;

	return 0;
}
