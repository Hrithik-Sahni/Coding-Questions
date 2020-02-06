#include<iostream>
using namespace std;

class Student{
public:
    int roll;
    int age;
};
class Shape{
    public : 
    int height;
    int width;
};

int main(){

    Student s1;

    Student *s6 = new Student;

    s1.age = 24;
    s1.roll = 101;

    Shape *s = new Shape;
    s -> height = 1;
    cout << s -> height;

    return 0;
}