class Solution:
    def check(self,a: List[int]) -> bool:
        if not len(a):
            return True
        for i in range(len(a)-1):
            if a[i]>=a[i+1]:
                return False
        
        return True

    def incremovableSubarrayCount(self, nums: List[int]) -> int:
        n=len(nums)
        c=0
        for i in range(n):
            a=nums.copy()
            for j in range(i,n):
                a.pop(i)
                if self.check(a):
                    c+=1

        return c
        