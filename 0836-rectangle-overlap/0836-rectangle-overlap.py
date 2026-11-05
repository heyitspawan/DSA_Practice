class Solution:
    def isRectangleOverlap(self, rec1: list[int], rec2: list[int]) -> bool:
        x1=rec1[0]
        x2=rec1[2]
        y1=rec1[1]
        y2=rec1[3]
        if((rec2[0]>=x1 and rec2[0]>=x2)or (rec2[2]<=x1 and rec2[2]<=x2)):
            return False
        if((rec2[1]>=y1 and rec2[1]>=y2)or (rec2[3]<=y1 and rec2[3]<=y2)):
            return False
             

        return True


        