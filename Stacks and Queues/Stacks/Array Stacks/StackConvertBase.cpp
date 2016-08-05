#include <iostream>

using namespace std;

class stack
{
  char s[100];
public:
  int top;
  stack()
  {
    top = -1;
  }
  void push(char);
  int read();
  void pop();
  void display();
};
void stack::push(char N)
{ if (top == 99)
    cout << "\n Stack Overflow!!";
  else s[++top] = N;
}
void stack::pop()
{
  if (top == -1)
    cout << "\nStack Underflow!!";
  else
  {
    top--;
  }
}

int stack::read()
{
  return s[top];
}

void stack::display()
{
  for (int i = top; i >= 0; i--)
    cout << s[i] << " ";
  cout << endl;
}

int main()
{
  stack s;
  int n, b;
  cout << "Enter the number - ";
  cin >> n;
  cout << "Enter the base - ";
  cin >> b;
  cout << n << " with a base " << b << " is ";
  for (; n > 0; n /= b)
  {
    if (n % b < 10)
    {
      s.push(n % b + '0');
    }

    else
    {
      switch (n % b)
      {
        case 10: s.push('A'); break;
        case 11: s.push('B'); break;
        case 12: s.push('C'); break;
        case 13: s.push('D'); break;
        case 14: s.push('E'); break;
        case 15: s.push('F'); break;
        default: cout << "Base exceeds the limit";
          return -1;
      }
    }
  }
  s.display();
  return 0;
}
