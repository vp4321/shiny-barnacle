#include <bits/stdc++.h>
using namespace std;

class Shape
{
    public:
        virtual void area()=0;
};

class Circle : public Shape
{
    public:
        void area(){
            cout<<"Enter radius"<<endl;
            int r;
            cin>>r;
            cout<<"Area of the circle is: "<<(3.14*r*r)<<endl;
        }
};

class Square : public Shape
{
    public:
        void area(){
            cout<<"Enter edge length"<<endl;
            int a;
            cin>>a;
            cout<<"Area of sqare is: "<<(a*a)<<endl;
        }
};

int main()
{
    Square s1;
    s1.area();
    Circle c1;
    c1.area();
    return 0;
}