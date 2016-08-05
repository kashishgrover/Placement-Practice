#include<iostream.h>
#include<conio.h>
#include<stdio.h>
////////////////////////////////////////////////////////////////////////
class stack
{
 int a[20],top;

 public:
	stack()
	{
	 top=-1;
	}
	void push(int);
	int pop();
};
////////////////////////////////////
////////////////////////////////////
void stack::push(int el)
{
 top++;
 a[top]=el;

}
////////////////////////////////////
int stack::pop()
{
  return a[top--];
}
////////////////////////////////////////////////////////////////////////
enum precedence{OPERATOR,OPERAND};
////////////////////////////////////
precedence check(char ch)
{
 switch(ch)
 {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':return OPERATOR;

    default :return OPERAND;
 }
}
////////////////////////////////////
int postfix_eval(char postfix[])
{
 stack s;
 int i=0;
 int op1,op2;
 precedence temp;
 while(postfix[i]!='\0')
 {
  temp=check(postfix[i]);
  if(temp==OPERAND)
   s.push(postfix[i]-48);
  else
  {
   op2=s.pop();
   op1=s.pop();

   switch(postfix[i])
   {
    case '+':s.push(op1+op2);break;
    case '-':s.push(op1-op2);break;
    case '*':s.push(op1*op2);break;
    case '/':s.push(op1/op2);break;
    case '%':s.push(op1%op2);
   }
  }
  i++;
 }
 return s.pop();
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void main()
{
  clrscr();
 char postfix[40];

 cout<<"Enter a postfix expression: ";
 gets(postfix);

 cout<<"Result is - "<<postfix_eval(postfix);

 getch();
}


