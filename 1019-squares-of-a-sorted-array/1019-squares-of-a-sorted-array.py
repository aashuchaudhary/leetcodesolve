class Solution:
    def sortedSquares(self, arr: List[int]) -> List[int]:
        n = len(arr)
        i,j = 0 ,n-1
        new_arr = [0]*n

        # for largest element placed on end
        for k in reversed(range(n)):
            if arr[i]**2 > arr[j]**2:
                new_arr[k] = arr[i] **2
                i+=1
            else:
                new_arr[k] = arr[j]**2
                j-=1
        return new_arr