#include <iostream>
using namespace std;

struct Edge;

struct Vertex
{
    int data;
    Edge* edgeList;
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
    else
    {
        Vertex* cur = graph;
        while(cur != NULL)
        {
            if(cur->data == V)
            {
                cout << "Vertex already exists." << endl;
                return;
            }
            if(cur->next == NULL)
            {
                break;
            }
            cur = cur->next;
        }
        cur->next = new Vertex{V, NULL, NULL};
        cout << "Vertex added: " << V << endl;
        return;
    }
}

void addEdge(int V, int E)
{
    Vertex* reqV = graph;
    while(reqV != NULL && reqV->data != V)
    {
        reqV = reqV->next;
    }
    if(reqV == NULL)
    {
        cout << "Vertex(" << V << ") not found." << endl;
        return;
    }

    if(reqV->edgeList == NULL)
    {
        reqV->edgeList = new Edge{E, NULL};
        cout << "Edge inserted: " << V << "-" << E << endl;
        return;
    }
    else
    {
        Edge* curE = reqV->edgeList;
        while(curE != NULL)
        {
            if(curE->data == E)
            {
                cout << "There is already an edge between " << V << " & " << E << "." << endl; 
                return;
            }
            if(curE->next == NULL)
            {
                break;
            }
            curE = curE->next;
        }
        curE->next = new Edge{E, NULL};
        cout << "Edge inserted: " << V << "-" << E << endl;
        return;
    }
}

void insertE(int V, int E)
{
    bool edgeVertexExist = false;
    Vertex* cur = graph;
    Vertex* reqV = NULL;

    while(cur != NULL)
    {
        if(cur->data == V)
        {
            reqV = cur;
        }
        if(cur->data == E)
        {
            edgeVertexExist = true;
        }
        cur = cur->next;
    }

    if(reqV == NULL || edgeVertexExist == false)
    {
        cout << "Vertex/Vertices Not Found." << endl;
        return;
    }

    addEdge(V, E);
    addEdge(E, V);
}

int degree(int V)
{
    Vertex* reqV = graph;
    while(reqV != NULL && reqV->data != V)
    {
        reqV = reqV->next;
    }
    if(reqV == NULL)
    {
        cout << "Vertex(" << V << ") not found." << endl;
        return 0;
    }

    Edge* cur = reqV->edgeList;
    int degreeCount = 0;
    while(cur != NULL)
    {
        degreeCount++;
        cur = cur->next;
    }
    return degreeCount;
}

void display()
{
    for(Vertex* curV = graph; curV != NULL; curV = curV->next)
    {
        cout << curV->data << ":";
        for(Edge* curE = curV->edgeList; curE != NULL; curE = curE->next)
        {
            cout << " " << curE->data;
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

    //Inserting edges
    insertE(4, 3);
    insertE(2, 3);
    insertE(1, 6); //when one or both vertices are unknown
    insertE(2, 3); //when inserting a existing edge

    //Degree of a vertex
    degree(5);
    cout << "Degree of vertex 1: " << degree(1) << endl;
    cout << "Degree of vertex 3: " << degree(3) << endl;

    //Display the adjacency list
    display();
}