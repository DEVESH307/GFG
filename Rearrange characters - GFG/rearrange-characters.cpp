//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    //TC: O(nlogn) SC:O(n)
    // string rearrangeString(string str){
    //     //code here
    //     string res = "";
    //     priority_queue<pair<int, char>> pq;
    //     int mp[26] = {0};
    //     for(auto ch: str){
    //         mp[ch-'a']++;
    //     }
    //     for(int i = 0; i < 26; i++){
    //         if(mp[i] > 0){
    //             pq.push({mp[i], 'a'+i});
    //         }
    //     }
    //     auto prev = pq.top();
    //     pq.pop();
    //     res += prev.second;
    //     prev.first--;
    //     while(!pq.empty()){
    //         auto curr = pq.top();
    //         pq.pop();
    //         res += curr.second;
    //         curr.first--;
    //         if(prev.first > 0){
    //             pq.push(prev);
    //         }
    //         prev = curr;
    //     }
    //     return prev.first ? "-1" : res;
    // }
    
    //TC: O(n) SC:O(n+26)
    char getMaxCountChar(vector<int>& count){
        int max = 0;
        char ch;
        for (int i = 0; i < 26; i++) {
            if (count[i] > max) {
                max = count[i];
                ch = 'a' + i;
            }
        }
        return ch;
    }
    string rearrangeString(string str){
        int n = str.size();
        if (n == 0) return "-1";
        vector<int> count(26, 0);
        for(auto& ch : str){
            count[ch - 'a']++;
        }
        char ch_max = getMaxCountChar(count);
        int maxCount = count[ch_max - 'a'];
        if (maxCount > (n + 1) / 2) return "-1";
        
        string res(n, ' ');
        int index = 0;
        while (maxCount){
            res[index] = ch_max;
            index += 2;
            maxCount--;
        }
        count[ch_max - 'a'] = 0;
        for (int i = 0; i < 26; i++){
            while (count[i] > 0) {
                index = (index >= n) ? 1 : index;
                res[index] = 'a' + i;
                index += 2;
                count[i]--;
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
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends