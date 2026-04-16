class Solution:
    def assignHole(self, mices, holes):
        # code here
        mices.sort()
        holes.sort()
        max_time = 0

        for i in range(len(mices)):
            max_time = max(max_time, abs(mices[i]-holes[i]))

        return max_time