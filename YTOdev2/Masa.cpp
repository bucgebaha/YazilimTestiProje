#include "Masa.h"
#include <Windows.h>
#include <iostream>
#include <thread>

using std::cout;
using std::cin;
using std::endl;
using std::this_thread::sleep_for;
using namespace std::chrono_literals;

bool Masa::ElendiMi(Kisi kisi)
{
    return (kisi.GetToplamPara() < 1000);
}

void Masa::OyunuBaslat()
{
    while (this->GetKisiSayisi() > 0) {
        sleep_for(std::chrono::milliseconds(500));
        YeniTur();
        MasaCizdir();
    }

    MasaCizdirFinal();
}

int Masa::GetTurNo()
{
    return this->turNo;
}

void Masa::YeniTur()
{
    this->turNo++;
    this->SansliSayiCek();
    this->BahisleriTopla();
    this->BahisKontrol();
    this->EnZenginiBul();
}

void Masa::BahisleriTopla()
{
    float yatirilanBahis = 0;
    for (int i = 0; i < this->GetKisiSayisi(); i++)
    {
        yatirilanBahis += this->kisiler[i].GetToplamPara() * this->kisiler[i].GetBahisOrani();
        this->kisiler[i].SetToplamPara(this->kisiler[i].GetToplamPara() - this->kisiler[i].GetToplamPara() * this->kisiler[i].GetBahisOrani());
    }

    this->SetMasaninParasi(this->GetMasaninParasi() + yatirilanBahis);
}

void Masa::SansliSayiCek()
{
    int yeniSansliSayi;
    yeniSansliSayi = rand() % 10 + 1;
    this->sansliSayi = yeniSansliSayi;
}

float Masa::GetMasaninParasi()
{
    return this->masaninParasi;
}

void Masa::SetMasaninParasi(float para)
{
    this->masaninParasi = para;
}

string Masa::GetEnZenginKisiAd()
{
    return enZenginKisiAd;
}

void Masa::SetEnZenginKisiAd(string ad)
{
    this->enZenginKisiAd = ad;
}

void Masa::EnZenginiBul()
{
    if (this->GetKisiSayisi() > 0) {
        Kisi enZenginKisi = this->kisiler[0];

        for (int i = 1; i < this->GetKisiSayisi(); i++)
        {
            if (this->kisiler[i].GetToplamPara() > enZenginKisi.GetToplamPara())
                enZenginKisi = this->kisiler[i];
        }

        this->SetEnZenginKisiAd(enZenginKisi.GetAdSoyad());
        this->SetEnZenginKisiPara(enZenginKisi.GetToplamPara());
    }
}

float Masa::GetEnZenginKisiPara()
{
    return this->enZenginKisiPara;
}

Masa::Masa(vector<Kisi> kisiler)
{
    srand(time(NULL));
    this->kisiler = kisiler;
    this->turNo = 0;
    this->masaninParasi = 0;
    EnZenginiBul();
}

int Masa::GetKisiSayisi()
{
    return this->kisiler.size();
}

void Masa::SetEnZenginKisiPara(float para)
{
    this->enZenginKisiPara = para;
}

void Masa::MasaCizdir()
{
    COORD coord;
    string sansliSayiMetni = "SANSLI SAYI: " + to_string(sansliSayi);
    string turMetni = "TUR: " + to_string(turNo);
    string masaBakiyeMetni = "MASA BAKIYE: " + to_string((int)masaninParasi) + " TL";
    string enZenginBakiyeMetni = "BAKIYESI: " + to_string((int)enZenginKisiPara) + " TL";
    string enZenginKisiMetni = "EN ZENGIN KISI";
    int width = 45;
    int length = 13;
    for (int i = 0; i < length; i++)
    {
        coord.X = 20;
        coord.Y = 4 + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == 2 || i == 3 || i == 12 || j == 0 || j == 1 || j == 44 || j == 43)
                cout << "#";
            else if (i == 1 && j == (int)(width - sansliSayiMetni.size()) / 2)
            {
                cout << sansliSayiMetni;
                j += sansliSayiMetni.size() - 1;
            }
            else if (i == 4 && j == (int)(width - turMetni.size()) / 2)
            {
                cout << turMetni;
                j += turMetni.size() - 1;
            }
            else if (i == 5 && j == (int)(width - masaBakiyeMetni.size()) / 2)
            {
                cout << masaBakiyeMetni;
                j += masaBakiyeMetni.size() - 1;
            }
            else if (i == 7)
                cout << "-";
            else if (i == 8 && j == (int)(width - enZenginKisiMetni.size()) / 2)
            {
                cout << enZenginKisiMetni;
                j += enZenginKisiMetni.size() - 1;
            }
            else if (i == 9 && j == (int)(width - enZenginKisiAd.size()) / 2)
            {
                cout << enZenginKisiAd;
                j += enZenginKisiAd.size() - 1;
            }
            else if (i == 10 && j == (int)(width - enZenginBakiyeMetni.size()) / 2)
            {
                cout << enZenginBakiyeMetni;
                j += enZenginBakiyeMetni.size() - 1;
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
}

int Masa::GetSansliSayi() {
    return this->sansliSayi;
}

void Masa::MasaCizdirFinal()
{
    COORD coord;
    string turMetni = "TUR: " + to_string(turNo);
    string masaBakiyeMetni = "MASA BAKIYE: " + to_string((int)masaninParasi) + " TL";
    string oyunBittiMetni = "OYUN BITTI";
    int width = 45;
    int length = 13;
    for (int i = 0; i < length; i++)
    {
        coord.X = 20;
        coord.Y = 4 + i;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
        for (int j = 0; j < width; j++)
        {
            if (i == 0 || i == 3 || i == 12 || j == 0 || j == 1 || j == 44 || j == 43)
                cout << "#";
            else if (i == 4 && j == (int)(width - turMetni.size()) / 2)
            {
                cout << turMetni;
                j += turMetni.size() - 1;
            }
            else if (i == 5 && j == (int)(width - masaBakiyeMetni.size()) / 2)
            {
                cout << masaBakiyeMetni;
                j += masaBakiyeMetni.size() - 1;
            }
            else if (i == 7)
                cout << "-";
            else if (i == 8 && j == (int)(width - oyunBittiMetni.size()) / 2)
            {
                cout << oyunBittiMetni;
                j += oyunBittiMetni.size() - 1;
            }
            else
                cout << " ";
        }
        cout << "\n";
    }
}

void Masa::KisiEkle(Kisi kisi)
{
    this->kisiler.push_back(kisi);
}

void Masa::KisiSil(Kisi kisi)
{
    for (int i = 0; i < this->GetKisiSayisi(); i++) {
        if (this->kisiler[i].GetAdSoyad() == kisi.GetAdSoyad())
            this->kisiler.erase(kisiler.begin() + i);
    }
}

void Masa::BahisKontrol()
{
    for (int i = 0; i < this->GetKisiSayisi(); i++)
    {
        if (this->sansliSayi == this->kisiler[i].GetSansliSayi())
            Kazandi(i);
        else
            Kaybetti(this->kisiler[i]);
    }
}

void Masa::Kazandi(int index)
{
    this->kisiler[index].SetToplamPara(this->kisiler[index].GetToplamPara() + (this->kisiler[index].GetToplamPara() / (1 - this->kisiler[index].GetBahisOrani())) * this->kisiler[index].GetBahisOrani() * 10);
}

void Masa::Kaybetti(Kisi kisi)
{
    if (ElendiMi(kisi))
    {
        if (this->kisiler.size() == 1)
            EnZenginiBul();
        KisiSil(kisi);
    }
    else
        return;
}
