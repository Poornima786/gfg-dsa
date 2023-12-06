//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   int solve(int R,int X){
      int a=0;
        for(int i=1;i<R;i++){
            int k=i;
            while(k){
                int rem=k%10;
                k=k/10;
                if(rem==X)a++;
            }
        }
        return a;
  }
    int countX(int L, int R, int X) {
      return solve(R,X)-solve(L+1,X);  
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int L, R, X;
        cin >> L >> R >> X;
        Solution ob;
        int ans = ob.countX(L, R, X);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
