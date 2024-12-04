#ifndef TITLE_HPP
#define TITLE_HPP

#include <string>
#include <fstream>
#include "eins/tui_support.h"



class Text {
public:
    Component text1(string str);
    Component create(string path);
};

#endif // TITLE_HPP
