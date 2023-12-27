//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> matrix) 
    {
        // Code here
        int n = matrix.size();
        vector<int> ans;
        
        for(int j = 0; j < n; j++){
            for(int x = 0, y = j; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
       
        for(int i = 1; i < n; i++){
            for(int y = n - 1, x = i; y > -1 and x < n; x++, y--){
                ans.push_back(matrix[x][y]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
