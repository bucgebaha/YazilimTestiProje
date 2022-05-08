#pragma once
#include <vector>
#include "Kisi.h"
#include <time.h>

class Masa
{
private:
	vector<Kisi> kisiler;
	int turNo;
	int sansliSayi;
	float masaninParasi;
	string enZenginKisiAd;
	float enZenginKisiPara;
	void MasaCizdir();
	void MasaCizdirFinal();
public:
	void KisiEkle(Kisi kisi);
	void KisiSil(Kisi kisi);
	void BahisKontrol();
	void Kazandi(int index);
	void Kaybetti(Kisi kisi);
	bool ElendiMi(Kisi kisi);
	void OyunuBaslat();
	int GetTurNo();
	void YeniTur();
	void BahisleriTopla();
	void SansliSayiCek();
	int GetSansliSayi();
	float GetMasaninParasi();
	void SetMasaninParasi(float para);
	void SetEnZenginKisiPara(float para);
	void SetEnZenginKisiAd(string ad);
	string GetEnZenginKisiAd();
	float GetEnZenginKisiPara();
	void EnZenginiBul();
	int GetKisiSayisi();
	Masa(vector<Kisi> kisiler);

	vector<Kisi> GetKisiler() {
		return this->kisiler;
	}
};

