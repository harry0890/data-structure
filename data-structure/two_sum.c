
// Time Complexity = O(n^2)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {

    int n = numsSize;
    int* result = NULL;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            
            if(target == nums[i] + nums[j]) {
                result = (int *)malloc(sizeof(int) * 2);
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }
    return result;
}
