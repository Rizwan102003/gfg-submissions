class Solution {
    public boolean validgroup(int[] arr, int k) {
        int n=arr.length;
        if((n%k)!=0) return false;
        TreeMap<Integer, Integer> freq = new TreeMap<>();
        for (int num : arr) {
            freq.put(num, freq.getOrDefault(num, 0) + 1);
        }
        while (!freq.isEmpty()) {
            int first = freq.firstKey();
            for (int i = 0; i < k; i++) {
                int current = first + i;
                if (!freq.containsKey(current)) return false;
                freq.put(current, freq.get(current) - 1);
                if (freq.get(current) == 0) {
                    freq.remove(current);
                }
            }
        }
        return true;
    }
}