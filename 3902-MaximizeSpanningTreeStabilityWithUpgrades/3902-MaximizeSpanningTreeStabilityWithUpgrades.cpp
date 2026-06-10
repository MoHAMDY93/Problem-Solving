// Last updated: 6/10/2026, 7:11:22 PM
struct DSU {
    vector<int> p, r;
    DSU(int n){
        p.resize(n);
        r.resize(n);
        iota(p.begin(), p.end(), 0);
    }
    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }
    bool unite(int a,int b){
        a=find(a), b=find(b);
        if(a==b) return false;
        if(r[a]<r[b]) swap(a,b);
        p[b]=a;
        if(r[a]==r[b]) r[a]++;
        return true;
    }
};

class Solution {
public:
    bool check(int n, vector<vector<int>>& edges, int k, int X){
        DSU dsu(n);
        int used=0, upgrades=0;

        vector<vector<int>> needUpgrade;

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];

            if(must){
                if(s<X) return false;
                if(!dsu.unite(u,v)) return false;
                used++;
            }
        }

        for(auto &e:edges){
            int u=e[0],v=e[1],s=e[2],must=e[3];
            if(must) continue;

            if(s>=X){
                if(dsu.unite(u,v)) used++;
            }
            else if(2*s>=X){
                needUpgrade.push_back(e);
            }
        }

        for(auto &e:needUpgrade){
            if(upgrades==k) break;
            if(dsu.unite(e[0],e[1])){
                used++;
                upgrades++;
            }
        }

        return used==n-1;
    }

    int maxStability(int n, vector<vector<int>>& edges, int k) {

        int l=0,r=2e5,ans=-1;

        while(l<=r){
            int mid=(l+r)/2;

            if(check(n,edges,k,mid)){
                ans=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }

        return ans;
    }
};