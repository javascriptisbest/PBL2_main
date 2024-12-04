#include "app/Title.hpp"


Component Text::text1(string str) {
    return Renderer([str]() {
        auto t = text(str) | color(Color::HotPink2) | center;
            return t;
        });
}

Component Text::create(string path) {
    ifstream input("D:\\edge ngu\\ppl2\\PBL2-main\\src\\" + path);
    string str;

    auto container = Container::Vertical({});

    for (int i = 0; i < 7; i++) {
        getline(input, str);
        container->Add(text1(str));
    }
    input.close();
    return container;
}
