class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        s=str(n)
        
        s=''.join(sorted(s))
        for i in range(0,30):
            x=2**i
            x=str(x)
            
            x=''.join(sorted(x))
            if s==x:return True
        return False