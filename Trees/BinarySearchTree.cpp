//BINARY SEARCH TREE
#include<iostream.h>
#include<conio.h>
#include<stdio.h>

class node
{
  int data;
  node *lchild, *rchild;
  node(int d)
  {
    data = d;
    rchild = lchild = NULL;
  }
  friend class bst;
};

class bst
{
  node *root;

public:
  bst()
  {
    root = NULL;
  }

  void insert();               //1
  void del();        //2
  void search();         //3
  void traverse();
};

void bst::insert()
{
  int ele;
  cout << "\n\nEnter element - ";
  cin >> ele;

  node *temp, *prev, *curr = root;

  temp = new node(ele);

  if (root == NULL)
    root = temp;

  else
  {
    while (curr)  //curr!=NULL
    {
      prev = curr;
      if (ele > curr->data)
        curr = curr->rchild;
      else curr = curr->lchild;
    }

    if (ele > prev->data)
      prev->rchild = temp;
    else prev->lchild = temp;
  }
}


void bst::traverse()
{
  node *s[20], *curr = root;
  int top = -1;
  if (root == NULL) cout << "TREE EMPTY!";

  else
  {
    while (1)
    {
      for (; curr != NULL; curr = curr->lchild)
      {
        s[++top] = curr;
      }

      if (top >= 0)
      {
        curr = s[top--];
        cout << curr->data << ' ';
        curr = curr->rchild;
      }
      else break;
    }
  }
}

void bst::search()
{
  node *curr = root;
  if (root == NULL)
  {
    cout << "\n\nTREE EMPTY!";
    return;
  }
  else
  {
    int flag = 0;
    int el;
    cout << "\n\nEnter element to search - ";
    cin >> el;
    while (curr)
    {
      if (el == curr->data)
      {
        flag = 1;
        break;
      }
      else if (el < curr->data)
        curr = curr->lchild;
      else curr = curr->rchild;
    }
    if (flag == 1) cout << "Element exists!";
    else cout << "Element does not exist!";
  }
  getch();
}

void bst::del()
{
  node *parent, *curr = root;
  if (root == NULL)
  {
    cout << "\n\nTREE EMPTY!";
    return;
  }
  else
  {
    int flag = 0;
    int el;
    cout << "\n\nEnter element - ";
    cin >> el;
    while (curr)
    { //parent=curr;
      if (el == curr->data)
      {
        flag = 1;
        break;
      }                                  //by this point, we have the
      else if (el < curr->data)          //value of curr and its parent
        curr = curr->lchild;          //and flag is 1
      else curr = curr->rchild;
    }

    if (flag == 1)
    {
      node *g, *scurr = curr;             //We need to find the greatest
      while (scurr)           //element in the LST of curr
      { //and then raplace curr with it.
        g = curr;
        scurr = scurr->rchild;
      }

      curr->data = g;
    }
    else cout << "Element does not exist!";
  }
  getch();
}


void main()
{
  char ch;
  bst t;
  do {
    clrscr();
    cout << "\t\t\t***Binary Search Tree Menu***\n";
    cout << "1. Insert Node\n2. Delete Node\n3. Search";
    cout << "\nTree - ";
    t.traverse();
    cout << "\nEnter choice - ";
    ch = getche();
    switch (ch)
    {
    case '1': t.insert();     break;
    case '2': t.del();    break;
    case '3': t.search();     break;
    }
  } while (ch != 27);
}