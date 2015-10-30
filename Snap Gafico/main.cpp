#include <Snap.h>
#include <iostream>
#include <fstream>
#include <chrono>

void exportGraphML(PUNGraph);
void exportGEXF(PUNGraph);
void exportGDF(PUNGraph);
void exportJSON(PUNGraph);

int main()
{
	PUNGraph g = TSnap::LoadEdgeList<PUNGraph>("CA-HepPH.txt", 0, 1);
	std::chrono::high_resolution_clock::time_point begin = std::chrono::high_resolution_clock::now();
	exportGraphML(g);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " GraphML: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	exportGEXF(g);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " GEXF: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	exportGDF(g);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " GDF: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;

	begin = std::chrono::high_resolution_clock::now();
	exportJSON(g);
	end = std::chrono::high_resolution_clock::now();
	duration = std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count();
	std::cout << " Graphson: " << duration << " micro s" << " = " << duration / 1000000 << " s." << std::endl;
}

void exportGraphML(PUNGraph g)
{
	int i = 1;
	std::ofstream archivo("Gnutella.graphml");
	if (archivo.is_open())
	{
		archivo << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
		archivo << "<graphml xmlns=\"http://graphml.graphdrawing.org/xmlns\" xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xsi:schemaLocation=\"http://graphml.graphdrawing.org/xmlns http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd\"> \n";
		archivo << "<graph id=\"G\" edgedefault=\"directed\">\n";

		for (PUNGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
		{
			archivo << "<node id=\"" << NI.GetId() << "\"/>\n";
		}
		for (PUNGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
		{
			archivo << "<edge id=\"e" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\" />\n";
		}

		archivo << "</graph>\n";
		archivo << "</graphml>\n";
		archivo.close();
	}
}

void exportGEXF(PUNGraph g)
{
	int i = 1;
	std::ofstream archivo("Gnutella.gexf");
	if (archivo.is_open())
	{
		archivo << "<?xml version=\"1.0\" encoding=\"UTF - 8\"?>\n";
		archivo << "<gexf xmlns=\"http://www.gexf.net/1.2draft\" version=\"1.2\">\n";
		archivo << "<graph mode=\"static\" defaultedgetype=\"directed\">\n";

		archivo << "<nodes>\n";
		for (PUNGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
		{
			archivo << "<node id=\"" << NI.GetId() << "\"/>\n";
		}
		archivo << "</nodes>\n";

		archivo << "<edges>\n";
		for (PUNGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
		{
			archivo << "<edge id=\"e" << i << "\" source=\"" << EI.GetSrcNId() << "\" target=\"" << EI.GetDstNId() << "\" />\n";
		}
		archivo << "</edges>\n";

		archivo << "</graph>\n";
		archivo << "</gexf>";
		archivo.close();
	}
}

void exportGDF(PUNGraph g)
{
	int i = 1;
	std::ofstream archivo("Gnutella.gdf");
	if (archivo.is_open())
	{
		archivo << "nodedef>Id VARCHAR\n";

		for (PUNGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
		{
			archivo << NI.GetId() << "\n";
		}

		archivo << "edgedef>sourceNode VARCHAR,destinationNode VARCHAR\n";

		for (PUNGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI(); EI++, ++i)
		{
			archivo << EI.GetSrcNId() << ", " << EI.GetDstNId() << "\n";
		}

		archivo.close();
	}
}

void exportJSON(PUNGraph g)
{
	int i = 1;
	std::ofstream archivo("Gnutella.json");
	if (archivo.is_open())
	{
		archivo << "{\n";
		archivo << "\"graph\": {\n";
		archivo << "\"mode\": \"NORMAL\",\n";
		archivo << "\"vertices\": [\n";
		
		for (PUNGraph::TObj::TNodeI NI = g->BegNI(); NI < g->EndNI(); NI++)
		{
			archivo << "{\n";
			archivo << "_id: \"" << NI.GetId() << "\"\n";
			archivo << "}\n";
			if (NI++ == g->EndNI())
				archivo << " ],\n";
			else
				archivo << ",\n";
		}

		archivo << "\"edges\": [\n";
		for (PUNGraph::TObj::TEdgeI EI = g->BegEI(); EI < g->EndEI();)
		{
			archivo << "{\n";
			archivo << "\"source\": \"" << EI.GetSrcNId() << "\", \"target\": \"" << EI.GetDstNId() << "\" \n";
			archivo << "}\n";
			if (EI++ == g->EndEI())
				archivo << " ]\n";
			else
				archivo << ",\n";
		}

		archivo << "} }";

		archivo.close();

	}
}