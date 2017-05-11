/*
 * E. Interesting Graph and Apples
 * time limit per test1 second
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * Hexadecimal likes drawing. She has drawn many graphs already, both directed and not. Recently she has started to work on a still-life «interesting graph and apples». An undirected graph is called interesting, if each of its vertices belongs to one cycle only — a funny ring — and does not belong to any other cycles. A funny ring is a cycle that goes through all the vertices just once. Moreover, loops are funny rings too.
 *
 * She has already drawn the apples and some of the graph edges. But now it is not clear, how to connect the rest of the vertices to get an interesting graph as a result. The answer should contain the minimal amount of added edges. And furthermore, the answer should be the lexicographically smallest one. The set of edges (x1, y1), (x2, y2), ..., (xn, yn), where xi ≤ yi, is lexicographically smaller than the set (u1, v1), (u2, v2), ..., (un, vn), where ui ≤ vi, provided that the sequence of integers x1, y1, x2, y2, ..., xn, yn is lexicographically smaller than the sequence u1, v1, u2, v2, ..., un, vn. If you do not cope, Hexadecimal will eat you. ...eat you alive.
 *
 * Input
 * The first line of the input data contains a pair of integers n and m (1 ≤ n ≤ 50, 0 ≤ m ≤ 2500) — the amount of vertices and edges respectively. The following lines contain pairs of numbers xi and yi (1 ≤ xi, yi ≤ n) — the vertices that are already connected by edges. The initial graph may contain multiple edges and loops.
 *
 * Output
 * In the first line output «YES» or «NO»: if it is possible or not to construct an interesting graph. If the answer is «YES», in the second line output k — the amount of edges that should be added to the initial graph. Finally, output k lines: pairs of vertices xj and yj, between which edges should be drawn. The result may contain multiple edges and loops. k can be equal to zero.
 *
 * Examples
 * input
 * 3 2
 * 1 2
 * 2 3
 * output
 * YES
 * 1
 * 1 3
 * */

#include <iostream>

using namespace std;

#define N 52

int p[N], d[N];

int get(int i) {
    if (i != p[i]) p[i] = get(p[i]);
    return p[i];
}

int main() {
    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        p[i] = i;
    }
    int u, v;
    bool ok = true;
    for(int i = 1; i <= m; i++) {
        cin >> u >> v;
        d[u]++;
        d[v]++;

        if (d[u]>2 || d[v]>2) {
            ok = false;
            break;
        }
        int pu = get(u);
        int pv = get(v);

        if ( pu==pv && ((i!=n)||i!=m)) {
            ok = false;
            break;
        }
        p[pu] = pv;
    }

    if (!ok) {
        cout << "NO\n";
        return 0;
    }
    cout << "YES\n";
    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            int pi = get(i);
            int pj = get(j);
            if (pi!=pj && d[i]<2 && d[j]<2) {
                d[i]++;
                d[j]++;
                cout << i << " " << j << "\n";
                p[pi] = pj;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        while (d[i] < 2) {
            cout << i << " ";
            d[i]++;
        }
    }
    return 0;
}
