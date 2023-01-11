#include "GraphMethod.h"

bool BFS(Graph* graph, int vertex)
{
    ofstream fout;
    fout.open("log.txt", ios::app); //set output textfile
    
    int size = graph->getSize(); //graph size
    bool isVisit[size] = {0, }; //check for visit
    int start = vertex;

    queue<int> bfs; //use queue for bfs
    bfs.push(start);
    isVisit[start] = true;
    fout << start;

    while(bfs.empty() == false) //if queue is not empty
    {
        int num = bfs.front();
        bfs.pop();
        if(num != start)
            fout <<  " -> " << num;

        map<int, int>* m = new map<int, int>;
        graph->getAdjacentEdges(num, m); //getter for undirectional graph
        map<int, int>::iterator it;

        for(it = m->begin(); it != m->end(); it++) //traversal m map
        {
            int newNum = it->first;
            if(isVisit[newNum] == false) //if not visited
            {
                bfs.push(newNum);
                isVisit[newNum] = true;
            }
        }
    }
    return true;
}

bool DFS(Graph* graph, int vertex)
{
    ofstream fout;
    fout.open("log.txt", ios::app); //set output textfile
    
    int size = graph->getSize();
    bool isVisit[size] = {0, };
    int start = vertex;

    stack<int> dfs;
    dfs.push(start);
    isVisit[start] = true;
    fout << start;

    while(dfs.empty() == false)
    {
        int num = dfs.top();
        dfs.pop();

        map<int, int>* m = new map<int, int>;
        graph->getAdjacentEdges(num, m);
        map<int, int>::iterator it;

        for(it = m->begin(); it != m->end(); it++)
        {
            int newNum = it->first;

            if(isVisit[newNum] == false)
            {
                fout <<  " -> " << newNum;
                isVisit[newNum] = true;

                dfs.push(num);
                dfs.push(newNum);
                break;
            }
        }
    }
    return true;
}

bool DFS_R(Graph* graph, bool* isVisit, int vertex, bool isStart)
{
    ofstream fout;
    fout.open("log.txt", ios::app);
    
    isVisit[vertex] = true;
    if(isStart == true)
        cout << vertex;
    else
        cout << " -> " << vertex;

    map<int, int>* m = new map<int, int>;
    graph->getAdjacentEdges(vertex, m);
    map<int, int>::iterator it;

    for(it = m->begin(); it != m->end(); it++)
    {
        int newNum = it->first;
        if(isVisit[newNum] == false)
            DFS_R(graph, isVisit, newNum, false);
    }
    return true;
}

bool Kruskal(Graph* graph)
{

}

bool Dijkstra(Graph* graph, int vertex)
{
    ofstream fout;
    fout.open("log.txt", ios::app);

    int size = graph->getSize();
    int start = vertex;
    int shortest[size];
    fill(shortest, shortest + size, 999);

    priority_queue<pair<int, int>> dij;
    dij.push({0, start});
    shortest[start] = 0;

    while(dij.empty() == false)
    {
        int dist = -dij.top().first;
        int curNode = dij.top().second;
        dij.pop();

        if(dist > shortest[curNode])
            continue;

        map<int, int>* m = new map<int, int>;
        graph->getEdges(curNode, m);
        map<int, int>::iterator it = m->begin();

        for(; it != m->end(); it++)
        {
            int cost = dist + it->second;

            if(cost < shortest[it->first])
            {
                shortest[it->first] = cost;
                dij.push(make_pair(-cost, it->first));
            }
        }
    }

    for(int i = 0; i < size; i++)
    {
        if(i != start)
        {
            fout << "[" << i << "] ";

            if(shortest[i] == 999)
               fout << "x";
        
            else
                fout << shortest[i];
        }

        if(i != size-1 && i != start)
            fout << endl;
    }
}

bool Bellmanford(Graph* graph, int s_vertex, int e_vertex)
{

}

bool FLOYD(Graph* graph)
{

}