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

void prefix_to_infix(char prefix[])
 {

  int i=strlen(prefix)-1;
  stack obj;
  char t[3],op1[20],op2[20];
  char infix[20];

  while(prefix[i]>=0)
  {
   t[0]=prefix[i];
   t[1]='\0';

   if(prefix[i]>=48 && prefix[i]<=57)
	obj.push(t);

   else
   {
    strcpy(op1,obj.pop());
    strcpy(op2,obj.pop());

    strcpy(infix, "(");
    strcat(infix, op1);
    strcat(infix, t);
    strcat(infix, op2);
    strcat(infix, ")");
    obj.push(infix);
   }
   i--;
  }
 cout<<obj.pop();
}


void main()
{
 clrscr();
 char prefix[20];
 cout<<"Enter a prefix expression - ";
 gets(prefix);
 cout<<"\nINFIX FORM : ";
 prefix_to_infix(prefix);
 getch();
}