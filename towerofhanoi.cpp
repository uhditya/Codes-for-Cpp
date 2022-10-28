#include<iostream>
using namespace std;
static int i=0;
int hanoi(char fro,char to,char oth,int num);
int main()
{
    int n;
    cout<<"Enter the number of disks:";
    cin>>n;
    cout<<"Tower of hanoi for "<<n<<" disks."<<"\n";
    hanoi('a','b','c',n);
    cout<<"Total steps:"<<i+1;
    return 0;
}
int hanoi(char fro,char to, char oth,int num)
{  
    if(num<=0)
    {
        cout<<"invalid number"<<"\n";
    }
    else if(num==1)
    {
        cout<<"move disk from "<<fro<<" to "<<oth<<"\n";
    }
    else if(num>1)
    {
        hanoi(fro,oth,to,num-1); i++;
        hanoi(fro,to,oth,1); i++;
        hanoi(to,fro,oth,num-1); 
    }
}