//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//function Template for C++

//Function to reverse the queue.
class Solution
{
    public:
    vector<int> v;
    queue<int> rev(queue<int> q)
    {
        // add code here.
        int n = q.size();
        while(n--) {
            int x = q.front();
            q.pop();
            v.push_back(x);
        }
        reverse(v.begin(), v.end());
        queue<int> newq;
        for(int i : v)newq.push(i);
        return newq;
    }
};


//{ Driver Code Starts.
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    Solution ob;
    queue<int> a=ob.rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends