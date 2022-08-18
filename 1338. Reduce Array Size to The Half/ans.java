import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collection;
import java.util.Collections;

class Solution {
    public static void reverse(int[] array) {
        int n = array.length;
        for (int i = 0; i < n / 2; i++) {
            int temp = array[i];
            array[i] = array[n - i - 1];
            array[n - i - 1] = temp;
        }
    }

    public int minSetSize(int[] arr) {
        int n = arr.length;
        int c = 0;
        int[] freq = new int[100005];

        for (int i = 0; i < n; i++)
            freq[arr[i]]++;

        Arrays.sort(freq);
        reverse(freq);
        int ans = 0;
        for (int i = 0; i < n && c < n / 2; i++) {
            c += freq[i];
            ans++;
        }

        return ans;
    }
}