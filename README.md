- ## Approach 2: Counting
    - ### Intuition
        - The h-index is a metric used to measure a researcher's productivity and citation impact. Given a list of citations for each paper, the h-index is defined as the maximum value `h` such that the researcher has published `h` papers, each cited at least `h` times.

    - ### Example of h-Index:
        If a researcher has the following citation counts: `[3, 0, 6, 1, 5]`, their h-index is `3` because:
        - There are `3` papers with at least `3` citations each (`[3, 5, 6]`).
        - Increasing `h` to `4` would require `4` papers with at least `4` citations, which is not satisfied.

    - ### Approach
        1. **Count Citations with a Frequency Array**: 
            - First, create an array `no_of_Papers_For_Each_Citation` of size `n + 1` (where `n` is the number of papers). This array will count the number of papers with each possible citation count.
            - If a paper has more than `n` citations, count it in the last index (`no_of_Papers_For_Each_Citation[n]`) since citations greater than `n` don't affect the h-index calculation.

        2. **Calculate h-Index**:
            - Start with `h_Index = n`, which is the maximum possible h-index.
            - Sum the number of papers with `h_Index` or more citations.
            - Decrement `h_Index` until the cumulative number of papers with `h_Index` or more citations is at least `h_Index`. This meets the h-index condition.

        3. **Return the Result**:
            - Once we find the highest possible `h_Index` where the condition holds, return it as the h-index.

    - ### Example Walkthrough
        Let’s take the citation list: `citations = [3, 0, 6, 1, 5]`.

        1. **Initialize Frequency Array**: 
            - Let `n = 5` (number of papers).
            - We initialize an array `no_of_Papers_For_Each_Citation` with size `6` (indices `0` to `5`), all initialized to `0`.

        2. **Populate Frequency Array**:
            - For each citation count in `citations`, update the array as follows:
                - Citation `3`: Increment `no_of_Papers_For_Each_Citation[3]`.
                - Citation `0`: Increment `no_of_Papers_For_Each_Citation[0]`.
                - Citation `6`: Since `6 > 5`, increment `no_of_Papers_For_Each_Citation[5]`.
                - Citation `1`: Increment `no_of_Papers_For_Each_Citation[1]`.
                - Citation `5`: Increment `no_of_Papers_For_Each_Citation[5]`.
        
            - The final array becomes: `[1, 1, 0, 1, 0, 2]`.

        3. **Calculate h-Index**:
            - Start with `h_Index = 5` and `sum_of_All_Citations = no_of_Papers_For_Each_Citation[5] = 2`.
            - Since `sum_of_All_Citations (2) < h_Index (5)`, decrement `h_Index` to `4` and add `no_of_Papers_For_Each_Citation[4]` to `sum_of_All_Citations`.
            - Continue this process until `h_Index = 3`, where `sum_of_All_Citations (3) >= h_Index (3)`.

        The maximum `h_Index` that satisfies the condition is `3`, so the h-index for this list is `3`.


    - ### Time Complexity
        - **Counting Citations**: Populating the frequency array takes `O(n)` time since we iterate over the `citations` list once.
        - **Calculating h-Index**: The loop to calculate the h-index also takes `O(n)` time.

        Overall, the time complexity is **`O(n)`**.

    - ### Space Complexity
        - We use an additional array `no_of_Papers_For_Each_Citation` of size `n + 1`. Thus, the space complexity is **`O(n)`**.

    - ### Code
        - **Python Solution**
            ```python3 []
            class Solution:
                def hIndex(self, citations: List[int]) -> int:
                    # Get the number of papers
                    n = len(citations)

                    # Initialize an array to count the number of papers with each possible citation count
                    # This array will have size n + 1, where index i stores the count of papers with i citations
                    # If a paper has more than n citations, it is counted in the last index (no_of_Papers_For_Citations[n])
                    no_of_Papers_For_Citation = [0] * (n + 1)

                    # Populate the citation counts array
                    for citation in citations:
                        # For citations greater than n, count them at index n
                        no_of_Papers_For_Citation[min(n, citation)] += 1

                    # Start with the highest possible h-index (n) and calculate the sum of papers with that many or more citations
                    h_Index = n
                    sum_of_All_Citations = no_of_Papers_For_Citation[h_Index]

                    # Reduce h_Index while the sum of papers with citations >= h_Index is less than h_Index
                    while h_Index > sum_of_All_Citations:
                        h_Index -= 1
                        sum_of_All_Citations += no_of_Papers_For_Citation[h_Index]

                    # Return the computed h-index
                    return h_Index
            ```
        - **C++ Solution**
            ```C++ []
            class Solution {
                public:
                    int hIndex(vector<int> citations) {
                        // Get the number of papers
                        int n = citations.size();
                        
                        // Initialize an array to count the number of papers with each possible citation count
                        // The array has size n + 1, where index i stores the count of papers with i citations
                        // If a paper has more than n citations, it is counted in the last index (no_of_Papers_For_Each_Citation[n])
                        vector<int> no_of_Papers_For_Each_Citation(n + 1, 0);

                        // Populate the citation counts array
                        for (const int& citation : citations)
                            ++no_of_Papers_For_Each_Citation[min(citation, n)];

                        // Start with the highest possible h-index (n) and calculate the sum of papers with that many or more citations
                        int h_Index = n;
                        int sum_of_All_Citations = no_of_Papers_For_Each_Citation[h_Index];

                        // Reduce h_Index while the sum of papers with citations >= h_Index is less than h_Index
                        for (; h_Index > sum_of_All_Citations; 
                            sum_of_All_Citations += no_of_Papers_For_Each_Citation[h_Index])
                            --h_Index;

                        // Return the computed h-index
                        return h_Index;
                    }
            };
            ```