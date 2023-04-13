class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int idx = 0;
        for(int i:pushed) {
            st.push(i);
            while(st.size()>0 && st.top()==popped[idx]) {
                st.pop();
                idx++;
            }
        }
        return st.size()==0?true:false;
    }
};