class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        period =minutesToTest/minutesToDie +1
        ans=0
        while pow(period,ans)<buckets :
            ans+=1
        return ans