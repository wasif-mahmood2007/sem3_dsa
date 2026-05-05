#include <iostream>
using namespace std;

struct Edge;

struct Vertex
{
    int data;
    Edge* edgeList = NULL;
    Vertex* next;
};

struct Edge
{
    int data;
    Edge* next;
};

Vertex* graph = NULL;

void insertV(int V)
{
    if(graph == NULL)
    {
        graph = new Vertex{V, NULL, NULL};
        cout << "Vertex added: " << V << endl;
        return;
    }

    Vertex* cur = graph;
    while(cur != NULL)
    {
        if(cur->data == V)
        {
            cout << "Vertex(" << V << ") already exists.\n";
            return;
        }
        if(cur->next == NULL) break;
        cur = cur->next;
    }
    cur->next = new Vertex{V, NULL, NULL};
    cout << "Vertex added: " << V << endl;
    return;
}

Vertex* findV(int V)
{
    Vertex* reqV = graph;
    while(reqV != NULL && reqV->data != V) reqV = reqV->next;
    return reqV;
}

void createEdge(Vertex* V, int E)
{
    if(V->edgeList == NULL)
    {
        V->edgeList = new Edge{E, NULL};
        cout << "Edge inserted: " << V << "-" << E << endl;
        return;
    }

    Edge* cur = V->edgeList;
    while(cur != NULL)
    {
        if(cur->data == E)
        {
            cout << "There is already an edge between " << V->data << " & " << E << ".\n"; 
            return;
        }
        if(cur->next == NULL) break;
        cur = cur->next;
    }
    cur->next = new Edge{E, NULL};
    cout << "Edge inserted: " << V << "-" << E << endl;
    return;
}

void insertE(int V, int E)
{
    Vertex* reqV = findV(V);
    Vertex* reqE = findV(E);
    if(reqV == NULL || reqE == NULL)
    {
        cout << "One or both vertices not found.\n";
        return;
    }
    
    createEdge(reqV, E);
    createEdge(reqE, V);
}

int degree(int V)
{
    int degree = 0;
    Vertex* reqV = findV(V);
    if(reqV == NULL)
    {
        cout << "Vertex not found.\n";
        return degree;
    }

    Edge* cur = reqV->edgeList;
    while(cur != NULL)
    {
        degree++;
        cur = cur->next; 
    }
    return degree;
}

int sumOfDegree()
{
    int sum = 0;
    Vertex* cur = graph;
    while(cur != NULL)
    {
        Edge* curEdge = cur->edgeList;
        while(curEdge != NULL)
        {
            sum++;
            curEdge = curEdge->next;
        }
        cur = cur->next;
    }
    return sum;
}

int countEdges()
{
    return sumOfDegree() / 2;
}

void display()
{
    if(graph == NULL)
    {
        cout << "Graph is empty.\n";
        return;
    }

    for(Vertex* cur = graph; cur != NULL; cur = cur->next)
    {
        cout << cur->data << ":";
        for(Edge* curEdge = cur->edgeList; curEdge != NULL; curEdge = curEdge->next)
        {
            cout << " " << curEdge->data;
        }
        cout << endl;
    }
}

int main()
{
    //Inserting vertices
    insertV(1);
    insertV(2);
    insertV(3);
    insertV(4);
    insertV(3); //insert existing vertex
    cout << endl;

    //Inserting edges
    insertE(4, 3);
    insertE(2, 3);
    insertE(1, 6); //one or both vertices are unknown
    insertE(2, 3); //inserting an existing edge
    cout << endl;

    //Degree of a vertex
    degree(5);
    cout << "Degree of vertex 1: " << degree(1) << endl;
    cout << "Degree of vertex 3: " << degree(3) << endl;
    cout << endl;

    //Sum of degree
    cout << "Sum of degree: " << sumOfDegree() << endl;
    cout << endl;

    //Number of edges
    cout << "Number of edges in the graph: " << countEdges() << endl;
    cout << endl;

    //Display the adjacency list
    display();
}
