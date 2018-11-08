void Topsort(Graph G)
{
	int Counter;
	Vertex V,W;
	
	for(Counter = 0;Counter < NumVertex;Counter++)
	{
		V = FindNewVertexOfDegreeZero();
		if(V == NotAVertex)
		{
			error("Graoh has a cycle");
			break;
		}
		TopNum[V] = Counter;
		for each W adjacecnt to V
			Indegree[W]--;
	}
}


