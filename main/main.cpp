#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
using namespace std;

vector<double> input_numbers(istream& in, size_t count) {
    vector<double> result(count);
    for (size_t i = 0; i < count; i++) {
        cin >> result[i];
    }
    return result;
}

vector<size_t> make_histogram(const vector<double>& numbers, size_t bin_count){
    double min, max;
    find_minmax(numbers, min, max);
    vector<size_t>count(bin_count,0);
    for (double x: numbers){
        size_t bin_index=(size_t)(x-min)*(bin_count)/(max-min);
        if (bin_index==bin_count)
        {
            bin_index--;
        }
        count[bin_index]++;}
    return count;
}

int main()
{
    size_t number_count;
    cerr<< "enter number count";
    cin>>number_count;
    const auto numbers=input_numbers(cin, number_count);

    size_t bin_count;
    cerr<< "enter bin count";
    cin>>bin_count;
    const auto bins = make_histogram(numbers, bin_count);
    show_histogram_svg(bins);
    return 0;

}
