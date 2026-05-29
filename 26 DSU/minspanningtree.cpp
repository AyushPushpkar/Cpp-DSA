#include <bits/stdc++.h>
using namespace std;
/*
Problem:
Find minimum spanning tree weight using DSU (Kruskal's variant).
*/

// TC: O((V + E)log E) | SC: O(V)
//? n nodes and n-1 edges and all nodes reachable
//? edge weight -> min sum

// original graph
//*      0
//*     / \
//*  (3)   (4)
//*   /      \
//*  2--------1
//*  |\ (2)  /|
//*  | \    / |
//* (2)(4)(1)(2)
//*  |   \/   |
//*  4---3----5
//*   (3) (5)
//*    \____/
//*     (1)

// Spanning tree A
//*         0
//*         |
//*        (4)
//*         |
//*  2------1------3
//*  | (3)     (1)
//* (2)
//*  |
//*  4-----5
//*    (1)

// Spanning tree B
//*        0
//*        |
//*       (4)
//*        |
//*  2-----1-----3
//*    (3) |  (1)
//*       (1)
//*        |
//*        3-----5
//*          (5)
