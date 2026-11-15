class Solution(object):
    def numOfSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        oddcount=0
        sum=0
        for i in arr:
            sum=sum+i
            oddcount+=int(sum%2)

        oddcount+=(len(arr)-oddcount)*oddcount
        return int(oddcount%(1e9+7))
