class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;

        int top=0,bottom=matrix.size()-1;
        int left=0,right=matrix[0].size()-1;

        int type = 1;
        while(top<=bottom and left<=right){
            if(type==1){    
                for(int i=left;i<=right;i++){
                    ans.push_back(matrix[top][i]);
                }
                type=2;
                top++;
            }
            else if(type==2){
                for(int i=top;i<=bottom;i++){
                    ans.push_back(matrix[i][right]);
                }
                type=3;
                right--;
            }
            else if(type==3){
                for(int i=right;i>=left;i--){
                    ans.push_back(matrix[bottom][i]);
                }
                type=4;
                bottom--;
            }
            else if(type==4){
                for(int i=bottom;i>=top;i--){
                    ans.push_back(matrix[i][left]);
                }
                type=1;
                left++;
            }
        }
        return ans;
        
    }
};