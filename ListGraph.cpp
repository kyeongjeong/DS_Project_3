#include "ListGraph.h"

ListGraph::ListGraph(bool type, int size) : Graph(type, size)
{
	m_Type = type;
	m_List = new map<int, int>[size];
}

ListGraph::~ListGraph()
{
	delete[] m_List;
}

void ListGraph::getAdjacentEdges(int vertex, map<int, int>* m)
{
	map<int, int>::iterator it = m_List[vertex].begin(); //iterator

	for(int i = 0;  i < m_Size; i++) 
	{
		it = m_List[i].begin();
		for(; it != m_List[i].end(); it++)
		{
			if(it->first == vertex)
				m->insert(pair<int, int>(i, it->second));

			if(i == vertex)
				m->insert(pair<int, int>(it->first, it->second));
		}
	}
}

void ListGraph::getEdges(int vertex, map<int, int>* m)
{
	map<int, int>::iterator it = m_List[vertex].begin();
	
	for(; it != m_List[vertex].end(); it++)
		m->insert(pair<int, int>(it->first, it->second));
}

void ListGraph::insertEdge(int from, int to, int weight)
{
	m_List[from].insert(pair<int, int>(to, weight));
}

bool ListGraph::printGraph()
{
	ofstream fout;
	fout.open("log.txt", ios::app);
	fout << "Graph is ListGraph!" << endl;

	for(int i = 0; i < m_Size; i++)
	{
		fout << "[" << i << "]";

		for(auto it_ = m_List[i].begin(); it_ != m_List[i].end() && fout<<" -> "; it_++)
		{
			fout << "("<<it_->first << "," << it_->second<<")";
		}
		fout << endl;
	}
	fout << endl;
	fout.close();
	return 1;
}