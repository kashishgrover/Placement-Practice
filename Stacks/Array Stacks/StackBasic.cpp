#include <iostream>
#include <sys/select.h>

using namespace std;

int kbhit(void)
{
  struct timeval tv;
  fd_set read_fd;

  /* Do not wait at all, not even a microsecond */
  tv.tv_sec = 0;
  tv.tv_usec = 0;

  /* Must be done first to initialize read_fd */
  FD_ZERO(&read_fd);

  /* Makes select() ask if input is ready:
  * 0 is the file descriptor for stdin */
  FD_SET(0, &read_fd);

  /* The first parameter is the number of the
  * largest file descriptor to check + 1. */
  if (select(1, &read_fd, NULL, /*No writes*/NULL, /*No exceptions*/&tv) == -1)
    return 0; /* An error occured */

  /* read_fd now holds a bit map of files that are
  * readable. We test the entry for the standard
  * input (file 0). */

  if (FD_ISSET(0, &read_fd))
    /* Character pending on stdin */
    return 1;

  /* no characters were pending */
  return 0;
}

class stack
{
  int s[5], top, el;

public:

  int size;

  stack()
  {
    top = -1;
  }

  void push(int);
  void pop();
  void display();

};

void stack::push(int size)
{
  for (int i = 0; i < size; i++)
  {
    if (top == size - 1)
      cout << "Stack Overflow!";
    else
    {
      cout << "Enter Element - ";
      cin >> el;
      s[++top] = el;
    }
  }
}

void stack::pop()
{
  if (top == -1)
    cout << "\nStack Underflow!";
  else
  {
    cout << "\nPopping Last Element!";
    top--;
  }
}

void stack::display()
{
  cout << endl;
  for (int i = 0; i <= top; i++)
    cout << s[i] << ' ';
}

int main()
{
  stack S1;
  int size;
  cout << "Enter size of the stack - ";
  cin >> size;

  S1.push(size);
  S1.display();

  while (size != 0)
  {
    cout << "Hit any key to pop!";
    if (!kbhit())
    {
      cin.get();
      S1.pop();
      S1.display();
    }
    size--;
  }
  return 0;
}