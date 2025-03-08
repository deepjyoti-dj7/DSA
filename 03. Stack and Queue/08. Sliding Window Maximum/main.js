// Brute Force Approach - O(N*K)
function bruteForce(nums, k) {
    let result = [];
    for (let i = 0; i <= nums.length - k; i++) {
        let maxVal = Math.max(...nums.slice(i, i + k));
        result.push(maxVal);
    }
    return result;
}

// Max Heap (Priority Queue) Approach - O(N log K)
class MaxHeap {
    constructor() {
        this.heap = [];
    }

    push(val, index) {
        this.heap.push([val, index]);
        this.heap.sort((a, b) => b[0] - a[0]); // Sort in descending order
    }

    pop() {
        return this.heap.shift();
    }

    top() {
        return this.heap[0];
    }

    size() {
        return this.heap.length;
    }
}

function heapSlidingWindow(nums, k) {
    let result = [];
    let pq = new MaxHeap();

    for (let i = 0; i < nums.length; i++) {
        pq.push(nums[i], i);

        if (i >= k - 1) {
            while (pq.top()[1] <= i - k) {
                pq.pop();
            }
            result.push(pq.top()[0]);
        }
    }
    return result;
}

// Optimized Deque Approach - O(N)
class Deque {
    constructor() {
        this.dq = [];
    }

    pushBack(index) {
        this.dq.push(index);
    }

    popBack() {
        this.dq.pop();
    }

    popFront() {
        this.dq.shift();
    }

    front() {
        return this.dq[0];
    }

    back() {
        return this.dq[this.dq.length - 1];
    }

    size() {
        return this.dq.length;
    }
}

function dequeSlidingWindow(nums, k) {
    let result = [];
    let dq = new Deque();

    for (let i = 0; i < nums.length; i++) {
        if (dq.size() > 0 && dq.front() === i - k)
            dq.popFront();

        while (dq.size() > 0 && nums[dq.back()] < nums[i])
            dq.popBack();

        dq.pushBack(i);

        if (i >= k - 1)
            result.push(nums[dq.front()]);
    }
    return result;
}

// Main function
function main() {
    let nums = [1, 3, -1, -3, 5, 3, 6, 7];
    let k = 3;

    console.log("Brute Force Output:", bruteForce(nums, k));
    console.log("Heap Output:", heapSlidingWindow(nums, k));
    console.log("Deque Output:", dequeSlidingWindow(nums, k));
}

// Run the program
main();
