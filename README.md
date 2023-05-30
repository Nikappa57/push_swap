<h1 align="center">Push Swap [42 School]</h1>

<p align="center">
	<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cld6lomfp00250fl5aqiuznp2/project/3099374" alt="lgaudino's 42 push_swap Score" /></a>
</p>

<p align="center">
	<a href="https://github.com/JaeSeoKim/badge42"><img src="https://badge42.vercel.app/api/v2/cld6lomfp00250fl5aqiuznp2/stats?cursusId=21&coalitionId=124" alt="lgaudino's 42 stats" /></a>
</p>

<p align="center">Summary</p>

<p align="center">
	<i>
	This project will make you sort data on a stack, with a limited set of instructions, using
	the lowest possible number of actions. <br>To succeed you’ll have to manipulate various
	types of algorithms and choose the most appropriate solution (out of many) for an
	optimized data sorting.
</i>
</p>

<hr>

<p align="center">
	<a href="#subject">Subject</a>
	·
	<a href="#how">How?</a>
	·
	<a href="#useful-links">Useful links</a>
	·
	<a href="#utils">Utils</a>
</p>

## Subject

<p>
	You have 2 stacks, A and B.
	Stack A contains a random numbers, Stack B is empty.
	You have to sort Stack A with the following moves:
</p>

<table>
	<tr>
		<th>Type</th>
		<th>Move</th>
		<th>Description</th>
	</tr>
	<tr>
		<td rowspan="3">Swap</td>
		<td>sa</td>
		<td>Swap the first 2 elements at the top of stack a.</td>
	</tr>
	<tr>
		<td>sb</td>
		<td>Swap the first 2 elements at the top of stack b.</td>
	</tr>
	<tr>
		<td>ss</td>
		<td>sa and sb at the same time.</td>
	</tr>
	<tr>
		<td rowspan="2">Push</td>
		<td>pa</td>
		<td>Take the first element at the top of b and put it at the top of a.</td>
	</tr>
	<tr>
		<td>pb</td>
		<td>Take the first element at the top of a and put it at the top of b.</td>
	</tr>
	<tr>
		<td rowspan="3">Rotate</td>
		<td>ra</td>
		<td>Shift up all elements of stack a by 1. The first element becomes the last one.</td>
	</tr>
	<tr>
		<td>rb</td>
		<td>Shift up all elements of stack b by 1. The first element becomes the last one.</td>
	</tr>
	<tr>
		<td>rr</td>
		<td>ra and rb at the same time.</td>
	</tr>
	<tr>
		<td rowspan="3">
		Reverse Rotate
		</td>
		<td>rra</td>
		<td>Shift down all elements of stack a by 1. The last element becomes the first one.</td>
	</tr>
	<tr>
		<td>rrb</td>
		<td>Shift down all elements of stack b by 1. The last element becomes the first one.</td>
	</tr>
	<tr>
		<td>rrr</td>
		<td>rra and rrb at the same time.</td>
	</tr>
</table>

<p>
	At the end, Stack A must be sorted and Stack B must be empty.
</p>

## How?

<h3> 3 numbers </h3>
<p> Just find the 6 possible permutations and find the best way to order them</p>

<h3> 5 numbers </h3>
<p> Push 2 elements to B, sorts A with the algorithm above and after all that push neatly from B to A the remaining 2 numbers.</p>

<h3> 100 / 500 numbers </h3>
<p> Find the LIS (Longest Increasing Subsequence) of A. Leave the LIS on A and push the rest on B. Then, push the elements of B to A in the correct order. </p>

<p> 
For push the elements from A to B, divide the stack in some chunks and push them in order to have all the chunks divided.
</p>

<p> 
For push elements from one stack to another, you have to find the best way to do it. Don't forget about possible combo moves (ss, rr, rrr) that can help you to optimize the number of moves. 

Check ```ft_push_to_b.c``` and ```ft_push_to_a.c``` for see my solution.
</p>

<img src="sort.gif" alt="sort">
<p><i><a href="https://github.com/o-reo/push_swap_visualizer">Visualizer</a></i></p>

## My optimizations

<lu>
	<li>
	Use a linked list instead of an array.
	</li>
	<li>
	Use an "async" print function to print moves.
	Keep the last move in a static variable and then compare it with the new one.
	So you can avoid to print moves like <code>sa sa</code>, <code>ra rra</code> or <code>ra rb</code> (and so on).
	Check <code>ft_print_utils.c</code> for see my implementation.
	</li>
	<li>
	Simplify the stack: Why should you order
	<code>26384, -99, 0, 42</code> instead of <code>3, 0, 1, 2</code>?
	</li>
</lu>

## Useful links

<ul>
	<li>
	<a href="https://www.geeksforgeeks.org/longest-increasing-subsequence-dp-3/">Longest Increasing Subsequence (LIS)</a>
	</li>
	<li>
	<a href="https://codeforces.com/blog/entry/97703">Weird sorts #1 — LIS sort</a>
	</li>
	<li>
	<a href="https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a">Chunks</a>
	</li>
	<li>
	<a href="https://github.com/sisittu99/push_swap/blob/master/README_EN.md">LIS in push_swap</a>
	</li>
	<li>
	<a href="https://github.com/LeoFu9487/push_swap_tester">Tester</a>
	</li>
	<li>
	<a href="https://github.com/o-reo/push_swap_visualizer">Visualizer</a>
	</li>
</ul>

## Utils

<p>
	You can use the <code>utils/check_moves.py</code> script to check the useless moves.
</p>
<p>
Save moves in a file <code>./push_swap ... > file.txt </code> and then run <code>python3 check_moves.py path/file.txt</code>.
</p>
