#include "ThetaFunctionChecker.hpp"


ThetaFunctionChecker::ThetaFunctionChecker(int num_cols_in, int min_coefficent_in, int max_coefficient_in, std::vector<std::vector<int>> lattice_1_in, std::vector<std::vector<int>> lattice_2_in){
    min_coefficient = min_coefficent_in;
    max_coefficient = max_coefficient_in;
    lattice_1 = lattice_1_in;
    lattice_2 = lattice_2_in;
    num_cols = num_cols_in;
}

void ThetaFunctionChecker::compute_norms(){ //hard code for 4 for now?
    for(int i = min_coefficient; i < max_coefficient + 1; ++i){
        for(int j = min_coefficient; j < max_coefficient + 1; ++j){
            for(int k = min_coefficient; k < max_coefficient + 1; ++k){
                for(int h = min_coefficient; h < max_coefficient + 1; ++h){
                    std::vector<int> curr_vector(4);
                    for(int row = 0; row < 4; ++row){
                       curr_vector[row] = (i * lattice_1[row][0]) + (j * lattice_1[row][1]) + (k * lattice_1[row][2]) + (h * lattice_1[row][3]); 
                    }
                    uint64_t norm_out = 0;
                    for(int row = 0; row < 4; ++row){
                        norm_out = norm_out + (curr_vector[row] * curr_vector[row]);
                    }
                    auto it = lattice_1_norms.find(norm_out);
                    if(it != lattice_1_norms.end()){
                        (it -> second)++; //sketchy
                    } else{
                        lattice_1_norms[norm_out] = 1;
                    }
                       
                }
            }
        }
    }

}

