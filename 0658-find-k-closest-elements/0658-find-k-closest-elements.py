class Solution:
    def findClosestElements(self, arr, k, x):
        arr.sort(key=lambda num: (abs(num - x), num))
        return sorted(arr[:k])
