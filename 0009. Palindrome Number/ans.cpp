

bool isPalindrome(int x)
{
    int r, temp;
    long sum = 0;
    temp = x;
    while (x > 0)
    {
        r = x % 10;
        sum = (sum * 10) + r;
        x /= 10;
    }

    if (temp == sum)
    {
        return true;
    }
    else
    {
        return false;
    }
}