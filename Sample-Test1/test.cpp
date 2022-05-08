#include "pch.h"
#include "../YTOdev2/Dosya.h"
#include "../YTOdev2/Kisi.h"
#include "../YTOdev2/Masa.h"

TEST(KisiTest, SetToplamParaTest) {
	Kisi* k = new Kisi("Test", 5555, .5, 5);
	k->SetToplamPara(4444);
	ASSERT_EQ(4444, k->GetToplamPara());

	delete k;
}

TEST(DosyaTest, DosyaOkuTest) {
	string icerik = "Lorem ipsum dolor sit amet.";
	ofstream MyFile("testFile.txt");
	MyFile << icerik;
	MyFile.close();

	Dosya* d = new Dosya("testFile.txt");
	d->DosyaOku();
	ASSERT_EQ(icerik, d->GetIcerik());

	delete d;
}

TEST(DosyaTest, IcerigiParcalaTest) {
	string icerik = "Lorem#ipsum#dolor#sit#amet.";

	Dosya* d = new Dosya("testFile.txt");
	d->IcerigiParcala(icerik);
	vector<string> beklenen;
	beklenen.push_back("Lorem");
	beklenen.push_back("ipsum");
	beklenen.push_back("dolor");
	beklenen.push_back("sit");
	beklenen.push_back("amet.");
	ASSERT_EQ(beklenen, d->GetAnlamliIcerik());

	delete d;
}

TEST(DosyaTest, SetDosyaYoluTest) {
	Dosya* d = new Dosya("testFile.txt");
	d->SetDosyaYolu("deneme1.txt");

	ASSERT_EQ("deneme1.txt", d->GetDosyaYolu());

	delete d;
}

TEST(MasaTest, ElendiMiTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);

	ASSERT_TRUE(m->ElendiMi(m->GetKisiler()[0]));
	ASSERT_FALSE(m->ElendiMi(m->GetKisiler()[1]));

	delete k1, k2, m;
}

TEST(MasaTest, OyunuBaslatEntegrasyonTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->OyunuBaslat();

	ASSERT_TRUE(m->GetMasaninParasi() != 0);
	ASSERT_TRUE(m->GetSansliSayi() != 0);
	ASSERT_TRUE(m->GetTurNo() != 0);

	delete k1, k2, m;
}

TEST(MasaTest, YeniTurEntegrasyonTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->YeniTur();

	ASSERT_TRUE(m->GetTurNo() == 1);
	ASSERT_TRUE(m->GetSansliSayi() != 0);

	delete k1, k2, m;
}

TEST(MasaTest, BahisleriToplaTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->BahisleriTopla();

	ASSERT_EQ(900 - 900 * .2, m->GetKisiler()[0].GetToplamPara());
	ASSERT_EQ(1200 - 1200 * .3, m->GetKisiler()[1].GetToplamPara());
	ASSERT_EQ(900 - 900 * .2 + 1200 - 1200 * .3, m->GetMasaninParasi());

	delete k1, k2, m;
}

TEST(MasaTest, SansliSayiCekTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->SansliSayiCek();

	ASSERT_TRUE(m->GetSansliSayi() != 0);
	ASSERT_TRUE(m->GetSansliSayi() <= 10 && m->GetSansliSayi() > 0);

	delete k1, k2, m;
}

TEST(MasaTest, SetMasaninParasiTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->SetMasaninParasi(5454);

	ASSERT_EQ(5454, m->GetMasaninParasi());

	delete k1, k2, m;
}

TEST(MasaTest, SetEnZenginKisiAdTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->SetEnZenginKisiAd("Can Tuysuz");

	ASSERT_EQ("Can Tuysuz", m->GetEnZenginKisiAd());

	delete k1, k2, m;
}

TEST(MasaTest, SetEnZenginKisiParaTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->SetEnZenginKisiAd("Can Tuysuz");

	ASSERT_EQ(1200, m->GetEnZenginKisiPara());

	delete k1, k2, m;
}

TEST(MasaTest, EnZenginiBulTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->EnZenginiBul();

	ASSERT_EQ("Can Tuysuz", m->GetEnZenginKisiAd());

	delete k1, k2, m;
}

TEST(MasaTest, KisiEkleTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	
	Kisi* k3 = new Kisi("Zekai Ozger", 5000, .5, 7);
	m->KisiEkle(*k3);//kisiler[2]'de k3 var.

	ASSERT_EQ(*k3, m->GetKisiler()[2]);

	delete k1, k2, k3, m;
}

TEST(MasaTest, KisiSilTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->KisiSil(*k1);

	ASSERT_TRUE(m->GetKisiler().size() == 1);
	ASSERT_TRUE(m->GetKisiler()[0].GetAdSoyad() != k1->GetAdSoyad());

	delete k1, k2, m;
}

TEST(MasaTest, BahisKontrolYeniTurKazandiKaybettiBahisKontrolEntegrasyon) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->YeniTur();

	if (m->GetSansliSayi() == k1->GetSansliSayi())
		ASSERT_EQ(900 + 900 * .2 * 10, k1->GetToplamPara());
	else
		ASSERT_EQ(900 - 900 * .2, k1->GetToplamPara());

	if (m->GetSansliSayi() == k2->GetSansliSayi())
		ASSERT_EQ(1200 + 1200 * .3 * 10, k2->GetToplamPara());
	else
		ASSERT_EQ(1200 - 1200 * .3, k2->GetToplamPara());

	ASSERT_EQ(1, m->GetTurNo());

	delete k1, k2, m;
}


TEST(MasaTest, BahisleriToplaKazandiEntegrasyonTest) {
	Kisi* k1 = new Kisi("Baha Bucge", 900, .2, 9);
	Kisi* k2 = new Kisi("Can Tuysuz", 1200, .3, 4);
	vector<Kisi> kisiler;
	kisiler.push_back(*k1); //kisiler[0]'da k1 var.
	kisiler.push_back(*k2); //kisiler[1]'de k2 var.
	Masa* m = new Masa(kisiler);
	m->BahisleriTopla();
	m->Kazandi(0); // Baha kazandi dersek:

	ASSERT_EQ(2520, m->GetKisiler()[0].GetToplamPara());
	ASSERT_EQ(840, m->GetKisiler()[1].GetToplamPara());

	delete k1, k2, m;
}