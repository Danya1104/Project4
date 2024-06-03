#pragma once
#include <string>
using namespace std;
class Line {
public:
    int value;
    string key;


    Line() : value(0), key("") {}
    Line(int v, string k) : value(v), key(k) {}
};