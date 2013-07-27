#include <vector>
#include "myMath.hpp"


double myMath::add(const std::vector<double> args){
    
    double result = 0;
    
    for(std::vector<double>::size_type i=0; i != args.size(); i++)
        result += args[i];
    
    return result;
    
}

double myMath::subtract(const std::vector<double> args){
    
    double result = args[0];
    
    for(std::vector<double>::size_type i=1; i != args.size(); i++)
        result -= args[i];
    
    return result;
}

double myMath::multiply(const std::vector<double> args){
    
    double result = args[0];
    
    for(std::vector<double>::size_type i=1; i != args.size(); i++)
        result *= args[i];
    
    return result;
    
}