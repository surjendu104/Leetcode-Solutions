class Solution {
    public boolean increasingTriplet(int[] arr) {
        int n = arr.length;

		int max = n - 1;
		int min = 0;
		int i;

		int[] smaller = new int[n];

		smaller[0] = -1;
		for (i = 1; i < n; i++) {
			if (arr[i] <= arr[min]) {
				min = i;
				smaller[i] = -1;
			}
			else
				smaller[i] = min;
		}
		int[] greater = new int[n];

		greater[n - 1] = -1;
		for (i = n - 2; i >= 0; i--) {
			if (arr[i] >= arr[max]) {
				max = i;
				greater[i] = -1;
			}
			else
				greater[i] = max;
		}

		for (i = 0; i < n; i++) {
			if (smaller[i] != -1 && greater[i] != -1) {
				return true;
			}
		}
        return false;
    }
}