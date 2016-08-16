#include<iostream>

using namespace std;

class Enemy {	// Abstract Class
	public:
		virtual void attack() {
		}
		virtual void set(int){
		}
};

class Ninja: public Enemy {
	public:
		int a;
		void attack() {
			cout<<"Ninja Attack!"<<endl;
		}
		void set(int a)
		{
			this->a = a;
		}
};

class Monster: public Enemy {
	public:
		int b;
		void attack() {
			cout<<"Monster Attack!"<<endl; 
		}
		void set(int b)
		{
			this->b=b;
		}
};

int main() {
	Ninja n;
	Monster m;
	Enemy *enemy1 = &n;
	Enemy *enemy2 = &m;
	enemy1->attack();
	enemy2->attack();
	n.set(1);
	cout<<n.a;
	m.set(2);
	cout<<m.b;
}
