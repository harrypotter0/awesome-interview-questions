/*
give a list of cities a to city b the price of air tickets for example
a b 100 $
b c 200 $
e f 200 $
...

Now let you from city x to city y, you cannot transfer more than twice between the two city, 
find the cheap flight from x to y, follow up print out the flight
November 25, 2017
*/

/*
Approach:: 

If price can not negative:
Dijkstra algorithm O(MlogN)
Otherwise:
Ford-Bellman algorithm O(NM)

where M = Edges, N = vertexes;

*/


//Bellman-Ford 

//dijkstra
