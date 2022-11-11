//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int findSubString(string str){
        // Your code goes here   
        int ans = INT_MAX;
        unordered_set<char> set;
        for(auto s: str){
            set.insert(s);
        }
        int desired_match_count = set.size();
        int match_count = 0;
        unordered_map<char, int> map;
        int p1 = 0; 
        int p2 = 0;
        while(p2 < str.size()){
            if(map.find(str[p2]) == map.end()){
                map[str[p2]]++;
                p2++;
                match_count++;
                while(p1 < p2 && match_count == desired_match_count){
                    ans = min(ans, p2-p1);
                    map[str[p1]]--;
                    if(map[str[p1]] == 0){
                        map.erase(str[p1]);
                        match_count--;
                    }
                    p1++;
                }
            }
            else{
                map[str[p2]]++;
                p2++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
// Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;
    }
    return 0;
}
// } Driver Code Ends