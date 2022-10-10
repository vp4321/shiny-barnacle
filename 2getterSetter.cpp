#include<bits/stdc++.h>
using namespace std;
class Student
{
    //access modifier
    private:
    int roll_no;
    string name;

    public:
    void setDetails(string n,int r) //setter
    {
        roll_no = r;
        name = n;
    }

    void getDetails()
    {
        cout<<"The name of student is:"<<name<<endl;
        cout<<"The roll number of student is:"<<roll_no<<endl;
    }

    int phone_no;


};
int main()
{
    Student first;
    first.setDetails("Ramesh Nambiar",12);
    first.phone_no = 12345678;//Since this is a public variable it can be acessed from outside the class
    first.getDetails();
    cout<<"The phone number of student is:"<<first.phone_no<<endl;

}