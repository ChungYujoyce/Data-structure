#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include "function.h"
using namespace std;

#define maxn 3000
#define INF 0x3f3f3f3f

int d[maxn];

void Implement::addEdge(const int label_1, const int label_2, const int weight) {
    VertexArr[label_1].neighbors.push_back(Neighbor(label_2, weight));
    VertexArr[label_2].neighbors.push_back(Neighbor(label_1, weight));
}

int Implement::shortest_path(const int label_1, const int label_2) {
    memset(d, INF, sizeof(d));
    d[label_1] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, label_1));
    while (pq.size()) {
        pair<int, int> u = pq.top();
        pq.pop();
        if (d[u.second] < u.first)
            continue;
        for (int i = 0; i < VertexArr[u.second].neighbors.size(); i++) {
            Neighbor v = VertexArr[u.second].neighbors[i];
            if (d[v.label] > d[u.second] + v.weight) {
                d[v.label] = d[u.second] + v.weight;
                pq.push(make_pair(d[v.label], v.label));
            }
        }
    }
    return d[label_2];
}

int pa[maxn];

int findset(int x) {
    return pa[x] == x ? pa[x] : pa[x] = findset(pa[x]);
}

struct Edge {
    int u, v, w;
    bool operator < (const Edge& rhs) {
        return w < rhs.w;
    }
};

int Implement::mst_weight() {
    for (int i = 0; i < VertexArr.size(); i++)
        pa[i] = i;
    vector<Edge> edges;
    for (int i = 0; i < VertexArr.size(); i++) {
        for (int j = 0; j < VertexArr[i].neighbors.size(); j++) {
            edges.push_back((Edge){i, VertexArr[i].neighbors[j].label, VertexArr[i].neighbors[j].weight});
        }
    }
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (int i = 0; i < edges.size(); i++) {
        int x = findset(edges[i].u);
        int y = findset(edges[i].v);
        if (x != y) {
            pa[x] = y;
            ans += edges[i].w;
        }
    }
    return ans;
}

int color[maxn];
vector<int> G[maxn];

bool dfs(int u) {
    for (int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if (!color[v]) {
            color[v] = 3 - color[u];
            if (!dfs(v))
                return false;
        } else if (color[v] == color[u])
            return false;
    }
    return true;
}

bool Implement::two_colorable() {
    memset(color, 0, sizeof(color));
    for (int i = 0; i < VertexArr.size(); i++)
        G[i].clear();
    for (int i = 0; i < VertexArr.size(); i++)
        for (int j = 0; j < VertexArr[i].neighbors.size(); j++)
            G[i].push_back(VertexArr[i].neighbors[j].label);
    for (int i = 0; i < VertexArr.size(); i++) {
        if (!color[i]) {
            color[i] = 1;
            if (!dfs(i))
                return false;
        }
    }
    return true;
}
