class Solution
{
public:
    int myAtoi(string s)
    {
        char *ch = s.data();
        bool negative = false;
        while (*ch != '\0')
        {
            if (*ch == ' ')
            {
                ch++;
                continue;
            }
            else if (*ch == '+')
            {
                ch++;
                break;
            }
            else if (*ch == '-')
            {
                negative = true;
                ch++;
                break;
            }
            else
            {
                break;
            }
        }

        int result = 0;
        if (negative)
        {
            while (*ch <= '9' && *ch >= '0')
            {
                if (result < -214748364)
                {
                    return INT_MIN;
                }
                result *= 10;
                int tmp = (int)(*ch - '0');
                if (result < INT_MIN + tmp)
                {
                    return INT_MIN;
                }
                result -= tmp;
                ch++;
            }
        }
        else
        {
            while (*ch <= '9' && *ch >= '0')
            {
                if (result > 214748364)
                {
                    return INT_MAX;
                }
                result *= 10;
                int tmp = (int)(*ch - '0');
                if (result > INT_MAX - tmp)
                {
                    return INT_MAX;
                }
                result += tmp;
                ch++;
            }
        }
        return result;
    }
};