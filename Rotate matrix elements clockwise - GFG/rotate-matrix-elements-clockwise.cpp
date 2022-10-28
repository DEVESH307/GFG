//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
        vector<vector<int>> rotateMatrix(int r, int c, vector<vector<int>> matrix) {
            if(r == 1 || c == 1)
                return matrix;
            int top=0, left=0, bottom = r-1, right = c-1;
            while(top < bottom && left < right){
                int curr, prev = matrix[top][left];
                for(int i = left; i <= right; i++){
                    curr = matrix[top][i];
                    matrix[top][i] = prev;
                    prev = curr;
                }
                for(int i = top+1; i <= bottom; i++){
                    curr = matrix[i][right];
                    matrix[i][right] = prev;
                    prev = curr;
                }
                for(int i = right-1; i >= left; i--){
                    curr = matrix[bottom][i];
                    matrix[bottom][i] = prev;
                    prev = curr;
                }
                for(int i = bottom-1; i >= top; i--){
                    curr = matrix[i][left];
                    matrix[i][left] = prev;
                    prev = curr;
                }
                top++;
                right--;
                bottom--;
                left++;
            }
            return matrix;
        }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, i, j;
        cin >> N >> M;
        vector<vector<int>> Mat(N, vector<int>(M));
        for (i = 0; i < N; i++)
            for (j = 0; j < M; j++) cin >> Mat[i][j];
        Solution ob;
        vector<vector<int>> ans = ob.rotateMatrix(N, M, Mat);
        for (i = 0; i < N; i++) {
            for (j = 0; j < M; j++) cout << ans[i][j] << " ";
            cout << "\n";
        }
    }
}
// } Driver Code Ends