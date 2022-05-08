#pragma once
#include <string>
using namespace std;

class Kisi
{
private:
	string adSoyad;
	float toplamPara;
	float bahisOrani;
	int sansliSayi;
public:
	string GetAdSoyad();
	float GetToplamPara();
	void SetToplamPara(float toplamPara);
	float GetBahisOrani();
	int GetSansliSayi();
	Kisi(string adSoyad, float toplamPara, float bahisOrani, int sansliSayi);
};

