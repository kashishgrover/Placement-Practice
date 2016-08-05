#include<iostream.h>
#include<conio.h>
#include<stdio.h>

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

	char pop()
	{return a[top--];
	}

friend void infix_postfix(char *infix)
};

enum precedence
{
 lpar, rpar, multiply, divide,
 modulus, add, subtract, eos,
 operand
};

int icp[]={20,19,13,13,13,12,12,0};
int isp[]={0,19,13,13,13,12,12,0};

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

void infix_postfix(char infix[])
{
 char postfix[20];
 char c;
 Stack s;
 s.push('#');
 precedence temp;
 int i=0,j=0;

 while(infix[i]!='\0')
 {
   temp=check(infix[i]);

   if(temp==operand)
	postfix[j++]=infix[i];

   else if(temp==rpar)
   {
    c=s.pop();

    while(c!='(')
    {
     postfix[j++]=c;
     c=s.pop();
    }
   }

   else{
	while(icp[temp]<=isp[check(s.a[s.top])])
	 {
	 postfix[j++]=s.pop();
	 }
	 s.push(infix[i]);
       }

  i++;
 }

 while(s.a[s.top]!='#')
	postfix[j++]=s.pop();

 postfix[j]='\0';

 cout<<"Postfix : "<<postfix;
}


void main()
{
 char infix[20];
 clrscr();
 cout<<"Enter an infix expression - ";
 gets(infix);
 infix_postfix(infix);
 getch();
}