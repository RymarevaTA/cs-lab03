#ifndef HISTOGRAM_H_INCLUDED
#define HISTOGRAM_H_INCLUDED
#include <string>
#include <windows.h>
#include <sstream>
#include <cstdio>
#include <vector>
using namespace std;

void find_minmax (const vector<double>& numbers, double& min, double& max);
string make_info_text();
#endif // HISTOGRAM_H_INCLUDED
