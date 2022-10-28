//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) {
        // code here
        vector<int> res;
        // int r = matrix.size();
        // int c = matrix[0].size();
        int top = 0;
        int bottom = r-1;
        int left = 0;
        int right = c-1;
        
        while(top <= bottom && left <= right && res.size() < r*c ){
            for(int i = left; i <= right && res.size() < r*c; i++){
                res.push_back(matrix[top][i]);
            }
            top++;
            for(int i = top; i <= bottom && res.size() < r*c; i++){
                res.push_back(matrix[i][right]);
            }
            right--;
            for(int i = right; i >= left && res.size() < r*c; i--){
                res.push_back(matrix[bottom][i]);
            }
            bottom--;
            for(int i = bottom; i >= top && res.size() < r*c; i--){
                res.push_back(matrix[i][left]);
            }
            left++;
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends