class Solution:
    def minSubArrayLen(self, target: int, nums: list[int]) -> int:
        res=1e9
        left=0
        csum=0
        for right,v in enumerate(nums):
            csum+=v
            while csum>=target:
                res=min(res,right-left+1)
                csum-=nums[left]
                left+=1
           
                
            
        if(res==1e9):
            return 0    
        else:
            return res