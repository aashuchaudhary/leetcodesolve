class Solution:
    def isMonotonic(self, arr: List[int]) -> bool:
        #write code here
        n = len(arr)
        if n==0: return True
        first = arr[0]
        last = arr[n-1]
        if first > last :
            # MD or not monotonic
            for k in range(n-1):
                if arr[k] < arr[k+1] : return False
        elif first == last:
                #  monotonic - All values are equal
            for k in range (n-1):
                if arr[k] != arr[k+1] : return False
        else :
              # first < last
               # MI or not monotonic
            for k in range(n-1):
               if arr[k] > arr[k+1] : return False
        return True