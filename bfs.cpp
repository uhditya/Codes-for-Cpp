#include <iostream>
#include <queue>
using namespace std;
int bfs(int arr[][10],int n,int v[]){
    queue<int> q;
    q.push(0);
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        v[i] = 0;
    }
    v[0] = 1;
    c++;
    while(c!=n){
        for (int i = q.front(); i < n; i++)
        {
           for (int j = 0; j < n; j++)
           {
               if(arr[i][j]==1 && v[j]==0 ){
                   q.push(j);
                   v[j] = 1;
                   c++;
               }
           }
           cout<<q.front()+1<<" ";
           q.pop();
           
        }
        
    }
    
    
    
}
int main()
{
    
    int n;
    cin>>n;
    int v[10],arr[10][10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>arr[i][j];
        }
        
    }
    bfs(arr,n,v);

    
     return 0;
}
