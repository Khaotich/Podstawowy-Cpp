#include "image.h"

#include <fstream>
#include <experimental/filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

using namespace std;

void Image :: load(const string& filename)
{
    //rodzaj grafiki
    constexpr auto MAGIC = "P6";

    //nazwa otwieranego pliku zapisana do obiektu
    this -> filename = filename;

    //otwarcie pliku w trybie binarnym
    ifstream in(filename, ios :: binary);

    //sprawdzamy czy się udało otworzyć plik
    if (!in) throw invalid_argument("failed to open \"" + filename + "\"");

    //pobranie ze zdjęcia rodzaju grafiki
    in >> magic;

    //sparawdzamy czy rodzaj otwieranej grafiki to ppm
    if (magic != MAGIC) throw logic_error("unknown magic naumber " + magic);

    //paramerty zdjęcia wpisujemy do pól obiektu
    in >> my_width >> my_height >> color_depth;

    //sprawdzamy czy parametry są prawidłowe
    if(!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw logic_error("invalid image parameter(s): " + to_string(my_width) + " " +
                               to_string(my_height) + " " + to_string(color_depth));
    in.ignore(1);

    //sprawdzamy wysokość zdjęcia
    pixels.resize(my_height);

    //wczytujemy pixele do vectora ze zdjęcia
    for (auto& line : pixels)
    {
        //sprawdzamy szerokość zdjęcia
        line.resize(my_width);

        //odczytujemy piksel po pikselu
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));

        //sprawdzamy czy poprawnie pobrano piksele
        if (!in) throw logic_error("failed to read binary pixel data from file " + filename);
    }

    //zamykamy plik
    in.close();
}

//zadanie 1
void Image :: save_as(const string& filename)
{
    ofstream file(filename, ios :: binary);

    if(file.is_open())
    {
        file << magic << "\n";
        file << my_width << "\n";
        file << my_height << "\n";
        file << color_depth << "\n";

        for(int i = 0; i < my_height; i++)
        {
            for(int j = 0; j < my_width; j++)
            {
                file.write((char*) &pixels[i][j], sizeof(RGB));
            }
        }
    }
    file.close();
}

//zadanie 2
//dodaje białą linię w połowie wysokości obrazka
void Image :: add_watermark()
{
    int position = my_height / 2;

    for(int i = 0; i < my_width; i++)
    {
        pixels[position][i].red  = 255;
        pixels[position][i].green = 255;
        pixels[position][i].blue = 255;
    }
}

//zadanie 3
void Image :: blurr()
{
    vector<vector <RGB> > tmp = pixels;

    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int r = 0;
            int g = 0;
            int b = 0;

            for(int x = -1; x < 2; x++)
            {
                int tx;
                if(i == 0 and x == -1) tx = 0;
                else if((i == my_height - 1) and (x == 1)) tx = my_height -1;
                else tx = i + x;

                for(int y = -1; y < 2; y++)
                {
                    if(x == 0 and y == 0) continue;

                    int ty;
                    if(j == 0 and y == -1) ty = 0;
                    else if((j == my_width - 1) and y == 1) ty = my_width -1;
                    else ty = j + y;

                    r += tmp[tx][ty].red;
                    g += tmp[tx][ty].green;
                    b += tmp[tx][ty].blue;

                }
            }

            pixels[i][j].red = r/8;
            pixels[i][j].green = g/8;
            pixels[i][j].blue = b/8;
        }
    }
}

//zadanie 4
void Image :: extract_layer(ColorLayer color_layer)
{
    if(color_layer == ColorLayer :: Red)
    {
        for(int i = 0; i < my_height; i++)
        {
            for(int j = 0; j < my_width; j++)
            {
                pixels[i][j].green = 0;
                pixels[i][j].blue = 0;
            }
        }
    }
    else if(color_layer == ColorLayer :: Green)
    {
        for(int i = 0; i < my_height; i++)
        {
            for(int j = 0; j < my_width; j++)
            {
                pixels[i][j].red = 0;
                pixels[i][j].blue = 0;
            }
        }
    }
    else if(color_layer == ColorLayer :: Blue)
    {
        for(int i = 0; i < my_height; i++)
        {
            for(int j = 0; j < my_width; j++)
            {
                pixels[i][j].red = 0;
                pixels[i][j].green = 0;
            }
        }
    }
}

//zadanie 5
void Image :: filter()
{
    vector<vector <RGB> > tmp = pixels;

    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int ti, tj;
            if(i == my_height - 1) ti = my_height - 2;
            else ti = i;
            if(j == my_width - 1) tj = my_width - 2;
            else tj = j;

            pixels[i][j].red = abs(tmp[ti][tj].red - tmp[ti+1][tj+1].red);
            pixels[i][j].green = abs(tmp[ti][tj].green - tmp[ti+1][tj+1].green);
            pixels[i][j].blue = abs(tmp[ti][tj].blue - tmp[ti+1][tj+1].blue);
        }
    }
}

