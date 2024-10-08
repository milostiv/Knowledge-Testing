/******************************************************************************

                        Milos Trifovic's assignment.
            Code tested using g++ version 9.4.0 on Ubuntu 20.04.6 LTS.

*******************************************************************************/

#include <iostream>
#include <vector>
#include <limits>
#include <random>

const int num_vertices = 50;
//const double density = 0.2; // 20%
const double density = 0.4; // 40%
const double dist_low = 1.0;
const double dist_hi = 10.0;

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

// Function to generate random probability using density
bool prob(double density) {

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(0.0, 1.0);

    if(distr(gen) < density)
        return true;

    return false; 
}

// Function to create a random square matrix (graph or connectivity matrix)
vector<vector<double>> rand_graph(int size, double dist_low, double dist_hi) {
    
    vector<vector<double>> mat(size, vector<double>(size, 0.0));

    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<double> distr(dist_low, dist_hi);

    for(int i = 0; i < size; i++) {
        for(int j = i; j < size; j++) {
            
            if(i == j) mat[i][j] = 0.0; // No loops
            else if(prob(density))
                mat[i][j] = mat[j][i] = distr(gen);
        }
    }

    return mat;
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

            cout << endl;
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

        double calc_average() {

            double avg = 0;
            
            for(int i = 0; i < num_vertices; i++) 
                avg += dist[i]; 

            return avg/num_vertices;
        }
};

int main() {

    ShortestPath shortest_path(rand_graph(num_vertices, dist_low, dist_hi));
    shortest_path.print_adj_mat();
    shortest_path.dijkstra();
    shortest_path.print_shortest_path();

    cout << "Average: " << shortest_path.calc_average() << endl;

    return EXIT_SUCCESS;
}
