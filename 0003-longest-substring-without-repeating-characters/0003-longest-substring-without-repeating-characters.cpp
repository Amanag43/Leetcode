class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int>mpp;
        int n = s.length();
        int l = 0;
            int r = 0;
            int MaxLen=0;
        int cnt =0;
            while(r<n)
            {
                if (mpp.find(s[r]) != mpp.end())
                {
                    if(mpp[s[r]]>=l){
                l = mpp[s[r]]+1;
                    }
            }
            int len = r-l+1;
            MaxLen = max(MaxLen, len);
            mpp[s[r]]=r;
            r++;
        }
        return MaxLen;
    }
};