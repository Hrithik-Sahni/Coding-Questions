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

    void add(Fraction const &f2){
      int lcm = deno * f2.deno;
      int x = lcm / deno;
      int y = lcm / f2.deno;

      int num = x*nume + y*f2.nume;
      nume = num;
      deno = lcm;
      simplify();
    }

    void multiply(Fraction const &f2){
        nume = nume * f2.nume;
        deno = deno * f2.deno;
        simplify();
    }

};

int main()
{
    Fraction f1(10 , 2);
    Fraction f2(10 , 2);
    f1.add(f2);
    f1.print();
    f1.multiply(f2);
    f1.print();
    f2.print();
    return 0 ;
}
