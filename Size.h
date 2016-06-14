#ifndef SIZE_H
#define SIZE_H


class Size
{
public:
    int width;
    int height;
    Size();
    Size(int w, int h);
    Size(const Size &sz);
};

#endif // SIZE_H