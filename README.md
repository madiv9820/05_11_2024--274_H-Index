- ## Approach 1:- Sorting

    - ### Problem Intuition
        - The h-index is a metric that measures both the productivity and citation impact of a researcher. Given a list of citations for each of a researcher's papers, the h-index is defined as the maximum value of `h` such that the researcher has published `h` papers that each have at least `h` citations.

    - ### Example of h-Index:
        If a researcher has the following citation counts: `[3, 0, 6, 1, 5]`, their h-index is `3` because:
        - There are `3` papers with at least `3` citations each (`[3, 5, 6]`).
        - Increasing `h` to `4` would require `4` papers with at least `4` citations, which is not satisfied.

    - ### Approach
        1. **Sort the Citations**: First, sort the list of citations in ascending order. This makes it easier to count how many papers meet the threshold for each potential h-index.
        
        2. **Iterate to Find h-Index**: Start from `h_Index = 0` and check if there are at least `h_Index + 1` papers with `h_Index + 1` citations.
            - For a sorted list `citations`, if `citations[len(citations) - 1 - h_Index] > h_Index`, then we can increment `h_Index`.
            - This condition checks if there are enough papers with at least `h_Index` citations from the rightmost end of the sorted list.

        3. **Return h-Index**: The maximum `h_Index` where the condition holds is our final h-index.

    - ### Example Walkthrough
        Let's say `citations = [3, 0, 6, 1, 5]`.

        1. **Sort the Citations**: `[0, 1, 3, 5, 6]`
        2. **Iterate with h_Index**:
            - `h_Index = 0`: `citations[4] = 6`, which is greater than `0`. So, increment `h_Index`.
            - `h_Index = 1`: `citations[3] = 5`, which is greater than `1`. So, increment `h_Index`.
            - `h_Index = 2`: `citations[2] = 3`, which is greater than `2`. So, increment `h_Index`.
            - `h_Index = 3`: `citations[1] = 1`, which is less than `3`. So, we stop here.

        The maximum `h_Index` where the condition holds is `3`, so the h-index for this list is `3`.


    - ### Time Complexity   
        - **Sorting**: Sorting the list takes `O(n log n)`.
        - **Iteration**: Checking the condition in the loop is `O(n)` since we only iterate through the list once.

            Overall, the time complexity is **`O(n log n)`**.

    - ### Space Complexity
        - We only need constant extra space (`O(1)`) if sorting can be done in-place. Otherwise, the space complexity for sorting is `O(n)`.

    - ### Code
        - **Python Solution**
            ```python3 []
            class Solution:
                def hIndex(self, citations: List[int]) -> int:
                    # Initialize h-index counter
                    h_Index = 0
                    
                    # Sort the citations in ascending order
                    citations.sort()

                    # Iterate to find the maximum h-index
                    # h-index is the maximum number where 'h' papers have at least 'h' citations
                    while (h_Index < len(citations) and 
                        citations[len(citations) - 1 - h_Index] > h_Index): 
                        h_Index += 1  # Increment h-index if the condition holds

                    return h_Index  # Return the computed h-index
            ```
        - **C++ Solution**
            ```C++ []
            class Solution {
                public:
                    int hIndex(vector<int> citations) {
                        // Initialize h-index counter
                        int h_Index = 0, n = citations.size();

                        // Sort citations in ascending order
                        sort(citations.begin(), citations.end());

                        // Loop to find the maximum h-index
                        // The h-index is the maximum value where h papers have at least h citations
                        for (; h_Index < n && citations[n - 1 - h_Index] > h_Index; ++h_Index);

                        return h_Index;  // Return the computed h-index
                    }
            };
            ```