#include "histogram.h"
#include <string>


void find_minmax(vector<double> numbers, double& min, double& max)
{
    min = numbers[0];
    max = numbers[0];
    for (auto number : numbers)
    {
        if (number < min)
        {
            min = number;
        }
        if (number > max)
        {
            max = number;
        }
    }
    return;
}

void show_histogram_text(vector<size_t> bins)
{
    const size_t SCREEN_WIDTH = 80;
    const size_t MAX_ASTERISK = SCREEN_WIDTH - 4 - 1;

    size_t max_count = 0;
    for (size_t count : bins)
    {
        if (count > max_count)
        {
            max_count = count;
        }
    }
    const bool scaling_needed = max_count > MAX_ASTERISK;

    for (size_t bin : bins)
    {
        if (bin < 100)
        {
            cout << ' ';
        }
        if (bin < 10)
        {
            cout << ' ';
        }
        cout << bin << "|";

        size_t height = bin;
        if (scaling_needed)
        {
            const double scaling_factor = (double)MAX_ASTERISK / max_count;
            height = (size_t)(bin * scaling_factor);
        }

        for (size_t i = 0; i < height; i++)
        {
            cout << '*';
        }
        cout << '\n';
    }
    return;
}

string make_info_text()
{
    stringstream buffer;
    DWORD WINAPI GetVersion();
    DWORD mask = 0x0000ffff;
    DWORD mask_2 = 0x000000ff;
    DWORD info = GetVersion();
    DWORD platform = info >> 16;
    DWORD version = info & mask;
    DWORD version_major = version & mask_2;
    DWORD version_minor = version >>8;
    if ((version & 0x40000000) == 0)
    {
        printf("equal to zero\n");
    }

    DWORD build = platform;

    buffer << "Windows v" << version_major << "." << version_minor << "(build " << build << ")\n";
    char computer_name[MAX_COMPUTERNAME_LENGTH + 1];
    DWORD size = sizeof(computer_name);
    GetComputerNameA(computer_name, &size);
    buffer << "Computer name: " << computer_name << "\n";
    return buffer.str(); }