//zadanie 6
void Image :: flip_horizontally()
{
    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width / 2; j++)
        {
            swap(pixels[i][j], pixels[i][my_width - (j + 1)]);
        }
    }
}

//zadanie 7
void Image :: flip_vertically()
{
    for(int i = 0; i < my_height / 2; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            swap(pixels[i][j], pixels[my_height - (i + 1)][j]);
        }
    }
}

//zadanie 8
void Image :: inflate()
{
    vector<vector <RGB> > tmp;

    tmp.resize(my_height*2);
    for (int i = 0; i < my_height * 2; i++)
    {
        tmp[i].resize(my_width * 2);
    }

    int h = 0;
    int w = 0;

    for(int i = 0; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            for(int x = 0; x < 2; x++)
            {
                for(int y = 0; y < 2; y++)
                {
                    tmp[x+h][y+w] = pixels[i][j];
                }
            }
            w += 2;
        }
        h += 2;
        w = 0;
    }

    my_height *= 2;
    my_width *= 2;

    pixels.resize(my_height);
    for (int i = 0; i < my_height; i++)
    {
        pixels[i].resize(my_width);
    }

    pixels.assign(tmp.begin(), tmp.end());
}

//zadanie 9
void Image :: negative()
{
    for(int i = 0 ; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            pixels[i][j].red  = 255 - pixels[i][j].red;
            pixels[i][j].green = 255 - pixels[i][j].green;
            pixels[i][j].blue = 255 - pixels[i][j].blue;
        }
    }
}

//zadanie 10
void Image :: rotate_clockwise_90()
{
    vector<vector <RGB> > tmp;

    tmp.resize(my_width);
    for (int i = 0; i < my_width; i++)
    {
        tmp[i].resize(my_height);
    }

    for (int i = 0; i < my_height; i++)
    {
       for (int j = 0; j < my_width; j++)
       {
           tmp [j][my_height - i - 1] = pixels[i][j];
       }
    }

    swap(my_height, my_width);
    pixels.assign(tmp.begin(), tmp.end());
}

//zadanie 11
void Image :: sepia()
{
    for(int i = 0 ; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int s = (pixels[i][j].red + pixels[i][j].blue + pixels[i][j].green) / 3;
            pixels[i][j].red  = s;
            pixels[i][j].green = s;
            pixels[i][j].blue = s;
        }
    }

    for(int i = 0 ; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int R = pixels[i][j].red;
            int G = pixels[i][j].green;
            int B = pixels[i][j].blue;

            pixels[i][j].red = 0.393*R + 0.769*G + 0.189*B;
            pixels[i][j].green = 0.349*R + 0.686*G + 0.168*B;
            pixels[i][j].blue = 0.272*R + 0.534*G + 0.131*B;

            if(pixels[i][j].red > 255) pixels[i][j].red = 255;
            if(pixels[i][j].green > 255) pixels[i][j].green = 255;
            if(pixels[i][j].blue > 255) pixels[i][j].blue = 255;
        }
    }
}

//zadanie 12
void Image :: shrink()
{
    vector<vector <RGB> > tmp;

    tmp.resize(my_height / 2);
    for (int i = 0; i < my_height / 2; i++)
    {
        tmp[i].resize(my_width / 2);
    }

    int h = 0;
    int w = 0;

    for(int i = 0; i < my_height / 2; i++)
    {
        for(int j = 0; j < my_width / 2; j++)
        {
            for(int x = 0; x < 2; x++)
            {
                for(int y = 0; y < 2; y++)
                {
                    tmp[i][j] = pixels[x + h][y + w];
                }
            }
            w += 2;
        }
        h += 2;
        w = 0;
    }

    my_height /= 2;
    my_width /= 2;

    pixels.resize(my_height);
    for (int i = 0; i < my_height; i++)
    {
        pixels[i].resize(my_width);
    }

    pixels.assign(tmp.begin(), tmp.end());
}

//zadanie 13
void Image :: to_grayscale()
{
    for(int i = 0 ; i < my_height; i++)
    {
        for(int j = 0; j < my_width; j++)
        {
            int s = (pixels[i][j].red + pixels[i][j].blue + pixels[i][j].green) / 3;
            pixels[i][j].red  = s;
            pixels[i][j].green = s;
            pixels[i][j].blue = s;
        }
    }
}

//zadanie 14
int Image :: height() const
{
    return my_height;
}

//zadanie 15
int Image :: width() const
{
    return my_width;
}
