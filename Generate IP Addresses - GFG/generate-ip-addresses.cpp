//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    // bool isValid(string subStr){
    //     if(subStr[0] == '0') return false;
    //     int num = stoi(subStr);
    //     return num <= 255;
    // } 
    // void genIpUtil(string &str, int idx, int par, const string &currAns, vector<string> &ans){
    //     if(idx == str.size() || par == 4){
    //         if(idx == str.size() && par == 4){
    //             ans.push_back(currAns.substr(0, currAns.size()-1));
    //         }
    //         return;
    //     }  
    //     genIpUtil(str, idx+1, par+1, currAns+str.substr(idx, 1)+".", ans);
    //     if(idx+2 <= str.size() && isValid(str.substr(idx, 2)))
    //         genIpUtil(str, idx+2, par+1, currAns+str.substr(idx, 2)+".", ans);
    //     if(idx+3 <= str.size() && isValid(str.substr(idx, 3)))
    //         genIpUtil(str, idx+3, par+1, currAns+str.substr(idx, 3)+".", ans);
    // }
    
    // vector<string> genIp(string &str) {
    //     // Your code here
    //     vector<string> ans;
    //     int n = str.size();
    //     if(n < 4 || n > 12) return {"-1"};
    //     genIpUtil(str, 0, 0, "", ans);
    //     return ans;
    // }
    vector<string> genIp(string &s) {
        vector<string> res;
        string ans;
        
        for (int a=1; a<=3; a++)
            for (int b=1; b<=3; b++)
                for (int c=1; c<=3; c++)
                    for (int d=1; d<=3; d++)
                        if (a+b+c+d == s.length()){
                            int A = stoi(s.substr(0, a));
                            int B = stoi(s.substr(a, b));
                            int C = stoi(s.substr(a+b, c));
                            int D = stoi(s.substr(a+b+c, d));
                            if (A<=255 && B<=255 && C<=255 && D<=255)
                                if ( (ans=to_string(A)+"."+to_string(B)+"."+to_string(C)+"."+to_string(D)).length() == s.length()+3)
                                    res.push_back(ans);
                        }
        return res;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends