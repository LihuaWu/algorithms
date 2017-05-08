/*
 * D. Two Friends
 * time limit per test1 second
 * memory limit per test64 megabytes
 * inputstandard input
 * outputstandard output
 * Two neighbours, Alan and Bob, live in the city, where there are three buildings only: a cinema, a shop and the house, where they live. The rest is a big asphalt square.
 *
 * Once they went to the cinema, and the film impressed them so deeply, that when they left the cinema, they did not want to stop discussing it.
 *
 * Bob wants to get home, but Alan has to go to the shop first, and only then go home. So, they agreed to cover some distance together discussing the film (their common path might pass through the shop, or they might walk circles around the cinema together), and then to part each other's company and go each his own way. After they part, they will start thinking about their daily pursuits; and even if they meet again, they won't be able to go on with the discussion. Thus, Bob's path will be a continuous curve, having the cinema and the house as its ends. Alan's path — a continuous curve, going through the shop, and having the cinema and the house as its ends.
 *
 * The film ended late, that's why the whole distance covered by Alan should not differ from the shortest one by more than t1, and the distance covered by Bob should not differ from the shortest one by more than t2.
 *
 * Find the maximum distance that Alan and Bob will cover together, discussing the film.
 *
 * Input
 * The first line contains two integers: t1, t2 (0 ≤ t1, t2 ≤ 100). The second line contains the cinema's coordinates, the third one — the house's, and the last line — the shop's.
 *
 * All the coordinates are given in meters, are integer, and do not exceed 100 in absolute magnitude. No two given places are in the same building.
 *
 * Output
 * In the only line output one number — the maximum distance that Alan and Bob will cover together, discussing the film. Output the answer accurate to not less than 4 decimal places.
 *
 * Examples
 * input
 * 0 2
 * 0 0
 * 4 0
 * -3 0
 *  output
 *  1.0000000000
 *  input
 *  0 0
 *  0 0
 *  2 0
 *  1 0
 *  output
 *  2.0000000000
 * */

#include <math.h>
#include <stdio.h>

#include <iostream>

using namespace std;

double dist(int x1, int y1, int x2, int y2) {
    int dx = x1-y1;
    int dy = x2-y2;
    return sqrt(dx*dx+dy*dy);
}

int main() {
    int t1, t2, cx, cy, hx, hy, sx, sy;
    cin >> t1 >> t2 >>cx >> cy >> hx >> hy >> sx >> sy;

    double dcs = dist(cx, cy, sx, sy);
    double dsh = dist(sx, sy, hx, hy);
    double dch = dist(cx, cy, hx, hy);

    double T1 = dcs + dsh + t1;
    double T2 = dch + t2;

    if (T1 < T2 || fabs(T1-T2) < 1e-6) {
        cout << T1;
        return 0;
    }


    return 0;
}
