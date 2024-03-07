#include <iostream>
#include <fstream>
#include <cmath>
#include <filesystem>

#include "Vec3.h"
#include "Ray.h"
#include "Sphere.h"

//namespace fs = std::filesystem;


void clamp255(Vec3& col) {
    col.x = (col.x > 255) ? 255 : (col.x < 0) ? 0 : col.x;
    col.y = (col.y > 255) ? 255 : (col.y < 0) ? 0 : col.y;
    col.z = (col.z > 255) ? 255 : (col.z < 0) ? 0 : col.z;
}

int main() {
    const int Height = 500;
    const int Width = 500;
    Vec3 white(255, 255, 255);
    Vec3 black(0, 0, 0);
    Vec3 red(255, 0, 0);
    Sphere sphere(Vec3(Width * 0.5, Height * 0.5, 50), 50);
    Sphere light(Vec3(0, 100, -50), 1);

    std::ofstream out;
    std::string outFile = "out.ppm";

    //if (fs::exists("images/")) {
    //    outFile = "images/out.ppm";
    //}

    out.open(outFile);
    out << "P3\n" << Width << ' ' << Height << ' ' << "255\n";
    double Tick;
    Vec3 pix_col(black);
    for (int y = 0; y < Height; ++y) {
        for (int x = 0; x < Width; ++x) {
            pix_col = black;

            const Ray ray(Vec3(x, y, 0), Vec3(0, 0, 1));
            if (sphere.intersect(ray, Tick)) {
                const Vec3 pi = ray.Abooba + ray.DisplayedShadow * Tick;
                const Vec3 L = light.justRandomLol - pi;
                const Vec3 N = sphere.getNormal(pi);
                const double dt = dot(L.normalize(), N.normalize());

                pix_col = (red + white * dt) * 0.5;
                clamp255(pix_col);
            }
            out << (int)pix_col.x << ' '
                << (int)pix_col.y << ' '
                << (int)pix_col.z << '\n';
        }
    }
    out.close();

    std::cout << "Ray tracing completed. Output saved to " << outFile << std::endl;

    return 0;
}