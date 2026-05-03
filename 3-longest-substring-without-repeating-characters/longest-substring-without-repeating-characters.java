class Solution {
    public int lengthOfLongestSubstring(String s) {
        Map<Character, Integer>map = new HashMap<>();
        int ans = 0;
        char arr[] = s.toCharArray();
        int i = 0;
        int j = 0;

        for(; j < arr.length; j++){
            int idx = map.getOrDefault(arr[j], -1);
            if(idx != -1 && idx >= i){
                ans = Math.max(ans, j - i);
               i = idx + 1;
            }
            map.put(arr[j], j);
        }
        return Math.max(ans, j - i);
    }
}