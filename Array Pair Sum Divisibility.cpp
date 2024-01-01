//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here
        map<int,int> f;
        
        for(int i = 0; i < nums.size(); i++){
            int cur = nums[i] % k;
            int need = (k - cur) % k;
            
            if(f.count(need)){
                --f[need];
                
                if(f[need] == 0)
                    f.erase(need);
            }
            else{
                ++f[cur];
            }
        }
        
        return f.size() == 0;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}
// } Driver Code Ends
