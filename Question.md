# [274. H-Index](https://leetcode.com/problems/h-index?envType=study-plan-v2&envId=top-interview-150)

__Type:__ Medium <br>
__Topics:__ Array, Sorting, Counting Sort
__Companies:__ Amazon, Bloomberg, Google, Microsoft, Meta, Adobe, Apple, Uber, Nvidia, Yahoo, ByteDance, Yandex, Zoox <br>
<hr>

Given an array of integers `citations` where `citations[i]` is the number of citations a researcher received for their <code>i<sup>th</sup></code> paper, return _the researcher's h-index._

According to the [definition of h-index on Wikipedia](https://en.wikipedia.org/wiki/H-index): The h-index is defined as the maximum value of `h` such that the given researcher has published at least `h` papers that have each been cited at least `h` times.
<hr>

### Examples:

- __Example 1:__ <br>
__Input:__ citations = [3,0,6,1,5] <br>
__Output:__ 3 <br>
__Explanation:__ [3,0,6,1,5] means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. <br>
Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, their h-index is 3.

- __Example 2:__ <br>
__Input:__ citations = [1,3,1] <br>
__Output:__ 1

<hr>

### Constraints:
- `n == citations.length`
- `1 <= n <= 5000`
- `0 <= citations[i] <= 1000`

<hr>

### Hints:
- An easy approach is to sort the array first.
- What are the possible values of h-index?
- A faster approach is to use extra space.