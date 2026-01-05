class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        bool zero=0;
        long long ans=0;
        int negcount=0;
        int mini=INT_MAX;
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0)
                negcount++;
                mini=min(mini,abs(matrix[i][j]));
                ans+=abs(matrix[i][j]);
            }
        }
        cout<<mini<<endl;
        if(negcount%2!=0)
        ans-=2*mini;
        return ans;
    }
};