//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
    std::unordered_map<int, int> mp;

    void primeFactors(int n) {
        while (n % 2 == 0) {
            mp[2]++;
            n = n / 2;
        }

        for (int i = 3; i <= sqrt(n); i = i + 2) {
            while (n % i == 0) {
                mp[i]++;
                n = n / i;
            }
        }

        if (n > 2)
            mp[n]++;
    }

    int sumOfPowers(int a, int b) {
        int sum = 0;
        for (int i = a; i <= b; i++) {
            primeFactors(i);
            for (const auto &it : mp) {
                sum += it.second;
            }
            mp.clear();
        }
        return sum;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
