//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	
	
	
	public:
	void shuffleArray(int arr[],int n)
	{
	   int m = n/2;
	    for(int i = 0; i < m; i++){
	        arr[i + m] += arr[i]*1001;
	    }
	    for(int i = 0; i < m; i++){
	        arr[2*i] = arr[i + m]/1001;
	        arr[2*i + 1] = arr[i + m]%1001;  // Your code goes here
	}
		 
	}
};


//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
