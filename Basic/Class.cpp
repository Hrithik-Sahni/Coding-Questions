#include<iostream>
#include<string>
using namespace std;

class Laptop
{
	string name;
	int price;
	string company;

	public:

		void read()
		{
			cin>>name;
			cin>>price;
			cin>>company;
		}

		void show()
		{
			cout<<"\nName is "<<name<<endl;
			cout<<"Price is "<<price<<endl;
			cout<<"Company is "<<company<<endl;
		}

};
int main()
{
	Laptop l;
	l.read();
	l.show();
	return 0;
}