from collections import deque
import heapq

# Brute Force - O(N*K)
def brute_force(nums, k):
    return [max(nums[i:i+k]) for i in range(len(nums) - k + 1)]

# Max Heap (Priority Queue) - O(N log K)
def heap_sliding_window(nums, k):
    result = []
    pq = []

    for i in range(len(nums)):
        heapq.heappush(pq, (-nums[i], i))

        if i >= k - 1:
            while pq[0][1] <= i - k:
                heapq.heappop(pq)
            result.append(-pq[0][0])

    return result

# Optimized Deque Approach - O(N)
def deque_sliding_window(nums, k):
    dq = deque()
    result = []

    for i in range(len(nums)):
        if dq and dq[0] == i - k:
            dq.popleft()

        while dq and nums[dq[-1]] < nums[i]:
            dq.pop()

        dq.append(i)

        if i >= k - 1:
            result.append(nums[dq[0]])

    return result

def main():
    nums = [1, 3, -1, -3, 5, 3, 6, 7]
    k = 3

    print("Brute Force Output:", brute_force(nums, k))
    print("Heap Output:", heap_sliding_window(nums, k))
    print("Deque Output:", deque_sliding_window(nums, k))

main()
