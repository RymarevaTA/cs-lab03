#include "svg.h"
#include "histogram.h"
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <cstdio>
using namespace std;

void svg_begin(double width, double height)
{
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end()
{
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text)
{
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill)
{
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

size_t calculation_star_factor (size_t MAX_WIDTH, size_t max_count)
{
    size_t star_factor=MAX_WIDTH/max_count;
    return (star_factor);
}

size_t calculation_interval_width (size_t star_factor, size_t interval)
{
    size_t interval_width=star_factor*interval;
    return(interval_width);
}



void show_histogram_svg(const vector<size_t>& bins, size_t bin_count, size_t interval)
{
    const auto IMAGE_WIDTH = 550;
    const auto IMAGE_HEIGHT = 300;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_HEIGHT = 30;
    size_t star_factor;
auto BLOCK_WIDTH = 10;
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    double top = 0;
    size_t max_count=0;
    for (size_t bin : bins)
    {
        if(max_count<bin)
            max_count=bin;
    }
    double MAX_WIDTH=IMAGE_WIDTH-4.5*TEXT_WIDTH;
    size_t interval_count;
    if (max_count%interval!=0)
        interval_count=max_count/interval+1;
    else
        interval_count=max_count/interval;
    star_factor=calculation_star_factor(MAX_WIDTH, max_count);
    size_t interval_width=calculation_interval_width(star_factor,interval);
    for (size_t bin : bins)
    {
        const double bin_width = star_factor * bin;

        svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
        svg_rect(TEXT_WIDTH, top, bin_width, BIN_HEIGHT,"black","green");

        top += BIN_HEIGHT;
    }

    size_t otstup= (double)bin_count*BIN_HEIGHT+15;
    if (interval<4 || interval>9)
        svg_text(TEXT_WIDTH, otstup, "ERROR!");
    else
    {
        size_t abscissa=TEXT_WIDTH;
        for (size_t i=1; i<=interval_count; i++)
        {
            svg_rect(abscissa, otstup, interval_width, BIN_HEIGHT, "black", "#90EE90");
            abscissa+=interval_width;
        }
        svg_text(TEXT_WIDTH, otstup+50, "0");
        svg_text(TEXT_WIDTH+interval_width, otstup+50, to_string(interval));
        svg_text(TEXT_WIDTH+interval_count*interval_width, otstup+50, to_string(interval*interval_count));
    }
svg_text(TEXT_WIDTH,otstup+80,make_info_text());
    svg_end();
}

