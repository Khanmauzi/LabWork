#include<iostream>
using namespace std;
typedef struct node
{
	int data;
	struct node *next;
}*lptr;
void del(lptr &l,int n,int i);
void display(lptr &l);
int main()
{
	int i=0,d;
	lptr l,t;
	cout<<"enter the first soldier number (enter -1 to terminate ): ";
	cin>>d;
	if(d!=-1)
	{
		l=new(struct node);
		l->data=d;
		l->next=NULL;
		i++;
	}
	cout<<"enter soldier number (-1 to terminate) "<<endl;
	cin>>d;
	while(d!=-1)
	{
		t=l;
		while(t->next!=NULL)
		t=t->next;
		t->next=new(struct node);
		t=t->next;
		t->data=d;
		t->next=NULL;
		i++;
		cout<<"enter soldier number (-1 to terminate ):"<<endl;
		cin>>d;
	}
	cout<<"soldiers number are : "<<endl;
	display(l);
	int n;
	while(i!=0)
	{
		cout<<"enter any number : ";
		cin>>n;
		del(l,n,i);
		i--;
	}
	cout<<"winning soldier is : "<<l->data;
	return 0;
	
}
void display(lptr &l)
{
	lptr t;
	t=l;
	while(t->next!=NULL)
	{
		cout<<t->data<<" ";
		t=t->next;
	}
}
void del(lptr &l,int n,int i)
{
	lptr t;
	t=l;
	int j=0;
	do
	{
		t=t->next;
		j++;
		if(j==i)
		l=t;
	}while(j<n);
	l=t;
	delete(t->next);
}

