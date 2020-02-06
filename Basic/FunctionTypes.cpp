#include<iostream>
using namespace std;

// void change(int m) //CALL BY VALUE 
// {
// 	m=m*m;
// 	cout<<"Value in the function: "<<m<<endl;
//}

void change(int &m)  //CALL BY REFERENCE
{
	m=m*m;
	cout<<"Value in function: "<<m<<endl;
}
int main()
{
	int n;
	cin>>n;
	change(n);
	cout<<"Value after function is called: "<<n<<endl;
	return 0;
}