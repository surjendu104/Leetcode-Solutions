class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        int n = students.size();
        
        for(int ele : students) {
            q.push(ele);
        }
        
        for(int i = 0; i < n; ++i) {
            int m = q.size();
            bool keep_going = true;
            for(int j = 0; j < m && keep_going; ++j) {
                int pref = q.front();
                q.pop();
                if(pref == sandwiches[i]) {
                    keep_going = false;
                    break;
                }
                else {
                    q.push(pref);
                }
            }
            if(q.size() == m) {
                return q.size();
            }
        }
        return 0;
    }
};