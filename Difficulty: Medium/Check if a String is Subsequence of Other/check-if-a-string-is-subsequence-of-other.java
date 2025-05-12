//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{

    public static void main (String[] args) throws IOException
    {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = Integer.parseInt(br.readLine().trim());
        while(T-->0)
        {
            String[] S = br.readLine().split(" ");
            String A = S[0];
            String B = S[1];
            Solution ob = new Solution();
            boolean ans = ob.isSubSequence(A,B);
            if(ans)
                System.out.println("True");
            else
                System.out.println("False");
       
System.out.println("~");
}
    }
}
// } Driver Code Ends


// User function Template for Java

class Solution {
    // Function to check if a string is subsequence of other string.
    public static boolean isSubSequence(String A, String B) {
        String s=A,t=B;
        if (s.length() == 0) return true;
        int c=0;
        for(int i=0;i<t.length();i++)
            if (c < s.length() && s.charAt(c) == t.charAt(i)) c++;
        return (c==s.length());
    }
};