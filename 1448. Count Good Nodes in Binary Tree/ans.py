# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def dfs(self,root: TreeNode,maxUpto:int)->int:
        if(root==None):return 0
        ans=0
        currMax=root.val
        if(currMax>=maxUpto):
            ans+=1
        else:
            currMax=maxUpto
        return self.dfs(root.left,currMax)+self.dfs(root.right,currMax)+ans
    def goodNodes(self, root: TreeNode) -> int:
        return self.dfs(root.left,root.val)+self.dfs(root.right,root.val)+1


