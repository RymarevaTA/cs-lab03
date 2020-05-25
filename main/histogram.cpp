#include "histogram.h"
#include <vector>
void find_minmax(const vector<double>& numbers, double& min, double& max)
{
    if(numbers.size()==0)
    {
        return;
    }
    else{
    min=numbers[0];
    max=numbers[0];
    for (size_t i=1; i<numbers.size(); i++)
    {
        if (min>numbers[i])
        {
            min=numbers[i];
        }
        if (max<numbers[i])
        {
            max=numbers[i];
        }}}
}
