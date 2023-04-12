class Solution {
public:
    string simplifyPath(string path) {
        path += '/';
        stack<string> st;
        string cur = "";
        for(int i=0; i<path.length(); i++){
            if(path[i] == '/'){
                if(cur == ".."){
                    if(!st.empty())
                        st.pop();
                }
                else if(cur != "." && cur!=""){
                    st.push(cur);
                }
                cur = "";
            }
            else{
               cur+=path[i];
            }
        }
        string ans = "";
        while(!st.empty()){
            ans = "/" + st.top() + ans;
            st.pop();
        }
        return ans == "" ? "/" : ans;
    }
};