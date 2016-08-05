#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>

class Stack
{
int a[20];
int top;

public:
	Stack()
	{top=-1;
	}

	void push(int x)
	{a[++top]=x;
	}

	int pop()
	{return a[top--];
	}

friend void infix_prefix(char *infix)
};

enum precedence
{
 lpar, rpar, multiply, divide,
 modulus, add, subtract, eos,
 operand
};

int icp[]={19,20,13,13,13,12,12,0};
int isp[]={19,0,13,13,13,12,12,0};

precedence check(char ch)
{
 switch(ch)
 {
  case '(':return lpar;
  case ')':return rpar;
  case '*':return multiply;
  case '/':return divide;
  case '%':return modulus;
  case '+':return add;
  case '-':return subtract;
  case '#':return eos;
  default: return operand;
 }
}

void infix_prefix(char infix[])
{
 char prefix[20];
 char c;
 Stack s;
 s.push('#');
 precedence temp;
 int i=strlen(infix)-1,j=0;

 while(i>=0)
 {
   temp=check(infix[i]);

   if(temp==operand)
	prefix[j++]=infix[i];

   else if(temp==lpar)
   {
    c=s.pop();

    while(c!=')')
    {
     prefix[j++]=c;
     c=s.pop();
    }
   }

   else{
	while(icp[temp]<isp[check(s.a[s.top])])
	 {
	 prefix[j++]=s.pop();
	 }
	 s.push(infix[i]);
       }


  i--;
 }

  while(s.a[s.top]!='#')
	prefix[j++]=s.pop();

 prefix[j]='\0';
 strrev(prefix);
 cout<<"Prefix : "<<prefix;
}


void main()
{
 char infix[20];
 clrscr();
 cout<<"Enter an infix expression - ";
 gets(infix);
 infix_prefix(infix);
 getch();
}