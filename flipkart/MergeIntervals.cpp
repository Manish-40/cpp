class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i;
        vector<vector<int>>a;
        sort(intervals.begin(),intervals.end());
        for(i=0;i<intervals.size();i++)
        {
            if(a.empty()||intervals[i][0]>a.back()[1])
            {
                a.push_back(intervals[i]);
            }
            else
            {
                a.back()[1]=max(a.back()[1],intervals[i][1]);
            }
        }
        return a;
    }
};