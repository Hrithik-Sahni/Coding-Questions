#include<iostream>
using namespace std;

template <typename T> 
class Pair{

	T x;
	T y;

public:
	void setX (T x){
		this -> x = x;
	}

	void setY(T y){
		this -> y = y;
	}

	T getX(){
		return x;
	}

	T getY(){
		return y;
	}
};

int main()
{
	Pair <int> p1;
	Pair <double> p2;
	p1.setY(20);
	p1.setX(10);
	cout << p1.getX() << endl;
	cout << p1.getY() << endl;

	p2.setX(10.986);
	p2.setY(20.986);
	cout << p2.getX() << endl;
	cout << p2.getY() << endl;



	return 0;
}