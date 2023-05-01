//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    void sort012(int a[], int n)
    {
        // code here 
        map<int, int> mpp;
        for(int i = 0; i < n; i++)mpp[a[i]]++;
        vector<int> v;
        for(auto it : mpp) {
            while(it.second--) {
                v.push_back(it.first);
            }
        }
        for(int i = 0; i < n; i++)a[i] = v[i];
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends