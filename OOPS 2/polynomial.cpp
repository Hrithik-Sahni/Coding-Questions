#include<iostream>
using namespace std;

//************
//Driver program to test below functions
class Polynomial {
    
    public:
    int capacity;
    int *degCoeff;
    
    Polynomial(){
        degCoeff = new int[10];
        capacity = 10;
        for(int i = 0 ; i < capacity ; i++)
        {
            degCoeff[i] = 0;
        }
    }
    
    
    Polynomial(Polynomial const &p1)
    {
        this -> degCoeff = new int[p1.capacity];
        this -> capacity = p1.capacity;
        for(int i = 0 ; i < p1.capacity ; i++){
            this -> degCoeff[i] = p1.degCoeff[i];
        }
        
    }
    
    
    Polynomial operator=(Polynomial const &p1)
    {
        this -> capacity = p1.capacity;
        this -> degCoeff = new int[p1.capacity];
        for(int i = 0 ; i < capacity ; i++){
            this -> degCoeff[i] = p1.degCoeff[i];
        }
    }
    
    
    void print()
    {
        for(int i = 0; i < capacity ; i++)
        {
            if(degCoeff[i] != 0){
                cout << degCoeff[i] << "x" << i << " ";
            }
        }
        cout << endl;
    }
    
    
    void setCoefficient(int deg , int coeff)
    {
        if (deg < capacity)
        {
            degCoeff[deg] = coeff;
        }
        else
        {
            while(capacity <= deg)
            {
                int *newDeg = new int[2 * capacity];
                for(int i = 0 ; i < capacity ; i ++)
                {
                    newDeg[i] = degCoeff[i];
                }
                delete [] degCoeff;
                degCoeff = newDeg;
                capacity = capacity * 2;
            }
            degCoeff[deg] = coeff;
        }
    }
    
    
Polynomial operator+(Polynomial const &p2)
    {
        Polynomial ans;
        int len;

        if(capacity<p2.capacity)
                len=capacity;
        else
            len=p2.capacity;

        int i;
        for(i=0; i < len; i++)
                ans.setCoefficient(i,this -> degCoeff[i] + p2.degCoeff[i]);

        while(i < capacity){
            ans.setCoefficient(i, this -> degCoeff[i]);
            i++;
        }

        while(i < p2.capacity){
            ans.setCoefficient(i , p2.degCoeff[i]);
            i++;
        }
        return ans;
    }
    
Polynomial operator-(Polynomial const &p2){
        Polynomial ans;
            int len;
            if(capacity < p2.capacity)
                    len=capacity;
            else
                len=p2.capacity;
            int i;
            for(i=0;i<len; i++)
                    ans.setCoefficient(i,this -> degCoeff[i] - p2.degCoeff[i]);
            while(i<capacity){
                ans.setCoefficient(i,this -> degCoeff[i]);
                i++;
            }
            while(i<p2.capacity){
                ans.setCoefficient(i,-p2.degCoeff[i]);
                i++;
            }
                return ans;
    }
    
    
Polynomial operator*(Polynomial const &p) {
        Polynomial newP;
        newP.capacity = p.capacity + capacity;
        newP.degCoeff = new int[newP.capacity];
        
        for(int i=0;i < newP.capacity; i++)
            newP.degCoeff[i]=0;
        
        for (int i=0 ; i < capacity; i++) {
            for (int j=0;j < p.capacity;j++) {
                newP.degCoeff[i+j] += degCoeff[i]*p.degCoeff[j];
            }
        }
        return newP;
    }
    
    // Complete the class
    
};
 
int main()
{
    int count1,count2,choice;
    cin >> count1;
    
    int *degree1 = new int[count1];
    int *coeff1 = new int[count1];
    
    for(int i=0;i < count1; i++) {
        cin >> degree1[i];
    }
    
    for(int i=0;i < count1; i++) {
        cin >> coeff1[i];
    }
    
    Polynomial first;
    for(int i = 0; i < count1; i++){
        first.setCoefficient(degree1[i],coeff1[i]);
    }
    
    cin >> count2;
    
    int *degree2 = new int[count2];
    int *coeff2 = new int[count2];
    
    for(int i=0;i < count2; i++) {
        cin >> degree2[i];
    }
    
    for(int i=0;i < count2; i++) {
        cin >> coeff2[i];
    }
    
    Polynomial second;
    for(int i = 0; i < count2; i++){
        second.setCoefficient(degree2[i],coeff2[i]);
    }
    
    cin >> choice;
    
    Polynomial result;
    switch(choice){
            // Add
        case 1:
            result = first + second;
            result.print();
            break;
            // Subtract
        case 2 :
            result = first - second;
            result.print();
            break;
            // Multiply
        case 3 :
            result = first * second;
            result.print();
            break;
            
        case 4 : // Copy constructor
        {
            Polynomial third(first);
            if(third.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
        case 5 : // Copy assignment operator
        {
            Polynomial fourth(first);
            if(fourth.degCoeff == first.degCoeff) {
                cout << "false" << endl;
            }
            else {
                cout << "true" << endl;
            }
            break;
        }
            
    }
    
    return 0;
}
//***************




