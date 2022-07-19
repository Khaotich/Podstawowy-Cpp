#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

using namespace std;

struct RGB
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

enum class ColorLayer
{
    Red,
    Green,
    Blue
};

class Image
{
  public:
    void load(const string& filename);
    int height() const;
    int width() const;

    // unimplemented
    void save_as(const string& filename);
    void add_watermark();
    void blurr();
    void extract_layer(ColorLayer color_layer);
    void filter();
    void flip_horizontally();
    void flip_vertically();
    void inflate();
    void negative();
    void rotate_clockwise_90();
    void sepia();
    void shrink();
    void to_grayscale();

  private:
    vector<vector <RGB> > pixels;
    int my_width{0};
    int my_height{0};
    int color_depth{0};
    string magic;
    string filename;
};



#endif  // IMAGE_H
