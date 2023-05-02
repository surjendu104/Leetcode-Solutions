//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:

	void rearrange(int arr[], int n) {
	    // code here
	    vector<int> pos,neg;
	    int cp = 0, cn = 0;
	    for(int i = 0; i < n; ++i) {
	        if(arr[i] >= 0)pos.push_back(arr[i]), cp++;
	        else neg.push_back(arr[i]), cn++;
	    }
	    vector<int> ans;
	    bool ok = false;
	    int i = 0, j = 0, k = 0;
	    while(i < cp && j < cn) {
	        if(!ok) {
	            ans.push_back(pos[i++]);
	            ok = true;
	        }else if(ok) {
	            ans.push_back(neg[j++]);
	            ok = false;
	        }
	    }
	    while(i < cp) {
	        ans.push_back(pos[i++]);
	    }
	    while(j < cn) {
	        ans.push_back(neg[j++]);
	    }
	    for(int i = 0; i < n ;i++)arr[i] = ans[i];
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.rearrange(arr, n);
        for (i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends