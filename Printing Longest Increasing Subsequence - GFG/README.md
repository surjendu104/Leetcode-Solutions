# Printing Longest Increasing Subsequence
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given an integer n and array of integers, returns the Longest Increasing subsequence which is lexicographically smallest corresponding to the indices of the elements.<br>LIS&nbsp; of a given sequence such that all elements of the subsequence are sorted in increasing order. For example, the length of LIS for {10, 22, 9, 33, 21, 50, 41, 60, 80} is 6 and LIS is {10, 22, 33, 50, 60, 80}.&nbsp;</span><br>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Note -&nbsp;</strong>A subsequence <span style="font-family: monospace;">S1</span>&nbsp;is&nbsp;<strong>lexicographically smaller</strong>&nbsp;than a subsequence <span style="font-family: monospace;">S2</span>&nbsp;if in the first position where&nbsp;<code>a</code>&nbsp;and&nbsp;<code>b</code>&nbsp;differ, subsequence&nbsp;<code>a</code>&nbsp;has a letter that appears earlier in the alphabet than the corresponding letter in&nbsp;<code>b</code>. For example , {1, 2, 3, 6, 7} is lexographically smaller than {1, 2, 3, 8, 10} and {1, 2, 3} is lexographically smaller than {1, 2, 3, 1}.</span></p>
<p>&nbsp;</p>
<p><strong><span style="font-size: 18px;">Example 1:</span></strong></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong>
n = 16
arr = [0,8,4,12,2,10,6,14,1,9,5,13,3,11,7,15]
<strong>Output:</strong>
0 4 6 9 13 15 
<strong>Explanation:</strong>
longest Increasing subsequence is 0 4 6 9 13 15  and the length of the longest increasing subsequence is 6.</span></pre>
<p><strong><span style="font-size: 18px;">Example 2:</span></strong></p>
<pre><strong><span style="font-size: 18px;">Input:</span></strong>
<span style="font-size: 18px;">n = 1
arr = [1]
<strong>Output:</strong>
1</span></pre>
<p><span style="font-size: 18px;"><strong>Your Task:</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>longestIncreasingSubsequence()&nbsp;</strong>which takes integer n and array arr&nbsp;and returns the longest increasing subsequence.</span></p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(n<sup>2</sup>)<br><strong>Expected Space Complexity:</strong> O(n)</span></p>
<p><strong><span style="font-size: 18px;">Constraint:</span></strong><br><span style="font-size: 18px;">1 &lt;= n &lt; = 1000<br>1 &lt;= arr[i] &lt;= 50000</span></p>
<p>&nbsp;</p></div>