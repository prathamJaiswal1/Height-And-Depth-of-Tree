#include<bits/stdc++.h>
using namespace std;
vector<int>depth,height;
void dfs(int node,int par,vector<int>adj[]){
      for(auto child:adj[node]){
         
         if(child != par){
            depth[child]=1+depth[node];
            dfs(child,node,adj);
            height[node]=max(height[node],1+height[child]);
         }
         
      }
}
void solve(){
    int n,e;cin>>n>>e;
    depth.resize(n+1,0);
    height.resize(n+1,0);
    vector<int>adj[n+1];
    while(e--){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0,adj);
    for(auto i:depth){
        cout<<i<<" ";
    }
    cout<<endl;
    for(auto i:height){
        cout<<i<<" ";
    }
}
int main(){
    solve();
    return 0;
}