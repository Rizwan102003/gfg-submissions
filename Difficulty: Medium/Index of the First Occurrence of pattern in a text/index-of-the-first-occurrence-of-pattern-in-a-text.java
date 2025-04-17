//{ Driver Code Starts
// Initial Template for Java

import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            String text = sc.next();
            String pat = sc.next();
            Solution obj = new Solution();
            int res = obj.findMatching(text, pat);
            System.out.println(res);
        
System.out.println("~");
}
    }
}
// } Driver Code Ends
// User function Template for Java
class Solution {
    public int findMatching(String text, String pat) {
        int m=text.length();
        int n=pat.length();
        for(int i=0;i<m-n+1;i++){
            String s=text.substring(i,i+n);
            if(s.equals(pat))return i;
        }
        return -1;
    }
}