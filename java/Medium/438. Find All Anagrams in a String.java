class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        List<Integer> result = new ArrayList<>();
        int[] targetCharacterMap = new int[26];
        for(char c: p.toCharArray()){
            targetCharacterMap[c-'a']++;
        }
        int[] sourceCharacterMap = new int[26];
        // for (char c : s.toCharArray())
        // {
        //     sourceCharacterMap[c - 'a']++;
        // }
        for (int i = 0; i < s.length(); i++)
        {
            sourceCharacterMap[s.charAt(i) - 'a']++;
            if (i >= p.length())
            {
                sourceCharacterMap[s.charAt(i - p.length()) - 'a']--;
            }
            if (i >= p.length() - 1 && isAnagram(sourceCharacterMap, targetCharacterMap))
            {
                result.add(i - p.length() + 1);
            }
        }
        return result;

    }

    boolean isAnagram( int[] sourceCharacterMap, int[] targetCharacterMap){

        for(int i=0;i<targetCharacterMap.length;i++){
            if(sourceCharacterMap[i]!=targetCharacterMap[i])
                return false;
        }
        return true;
    }
}