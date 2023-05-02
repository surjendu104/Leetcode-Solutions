class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
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
        return ans;
    }
};