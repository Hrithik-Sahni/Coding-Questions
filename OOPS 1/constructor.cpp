#include<iostream>
using namespace std;

class Student{

    int roll;
    int age;

    public:
        Student()
        {
            cout << "Constructor 1" << endl;
        }

        Student(int roll , int age)
        {
            this -> roll = roll;
            this -> age = age;
            cout << "Constructor 3" << endl;
        }

        Student(int roll)
        {
            this -> roll = roll;
            cout << "Constructor 2" << endl;
        }

        void display(){

            cout << "Age is " << age << " Roll Number is " << roll << endl; 
        }

};

int main()
{
    Student s1;
    Student s2 (101);
    Student s3(102 , 4);

    Student s4(s3);

    s1 = s2;  //Copy Assignment Operator
    return 0;
}


