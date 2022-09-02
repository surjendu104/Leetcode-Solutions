# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
import numpy as np


class Solution:
    def averageOfLevels(self, root: Optional[TreeNode]) -> List[float]:
        averages = []

        def recursion_average(list_of_nodes: Optional[TreeNode]):
            if np.any(list_of_nodes):
                averages.append(
                    np.mean([node.val for node in list_of_nodes if node]))
                recursion_average(
                    [child for node in list_of_nodes if node for child in [node.left, node.right]])
        recursion_average([root])
        return averages
