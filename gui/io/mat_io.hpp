//
//  mat_io.h
//  SequentialRandomForest
//
//  Created by jimmy on 2017-07-01.
//  Copyright (c) 2017 Nowhere Planet. All rights reserved.
//

#ifndef __SequentialRandomForest__mat_io__
#define __SequentialRandomForest__mat_io__

// matlab input output
#include <stdio.h>
#include <Eigen/Dense>
#include <string>
#include <vector>
#include <unordered_map>


using std::unordered_map;
using std::vector;
using std::string;

namespace matio {
    
    // suppport Eigen::MatrixXd, Eigen::MatrixXf and Eigen::MatrixXi
    template<class matrixT>
    bool readMatrix(const char *file_name, const char *var_name, matrixT & data, bool verbose = true);
    
    bool readString(const char *file_name, const char *var_name, std::string& data, bool vervose = true);
    
    
    // support Eigen::MatrixXd, Eigen::MatrixXf
    // In .mat file, both are in double format
    template<class matrixT>
    bool writeMatrix(const char *file_name, const char *var_name, const matrixT& data);
    
    
    template<class matrixT>
    bool writeMultipleMatrix(const char *file_name,
                             const std::vector<std::string>& var_name,
                             const std::vector<matrixT>& data);
    
    template<class matrixT>
    bool writeStringMatrix(const char *file_name,
                           const unordered_map<string, string>& strs,
                           const unordered_map<string, matrixT>& mats);
    
} // name space matio



#endif /* defined(__SequentialRandomForest__mat_io__) */
