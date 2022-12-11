# Definition for a binary tree node.


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def getSum(self, root: TreeNode) -> int:
        if not root:
            return 0
        sum_left, sum_right = self.getSum(root.left), self.getSum(root.right)

        max_length_path = max(root.val+max(sum_left, sum_right), root.val)
        self.ans = max(self.ans, max_length_path, root.val+sum_left+sum_right)
        return max_length_path

    def maxPathSum(self, root: TreeNode) -> int:
        self.ans = float('-inf')
        self.getSum(root)
        return self.ans
