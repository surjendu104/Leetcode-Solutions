class Solution {
public:
    
     bool ok(int max_cookies,int ind,vector<int>& cookies,int k,vector<int>& child){
        if(ind==cookies.size()){
            return true;
        }
        for(int i=0;i<k;i++){
            if(child[i]+cookies[ind]<=max_cookies){
                child[i] += cookies[ind];
                if(ok(max_cookies,ind+1,cookies,k,child)){
                    return true;
                }
                child[i] -= cookies[ind];
            }
            if(child[i]==0){
                return false;
            }
        }
        return false;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
       int n = cookies.size();
        int l = *max_element(cookies.begin(), cookies.end()), r = accumulate(cookies.begin(), cookies.end(), 0);
        vector<int> child(k, 0); 
        sort(cookies.begin(), cookies.end());
        int ans = r;
        while(l <= r){
            int mid = (l + r) >> 1;
            fill(child.begin(),child.end(),0);
            if(ok(mid,0,cookies,k,child)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
};