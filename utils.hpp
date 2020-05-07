#ifndef UTILS_HPP
#define UTILS_HPP

#include "lib/math/lib/eigen_3.3.3/Eigen/Dense"
#include <fstream>


#define MAXBUFSIZE ((int) 1e6)

Eigen::MatrixXd read_eigen_matrix(const std::string &filename) {
    unsigned int cols = 0, rows = 0;
    double buffer[MAXBUFSIZE];
    std::ifstream istr(filename);

    if(!istr.is_open()) {
        std::string err = "Error: file " + filename + " does not exist";
        throw std::invalid_argument(err);
    }

    while(!istr.eof()) {
        std::string line;
        getline(istr, line);

        unsigned int temp = 0;
        std::stringstream stream(line);
        while(!stream.eof()){
            stream >> buffer[ cols*rows + temp++ ];
        }
        if (temp == 0){
            continue;
        }
        if (cols == 0){
            cols = temp;
        }
        rows++;
    }

    istr.close();

    rows--;

    Eigen::MatrixXd result(rows,cols);
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < cols; j++)
            result(i,j) = buffer[ cols*i + j ];

    return result;
};


#endif // UTILS_HPP
