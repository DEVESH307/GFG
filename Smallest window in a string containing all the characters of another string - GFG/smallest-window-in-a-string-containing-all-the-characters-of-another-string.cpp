//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p){
        // Your code here
        if(s == p) return s;
    
        unordered_map<char, int> mp_s;
        unordered_map<char, int> mp_p;
        int match_count = 0;
        int desired_match_count = p.length();
        int i = -1;
        int j = -1;
        int left = -1; 
        int right;
    
        for(auto ch: p){
            mp_p[ch]++;
        }
    
        while(true){
            bool flag1 = false;
            bool flag2 = false;
            while(j < (int) s.length() -1 && match_count < desired_match_count){
                j++;
                char ch = s[j];
                mp_s[ch]++;
                if(mp_p.find(ch) != mp_p.end() && mp_s[ch] <= mp_p[ch]){
                    match_count++;
                }
                flag1 = true;
            }
            while(i < j && match_count == desired_match_count){
                if(left == -1 || right-left+1 > j-i){
                    left = i+1;
                    right = j;
                }
                i++;
                char ch = s[i];
                if(mp_s[ch] == 0){
                    mp_s.erase(ch);
                }
                else{
                    mp_s[ch]--;
                }
                if(mp_s[ch] < mp_p[ch]){
                    match_count--;
                }
                flag2 = true;
            }
            if(flag1 == false && flag2 == false){
                break;
            }
        }
        return left == -1 ? "-1" : s.substr(left, right-left+1);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends