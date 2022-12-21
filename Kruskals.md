# Kruskal's Algorithm (A greedy algorithm)

1. Sort all edges by weight
2. Scan edges by weight from lowest to highest
3. If an edge introdueces a cycle, drop it.
4. If an edge does not introduce a cycle, pick it.
5. Terminate when $n-1$ edges are picked.
