#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<string.h>
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
int prefix_eval(char prefix[])
{
 stack s;
 int i=strlen(prefix)-1;
 int op1,op2;
 precedence temp;

 while(i>=0)
 {
  temp=check(prefix[i]);

  if(temp==OPERAND)
   s.push(prefix[i]-48);

  else
  {
   op2=s.pop();
   op1=s.pop();

   switch(prefix[i])
   {
    case '+':s.push(op1+op2);break;
    case '-':s.push(op1-op2);break;
    case '*':s.push(op1*op2);break;
    case '/':s.push(op1/op2);break;
    case '%':s.push(op1%op2);
   }
  }
  i--;
 }
 return s.pop();
}
////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////
void main()
{
  clrscr();
 char prefix[40];

 cout<<"Enter a prefix expression: ";
 gets(prefix);

 cout<<"Result is - "<<prefix_eval(prefix);

 getch();
}


