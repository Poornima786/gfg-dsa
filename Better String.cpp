//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSub(string s) {
        unordered_map<char, int> mp;
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = 2 * dp[i - 1];
            
            char ch=s[i-1];
            
            if (mp.find(ch) != mp.end()) {
                dp[i] = dp[i] - dp[mp[ch]];
            }

            mp[ch] = (i - 1);
        }

        return dp[n];
    }
    
    string betterString(string str1, string str2) {
        int x = countSub(str1);
        int y = countSub(str2);

        if (x < y) {
            return str2;
        }

        return str1;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends
