//{ Driver Code Starts
import java.io.*;
import java.util.*;

class Sorting {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        for (int g = 0; g < t; g++) {
            String[] str = (br.readLine()).trim().split(" ");
            int arr[] = new int[str.length];
            for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
            System.out.println(new Solution().maxWater(arr));
            System.out.println("~");
        }
    }
}
// } Driver Code Ends
// https://www.geeksforgeeks.org/container-with-most-water/
// User function Template for Java
// https://algo.monster/liteproblems/11
class Solution {
    public int maxWater(int arr[]) {
        int left = 0, right = arr.length - 1,res = 0;
        while (left < right) {
            int water = Math.min(arr[left], arr[right]) * (right - left);
            res = Math.max(res, water);
            if (arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }
        return res;
    }
}