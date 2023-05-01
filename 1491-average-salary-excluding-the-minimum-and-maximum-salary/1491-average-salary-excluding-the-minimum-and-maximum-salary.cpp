class Solution {
public:
    double average(vector<int>& salary) {
        sort(salary.begin(),salary.end());
        double x = accumulate(salary.begin(),salary.end(),0);
        return (x-salary[0]-salary[salary.size()-1])/(salary.size()-2);
    }
};