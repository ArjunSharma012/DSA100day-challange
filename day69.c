using System;
using System.Collections.Generic;

class Program
{
    static void Main()
    {
        int V = 5; 


        List<List<(int, int)>> adj = new List<List<(int, int)>>();

        for (int i = 0; i < V; i++)
            adj.Add(new List<(int, int)>());

        adj[0].Add((1, 2));
        adj[0].Add((2, 4));
        adj[1].Add((2, 1));
        adj[1].Add((3, 7));
        adj[2].Add((4, 3));
        adj[3].Add((4, 1));

        int src = 0;

        int[] dist = Dijkstra(V, adj, src);

        Console.WriteLine("Shortest distances from source:");
        for (int i = 0; i < V; i++)
        {
            Console.WriteLine($"Node {i} → {dist[i]}");
        }
    }

    static int[] Dijkstra(int V, List<List<(int, int)>> adj, int src)
    {
        int[] dist = new int[V];

        for (int i = 0; i < V; i++)
            dist[i] = int.MaxValue;

        dist[src] = 0;

        var pq = new PriorityQueue<int, int>(); // (node, priority=distance)
        pq.Enqueue(src, 0);

        while (pq.Count > 0)
        {
            int u = pq.Dequeue();

            foreach (var (v, weight) in adj[u])
            {
                if (dist[u] + weight < dist[v])
                {
                    dist[v] = dist[u] + weight;
                    pq.Enqueue(v, dist[v]);
                }
            }
        }

        return dist;
    }
}