# Level of Nodes
## Medium
<div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">Given a Undirected Graph with V vertices and E edges, </span><span style="font-size: 18px;">Find the level of node X. if X does not exist in the graph then print -1.<br><strong>Note:&nbsp;</strong>Traverse the graph starting from vertex 0.<br>&nbsp; </span></p>
<p><span style="font-size: 18px;"><strong>Example 1:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701248/Web/Other/afb73eb4-8c50-4e77-b161-e3fd4d35939c_1685086954.png" alt="">
<span style="font-size: 18px;"><strong>X</strong> = 4</span>
<span style="font-size: 18px;"><strong>Output:</strong>
2
<strong>Explanation</strong>:
</span><img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701248/Web/Other/ef6cced7-96f1-46e4-bf8b-4fc091c04ee7_1685086954.png" alt="">
<span style="font-size: 18px;">We can clearly see that Node 4 lies at Level 2.</span>
</pre>
<p><span style="font-size: 18px;"><strong>Example 2:</strong></span></p>
<pre><span style="font-size: 18px;"><strong>Input:</strong></span>
<img src="https://media.geeksforgeeks.org/img-practice/PROD/addEditProblem/701248/Web/Other/79ea2467-b795-4328-a0aa-d2679f671e55_1685086954.png" alt="">
<span style="font-size: 18px;"><strong>X</strong> = 5</span>
<span style="font-size: 18px;"><strong>Output:</strong>
-1
<strong>Explanation</strong>:
Node 5 isn't present in the Graph, so the
Output is -1.</span>
</pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your task:</strong></span><br><span style="font-size: 18px;">You dont need to read input or print anything. Your task is to complete the function <strong>nodeLevel()</strong>&nbsp;which takes two integers V and X denoting the number of vertices and the node, and another adjacency list adj as input parameters and returns the level of Node X. If node X isn't present it returns -1.</span></p>
<p><br><span style="font-size: 18px;"><strong>Expected Time Complexity:&nbsp;</strong>O(V + E)<br><strong>Expected Auxiliary Space:&nbsp;</strong>O(V)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraints:</strong><br>2 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> V </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> 10<sup>4</sup><br>1 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> E </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> (N*(N-1))/2<br>0 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;">u, v &lt; V</span><br><span style="font-size: 18px;">1 </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> X </span> <span style="font-size: 18px;">≤</span> <span style="font-size: 18px;"> 10<sup>4</sup><br>Graph doesn't contain multiple edges and self loops.</span></p></div>