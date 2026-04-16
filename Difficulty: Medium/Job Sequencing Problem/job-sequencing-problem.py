import heapq

class Solution:
    def jobSequencing(self, deadline, profit):
        # code here
        jobs = list(zip(deadline, profit))
        jobs.sort()
        min_heap = []

        for deadline, profit in jobs:
            heapq.heappush(min_heap, profit)

            # if we exceed allowed jobs till this deadline
            if len(min_heap) > deadline:
                heapq.heappop(min_heap) # remove smallest profit

        return [len(min_heap), sum(min_heap)]        