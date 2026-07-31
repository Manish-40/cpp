#include <bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&points)
{
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+f(day-1,task,points);
            maxi=max(maxi,point);
        }
    }
    return maxi;
    
}
int ninjaTraining(int n,vector<vector<int>>&points)
{
    return f(n-1,3,points);
}
int main() {
	// your code goes her
// ninjas training
// TC->O(N*4)*3
// SC->O(N)
// 3 col 2 row 
// 10      50       1        day1
// 5       100      11       day2

// 1       2        3    activity


// 50/1st day 11/2nd day = 61
// 10/1st day 100/2nd day = 110


// try all possible ways recursion top-down n-1 to 0

// 0 based indexing

// last 0 - task 0 is done
//      1 - task 1 is done
//      2 - task 2 is done
//      3 - no tatsk is done

// f(day,last)
// f(n-1,3)

// n=4
// task=0  task=1  task=2
// 2       1        3     day0
// 3       4        6     day1
// 10      1        6     day2
// 8       3        7     day3

//                                 f(3,3)
//               +task0/           +task1|         \+task2
//              12=f(2,0)           f(2,1)           f(2,2)
//          +task1/ \+task2     +task0/\+task2
//          8=f(1,1)   f(1,2)=7s  f(1,0) f(1,2)
//          +task0/   \task2
//         3=f(0,0)     f(0,2)=2

// f(1,2) overlapping 

// +rask0 ma f(2,0) no matlab che day 2 ma gaya tyare task 0 perform nahi karvanu only task1 and task 2
}


#include <bits/stdc++.h>
using namespace std;
int f(int day,int last,vector<vector<int>>&points,vector<vector<int>>&dp)
{
    if(day==0)
    {
        int maxi=0;
        for(int task=0;task<3;task++)
        {
            if(task!=last)
            {
                maxi=max(maxi,points[0][task]);
            }
        }
        return maxi;
    }
    if(dp[day][last]!=-1) return dp[day][last];
    int maxi=0;
    for(int task=0;task<3;task++)
    {
        if(task!=last)
        {
            int point=points[day][task]+f(day-1,task,points,dp);
            maxi=max(maxi,point);
        }
    }
    return dp[day][last]=maxi;
    
}
int ninjaTraining(int n,vector<vector<int>>&points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    return f(n-1,3,points,dp);
}
int main() {
	// your code goes her
// 	memoization 
// TC->O(N*4)*3
// SC->O(N)+O(N*4)
}


#include <bits/stdc++.h>
using namespace std;
int ninjaTraining(int n,vector<vector<int>>&points)
{
    vector<vector<int>>dp(n,vector<int>(4,-1));
    
    dp[0][0]=max(points[0][1],points[0][2]);
    dp[0][1]=max(points[0][0],points[0][2]);
    dp[0][2]=max(points[0][0],points[0][1]);
    dp[0][3]=max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++)
    {
        for(int last=0;last<4;last++)
        {
            dp[day][last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    int point=ponits[day][task]+dp[day-1][task];
                    dp[day][last]=max(dp[day][last],point);
                }
            }
        }
    }
    return dp[n-1][3];
}
int main() {
	// your code goes her
// 	tabulation bottom-up
// TC->O(N*4*3)
// SC->O(N*4)
}


#include <bits/stdc++.h>
using namespace std;
int ninjaTraining(int n,vector<vector<int>>&points)
{
    vector<int>prev(4,0);
    
    prev[0]=max(points[0][1],points[0][2]);
    prev[1]=max(points[0][0],points[0][2]);
    prev[2]=max(points[0][0],points[0][1]);
    prev[3]=max(points[0][0],max(points[0][1],points[0][2]));
    
    for(int day=1;day<n;day++)
    {
        vector<int>temp(4,0);
        for(int last=0;last<4;last++)
        {
            temp[last]=0;
            for(int task=0;task<3;task++)
            {
                if(task!=last)
                {
                    temp[last]=max(temp[last],points[day][task]+prev[task]);
                }
            }
        }
        prev=temp;
    }
    return prev[3];
}
int main() {
	// your code goes her
// space optimization
// TC->O(N*4*3)
// SC->O(4)
}