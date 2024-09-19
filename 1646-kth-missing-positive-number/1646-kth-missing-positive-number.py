class Solution:
    def findKthPositive(self, arr: List[int], k: int) -> int:
        start,end,ans=0,len(arr)-1,len(arr)

        while start <= end:
            mid = start + (end-start)//2

            if(arr[mid]-mid-1>=k):
                ans= mid
                end=mid-1
            else:
                start=mid+1
        return ans+k