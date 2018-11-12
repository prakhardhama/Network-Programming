#include<iostream>
using namespace std;

#include<stdlib.h>
#include<stdio.h>

class A{
public:
A(){cout<<"A(), "<<getpid()<<endl;}
~A(){cout<<"~A(), "<<getpid()<<endl;}
};

A a;
int main()
{

if(fork()==0){
cout<<"child, "<<getpid()<<endl;
_exit();
}
else
{
sleep(1);
wait();
cout<<"parent, "<<getpid()<<endl;
exit();
}
}
