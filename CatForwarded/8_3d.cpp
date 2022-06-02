//------------------------------------------------------------------------------
// 8.
//
// Suppose that you have an array of shorts which corresponds to the vertex ids
// of a set of T triangles. The shorts would be interpreted 3 at a time, so the
// array

// 0,2,7,1,3,5,6,2,0

// would represent 3 triangles with vertex ids : (0,2,7), (1,3,5) and (6,2,0)
// There are 9 edges implicit in the data
// Triangle 1 : (0,2), (2,7), (7,0)
// Triangle 2 : (1,3), (3,5), (5,1)
// Triangle 3 : (6,2), (2,0), (0,6)

// Write a method to find all connectivity information between all triangles.
// Two triangles are considered connected if they share an edge.
// For example, triangle 1 and triangle 3 are connected because triangle 1 has
// edge (0,2) and triangle 3 has opposite edge (2,0).

// Your method should fill an output array of size 3T with the corresponding
// indices of the opposite edge. You may assume that every edge has at most one
// match. Edges with no opposite are flagged with -1.

// The output for the example above should be
// 7, -1, -1, -1, -1, -1, -1, 0, -1

// 8(a) First write the method using a brute force implementation (may be
// very slow for large T) [10 marks]

// 8(b) Then consider how you might preprocess the data to find
// the edge matches more quickly for large T. Use code or
// pseudocode to illustrate your approach. [15 marks]

// Your method declaration should look like:
void findConnectivity(unsigned short* indexTriples, int T, int* connectivityOut);