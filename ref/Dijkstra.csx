// Licensed under the MIT License.

// Path Sum: Two Ways
// Path Sum: Three Ways
// Path Sum: Four Ways

using System;
using System.Collections.Generic;
using System.IO;

readonly struct Coordinate
{
    public Coordinate(int i, int j)
    {
        I = i;
        J = j;
    }

    public int I { get; }
    public int J { get; }
}

void Dijkstra(
    int[,] grid,
    Coordinate source,
    Func<int[,], Coordinate, IEnumerable<Coordinate>> neighbors,
    Func<int[,], Coordinate, Coordinate, int> weight,
    out IDictionary<Coordinate, int> distances,
    out IDictionary<Coordinate, Coordinate> path)
{
    distances = new Dictionary<Coordinate, int>();
    path = new Dictionary<Coordinate, Coordinate>();

    var priorityQueue = new PriorityQueue<Coordinate, int>();

    for (int i = 0; i < grid.GetLength(0); i++)
    {
        for (int j = 0; j < grid.GetLength(1); j++)
        {
            distances.Add(new Coordinate(i, j), int.MaxValue);
        }
    }

    priorityQueue.Enqueue(source, 0);
    distances[source] = 0;

    while (priorityQueue.TryDequeue(out Coordinate u, out int distance))
    {
        if (distance != distances[u])
        {
            continue;
        }

        foreach (Coordinate v in neighbors(grid, u))
        {
            int alternative = distances[u] + weight(grid, u, v);

            if (alternative < distances[v])
            {
                distances[v] = alternative;
                path[v] = u;

                priorityQueue.Enqueue(v, alternative);
            }
        }
    }
}

IEnumerable<Coordinate> Path(
    int[,] grid,
    Coordinate source,
    Coordinate target,
    IDictionary<Coordinate, Coordinate> path)
{
    Coordinate u = target;

    if (!path.ContainsKey(u) && u.I != source.I && u.J != source.J)
    {
        return Array.Empty<Coordinate>();
    }

    Stack<Coordinate> stack = new Stack<Coordinate>();

    do
    {
        stack.Push(u);
    }
    while (path.TryGetValue(u, out u));

    return stack;
}

IEnumerable<Coordinate> Neighbors(
    int[,] grid,
    Coordinate vertex)
{
    // if (vertex.I > 0)
    // {
    //     yield return new Coordinate(vertex.I - 1, vertex.J);
    // }

    // if (vertex.J > 0)
    // {
    //     yield return new Coordinate(vertex.I, vertex.J - 1);
    // }

    if (vertex.I < grid.GetLength(0) - 1)
    {
        yield return new Coordinate(vertex.I + 1, vertex.J);
    }

    if (vertex.J < grid.GetLength(1) - 1)
    {
        yield return new Coordinate(vertex.I, vertex.J + 1);
    }
}

int Weight(int[,] grid, Coordinate source, Coordinate target)
{
    return grid[target.I, target.J];
}

// int[,] grid = new int[,]
// {
//     { 131, 673, 234, 103,  18 },
//     { 201,  96, 342, 965, 150 },
//     { 630, 803, 746, 422, 111 },
//     { 537, 699, 497, 121, 956 },
//     { 805, 732, 524,  37, 331 }
// };

int[,] grid = new int[80, 80];

using (StreamReader streamReader = File.OpenText("data/id0081.txt"))
{
    int i = 0;
    string line;

    while ((line = streamReader.ReadLine()) != null)
    {
        string[] segments = line.Split(',');

        for (int j = 0; j < segments.Length; j++)
        {
            grid[i, j] = int.Parse(segments[j]);
        }

        i++;
    }
}

// Coordinate minSource;
// Coordinate minTarget;
// int minDistance = int.MaxValue;
// IDictionary<Coordinate, Coordinate> minPath;

// for (int sourceI = 0; sourceI < grid.GetLength(0); sourceI++)
// {
//     Coordinate s = new Coordinate(sourceI, 0);

//     Dijkstra(
//         grid,
//         s,
//         Neighbors,
//         Weight,
//         out IDictionary<Coordinate, int> distances,
//         out IDictionary<Coordinate, Coordinate> path);

//     for (int targetI = 0; targetI < grid.GetLength(0); targetI++)
//     {
//         Coordinate t = new Coordinate(targetI, grid.GetLength(1) - 1);
        
//         if (distances[t] < minDistance)
//         {
//             minSource = s;
//             minTarget = t;
//             minPath = path;
//             minDistance = distances[t];
//         }
//     }
// }

Coordinate s = new Coordinate();
Coordinate t = new Coordinate(grid.GetLength(0) - 1, grid.GetLength(1) - 1);

Dijkstra(grid, s, Neighbors, Weight,
    out IDictionary<Coordinate, int> distances,
    out IDictionary<Coordinate, Coordinate> path);

foreach (Coordinate u in Path(grid, s, t, path))
{
    Console.Write(" -> ({0}, {1}) ${2}", u.I, u.J, grid[u.I, u.J]);
}

Console.WriteLine();
Console.WriteLine(grid[s.I, s.J] + distances[t]);
