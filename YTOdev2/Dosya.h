#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Dosya
{
private:
	string icerik;
	vector<string> anlamliIcerik;
	int satirSayisi;
	string dosyaYolu;
public:
	void DosyaOku();
	string GetIcerik();
	void IcerigiParcala(string satir);
	vector<string> GetAnlamliIcerik();
	void SetDosyaYolu(string dosyaYolu);
	string GetDosyaYolu();
	int GetSatirSayisi();
	Dosya(string dosyaYolu);
};

