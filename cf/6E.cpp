/*
 * E. Exposition
 * time limit per test1.5 seconds
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * There are several days left before the fiftieth birthday of a famous Berland's writer Berlbury. In this connection the local library decided to make an exposition of the works of this famous science-fiction writer. It was decided as well that it is necessary to include into the exposition only those books that were published during a particular time period. It is obvious that if the books differ much in size, the visitors will not like it. That was why the organizers came to the opinion, that the difference between the highest and the lowest books in the exposition should be not more than k millimeters.
 *
 * The library has n volumes of books by Berlbury, arranged in chronological order of their appearance. The height of each book in millimeters is know, it is hi. As Berlbury is highly respected in the city, the organizers want to include into the exposition as many books as possible, and to find out what periods of his creative work they will manage to cover. You are asked to help the organizers cope with this hard task.
 *
 * Input
 * The first line of the input data contains two integer numbers separated by a space n (1 ≤ n ≤ 105) and k (0 ≤ k ≤ 106) — the amount of books by Berlbury in the library, and the maximum allowed height difference between the lowest and the highest books. The second line contains n integer numbers separated by a space. Each number hi (1 ≤ hi ≤ 106) is the height of the i-th book in millimeters.
 *
 * Output
 * In the first line of the output data print two numbers a and b (separate them by a space), where a is the maximum amount of books the organizers can include into the exposition, and b — the amount of the time periods, during which Berlbury published a books, and the height difference between the lowest and the highest among these books is not more than k milllimeters.
 *
 * In each of the following b lines print two integer numbers separated by a space — indexes of the first and the last volumes from each of the required time periods of Berlbury's creative work.
 *
 * Examples
 * input
 * 3 3
 * 14 12 10
 * output
 * 2 2
 * 1 2
 * 2 3
 * input
 * 2 0
 * 10 10
 * output
 * 2 1
 * 1 2
 * input
 * 4 5
 * 8 19 10 13
 * output
 * 2 1
 * 3 4
 * */

#include <stdio.h>

#include <limits>
#include <iostream>
#include <algorithm>

using namespace std;

#define  MAX numeric_limits<int>::max()
#define N 1000000

//segment tree implementation.

struct SgNode {
    int lc, rc; // left(right)child
    int value;
    int l, r; //range
    int maxv, minv; //max value and min value
};

SgNode p[N];

int cnt = 0;

int n, k;
int h[N];

void setTree(int l, int r) {
    cnt++;
    int v = cnt;
    p[v].l = l, p[v].r = r;
    p[v].lc = 0, p[v].rc = 0;
    p[v].maxv = 0, p[v].minv = MAX;

    if (r-l > 0) {
        int mid = l + r >> 1;
        p[v].lc = cnt + 1;
        setTree(l, mid);
        p[v].rc = cnt + 1;
        setTree(mid+1, r);
    }
}

void insert(int l, int r, int v, int value) {
    if (l <= p[v].l && r >= p[v].r) {
        p[v].value = p[v].maxv = p[v].minv = value;
        return;
    }
    int mid = p[v].l + p[v].r >> 1;
    if (l <= mid && p[v].lc) {
        insert(l, r, p[v].lc, value);
        p[v].maxv = max(p[v].maxv, p[p[v].lc].maxv);
        p[v].minv = min(p[v].minv, p[p[v].lc].minv);
    }
    if (r > mid && p[v].rc) {
        insert(l, r, p[v].rc, value);
        p[v].maxv = max(p[v].maxv, p[p[v].rc].maxv);
        p[v].minv = min(p[v].minv, p[p[v].rc].minv);
    }
}

int getmax(int l, int r, int v) {
    if (l <= p[v].l && r >= p[v].r) {
        return p[v].maxv;
    }
    int ret = 0;
    int mid = p[v].l + p[v].r >> 1;
    if (l <= mid && p[v].lc) {
        ret = max(ret, getmax(l, r, p[v].lc));
    }
    if (r > mid && p[v].rc) {
        ret = max(ret, getmax(l, r, p[v].rc));
    }
    return ret;
}

int getmin(int l, int r, int v) {
    if (l <= p[v].l && r >= p[v].r) {
        return p[v].minv;
    }
    int ret = MAX;
    int mid = p[v].l + p[v].r >> 1;
    if (l <= mid && p[v].lc) {
        ret = min(ret, getmin(l, r, p[v].lc));
    }
    if (r > mid && p[v].rc) {
        ret = min(ret, getmin(l, r, p[v].rc));
    }
    return ret;
}

void printTree() {
    for (int i = 1; i <= 2 * n - 1; i++) {
        printf("i = %d lc = %d rc = %d l = %d r = %d value=%d maxv=%d minv=%d\n", i, p[i].lc, p[i].rc, p[i].l, p[i].r, p[i].value, p[i].maxv, p[i].minv);
    }
}

struct Res {
    int l, r;
} res[N];

int main() {
    cin >> n >> k;
    setTree(1, n);

    for (int i = 1; i <= n; i++) {
        cin >> h[i];
        insert(i, i, 1, h[i]);
    }

    int cnt = 0;
    int maxele = 0;

//    printTree();

    for (int i = 1, j = 1; j <= n;) {
        while (getmax(i, j, 1) - getmin(i, j, 1) > k) {
            i++;
        }
        int len = j-i+1;
//        printf("len=%d i=%d j=%d max=%d min=%d k=%d\n", len, i, j, getmax(i, j, 1), getmin(i, j, 1), k);
        if (len > maxele) {
            maxele = len;
            cnt = 0;
            res[cnt].l = i;
            res[cnt].r = j;
            cnt++;
        } else if (len == maxele) {
            res[cnt].l = i;
            res[cnt].r = j;
            cnt++;
        }
        j++;
    }

    printf("%d %d\n", maxele, cnt);
    for (int i = 0; i < cnt; i++) {
        printf("%d %d\n", res[i].l, res[i].r);
    }

//    printTree();
//    printf("getmin(2,4,1)=%d\n", getmin(2,4,1));
//    printf("getmax(1,3,1)=%d\n", getmax(1,3,1));

    return 0;
}
