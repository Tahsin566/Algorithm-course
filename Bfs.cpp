#include<iostream>
#include<vector>
#include<queue>
#define maxn 1000

using namespace std;

bool vis[maxn];
vector<int>adj[maxn];
queue<int>q;
int lev[maxn];
int par[maxn];

void bfs(int node)
{
    if(!vis[node])
    {
        lev[node]=0;
        par[node]=node;
        q.push(node);
        vis[node]=true;
        cout<<"\nThe required bfs traversal is"<<endl;
        //By printing fr variable after every change gives us the bfs traversal
        while(!q.empty())
        {
            int fr=q.front();
            cout<<fr<<" ";
            q.pop();
            for(int i=0; i<adj[fr].size(); ++i)
            {
                int v= adj[fr][i];
                if(!vis[v])
                {
                    lev[v]=lev[fr]+1;
                    par[v]=fr;
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
    }
    cout<<endl<<endl;
}
int main()
{
    int n,e,node;
    cin>>n>>e;
    for(int i=0; i<e; ++i)
    {
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int d;
    cin>>node>>d;
    bfs(node);
    cout<<"The level of "<<d<<" is "<<lev[d]<<endl;


    //The required bfs path to a destination node from parent node

    cout<<"\n\nThe path from source to destination is"<<endl;
    int now=d;
    cout<<now<<" ";
    while(now!=node){
        now=par[now];
        cout<<now<<" ";
    }
    cout<<endl;

    

    return 0;
}