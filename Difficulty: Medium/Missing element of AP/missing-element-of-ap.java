//{ Driver Code Starts
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(reader.readLine().trim());

        Solution solution = new Solution();
        while (t-- > 0) {
            String input = reader.readLine().trim();
            String[] parts = input.split("\\s+");
            int[] arr = Arrays.stream(parts).mapToInt(Integer::parseInt).toArray();

            System.out.println(solution.findMissing(arr));

            System.out.println("~");
        }
    }
}

// } Driver Code Ends
// User function Template for Java
// self
class Solution {
    public int findMissing(int[] arr) {
        int n=arr.length;
        long d = Math.min(arr[1] - arr[0], arr[2] - arr[1]); // safer to check 2
        long a = arr[0];
        long expectedSum = (n + 1) * (2 * a + n * d) / 2;
        long actualSum = 0;
        for (int i = 0; i < n; i++)
            actualSum += arr[i];
        return (int)(expectedSum - actualSum);
    }
}