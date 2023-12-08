#include <bits/stdc++.h>
using namespace std;
void dfs(int start, vector<int> adj[], vector<int> &vis, stack<int> &st)
{
    vis[start] = 1;
    for (auto it : adj[start])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, st);
        }
    }
    st.push(start);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, adj, vis, st);
        }
    }
    vector<int> ans;
    int n = st.size();
    while (!st.empty())
    {
        int top = st.top();
        ans.push_back(top);
        st.pop();
    }
    return ans;
}
int main()
{
    unordered_map<int, string> mp;
    mp[0] = "Review Board";
    mp[1] = "Hospitality";
    mp[2] = "Registration";
    mp[3] = "Finance";
    mp[4] = "Session";
    mp[5] = "Approval from TEQIP coordinator";
    mp[6] = "Food";
    mp[7] = "Paper";
    mp[8] = "Poster";
    mp[9] = "Approval from director";
    // adjecency list for the graph;
    vector<int> adj[10];
    adj[0].push_back(2);
    adj[0].push_back(7);
    adj[0].push_back(8);
    adj[1].push_back(3);
    adj[1].push_back(6);
    adj[2].push_back(3);
    adj[3].push_back(5);
    adj[4].push_back(0);
    adj[5].push_back(9);
    adj[6].push_back(3);
    vector<int> ans = topoSort(10, adj);
    reverse(ans.begin(), ans.end());
    cout << endl;
    cout << "Execution of the commities can be possible in the following order " << endl;
        for (int i = 0; i < 10; i++)
    {
        cout << i + 1 << " . " << mp[ans[i]] << endl;
    }
    cout << endl;
    return 0;
}