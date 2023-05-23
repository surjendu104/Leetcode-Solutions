class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int myk;
public:
    KthLargest(int k, vector<int> nums) {
        myk = k;
        for(int e : nums){
            pq.push(e);
            //pop the smallest value
            if(pq.size() > k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        //only retain myK elements in pq
        if(pq.size() > myk) pq.pop();
        //toppest is the smallest
        return pq.top();
    }
};