#include"Empdet.h"
#include<fstream>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>
#define BUF_SIZE 2000

int main()
{
	int N,i;
	cin>>N;   
	fstream f1;
	Employee *E=new Employee[N];

	f1.open("data.txt",ios::in | ios::out);
	if(!f1)
	{
		cout<<"Unable to open file"<<endl;
		exit(0);
	}

	for(int i=0; i< N;i++)
	{
		E[i].getdet();
	f1.write(reinterpret_cast<char *>(&E[i]),sizeof(Employee));
	}
	f1.close();

	char buf[BUF_SIZE];
	int pid;
	pid = fork();
	
	if(pid == 0)
	{
		cout<<"Child Starts"<<endl;

		f1.open("data.txt", ios::out);
	
		if(!f1)
		{
			cout<<"\nUnable to open the file"<<endl;
			exit(0);
		}

		f1.write(reinterpret_cast<char *>(&E[i]),sizeof(Employee));

		f1.close();

	}
	else
	{
		wait(0);
		cout<<"Parent Starts"<<endl;

		f1.open("data.txt", ios::in);
	
		if(!f1)
		{
			cout<<"\nUnable to open the file"<<endl;
			exit(0);
		}
		cout<<"Sizeof buf:"<< sizeof(buf)<<endl;
		for(int i=0;i<N;i++)
		{
		E[i].display();
		f1.read(reinterpret_cast<char*>(&buf),sizeof(buf));
		}
		f1.close();
		
	}

	return 0;
}
