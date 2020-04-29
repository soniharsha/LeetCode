class Solution {
public:
    
    string longestPalindrome(string s) {
        string out;
        for(int i=s.size();i>=1;i--) {
            bool flag = false;
            for(int j=0;j<s.size();j++) {
                int l = j, r = j+i-1;
                while(l>=0 && r<s.size() && l<=r) {
                    if(s[l]!=s[r]) {
                        break;
                    }
                    l++;
                    r--;
                }
                if(l>r) {
                    flag = true;
                    out = s.substr(j,i);
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return out;
    }
};
