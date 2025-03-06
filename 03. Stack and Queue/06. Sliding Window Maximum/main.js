function maxSlidingWindow(nums, k) {
    let dq = [];
    let result = [];

    for (let i = 0; i < nums.length; i++) {
        if (dq.length && dq[0] === i - k) 
            dq.shift();

        while (dq.length && nums[dq[dq.length - 1]] < nums[i]) 
            dq.pop();

        dq.push(i);

        if (i >= k - 1) 
            result.push(nums[dq[0]]);
    }
    return result;
}

function main() {
    let nums = [1, 3, -1, -3, 5, 3, 6, 7];
    let k = 3;
    console.log(maxSlidingWindow(nums, k));
}

main();
