// Last updated: 6/10/2026, 7:11:17 PM
class Solution {
public:

    vector<vector<int>> gen(vector<int> a) //returns all nbrs of a
    {
        int n = a.size();
        vector<vector<int>> ans;
        
        for(int l=0;l<n;l++)
            {
                for(int r=l;r<n;r++)
                    {
                        //valid (r,l) we need to cut from a
                        vector<int> cutpiece(a.begin()+l,a.begin()+r+1);
                        vector<int> vec;
                        for(int i=0;i<n;i++)
                            {
                                if(i<l || i>r) //remaining array before our given l and r
                                {
                                    vec.push_back(a[i]);
                                }
                            }

                        for(int j=0;j<=vec.size();j++)
                            {
                                vector<int> fnal;
                                fnal.insert(fnal.end(),vec.begin(),vec.begin()+j);
                                fnal.insert(fnal.end(),cutpiece.begin(),cutpiece.end());
                                fnal.insert(fnal.end(),vec.begin()+j,vec.end());
                                if(fnal!=a) ans.push_back(fnal);
                            }
                    }
            }
        return ans;
    }
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {

        int ans=0;
        queue<pair<vector<int>,int>> q;
        
        q.push({nums1,ans});
        map<vector<int>,int> vis;
        
        while(!q.empty())
            {
                auto top = q.front(); q.pop();
                auto topvec = top.first; int ansval = top.second;
                //cout <<"fronting top "; printvec(topvec);
                
                vis[topvec]++;
                if(topvec==nums2){
                    return ansval;   //return answer here
                }

                for(auto it: gen(topvec))
                    {
                        if(!vis[it]){
                            //cout <<"pushing "; printvec(it);
                            q.push({it,ansval+1});
                            vis[it]++;
                        }
                    }
            }
        return 0;
        
    }
};