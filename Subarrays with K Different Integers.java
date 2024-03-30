public class Solution {
    public int subarraysWithKDistinct(int[] A, int K) {
        // The answer is the difference between subarrays with at most K distinct
        // and subarrays with at most K-1 distinct.
        return atMostKDistinct(A, K) - atMostKDistinct(A, K - 1);
    }

    private int atMostKDistinct(int[] A, int K) {
        int count = 0;
        int left = 0;
        int[] frequency = new int[A.length + 1]; // Frequency map assuming numbers in A are 1-indexed for simplicity.
        int uniqueCount = 0; // Tracks the number of unique elements in the current window.

        for (int right = 0; right < A.length; right++) {
            // If this is a new element, increment uniqueCount.
            if (frequency[A[right]] == 0) {
                uniqueCount++;
            }
            frequency[A[right]]++;

            // If uniqueCount exceeds K, move the left pointer to reduce it.
            while (uniqueCount > K) {
                frequency[A[left]]--;
                if (frequency[A[left]] == 0) {
                    uniqueCount--;
                }
                left++;
            }

            // Add the number of subarrays ending at 'right' with at most K distinct numbers.
            // The +1 is because every addition of a new character to the right
            // forms 'right - left + 1' new subarrays.
            count += right - left + 1;
        }

        return count;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] A = {1, 2, 1, 2, 3};
        int K = 2;
        System.out.println("Number of subarrays with exactly " + K + " different integers: " + solution.subarraysWithKDistinct(A, K));
    }
}
