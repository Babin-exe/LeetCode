 class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int start = 0;
        int end = numbers.length - 1;
        while (start <= end) {
            if (numbers[start] + numbers[end] == target) {
                return new int[] { start + 1, end + 1 };
            } else if (numbers[start] + numbers[end] > target) {
                end--;
            } else {
                start++;
            }
        }
        return new int[] {};
    }
}
//We add the start and end value to check if the sum is equals to the target or not is yes then return the index , 
// but if the sum we got is less that the target required that means we need to go the the right side of the array 
// to find our sum, and we know the array is sorted so for sure going right increase the sum
//similarly if we got a sum that is greater than the target that means we need to go to the left side of the array 
//to find a smaller sum 



//and thats it for the problem 



// Time Complexity: O(n)
// We scan the array from both ends using two pointers, moving one pointer at a time until we find the target pair.

// Space Complexity: O(1)
// No extra space is used except for a constant-sized output array.
 
