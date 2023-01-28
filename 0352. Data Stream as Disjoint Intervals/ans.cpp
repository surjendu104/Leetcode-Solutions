class SummaryRanges {
    vector<vector<int>>arr;
public:
    SummaryRanges() {
        arr=vector<vector<int>>(0);
    }
    
    void addNum(int val) {
        if(!arr.size()){
        arr.push_back({val,val});
        return;
    }
    
    
    int n = arr.size(), l = 0, h = n-1;
    while(l <= h){
        
        int m = l+(h-l)/2;
        if(val >= arr[m][0] && val <= arr[m][1]) 
            return;
        
        if(arr[m][1] < val)
            l = m+1;
        else 
            h = m-1;
    }
    
    
    if(l == n){
        if(arr[n-1][1]+1 < val)arr.push_back({val,val}); 
        else arr[n-1][1] = val;
    }
        
    else if(h == -1){
        if(arr[0][0] > val+1)arr.insert(arr.begin(),{val,val}); 
        else arr[0][0] = val;
    }
    else{
        int x = max(l,h);
        l = min(l,h);
        h = x;
        
        if(arr[l][1] + 1 == val && val + 1 == arr[h][0]){
            int end = arr[h][1];
            arr.erase(arr.begin()+h);
            arr[l][1] = end;
        }
        else if(arr[l][1] + 1 == val){
            arr[l][1] = val;
        }
        else if(val + 1 == arr[h][0]){
            arr[h][0] = val;
        }
        else{
            arr.insert(arr.begin()+h,{val,val});
        }
    }
    }
    
    vector<vector<int>> getIntervals() {
        return arr;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */