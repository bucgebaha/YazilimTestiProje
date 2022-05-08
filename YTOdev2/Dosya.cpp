#include "Dosya.h"

void Dosya::DosyaOku()
{
    ifstream myfile(dosyaYolu);
    string line;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            this->icerik += line + "\n";
            this->satirSayisi++;
            IcerigiParcala(line); // Hashtaglerden split edilip kullanilacak.
        }
        myfile.close();
    }
}

string Dosya::GetIcerik()
{
    return this->icerik;
}

void Dosya::IcerigiParcala(string satir)
{
    stringstream test(satir);
    string kelime;

    while (getline(test, kelime, '#')) // Hashtaglerden ayirip bir vektorde tutuyoruz kelime kelime.
    {
        this->anlamliIcerik.push_back(kelime);
    }
}

vector<string> Dosya::GetAnlamliIcerik()
{
    return anlamliIcerik;
}

void Dosya::SetDosyaYolu(string dosyaYolu)
{
    this->dosyaYolu = dosyaYolu;
}

string Dosya::GetDosyaYolu()
{
    return this->dosyaYolu;
}

int Dosya::GetSatirSayisi()
{
    return satirSayisi;
}

Dosya::Dosya(string dosyaYolu)
{
    this->dosyaYolu = dosyaYolu;
    this->icerik = "";
    this->satirSayisi = 0;
}

