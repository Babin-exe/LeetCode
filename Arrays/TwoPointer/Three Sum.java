class Solution {
    List<List<Integer>> result = new ArrayList<>();

    public void twoSum(int target, int[] nums, int start, int end) {

        int i = start;
        int j = end;

        while (i < j) {

            if (nums[i] + nums[j] > target) {
                j--;

            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {

                while (i < j && nums[i] == nums[i + 1])
                    i++;

                while (i < j && nums[j] == nums[j - 1])
                    j--;

                result.add(Arrays.asList(-target, nums[i], nums[j]));
                i++;
                j--;
            }

        }

    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        for (int i = 0; i < nums.length - 2; i++) {
            if (i != 0 && nums[i] == nums[i - 1])
                continue;

            int n1 = nums[i];
            int target = -n1;
            twoSum(target, nums, i + 1, nums.length - 1);
        }
        return result;
    }
}
