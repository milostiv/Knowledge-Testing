/******************************************************************************

                        Milos Trifovic's assignment.
            Code tested using g++ version 9.4.0 on Ubuntu 20.04.6 LTS.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <limits>

const int num_vertices = 9;

using namespace std;

// Operator overloading to print matrices easier
ostream& operator << (ostream& os, const vector<vector<double>> mat) {
    
    for(int i = 0; i < mat.size(); i++) {
        for(int j = 0; j < mat[i].size(); j++) {
            os << mat[i][j] << " ";
        }

        os << endl;
    }

    return os;
}

class Graph {

    private:
        vector<vector<double>> adj_mat;

    public:
        // Constructor
        Graph(vector<vector<double>> mat) : adj_mat(mat) {}

        void print_adj_mat(void) {
            
            cout << endl << adj_mat << endl;
        }

        double get_val(int i, int j) {
            
            return adj_mat[i][j];
        }
};

class ShortestPath {

    private:
        Graph graph;
        vector<double> dist;
        vector<bool> spt_set; 

    public:
        // Constructor
        ShortestPath(vector<vector<double>> mat) : graph(mat) {
            
            dist.assign(num_vertices, numeric_limits<double>::max());
            spt_set.assign(num_vertices, false); 
        }

        void print_adj_mat() {
            
            graph.print_adj_mat();
        }

        void print_shortest_path() {

            cout << "Vertex" << '\t' << "Distance" << endl;
            
            for(int i = 0; i < num_vertices; i++) {

                cout << i << "\t" << dist[i] << endl;
            } 
        }

        double min_distance() {
            
            double min = numeric_limits<double>::max(); 
            int min_index = 0;

            for(int i = 0; i < num_vertices; i++) {
                
                if(spt_set[i] == false && dist[i] <= min) {
                    
                    min = dist[i];
                    min_index = i;
                }
            }         
     
            return min_index; 
        }

        void dijkstra() {
            
            // Edge distance from vertex 0 to itself 
            dist[0] = 0;
    
            // Find shortest path for all vertices
            for(int i = 0; i < num_vertices - 1; i++) {
                
                int min_v = min_distance();
                spt_set[min_v] = true;

                for(int j = 0; j < num_vertices; j++) {
                
                    if(!spt_set[j] && graph.get_val(min_v, j) && dist[min_v] != numeric_limits<double>::max() && dist[min_v] + graph.get_val(min_v, j)  < dist[j])
                        dist[j] = dist[min_v] + graph.get_val(min_v, j);
                }  
            }
        }
};

int main() {

    vector<vector<double>> mat = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                                   { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                                   { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                                   { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                                   { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                                   { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                                   { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                                   { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                                   { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };

    ShortestPath shortest_path(mat);
    shortest_path.print_adj_mat();
    shortest_path.dijkstra();
    shortest_path.print_shortest_path();

    return EXIT_SUCCESS;
}
