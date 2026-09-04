class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        arr = [(nums[i], i) for i in range(len(nums))]
        arr.sort()
        i = 0
        j = len(arr) - 1
        while i < j:
            curr = arr[i][0] + arr[j][0]
            if curr > target:
                j -= 1
            elif curr < target:
                i += 1
            else:
                return [arr[i][1], arr[j][1]]