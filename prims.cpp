// prims algo 

#include<iostream>
#include<climits>

using namespace std;
int prims(int **cost, int n, int t[][2])
{
    int *nearest= new int[n+1];
    int mincost=0;
    int j=-1;
    const int INF = INT_MAX;

    int stv=1;
    //assuming starting vertex is 1
    //inititalize starting array

    nearest[stv]=-1;

    for(int i=1;i<=n;i++)
    {
        if(i!=stv)
        {
            nearest[i]=stv;
        }
    }
    int r=1;
    //main loop to find n-1 edges

    for(int i=1;i<n;i++)
    {
        int min=INF;

        for(int k=1; k<=n;k++)
        {
            if(nearest[k]!=-1 && cost[k][nearest[k]]<min)
            {
                j=k;
                min=cost[k][nearest[k]];
            }
        }
        if(j==-1)
        break;
        t[r][0]=j;
        t[r][1]=nearest[j];
        r++;
        mincost+=min;
        nearest[j]=-1;
    }

    //update nearest array 

    for(int k=1;k<=n;k++)
    {  
        if(nearest[k]!=-1 && cost[k][nearest[k]]>cost[k][j])
        nearest[k]=j;
    }
    delete[] nearest;
    return mincost;

}




int main()
{
    int n;
    cout<<"Enter the no. of vertices";
    cin>>n;

    //dynamically allocate memory for the adjacency matrix 

    int **cost=new int*[n+1];
    for(int i=1;i<=n;i++)
    {
        cost[i]= new int[n+1];        
    }

    cout<<"Enter the adjacency matrix";
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>cost[i][j];
            if(cost[i][j]==0)
            cost[i][j]=INT_MAX;

        }
    }

    //array to store the resulting tree
    int t[n][2];//each row will hold one edge 
    
    //run prim's algo
    int mincost=prims(cost,n,t);
    
    //display the edges of a minimum cost spanning tree
    cout<<"Edges in the minimum cost spanning tree are:";

    for(int i=1;i<n;i++)
    {
        cout<<"("<<t[i][0]<<","<<t[i][1]<<")\n";
    }

    // display the total cost of the minimum cost spanning tree

    cout<<"Minimum cost:"<<mincost<<endl;

    //clean up
    for(int i=1;i<=n;i++)
    {
        delete[]cost[i];
    }
    delete[] cost;

    return 0;
}