# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
'''Runtime: 110 ms, faster than 50.91% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.
Memory Usage: 26.4 MB, less than 30.85% of Python3 online submissions for Lowest Common Ancestor of a Binary Tree.'''


class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        if(not root or root == p or root == q):
            return root

        left, right = self.lowestCommonAncestor(
            root.left, p, q), self.lowestCommonAncestor(root.right, p, q)

        if left and right:
            return root
        elif left:
            return left
        else:
            return right
