#include <bits/stdc++.h>
using namespace std;
int findcity(int n,int m,vector<vector<int>>&edges,int distanceThreshold)
{
    vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
    for(auto it:edges)
    {
        dist[it[0]][it[1]]=it[2];
        dist[it[1]][it[0]]=it[2];
    }
    int i;
    int j;
    for(i=0;i<n;i++)
    {
        dist[i][i]=0;
    }
    int k;
    for(k=0;k<n;k++)
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                {
                    continue;
                }
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    int countCity=n;
    int cityNo=-1;
    int city;
    int adjCity;
    for(city=0;city<n;city++)
    {
        int count=0;
        for(adjCity=0;adjCity<n;adjCity++)
        {
            if(dist[city][adjCity]<=distanceThreshold)
            {
                count++;
            }
        }
            if(count<=countCity)
            {
                countCity=count;
                cityNo=city;
            }
    }
    return cityNo;
}
int main() {
	// your code goes her
// Find the city with the smallest number of neighbour at a threshold difstance
}
