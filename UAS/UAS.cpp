#include <iostream>
using namespace std;

class MataKuliah
{
private:
	float presensi;
	float activity;
	float exercise;
	float tugasAkhir;

public:
	MataKuliah()
	{
		presensi = 0.0;
		activity = 0.0;
		exercise = 0.0;
		tugasAkhir = 0.0;
	}
	virtual void namaMataKuliah() { return; }
	
	virtual void inputNilai() { return; }

	virtual void hitungNilaiAkhir() { return; }

	virtual void cekKelulusan() { return; }

	void setPresensi(float nilai)
	{
		this->presensi = nilai;
	}
	float getPresensi()
	{
		return presensi;
	}
	void setActivity(float nilai)
	{
		this->activity = nilai;
	}
	float getActivity()
	{
		return activity;
	}
	void setExercise(float nilai)
	{
		this->exercise = nilai;
	}
	float getExercise()
	{
		return exercise;
	}
	void setTugasAkhir(float nilai)
	{
		this->tugasAkhir = nilai;
	}
	float getTugasAkhir()
	{
		return tugasAkhir;
	}

};

class Pemrograman : public MataKuliah
{
public :

	void inputNilai()
	{
		float nilaiPresensi, nilaiActivity, nilaiExercise, nilaiTugasAkhir;

		cout << "Masukan nilai presensi : ";
		cin >> nilaiPresensi;
		setPresensi(nilaiPresensi);
		cout << endl;
		cout << "Masukan nilai activity : ";
		cin >> nilaiActivity;
		setActivity(nilaiActivity);
		cout << endl;
		cout << "Masukan nilai exercise : ";
		cin >> nilaiExercise;
		setExercise(nilaiExercise);
		cout << endl;
		cout << "Masukan nilai tugas akhir : ";
		cin >> nilaiTugasAkhir;
		setTugasAkhir(nilaiTugasAkhir);
		cout << endl;
	}

	void hitungNilaiAkhir()
	{
		float nilaiAkhir = (getPresensi() + getActivity() + getExercise() + getTugasAkhir()) / 4;
		cout << "Nilai Akhir : " << nilaiAkhir << endl;
	}

	void cekKelulusan()
	{
		float nilaiAkhir = (getPresensi() + getActivity() + getExercise() + getTugasAkhir()) / 4;

		if (nilaiAkhir >= 75)
		{
			cout << "Selamat anda dinyatakan Lulus";
		}
		else
		{
			cout << "Anda dinyatakan Tidak Lulus";
		}
	}
};

class Jaringan : public MataKuliah
{
public:

	void inputNilai()
	{
		float nilaiActivity, nilaiExercise;

		cout << "Masukan nilai activity : ";
		cin >> nilaiActivity;
		setActivity(nilaiActivity);
		cout << endl;

		cout << "Masukan nilai exercise : ";
		cin >> nilaiExercise;
		setExercise(nilaiExercise);
		cout << endl;
	}

	void hitungNilaiAkhir()
	{
		float nilaiAkhir = (getActivity() + getExercise()) / 2;
		cout << "Nilai Akhir : " << nilaiAkhir << endl;
	}

	void cekKelulusan()
	{
		float nilaiAkhir = (getActivity() + getExercise()) / 2;

		if (nilaiAkhir >= 75)
		{
			cout << "Selamat anda dinyatakan Lulus";
		}
		else
		{
			cout << "Anda dinyatakan Tidak Lulus";
		}
	}
};

int main()
{
	int pilih;
	MataKuliah* mataKuliah;
	Pemrograman pemrograman;
	Jaringan jaringan;

	do
	{
		system("cls");
		cout << "Pilih Mata Kuliah : " << endl;
		cout << "1. Pemrograman" << endl;
		cout << "2. Jaringan" << endl;
		cout << "3. Keluar" << endl;
		cout << "Pilih : ";
		cin >> pilih;

		switch (pilih)
		{
		case 1:
			pemrograman.inputNilai();
			pemrograman.hitungNilaiAkhir();
			pemrograman.cekKelulusan();
			system("pause");
			break;
		case 2:
			mataKuliah = &jaringan;
			mataKuliah->inputNilai();
			jaringan.hitungNilaiAkhir();
			jaringan.cekKelulusan();
			system("pause");
			break;
		case 3 :
			break;
		default :
			cout << "Menu Tidak Tersedia, Pilih Lagi :" << endl;
			system("pause");
			break;
		}

	} while (pilih != 3);
}