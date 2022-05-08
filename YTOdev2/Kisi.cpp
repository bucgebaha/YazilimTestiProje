#include "Kisi.h"

string Kisi::GetAdSoyad()
{
    return this->adSoyad;
}

float Kisi::GetToplamPara()
{
    return this->toplamPara;
}

void Kisi::SetToplamPara(float toplamPara)
{
    this->toplamPara = toplamPara;
}

float Kisi::GetBahisOrani()
{
    return this->bahisOrani;
}

int Kisi::GetSansliSayi()
{
    return this->sansliSayi;
}

Kisi::Kisi(string adSoyad, float toplamPara, float bahisOrani, int sansliSayi)
{
    this->adSoyad = adSoyad;
    this->toplamPara = toplamPara;
    this->bahisOrani = bahisOrani;
    this->sansliSayi = sansliSayi;
}
