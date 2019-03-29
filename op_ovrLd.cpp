#include<iostream>
#include<bits/stdc++.h>

using namespace std;

class A{
	private:
		int a;
	public:
		A(){
			a=0;
		}	
		A(int a){
			A::a=a;
		}
	A operator+(A &);
	ostream & operator<<(ostream &out,A)
};

A A::operator+(& obj){
	A c;
	c.a=a+obj.a;
	return c;
}

int main(){
	A a(10),b(20),c;
	c=a+b
	return 0;
}

