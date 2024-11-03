Quick Notes to generate a .dot file and eventually a .pdf file to view the graph

Visualize a Graph:
-- There's a program on Mac called 'dot'
	-- create and open a .dot file
	-- utilize 'C' like struct definition and declaration
		ex) graph { Susan -- Mark; }
			-- use digraph and '->' for directed graph
	-- create the graph as a pdf
		ex) dot <filename>.dot -Tpdf > graph.pdf
