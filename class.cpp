#include <iostream>
using namespace std;


class employee{
private:
    string Name;
    string Company;
    int Age;

public:
    void setname(string name)
    {
        Name=name;
    }
    string getname()
    {
        return Name;
    }
    void setcompany(string company)
    {
        Company=company;
    }
    string getcompany()
    {
        return Company;
    }
    void setage(int age)
    {
        if(age>=18)
        
        Age=age;
    }
    int getage()
    {
        return Age;
    }
    void introduceyourself(){
        cout<<"name - "<<Name<<endl;
        cout<<"company - "<<Company<<endl;
        cout<<"age - "<<Age<<endl;

    }
    employee(string name,string company,int age)
    {
        Name=name;
        Company=company;
        Age=age;
    }
};

int main(){
    employee employee1=employee("ozi","aktasmuh",20);
    employee1.introduceyourself(); 

    employee employee2=employee("john","amazon",35);
    employee2.introduceyourself();

    employee1.setage(21);
    cout<<employee1.getname()<<" is "<<employee1.getage()<<"years old"<<endl;
}



/*
int main()
{
    string name="ozi";
    string company="aktasmuh";
    int age=20;
    cout<<"name - "<<name<<endl;
    cout<<"company - "<<company<<endl;
    cout<<"age - "<<age<<endl;
}*/