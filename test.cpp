
#include<bits/stdc++.h>
using namespace std;

#define INF 10000

vector<int>arr[1000];

vector<pair<int,int>>V[1000];

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int par[1000];
int lev[1000];
int vis[1000];
int cost[1000];

queue<int>q;

stack<int>s;

int minedit(string,string);
int Lis(int num[],int n);

void Bfs(int node);
void Dfs(int node);
void Dijkstra(int source);

int main(){


    memset(V,0,sizeof(V));

    int node,edge;
    cin>>node>>edge;

    for(int i = 0;i<edge;i++){

        int u,v,weight;
        cin>>u>>v>>weight;
        V[u].push_back({v,weight});
        V[v].push_back({u,weight});
    
    }

    int start,dest;
    cin>>start>>dest;
    Dijkstra(start);
    
    int now = dest;

    vector<int>vv;
    vv.push_back(now);

    while(now!=par[now]){
        now = par[now];
        vv.push_back(now);
    }
    reverse(vv.begin(),vv.end());

    cout<<"The path from source to destination : ";
    for(int i = 0;i<vv.size();i++){
        cout<<vv[i];
        if(i!=vv.size()-1){
            cout<<"-->";
        }
    }

    cout<<"\n\nThe minimum cost to travel from "<<start<<" to "<<dest<<" is "<<cost[dest]<<endl<<endl;

}

void Dijkstra(int source){

    for(int i = 0;i<1000;i++){
        
        cost[i] = INF;

    }
    par[source]=source;
    cost[source]=0;

    pq.push({0,source});

    while(!pq.empty()){

        int fr = pq.top().second;
        pq.pop();

        for(int i = 0;i< V[fr].size();i++){

            int v = V[fr][i].first;
            int weight = V[fr][i].second;

            if(cost[fr]+weight < cost[v]){
                cost[v]=cost[fr]+weight;
                par[v]=fr;
                pq.push({cost[v],v});
            }


        }

    }
}



void Bfs(int node){

    if(!vis[node]){

        par[node] = node;
        lev[node] = 0;
        vis[node] = true;
        q.push(node);

        while(!q.empty()){
            int fr = q.front();
            cout<<fr<<" ";
            q.pop();
            for(int i = 0;i < arr[fr].size();i++){

                int v = arr[fr][i];

                if(!vis[v]){
                    par[v]=fr;
                    lev[v]=lev[fr]+1;
                    vis[v]=true;
                    q.push(v);
                }

            }
        }

    }

}
void Dfs(int node){

    if(!vis[node]){

        par[node] = node;
        lev[node] = 0;
        vis[node] = true;
        s.push(node);

        while(!s.empty()){
            int fr = s.top();
            cout<<fr<<" ";
            s.pop();
            for(int i = 0;i < arr[fr].size();i++){

                int v = arr[fr][i];

                if(!vis[v]){
                    par[v]=fr;
                    lev[v]=lev[fr]+1;
                    vis[v]=true;
                    s.push(v);
                }

            }
        }

    }

}

int Lis(int num[],int n){


    int dp[n];

    for (int i = 0; i < n; i++)
    {
        dp[i] = 1;
        
    }

    for(int i = 1;i<n;i++){
        for(int j = 0;j<i;j++){

            if(num[j] < num[i]){

                dp[i] = max(dp[i],dp[j]+1);

            }
        }
    }

    int max = 0,a[n];
    cout<<"\nThe required lis : ";
    for(int i  = 0;i<n;i++){

        if(dp[i]>max){
            max=dp[i];
            a[i]=max;
            if(a[i]==max){
                cout<<num[i];
                if(i!=n-1){
                cout<<" , ";
                }
            }
        }

    }

    return dp[n-1];
    
}


int minedit(string s1,string s2){

    int n = s2.size();
    int m = s1.size();

    int dp[n+1][m+1];

    for(int i = 0;i<=n;++i){
        for(int j = 0;j <= m;++j){

            if(i==0){
                dp[i][j] = j;
            }
            else if(j==0){
                dp[i][j] = i;
            }
            else if(s2[i-1]==s1[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1]);
            }
        }
    }

    int i = n,j = m;

    while(i>0 && j>0){

        if(s2[i-1]==s1[j-1]){
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j-1]+1){
            
            cout<<"Replace "<<s1[j-1]<<" with "<<s2[i-1]<<endl;
            // cout<<s2[i-1];
            i--;
            j--;
        }
        else if(dp[i][j] == dp[i-1][j]+1){
            i--;
            cout<<"Add "<<s2[i-1]<<endl;
        }
        else if(dp[i][j] == dp[i][j-1]+1){
            cout<<"Delete "<<s1[j-1]<<endl;
            j--;
        }
    }

    return dp[n][m];
}
