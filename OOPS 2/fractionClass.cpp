#include<iostream>
using namespace std;

class Fraction{
private:
    int nume;
    int deno;


public:
    //PARAMETERIZED CONSTRUCTOR
    Fraction(int nume , int deno){
        this -> nume = nume;
        this -> deno = deno;
    }


    void print(){
        cout << nume << "/" << deno << endl;
    }

    void simplify(){
        int gcd = 1;
        int j = min(this -> nume , this -> deno);

        for(int i = 1 ; i <= j ; i ++)
        {
            if(nume % i == 0 && deno % i == 0)
                gcd = i;
        }

        nume = nume / gcd;
        deno = deno / gcd;
    }

    Fraction add(Fraction const &f2){
      int lcm = deno * f2.deno;
      int x = lcm / deno;
      int y = lcm / f2.deno;

      int num = x*nume + y*f2.nume;
      Fraction fnew(num , lcm);
      fnew.simplify();
      return fnew;
    }

    Fraction operator+(Fraction const &f2){
      int lcm = deno * f2.deno;
      int x = lcm / deno;
      int y = lcm / f2.deno;

      int num = x*nume + y*f2.nume;
      Fraction fnew(num , lcm);
      fnew.simplify();
      return fnew;
    }

    Fraction operator*(Fraction const &f2)const{
        int x = nume * f2.nume;
        int y = deno * f2.deno;
        Fraction fnew(x , y);
        fnew.simplify();
        return fnew;
    }

    bool operator==(Fraction const &f2) const
    {
        if(nume == f2.nume && deno == f2.deno)
            return true;
        return false;
    }
    //Pre Increament
    Fraction& operator++()
    {
        nume = nume + deno;
        simplify();
        //if we want to receive it in another variable
        return *(this);  // it has the address of the object which was called
    }

    // Post Increment
    Fraction operator++(int){
        Fraction fnew(nume , deno);
        nume = nume + deno;
        simplify();
        fnew.simplify();
        return fnew;
    }

    Fraction& operator +=(Fraction const&f){
      int lcm = deno * f.deno;
      int x = lcm / deno;
      int y = lcm / f.deno;

      int num = x*nume + y*f.nume;

      nume = num;
      deno = lcm;
      simplify();
      return *this;
    }

};

int main()
{
    Fraction f1(10 , 3);
    Fraction f2(5 , 2);
//    Fraction f3 = f1 + f2;
//    Fraction f4 = f1 * f2;
    f1.print();
    f2.print();
//    f3.print();
//    f4.print();
//    ++(++(++f1));
//    f1.print();
//    Fraction f5 = f2++;
//    f2.print();
//    f5.print();
    f1 += f2;
    f1.print();
//    if(f1 == f2)
//        cout << "Equal";
//    else
//        cout << "Not Equal";
    return 0 ;
}
