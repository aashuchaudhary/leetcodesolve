class Solution:
    def search(self, nums,target):
        start,end=0,len(nums)-1
        
        while start<=end:
            mid=start+(end-start)//2

            # find element
            if nums[mid]==target:
                return mid
                # left side sorted 
            elif nums[mid]>=nums[0]:
                if nums[start]<=target<=nums[mid]:
                    end=mid-1
                else:
                    start=mid+1
            # right side sorted
            else:
                if nums[mid]<=target<=nums[end]:
                    start=mid+1
                else:
                    end=mid-1
        return -1