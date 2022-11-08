//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
    string removeConsecutiveCharacter(string str){
        // code here.
        string res = "";
        res.push_back(str[0]);
        for(int i = 1; i < str.size(); i++){
            if(str[i-1] == str[i]){
                continue;
            }
            else{
                res.push_back(str[i]);
            }
        }
        return res;
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
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends