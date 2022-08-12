/**
 * Definition for a binary tree node.
 * function TreeNode(val) {
 *     this.val = val;
 *     this.left = this.right = null;
 * }
 */

/**
 * @param {TreeNode} root
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {TreeNode}
 */
var lowestCommonAncestor = function (root, p, q) {
    let cur = root
    while (cur != null) {
        if (cur.val > p.val && cur.val > q.val) {
            cur = cur.left
        }
        else if (cur.val < p.val && cur.val < q.val) {
            cur = cur.right
        }
        else {
            return cur
        }

    }
};