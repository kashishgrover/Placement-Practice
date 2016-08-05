//Binary Tree

#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class node
{
 char data;
 node *lchild,*rchild;

 friend class tree;
};


class tree
{
 node *root;

 public:

	tree()
	{
	 root=NULL;
	}

	void createNode();           //1
	void inorder();              //2
	void postorder();            //3
	void preorder();             //4
	void getParent();            //5
	void getDepth();             //6
	void getAncestors();         //7
	void getLeafNodeCount();     //8
};

void tree::createNode()
{
 clrscr();
 node *temp=new node;
 node *prev,*curr=root;

 cout<<"Enter data - ";			//
 cin>>temp->data;                       // leaf node
 temp->lchild=temp->rchild=NULL;        //

 if(root==NULL)
	root=temp;
 else
 {
  char dir[20];

  cout<<"Enter direction path (LRL...) - "; // get direction
  gets(dir);                                //

  for(int i=0;dir[i]!='\0'&&curr!=NULL;i++)
  {
   prev=curr;
   if(dir[i]=='L'||dir[i]=='l') curr=curr->lchild;
   else	curr=curr->rchild;
  }

   if((curr==NULL)&&dir[i]=='\0')
   {
    if(dir[i-1]=='L'||dir[i-1]=='l') prev->lchild=temp;
    else	prev->rchild=temp;
   }

   else
   {
    cout<<"Not possible!";
    getch();
   }
 }
}

void tree::inorder()
{
 clrscr();
 node *s[20], *curr=root;
 int top=-1;

 if(root==NULL) cout<<"TREE EMPTY!";

 else
 {
   while(1)
   {
    for(;curr!=NULL;curr=curr->lchild)
    {
     s[++top]=curr;
    }

    if(top>=0)
    {
     curr=s[top--];
     cout<<curr->data;
     curr=curr->rchild;
    }
    else break;
   }
 }
 getch();
}

void tree::preorder()
{
 clrscr();
 node *s[20], *curr=root;
 int top=-1;

 if(root==NULL) cout<<"TREE EMPTY!";

 else
 {
   while(1)
   {
    for(;curr!=NULL;curr=curr->lchild)
    {
     cout<<curr->data;
     s[++top]=curr;
    }

    if(top>=0)
    {
     curr=s[top--];
     curr=curr->rchild;
    }
    else break;
   }
 }
 getch();
}

void tree::postorder()
{
 clrscr();                               //wrong (same as inorder)
 node *s[20], *curr=root;
 int top=-1;

 if(root==NULL) cout<<"TREE EMPTY!";

 else
 {
   while(1)
   {
    for(;curr!=NULL;curr=curr->lchild)
    {
     s[++top]=curr;
    }

    if(top>=0)
    {
     curr=s[top--];
     cout<<curr->data;
     curr=curr->rchild;

    }
    else break;
   }
 }
 getch();
}

void tree::getParent()
{
}
void tree::getDepth()
{
}
void tree::getAncestors()
{
 clrscr();
 if(root==NULL)                      //wrong
  cout<<"TREE EMPTY!";

 else
 {
  int ele;
  cout<<"Enter key element - ";
  cin>>ele;

  node *s[20], *curr=root;
  int top=-1;
  int flag=0;

  while(1)
   {
    for(;curr!=NULL;curr=curr->lchild)
    {
     s[++top]=curr;
    }

    if(top>=0)
    {
     curr=s[top--];
     if(curr->data==ele)
     {
      flag=1;
      break;
     }
     curr=curr->rchild;
    }
    else break;
   }//while ends

  if(flag==1)
  {
   for(;top>=0;top--)
    cout<<s[top]->data<<endl;
  }
  else cout<<"Element does not exist!";

 }
 getch();


}
void tree::getLeafNodeCount()
{
}

void main()
{
 char ch;
 tree t;
 do{
	clrscr();
	cout<<"\t\t\t***Binary Tree Menu***\n";
	cout<<"1. Add node\n2. Inorder Traversal\n3. Postorder Traversal"
	    <<"\n4. Preorder Traversal\n5. Parent of a node\n6. Depth"
	    <<"\n7. Ancestors of a node\n8. Number of leaf nodes";
	cout<<"\nEnter choice - ";
	ch=getche();
	switch(ch)
	{
	 case '1': t.createNode();       break;
	 case '2': t.inorder();	        break;
	 case '3': t.postorder();      break;
	 case '4': t.preorder();      break;
	 case '5': t.getParent();      break;
	 case '6': t.getDepth();        break;
	 case '7': t.getAncestors();     break;
	 case '8': t.getLeafNodeCount();
	}
  }while(ch!=27);
}