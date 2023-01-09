"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""


class Solution:
    def preordertravresal(self, root: 'Node', ans: List[int]) -> List[int]:
        if root is None:
            return ans

        ans.append(root.val)

        for child in root.children:
            ans = self.preordertravresal(child, ans)
        return ans

    def preorder(self, root: 'Node') -> List[int]:
        res = []

        return self.preordertravresal(root, res)
