//Singly Linked List :D

#include<iostream.h>
#include<conio.h>

class list
{
 int a;
 list *next;

 public:
   void insert();
   void display();
   void insertbefore();
   void insertafter();
   void deletenode();
   void reverselist();
   void sort();
   void deletealternate();
   void insertinsorted();
};

//////////////////////global pointer first////////
list *first=NULL;
//////////////////////////////////////////////////
//////////////////////create function/////////////
void list::insert()
{
 list *temp;
 temp=new list;

 if(temp!=NULL)
 {
  temp->next=NULL;

  cout<<"\n\nEnter value - ";
  cin>>temp->a;

  if(first==NULL)
	first=temp;
  else
  {
   for(list *curr=first;curr->next!=NULL;curr=curr->next);
	curr->next=temp;
  }
 }
}
///////////////////////////////////////////////////
//////////////////////display function/////////////
void list::display()
{clrscr();
 cout<<"LIST:\n";
 if(first==NULL) cout<<"\nList empty!";

 else
 for(list *curr=first;curr!=NULL;curr=curr->next)
 {
  cout<<curr->a<<endl;
 }
 getch();
}
///////////////////////////////////////////////////
//////////////////////insert before////////////////
void list::insertbefore()
{
 int key,ele;
 list *temp;
 clrscr();
 cout<<"Enter key element - ";
 cin>>key;

 cout<<"Enter element to be inserted - ";
 cin>>ele;

 for(list *curr=first,*prev=NULL;curr!=NULL;prev=curr,curr=curr->next)
  if(curr->a==key)
  {
   temp=new list;
   temp->a=ele;

   if(curr==first)
     first=temp;
   else
     prev->next=temp;

   temp->next=curr;
  }
}
///////////////////////////////////////////////////
//////////////////////insert after/////////////////
void list::insertafter()
{
 int key,ele;
 list *temp;
 clrscr();
 cout<<"Enter key element - ";
 cin>>key;

 cout<<"Enter element to be inserted - ";
 cin>>ele;

 for(list *curr=first;curr!=NULL;curr=curr->next)
  if(curr->a==key)
  {
   temp=new list;
   temp->a=ele;

   temp->next=curr->next;
   curr->next=temp;
   curr=temp;

  }
}
///////////////////////////////////////////////////
//////////////////////delete a node////////////////
void list::deletenode()
{
 clrscr();
 if(first==NULL)
 {
  cout<<"List empty!";
  getch();
 }

 else
 {
  int ele;
  cout<<"Enter element to be deleted - ";
  cin>>ele;
  list *temp;

  for(list *curr=first,*prev=NULL;curr!=NULL;prev=curr,curr=curr->next)
  if(curr->a==ele)
  {
   if(curr==first)
    {
     temp=first;
     first=first->next;
     delete temp;
    }
   else
    {
     temp=curr;
     prev->next=curr->next;
     delete curr;
     curr=prev->next;
    }
  }
 }
}

///////////////////////////////////////////////////
//////////////////////reverse the list/////////////
void list::reverselist()
{
 clrscr();
 if(first==NULL)
 {
  cout<<"List empty!";
  getch();
 }

 else
 {
  list *temp1=NULL;
  list *temp2;
  while(first!=NULL)
   {
    temp2=first;
    first=first->next;
    temp2->next=temp1;
    temp1=temp2;
   }
    first=temp1;
 }
}
///////////////////////////////////////////////////
//////////////////////Sort the list////////////////
void list::sort()
{
clrscr();

list *temp, *i, *j;
 if(first==NULL)
 {
  cout<<"List empty!";
  getch();
 }

else
		//Selection Sort
for(i=first;i!=NULL;i=i->next)
 for(j=i->next;j!=NULL;j=j->next)
  {
   if((i->a)>(j->a))
    {
     temp->a=i->a;
     i->a=j->a;
     j->a=temp->a ;
    }
  }
}
///////////////////////////////////////////////////
//////////////////////Delete alternate nodes///////
void list::deletealternate()
{
 clrscr();
 if(first==NULL)
 {
  cout<<"List empty!";
  getch();
 }

 else
 {
  list *temp;
  list *curr=first;

  while(curr!=NULL)
  {
   if(curr==first)
    {
     first=first->next;
     delete curr;
     curr=first;
    }
   temp=curr->next;
   curr->next=temp->next;
   delete temp;
   curr=curr->next;
  }
  cout<<"DONE!";
  getch();
 }
}

///////////////////////////////////////////////////
//////////////////////Insert in sorted list////////
void list::insertinsorted()
{
 int key,ele;
 list *temp;
 clrscr();
 cout<<"Enter element to be inserted - ";
 cin>>ele;

 for(list *curr=first;curr!=NULL;curr=curr->next)
 {
  if(ele<(curr->next->a))
  {temp=new list;
   temp->a=ele;

   if(curr==first)
   {
    temp->next=first;
    first=temp;
    break;
   }
   else
   {
    temp->next=curr->next;
    curr->next=temp;
    break;
   }
  }
  else
   {temp=new list;
    temp->a=ele;
    temp->next=curr->next;
    curr->next=temp;
    break;
   }
 }
}
///////////////////////////////////////////////////
//////////////////////MAIN/////////////////////////
void main()
{
 char ch;
 list a;
 do{
	clrscr();
	cout<<"\t\t\t***LINKED LIST MENU***\n";
	cout<<"1)View List\n";
	cout<<"2)Insert Node\n";
	cout<<"3)Insert a node before another node\n";
	cout<<"4)Insert a node after another node\n";
	cout<<"5)Delete a node\n";
	cout<<"6)Reverse the list\n";
	cout<<"7)Sort\n";
	cout<<"8)Delete alternate nodes\n";
	cout<<"9)Insert in sorted list\n";
	cout<<"ESC)Exit";
	cout<<"\n\nEnter choice - ";
	ch=getche();
	switch(ch){
		   case '1':a.display();break;
		   case '2':a.insert();break;
		   case '3':a.insertbefore();break;
		   case '4':a.insertafter();break;
		   case '5':a.deletenode();break;
		   case '6':a.reverselist();break;
		   case '7':a.sort();break;
		   case '8':a.deletealternate();break;
		   case '9':a.insertinsorted();
		  }
 }while(ch!=27);
}