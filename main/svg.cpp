#include "svg.h"
#include "histogram.h"
#include <vector>
#include <string>
#include <iostream>
#include <windows.h>
#include <cstdio>
using namespace std;

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}

void svg_end() {
    cout << "</svg>\n";
}

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text <<"</text>";
}

void svg_rect(double x, double y, double width, double height, string stroke, string fill) {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />";
}

void show_histogram_svg(const vector<size_t>& bins) {
const size_t MAX_ASTERISK=35;
const auto IMAGE_WIDTH = 550;
const auto IMAGE_HEIGHT = 380;
const auto TEXT_LEFT = 20;
const auto TEXT_BASELINE = 20;
const auto TEXT_WIDTH = 50;
const auto BIN_HEIGHT = 30;
const auto BLOCK_WIDTH = 10;
double top = 0;
svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
for (size_t bin : bins) {
unsigned max_count=0;
for (size_t bin : bins)
{
if(max_count<bin)
max_count=bin;
}
for (size_t bin : bins)
    {
    size_t height=35;
if(max_count>MAX_ASTERISK)
height=MAX_ASTERISK*((static_cast<double>(bin))/max_count);
else
{
height=bin;
}
height = BLOCK_WIDTH * height;
    svg_text(TEXT_LEFT, top + TEXT_BASELINE, to_string(bin));
    svg_rect(TEXT_WIDTH, top, height, BIN_HEIGHT,"black","black");

    top += BIN_HEIGHT;
}
svg_text(TEXT_WIDTH, top + TEXT_BASELINE,make_info_text());
    svg_end();
}
}
