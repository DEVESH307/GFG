//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
string firstRepChar(string s);
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        cout<<firstRepChar(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends


string firstRepChar(string str){
    //code here.
    string ans;
    unordered_set<char> set;
    for(auto ch: str){
        if(set.find(ch) != set.end()){
            ans.push_back(ch);
            break;
        }
        else{
            set.insert(ch);
        }
    }
    return ans.size() > 0 ? ans: "-1";
}