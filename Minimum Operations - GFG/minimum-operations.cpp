//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int minOperation(int n)
    {
        //code here.
        if(n <= 2) return n;
        int ct = 2;
        while(n > 2) {
            if(n % 2 == 0) 
            n = n / 2;
            else 
            n = n - 1;
            ct++;
        }
        return ct;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends