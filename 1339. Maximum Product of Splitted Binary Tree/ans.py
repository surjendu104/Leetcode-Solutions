# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def maxProduct(self, root: TreeNode) -> int:
        def total_tree_sum(node: TreeNode) -> int:
            return 0 if not node else (total_tree_sum(node.left) + node.val + total_tree_sum(node.right))
            
        def max_tree_product(node: TreeNode) -> int:
            if not node:
                return 0 
            
            tree_sum = max_tree_product(node.left) + node.val + max_tree_product(node.right)
            self.max_product = max(self.max_product, tree_sum * (self.total_sum - tree_sum))
            
            return tree_sum
        
        self.max_product = 0
        self.total_sum = total_tree_sum(root)
        max_tree_product(root)
        
        return self.max_product % (10**9 + 7)