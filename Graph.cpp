#include "Graph.h"

Graph::Graph(bool type, int size)
{
	m_Type = type; //set type(list, matrix)
	m_Size = size; //set size
}

Graph::~Graph()
{
}


bool Graph::getType(){return m_Type;}
int Graph::getSize(){return m_Size;}
