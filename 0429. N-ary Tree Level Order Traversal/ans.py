class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans=[]
        if(root==None):
            return ans
        q=[]
        q.append(root)
        while( len(q)):
            v1=[]
            v2=[]
            while(len(q)):
                v1.append(q[0].val)
                for i in q[0].children:
                    v2.append(i)
                q.pop(0)
            for i in v2:q.append(i)
            # ans.append(v1[::-1])
            ans.append(v1)

        return ans


        