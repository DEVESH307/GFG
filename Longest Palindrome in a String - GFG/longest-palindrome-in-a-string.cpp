//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    pair<int, int> expend(string str, int p1, int p2){
        while(str[p1] == str[p2] && p1 >= 0 && p2 < str.size()){
            p1--;
            p2++;
        }
        return {p1, p2};
    }
    
    string longestPalin (string str) {
        // code here
        string ans = "";
        int n = str.size();
        int maxLen = 0;
        int start, end;
        // int p1, p2;
        // odd centre
        for(int i = 0; i < n; i++){
            pair<int, int> temp = expend(str, i, i);
            int p1 = temp.first;
            int p2 = temp.second;
            if(p2-p1-1 > maxLen){
                maxLen = p2-p1-1;
                start = p1+1;
                end = p2-1;
            }
        }
        //even centre
        for(int i = 0; i < n-1; i++){
            pair<int, int> temp = expend(str, i, i+1);
            int p1 = temp.first;
            int p2 = temp.second;
            if(p2-p1-1 > maxLen){
                maxLen = p2-p1-1;
                start = p1+1;
                end = p2-1;
            }
        }
        //answer
        for(int i = start; i <= end; i++){
            ans.push_back(str[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends