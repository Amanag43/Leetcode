class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();//child
        int m = s.size();//cookie
        int l=0;// child 
        int r=0;//cookie
        sort(g.begin(),g.end());
        sort(s.begin(), s.end());
        while(l<n && r<m){
         if(g[l] <= s[r])
         {
            l++;
         }
         r++;
        }
        return l;
    }
};