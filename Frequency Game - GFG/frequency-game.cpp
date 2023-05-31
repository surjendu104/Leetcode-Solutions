//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int LargButMinFreq(int arr[], int n) {
        // code here
        unordered_map<int, int> mpp;
        int min_frq = INT_MAX;
        for(int i = 0; i<n;++i)mpp[arr[i]]++;
        
        for(auto it : mpp) {
            min_frq = min(min_frq, it.second);
        }
        int ans = INT_MIN;
        for(auto it : mpp) {
            if(it.second == min_frq)ans = max(ans,it.first);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    // Iterating over testcases
    while (t--) {
        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;

        cout << ob.LargButMinFreq(arr, n) << endl;
    }
}
// } Driver Code Ends