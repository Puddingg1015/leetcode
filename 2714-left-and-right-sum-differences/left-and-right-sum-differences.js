/**
 * @param {number[]} nums
 * @return {number[]}
 */
var leftRightDifference = function(nums) {
    var leftSum = 0;
    var rightSum = 0;
    for (var i = 0; i < nums.length; i++) rightSum += nums[i];
    const answer = new Array(nums.length);
    for (var i = 0; i < nums.length; i++) {
        rightSum -= nums[i];
        answer[i] = Math.abs(leftSum - rightSum);
        leftSum += nums[i];
    }
    return answer;
};