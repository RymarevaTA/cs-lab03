#include <iostream>
#include <vector>
#include "histogram.h"
#include "svg.h"
#include <curl/curl.h>
#include <sstream>
#include <string>
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

size_t
write_data(void* items, size_t item_size, size_t item_count, void* ctx) {
    const size_t data_size= item_size*item_count;
    const char* new_items = reinterpret_cast<const char*>(items);
    stringstream* buffer = reinterpret_cast<stringstream*>(ctx);
    buffer->write(new_items, data_size);
    return data_size;
}

Input
download(const string& address)
{
    stringstream buffer;
    curl_global_init(CURL_GLOBAL_ALL);
    CURL* curl = curl_easy_init();
    if(curl)
    {
        CURLcode res;
        curl_easy_setopt(curl, CURLOPT_URL, address.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, write_data);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (res!= CURLE_OK)
        {
            cerr<<curl_easy_strerror(res);
            exit(1);
        }
        curl_easy_cleanup(curl);
    }

    return read_input(buffer, false);
}


int main(int argc, char* argv[])
{
    Input input;
    if (argc>1)
    input=download(argv[1]);
    else
    input = read_input(cin, true);
    const auto bins=make_histogram(input);
    show_histogram_svg(bins);
    return 0;
}
