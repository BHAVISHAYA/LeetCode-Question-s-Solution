//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	bool isPalin(int i, int j, string &s) {
	    if(i >= j) return true;
	    if(s[i] != s[j]) return false;
	    i++;
	    j--;
	    return isPalin(i, j, s);
	}
	int isPalindrome(string S)
	{
	    // Your code goes here
	    if(isPalin(0, S.size() - 1, S)) return 1;
	    return 0;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends