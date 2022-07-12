#include<iostream>
#include<string>
#include<fstream>

using namespace std;

class Employee
{
        protected:
                int id,sal;
                string Ename;
        public:
                Employee(){}
                Employee(int i,int s,string name)
                {
                        id = i;
			sal = s;
                        Ename = name;
                }
                int getID(){ return id;}
		int getSalary(){ return sal;}

                string getName(){return Ename;}

                void display(){
                        cout<<"\n ID :" << id <<endl;
                        cout<<"Name :" << Ename << endl;
			cout<<"Salary :" << sal <<endl;
		}
		void getdet(){
			cout<<"\n Employee details "<<endl;
			cout<<"ID :"<< id << endl;
			cout<<" Name : "<< Ename <<endl;
			cout<<"Salary : "<< sal << endl;
		}

};
