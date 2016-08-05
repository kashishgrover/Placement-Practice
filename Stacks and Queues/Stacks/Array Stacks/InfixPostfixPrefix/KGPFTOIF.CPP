#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class stack
{
 char s[20][20];
 int top;

public:
	stack()
	{top=-1;
	}

	void push(char a[])
	{strcpy(s[++top],a);
	}

	char *pop()
	{return s[top--];
	}
};

void postfix_to_infix(char postfix[])
 {
  int i=0;
  stack obj;
  char t[3],op1[20],op2[20];
  char infix[20];

  while(postfix[i]!='\0')
  {
   t[0]=postfix[i];
   t[1]='\0';

   if(postfix[i]>=48 && postfix[i]<=57)
	obj.push(t);

   else
   {
    strcpy(op2,obj.pop());
    strcpy(op1,obj.pop());

    strcpy(infix, "(");
    strcat(infix, op1);
    strcat(infix, t);
    strcat(infix, op2);
    strcat(infix, ")");
    obj.push(infix);
   }
   i++;
  }
 cout<<obj.pop();
}


void main()
{
 clrscr();
 char postfix[20];
 cout<<"Enter a postfix expression - ";
 gets(postfix);
 cout<<"\nINFIX FORM : ";
 postfix_to_infix(postfix);
 getch();
}