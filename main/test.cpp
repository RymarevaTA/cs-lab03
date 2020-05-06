#include "histogram.h"
#include "svg.h"
#include <cassert>

void test_positive()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 2, 3}, min, max);
    assert(min == 1);
    assert(max == 3);
}

void test_negative()
{
    double min = 0;
    double max = 0;
    find_minmax({-1, -2, -3}, min, max);
    assert(min == -3);
    assert(max == -1);
}

void test_same()
{
    double min = 0;
    double max = 0;
    find_minmax({1, 1, 1}, min, max);
    assert(min == 1);
    assert(max == 1);
}

void test_one()
{
    double min = 0;
    double max = 0;
    find_minmax({2}, min, max);
    assert(min == 2);
    assert(max == 2);
}

void test_empty()
{
    double min = 0;
    double max = 0;
    find_minmax({}, min, max);
    assert(min == 0);
    assert(max == 0);
}

void test_calculation_star_factor ()
{
   size_t test_star=0;
    test_star=calculation_star_factor(250, 2);
    assert(test_star == 125);
}
void test_interval_width ()
{
    size_t test_interval=0;
    test_interval=calculation_interval_width (30, 4);
    assert(test_interval == 120);
}



int
main()
{
    test_positive();
    test_negative();
    test_same();
    test_one();
    test_empty();
    test_calculation_star_factor ();
    test_interval_width ();

}
