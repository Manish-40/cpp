#include <bits/stdc++.h>
using namespace std;
void shortest_distance(vector<int>&matrix)
{
    int n=matrix.size();
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==-1)
            {
                matrix[i][j]=1e9;
            }
            // diagonal 0
            if(i==j) matrix[i][j]=0;
        }
    }
    int k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
            matrix[i][j]=min(matrix[i][j],matrix[i][k]+matrix[k][j]);
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(matrix[i][i]<0)
        {
            // negative cycle
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(matrix[i][j]==1e9)
            {
                matrix[i][j]=-1;
            }
        }
    }
}
int main() {
	// your code goes her
// 	Floyd warshall algorithm
// TC->O(N^3)
// SC->O(N^2)
}
