/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    let n = nums.length;
    if(n == 1) return true;
    let maxJump = nums[0];
    let i = 1;
    while(maxJump){
        if(i == n-1){
            return true;
        }
        maxJump--;
        maxJump = Math.max(maxJump,nums[i]);
        i++;
    }
    return false;
};