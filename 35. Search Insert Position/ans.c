

int searchInsert(int *nums, int numsSize, int target)
{
    if (numsSize > 0 && target < nums[0])
        return 0;
    for (int i = 0; i < numsSize; i++)
        if (nums[i] >= target)
            return i;
    return numsSize;
}