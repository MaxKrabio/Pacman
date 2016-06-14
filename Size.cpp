#include "Size.h"

Size::Size()
{
    width = 0;
    height = 0;
}
Size::Size(int w, int h) {
 this->width = w;
 this->height = h;
}

Size::Size(const Size &sz) {
    this->width = sz.width;
    this->height = sz.height;
}
