class Solution {
public:
    int M = 1000000007;
    
    int numberOfArrays(string s, int k) {
        int dp[s.size()];
        if(s[0]-'0'<=k){
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }
        for(int i=1;i<s.size();i++) {
            int count = 0;
            int val = 0,mul = 1;
            for(int l=1;l<=9 && i-l+1>=0;l++) {
                int num = s[i-l+1] - '0';
                val = num*mul + val;
                mul*=10;
                if(i-l>=0&&s[i-l+1]!='0'&&val<=k) {
                    count=(count+dp[i-l])%M;
                }
                if(i-l<0 && val<=k){
                    count= (count+1)%M;
                }
            }
            if(count<0){
                count+=M;
            }
            dp[i] = count;
        }
        
        return dp[s.size()-1];
    }
};
