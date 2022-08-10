#include <fstream>
#include <iostream>

using namespace std;

int main() {
    constexpr auto width = 100u, height = 200u;

    ofstream ofs("first.ppm", ios_base::out | ios_base::binary);

    ofs << "P6" << endl << width << ' ' << height << endl << "255" << endl;
 
    for (auto j = 0u; j < height; ++j)
        for (auto i = 0u; i < width; ++i){
            ofs << (char)(j%256 )      // red
		<< (char)(i%256)        // green
		<< (char)((i+j)%256); // red, green, blue
        }
    ofs.close();
    return EXIT_SUCCESS;
}
