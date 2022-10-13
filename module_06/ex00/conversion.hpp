#ifndef CONVERSION_H
# define CONVERSION_H

# include <string>
# include <iostream>
# include <cstdlib>
# include <cstring>
# include <limits>
# include <locale> 
# include <cmath>

void convert(std::string literal);
char analise(std::string literal, int *flow_lvl);
int calc_flow_lvl(std::string literal);

bool check_if_pseudo_float(std::string literal);
bool check_if_pseudo_double(std::string literal);
std::string trim(std::string str);


#endif