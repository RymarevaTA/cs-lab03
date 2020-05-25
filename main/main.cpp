#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
using namespace std;


vector<double> input_numbers(istream& in, size_t count)
{
    vector <double> result(count);
    for (int i=0; i<count; i++)
    {
        in>>result[i];
    }
    return result;
}

Input read_input(istream& in, bool prompt)
{

    Input data;
    if (prompt)
    {
        cerr << "Enter number count: ";
        size_t number_count;
        in >> number_count;

        cerr << "Enter numbers: ";
        data.numbers = input_numbers(in, number_count);


        cerr << "Enter column count: ";
        in >> data.bin_count;
    }
    else
    {
        size_t number_count;
        in >> number_count;

        data.numbers = input_numbers(in, number_count);


        in >> data.bin_count;
    }

    return data;
}

vector<size_t> make_histogram(const Input& data)
{
    vector<size_t> result(data.bin_count, 0);
    double min;
    double max;
    find_minmax(data.numbers, min, max);
    for (double number : data.numbers)
    {
        size_t bin = (size_t)((number - min) / (max - min) * data.bin_count);
        if (bin == data.bin_count)
        {
            bin--;
        }
        result[bin]++;
    }

    return result;
}

int main()
{

    const auto input = read_input(cin, true);
    const auto bins=make_histogram(input);
    show_histogram_svg(bins);
    return 0;
}
