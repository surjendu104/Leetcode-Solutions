
int max(int a, int b)
{
    return (a > b) ? a : b;
}

int maxSubArray(int *a, int n)
{
    int sum = 0, max_num = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        max_num = max(sum, max_num);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return max_num;
}