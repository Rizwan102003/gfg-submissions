//{ Driver Code Starts
// Initial Template for Java

/*package whatever //do not write package name here */

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String[] args) {

        // taking input using Scanner class
        Scanner sc = new Scanner(System.in);

        // taking total count of testcases
        int t = sc.nextInt();

        while (t-- > 0) {
            // taking total number of elements
            int n = sc.nextInt();

            // calling fibonacciNumbers() method
            int[] res = new Solution().fibonacciNumbers(n);

            // printing the elements of the array
            for (int i = 0; i < res.length; i++) System.out.print(res[i] + " ");
            System.out.println();

            System.out.println("~");
        }
    }
}
// } Driver Code Ends
// User function Template for Java
class Solution {
    // Function to return list containing first n fibonacci numbers.
    public static int[] fibonacciNumbers(int n) {
        int f[]=new int[n];
        f[0]=0;
        if(n>1)f[1]=1;
        for(int i=2;i<n;i++)
            f[i]=f[i-1]+f[i-2];
        return f;
    }
}