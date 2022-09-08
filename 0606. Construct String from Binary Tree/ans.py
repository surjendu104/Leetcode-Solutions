# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    ans = ""

    def preOrderString(self, root: Optional[TreeNode]) -> None:
        if(root == None):
            return
        self.ans += str(root.val)
        if(root.left == None and root.right != None):
            self.ans += "()"
        if(root.left != None):
            self.ans += "("
            self.preOrderString(root.left)
            self.ans += ")"
        if(root.right != None):
            self.ans += "("
            self.preOrderString(root.right)
            self.ans += ")"

    def tree2str(self, root: Optional[TreeNode]) -> str:
        self.preOrderString(root)
        return self.ans
