//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2){
        // Your code here
        int n1 = str1.size();
        int n2 = str2.size();
        if(n1 != n2) return false;
        
        int str1_map[26] = {0};
        int str2_map[26] = {0};
        for(auto ch: str1){
            str1_map[ch-'a']++;
        }
        for(auto ch: str2){
            str2_map[ch-'a']++;
        }
        for(int i = 0; i < n1; i++){
            if(str1_map[str1[i]-'a'] == str2_map[str2[i]-'a']){
                str1_map[str1[i]-'a']--;
                str2_map[str2[i]-'a']--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends