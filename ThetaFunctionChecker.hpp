#include <vector>
#include <unordered_map>
#include <cstdint>
class ThetaFunctionChecker{
    public:
    std::vector<std::vector<int>> lattice_1;
    std::vector<std::vector<int>> lattice_2;
    std::unordered_map<uint64_t, uint64_t> lattice_1_norms;
    std::unordered_map<uint64_t, uint64_t> lattice_2_norms;
    int num_cols;
    int min_coefficient; 
    int max_coefficient; //the largest integer multiple we can multiply each basis vector by
    ThetaFunctionChecker(int num_cols_in, int min_coefficient_in, int max_coefficient_in, std::vector<std::vector<int>> lattice_1_in, std::vector<std::vector<int>> lattice_2_in);
    void compute_norms();
    void output_results();

};