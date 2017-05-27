/*
 * D. A Simple Task
 * time limit per test2 seconds
 * memory limit per test256 megabytes
 * inputstandard input
 * outputstandard output
 * Given a simple graph, output the number of simple cycles in it. A simple cycle is a cycle with no repeated vertices or edges.
 *
 * Input
 * The first line of input contains two integers n and m (1 ≤ n ≤ 19, 0 ≤ m) – respectively the number of vertices and edges of the graph. Each of the subsequent m lines contains two integers a and b, (1 ≤ a, b ≤ n, a ≠ b) indicating that vertices a and b are connected by an undirected edge. There is no more than one edge connecting any pair of vertices.
 *
 * Output
 * Output the number of cycles in the given graph.
 *
 * Examples
 * input
 * 4 6
 * 1 2
 * 1 3
 * 1 4
 * 2 3
 * 2 4
 * 3 4
 * output
 * 7
 * Note
 * The example graph is a clique and contains four cycles of length 3 and three cycles of length 4.
 *
 * */

#include <iostream>
#include <vector>
#include <set>

using namespace std;


int n, m, u, v;
int g[20][20];

int vis[20], par[20];



int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        g[u][v] = 1;
        g[v][u] = 1;
    }
    return 0;
}
