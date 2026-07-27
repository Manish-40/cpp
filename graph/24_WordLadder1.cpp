#include <bits/stdc++.h>
using namespace std;
int wordladder(string startWord,string targetWord,vector<String>&wordList)
{
    queue<pair<int,int>>q;
    q.push({startWord,1});
    unordered_set<string>st(wordList.begin(),wordList.end());
    st.erase(startWord);
    while(!q.empty())
    {
        string word=q.front().first;
        int steps=q.front().second;
        q.pop();
        if(word==targetWord) return steps;
        int i;
        
        for(i=0;i<word.size();i++)
        {
            // word=hat 
            // original=word[i]=h
            char original=word[i];
            for(char ch='a';ch<='z';ch++)
            {
                // aat bat cat dat
                word[i]=ch;
                // it exist in the set
                if(st.find(word)!=st.end())
                {
                    st.erase(word);
                    q.push({word,steps+1});
                }
            }
// aama pachu h nakhi do e step che kemke pachu have hat ma a mate a to z nu loop farse ne aetle
            word[i]=original;
            
        }
    }
    return 0;
}
int main() {
	// your code goes here
// Word ladder 1
// TC->N*word.size()*26*logN->set SC->O(N)
}
