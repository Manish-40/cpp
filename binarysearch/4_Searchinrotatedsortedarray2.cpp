#include <bits/stdc++.h>
using namespace std;
int main() {
	// your code goes here
	
	vector<int>arr={7,8,9,1,2,3,4,5,6};
	int target=1;
	int low=0;
	int high=arr.size()-1;
	int mid;
	while(low<=high)
	{
	    mid=low+high/2;
	    if(arr[mid]==target)
	    {
	        cout<<mid<<endl;
	        break;
	    }
        if(arr[low]==arr[mid] && arr[mid]==arr[high])
        {
            low=mid+1;
            high=mid-1;
            continue;
        }
	    if(arr[low]<=arr[mid])
	    {
	        if(arr[low]<=target && target<=arr[mid])
	        {
	            high=mid-1;
	        }
	        else
	        {
	            low=mid+1;
	        }
	    }
	    else
	    {
	        if(arr[mid]<=target && target<=arr[high])
	        {
	            low=mid+1;
	        }
	        else
	        {
	            high=mid-1;
	        }
	    }
	    
	}
}
