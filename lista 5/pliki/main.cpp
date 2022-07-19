#include "image.h"

int main()
{
    Image image;
    image.load("obrazek.ppm");

    //image.filter();
    //image.extract_layer(ColorLayer :: Red);
    //image.add_watermark();
    //image.flip_horizontally();
    //image.flip_vertically();
    //image.to_grayscale();
    //image.negative();
    //image.sepia();
    //image.rotate_clockwise_90();
    //image.inflate();
    //image.shrink();
    //for(int i=0; i<10; i++)image.blurr();
    //image.filter();

    image.save_as("x.ppm");

    return 0;
}
