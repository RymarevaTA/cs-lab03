#pragma once

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <curl/curl.h>
using namespace std;

struct Input
{
    vector<double> numbers;
    size_t bin_count;
};

void find_minmax(vector<double> numbers, double& min, double& max);

void show_histogram_text(vector<size_t> bins);
