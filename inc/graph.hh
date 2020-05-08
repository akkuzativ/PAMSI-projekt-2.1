#ifndef GRAPH_HH
#define GRAPH_HH

#include "linkedlist.hh"

class Edge;
class Graph;



class Edge
{
    //protected:
    public:
        int weight;
        int sourceVertex;
        int destinationVertex;
        LinkedList<Edge*>::Iterator edgeListPosition;
        bool operator ==(Edge e);
        bool operator !=(Edge e);
        Edge(int sV, int dV, int w) {sourceVertex = sV; destinationVertex = dV; weight = w;};
        Edge() {};
    friend class Graph;
};


class Graph
{
    protected:
        int nVertices;
        int startingVertexForBellmanford;
        LinkedList<Edge*> edgeList;

    public:
        virtual bool areAdjacent(int firstVertex, int secondVertex) = 0;

        virtual void insertEdge(int sourceVertex, int destinationVertex, int weight) = 0;

        virtual int vertices() = 0;
        virtual LinkedList<Edge*> edges() = 0;

        virtual void allocateMemoryForDataStructure() = 0;
        virtual void print() = 0;
        virtual void fillRandom(int vertexNumber, float density) = 0;
        virtual void fillFromFile(char* filename) = 0;
        virtual void setStartingVertexForBellmanford(int startingVertex) = 0;
};



#endif