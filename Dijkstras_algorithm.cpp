#include<bits/stdc++.h>
using namespace std;
#define INF 100000
vector<pair<int,int>>adj[1000];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

int cost[1000];
int parent[1000];
void dijkstra(int source)
{

    //memset(cost,999,sizeof(cost));
    //instead of memset we can use loop
    for(int i=0; i<1000; i++)
    {
        cost[i]=INF;
    }
    cost[source]=0;
    parent[source]=source;

    pq.push({0,source});

    while(!pq.empty())
    {
        int fr=pq.top().second;
        pq.pop();
        //int v, weight;
        for(int i=0; i<adj[fr].size(); i++)
        {
            int v=adj[fr][i].first;
            int weight=adj[fr][i].second;
            if(cost[fr]+weight<cost[v])  //if cost is less than previous cost
            {
                cost[v]=cost[fr]+weight;
                parent[v]=fr;
                pq.push({cost[v], v});
            }
        }

    }


}

int main()
{
    memset(adj,0,sizeof(adj));

    int node, edge;
    cin>>node>>edge;
//1 2 5
//1 3 2
    int u,v,weight;
    for(int i=0; i<
    edge; i++)
    {
        cin>>u>>v>>weight;
        adj[u].push_back({v,weight});
        adj[v].push_back({u,weight});
        //adj[u].push_back(make_pair(v,weight);
    }
    int start, dest;
    cin>>start;
    cin>>dest;
    dijkstra(start);

    cout<<"Total Cost to reach form node "<<start<<" to "<<dest<<" is: "<<cost[dest]<<endl;

    cout<<"Path is:"<<endl;
    vector<int>vv;
    vv.push_back(dest);
    int now=dest;
    while(now!=parent[now])
    {
        now=parent[now];
        vv.push_back(now);
    }
    reverse(vv.begin(), vv.end());

    for(int i=0; i<vv.size(); i++)
    {
        cout<<vv[i];
        if(i != vv.size()-1){
            cout<<"-->";
        }
    }
    
    return 0;
}
/*
6 8
1 2 5
1 3 2
2 4 7
3 4 1
3 5 8
4 5 1
4 6 3
5 6 1
1
6
*/