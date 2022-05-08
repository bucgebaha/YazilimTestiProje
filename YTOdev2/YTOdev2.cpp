#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include "Masa.h"
#include "Dosya.h"
#include <fstream>

using namespace std;

vector<Kisi> KisileriOlustur(vector<string> icerik) {
    vector<Kisi> kisiler;

    for (int i = 0; i < icerik.size(); i += 4)
    {
        kisiler.push_back(Kisi(icerik[i], atof(icerik[i+1].c_str()), atof(icerik[i + 2].c_str()), stoi(icerik[i + 3])));
    }

    return kisiler;
}

int main()
{
    std::cout << std::fixed;
    std::cout << std::setprecision(2);
    Dosya dosya = Dosya("C:\\Users\\bhabu\\Desktop\\kisiler.txt");
    dosya.DosyaOku();
    vector<Kisi> kisiler = KisileriOlustur(dosya.GetAnlamliIcerik());
    Masa masa(kisiler);
    masa.OyunuBaslat();
}