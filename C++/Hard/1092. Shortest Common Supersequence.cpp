class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.length();
        int n = str2.length();
        int t[m+1][n+1];

        // Find the LCS length
        // Intitialisation
        for(int i=0; i<m+1; i++){
            for(int j=0; j<n+1; j++){
                if(i==0 || j==0){
                    t[i][j]=0;
                }
            }
        }

        // DP
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                if(str1[i-1] == str2[j-1]){
                    t[i][j] = 1 + t[i-1][j-1];
                }
                else
                {
                    t[i][j] = max(t[i-1][j], t[i][j-1]);
                }
            }
        }

        // find the LCS
        int i=m;
        int j=n;
        string lcs = "";

        while(i>0 && j>0){
            if(str1[i-1] == str2[j-1]){
                lcs = lcs + str1[i-1];
                i--;
                j--;
            }
            else{
                if(t[i-1][j]>t[i][j-1]){
                    lcs = lcs + str1[i-1];
                    i--;
                }    
                else{
                    lcs = lcs + str2[j-1];
                    j--;
                }
            }
        }

        // remaining characters
        while(i>0){
            lcs = lcs + str1[i-1];
            i--;
        }
        while(j>0){
            lcs = lcs + str2[j-1];
            j--;
        }
        reverse(lcs.begin(), lcs.end());
        return lcs;
    }
};
