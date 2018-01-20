#include <iostream>
#include <cmath>
#include <cstdlib>
#include <locale.h>
#include <conio.h>
#define pi  3.14159265

using namespace std;

int main() {

	int choice, carpim = 1;
	double num1, num2, ans = 0, t, rad, angle;

	setlocale(LC_ALL, "Turkish"); // Türkçe karakter kullanýmýna izin verir.

	do {
		system("cls"); // Ekran temizlenir.
		cout << "========== HESAP MAKÝNESÝ ==========" << endl;
		cout << "         Editör ===> BTU-EEM" << endl;
		cout << "Ýþleminizi Seçiniz:\n\n";
		cout << "1) Toplama \n2) Çýkarma\n";
		cout << "3) Çarpma \n4) Bölme\n";
		cout << "5) Üs Alma\n6) Kök Alma\n";
		cout << "7) Faktöriyel\n8) Trigonometrik Deðerler\n";
		cout << "9) Logaritma\n\n";
		cout << "---Programý sonlandýrmak için -1 deðerini giriniz.---\n\n";

		cin >> choice;

		// Eðer seçim -1 ise döngüden çýksýn.
		if (choice == -1) {
			break;
		}

		// Kök alma iþlemi.
		if (choice == 6){
			cout << "Bir sayý giriniz: ";
			cin >> num1;
			cout << num1 << " Sayýsýnýn Karekökü = " << sqrt(num1);
		}
		// Faktöriyel iþlemi.
		else if(choice == 7){
			cout << "Faktöriyelini Almak Ýstediðiniz Sayýyý Giriniz: ";
			cin >> num1;
			for(int i = 1; i <= num1; i++){
				carpim *= i;
			}
			cout << num1 << "! = " << carpim;
		}
		// Trigonometrik deðer hesaplama.
		else if(choice == 8){
			cout << "Açýyý Giriniz: ";
			cin >> angle;
			cout << "1)Sinüs\n2)Kosinüs\n";
			cout << "3)Tanjant\n4)Kotanjant\n";
			cin >> t;
			rad = angle*(pi/180);

			if(t == 1)
				cout << "Sinüs " << angle << "=" << sin(rad);
			else if(t == 2)
				cout << "Kosinüs " << angle << "=" << cos(rad);
			else if(t == 3)
				cout << "Tanjant " << angle << "=" << sin(rad)/cos(rad);
			else if(t == 4)
				cout << "Kotanjant " << angle << "=" << cos(rad)/sin(rad);
		}
		// Logaritma hesaplama.
		else if(choice == 9){
			cout << "Tabaný Giriniz: ";
			cin >> num1;
			cout << "Deðeri Giriniz: ";
			cin >> num2;
			ans = log(num2)/log(num1);
			cout << "Logaritma " << num1 << " Tabanýnda " << num2 << "==> " << ans;
		}
		// Diðer iþlemler.
		else {
			cout << "1. Sayýyý Giriniz: ";
			cin >> num1;
			cout << "2. Sayýyý Giriniz: ";
			cin >> num2;

			if(choice == 1)
				cout << "Toplama Sonucu = " << num1+num2;
			else if(choice == 2)
				cout << "Çýkarma Sonucu = " << num1-num2;
			else if(choice == 3)
				cout << "Çarpma Sonucu = " << num1*num2;
			else if(choice == 4)
				cout << "Bölme Sonucu = " << num1/num2;
			else if(choice == 5)
				cout << "Üs Sonucu = " << pow(num1, num2);
		}

		cout << "\n\nDevam etmek için bir tuþa basýnýz...\n";
		getch();

}	while (1);

cout << "Programý Kullandýðýnýz Ýçin Teþekkür Ederiz  !!!";

	return 0;
}
