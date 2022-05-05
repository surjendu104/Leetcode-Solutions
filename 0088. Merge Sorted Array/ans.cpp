class Solution
{
public:
    // two pointer approach
    void merge(vector<int> &a, int m, vector<int> &b, int n)
    {
        //         a.size()=m+n;
        //         sort(a,a+m);
        //         sort(b,b+n);

        //         marge(a,a+m,b,b+n,a);
        //         cout<<a<<endl;

        int i = m - 1;
        int j = n - 1;
        int k = (m + n - 1);
        while (i >= 0 && j >= 0)
        {
            if (a[i] > b[j])
            {
                a[k--] = a[i--];
            }
            else
            {
                a[k--] = b[j--];
            }
        }
        while (i >= 0)
        {
            a[k--] = a[i--];
        }
        while (j >= 0)
        {
            a[k--] = b[j--];
        }
    }
};