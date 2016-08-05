// circular queue

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

class CQ
{
  int front, rear, size, a[20];

public:
  CQ(int s = 5)
  {
    size = s;
    front = rear = 0;
  }

  bool Isempty()
  {
    if (front == rear) return true;
    return false;
  }

  bool Isfull()
  {
    if (front == (rear + 1) % size) return true;
    return false;
  }

  void display();
  void ins(int);
  int del();
};

void CQ::display()
{
  int i;
  for (i = (front + 1) % size; i != rear; i = (i + 1) % size)
    cout << a[i] << endl;
  cout << a[i];
}

void CQ::ins(int ele)
{
  if (Isfull()) cout << "FULL!";
  else
  {
    rear = (rear + 1) % size;
    a[rear] = ele;
  }
}

int CQ::del()
{
  if (Isempty())
  {
    cout << "EMPTY!";
    return -1;
  }
  else
  {
    front = (front + 1) % size;
    return a[front];
  }

}


int main()
{
  int size, el;

  cout << "Enter size of the queue - ";
  cin >> size;

  CQ c(size);

  cout << "Insert " << size - 1 << " elements!\n";
  for (int i = 0; i < size; i++)
  {
    cin >> el;
    c.ins(el);
  }

  cout << "\n\nElements entered:\n";

  do
  { cout << endl;
    c.display();
    cout << "\nHit any key to delete!\n";
    if (!kbhit())
    {
      cin.get();
      int del = c.del();
      cout << del << " was deleted!\n";
    }
  } while (!c.Isempty());

  return 0;
}

