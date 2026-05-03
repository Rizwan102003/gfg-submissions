class Solution {
    public ArrayList<Integer> prefSum(int[] arr) {
        int s=0;
        ArrayList<Integer> ans=new ArrayList<>();
        for(int i:arr){
            s+=i;
            ans.add(s);
        }
        return ans;
    }
}