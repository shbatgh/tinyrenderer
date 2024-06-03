#include "tgaimage.h"
#include <iostream>

const TGAColor white = TGAColor(255, 255, 255, 255);
const TGAColor red   = TGAColor(255, 0,   0,   255);

void line(int x0, int y0, int x1, int y1, TGAImage &image, TGAColor color) {
  double slope = (y1 - y0) / (x1 - x0); 
  int dx = x1 - x0;
  int dy = y1 - y0;
  int d = 2 * dy - dx;
  int deltaE = 2 * dy;
  int ne = 2 * (dy - dx);
  int currY = y0;
  for (int i = x0; i < x1; i++) {
    if (d <= 0) {
      d++;
      i++;
      image.set(i, currY, color);
    } else {
      d += ne;
      i++;
      currY++;
      image.set(i, currY, color);
    }
  }  
  image.set(0, 0, color);
}

int main(int argc, char** argv) {
  TGAImage image(100, 100, TGAImage::RGB);
  line(13, 20, 80, 40, image, white);
  image.flip_vertically(); // i want to have the origin at the left bottom corner of the image
	image.write_tga_file("output.tga");
  std::cout << "test" << std::endl;
	return 0;
}

