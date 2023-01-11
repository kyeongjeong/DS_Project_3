#include "Manager.h"

Manager::Manager()
{
	graph = nullptr;
	fout.open("log.txt", ios::app); //output file
	load = 0;
}

Manager::~Manager()
{
	if(load)
		delete graph;

	fout.close();
}

void Manager::run(const char* command_txt){
	ifstream fin;
	fin.open(command_txt);
		
	if(!fin) //command file open fail
	{
		fout << "[ERROR] command file open error!" << endl;
		return;
	}
	
	while(!fin.eof()) //while command file is not done
	{
		string select;
		fin >> select;

		if(select == "LOAD") //command is LOAD
		{
			char buf[129]={0};
			char buf2[129]={0};

			fin.getline(buf, 128);
			strcpy(buf2, buf+1);

			if(LOAD(buf2) == true);
			{
				fout << "========LOAD========" << endl;
				fout << "Success" << endl;
				fout << "=====================" << endl;
			}
		}

		else if(select == "PRINT") //command is PRINT
		{
			PRINT();
		}

		else if(select == "BFS") //command is BFS
		{
			int ver;
			fin >> ver;

			if(mBFS(ver) == false)
				printErrorCode(300);
		}

		else if(select == "DFS") //command is DFS
		{
			int ver;
			fin >> ver;

			if(mDFS(ver) == false)
				printErrorCode(400);
		}

		else if(select == "DFS_R") //command is DFS_R
		{
			int ver;
			fin >> ver;

			if(mDFS_R(ver) == false)
				printErrorCode(500);
			
			cout << endl << endl;
		}

		else if(select== "DIJKSTRA") //command is DIJKSTRA
		{
			int ver;
			fin >> ver;

			if(mDIJKSTRA(ver) == false)
				printErrorCode(600);
		}

		fout << endl;
	}	
	fin.close();
}

bool Manager::LOAD(char* filename)
{
	ifstream fin2;
	fin2.open(filename);
	if(!fin2)
	{
		printErrorCode(100);
		return false;
	}

	char mode;
	int size;
	fin2 >> mode;
	fin2 >> size;
	
	char *buf = new char[10];
	fin2.getline(buf, 10);

	if(mode == 'L')
	{
		graph = new ListGraph(1, size);
		int start;
		
		while(!fin2.eof())
		{
			char *str = new char[100];
			fin2.getline(str, 100);

			char* ptr = strtok(str, " ");
			string number = ptr;
			int num = std::stoi(number);

			ptr = strtok(NULL, " ");

			if(ptr == NULL)
			{
				start = num;
			}
			
			while(ptr != NULL)
			{
				int end = num;

				string weightNum = ptr;
				int w = std::stoi(weightNum);

				graph->insertEdge(start, end, w);
				ptr = strtok(NULL, " ");
			}
		}
	}

	else if(mode == 'M')
	{
		graph = new MatrixGraph(1, size);

		int j = 0;
		while(!fin2.eof())
		{			
			for(int i = 0; i < size; i++)
			{
				int num;
				fin2 >> num;
				if(num != 0)
					graph->insertEdge(j, i, num);
			}
			j++;
		}
	}
	return true;
}

bool Manager::PRINT()
{
	fout << "========PRINT========" << endl;
	if(graph->printGraph())
		return true;
	else
	{
		printErrorCode(200);
		return false;
	}
}

bool Manager::mBFS(int vertex)
{
	fout << "========BFS========" << endl;
	fout << "startvertex: " << vertex <<endl;
	if(BFS(graph, vertex) == true)
	{
		fout << endl << "=====================" << endl;
		return true;
	}
	return false;
}

bool Manager::mDFS(int vertex)
{
	fout << "========DFS========" << endl;
	fout << "startvertex: " << vertex <<endl;

	if(DFS(graph, vertex) == true)
	{
		fout << endl << "=====================" << endl;
		return true;
	}
	return false;
}

bool Manager::mDFS_R(int vertex)
{
	fout << "========DFS_R========" << endl;
	fout << "startvertex: " << vertex <<endl;

	int size = graph->getSize();
    bool* isVisit = new bool[size];
	for(int i = 0; i < size; i++)
		isVisit[i] = false;

	if(DFS_R(graph, isVisit, vertex, true) == true)
	{
		fout << endl << "=====================" << endl;
		return true;
	}
	return false;
}

bool Manager::mDIJKSTRA(int vertex)
{
	fout << "========DIJKSTRA========" << endl;
	fout << "startvertex: " << vertex << endl;
	if(Dijkstra(graph, vertex) == true)
	{
		fout << endl << "=====================" << endl;
		return true;
	}
	return false;
}

bool Manager::mKRUSKAL()
{

}

bool Manager::mBELLMANFORD(int s_vertex, int e_vertex)
{

}

bool Manager::mFLOYD()
{

}

void Manager::printErrorCode(int n)
{
	fout<<"======== ERROR ========"<<endl;
	fout<<n<<endl;
	fout<<"======================="<<endl;
}
