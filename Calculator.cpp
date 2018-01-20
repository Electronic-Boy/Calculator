#include <iostream>
#include <cmath>
#include <cstdlib>
#include <locale.h>
#include <conio.h>
#include <cstdio>
#define pi  3.14159265

using namespace std;

int main() {

	FILE *history;
	char ext;
	int choice, carpim = 1;
	double num1, num2, ans = 0, t, rad, angle;

	setlocale(LC_ALL, "Turkish"); // Türkçe karakter kullanımına izin verir.

	do {
		system("cls"); // Ekran temizlenir.
		cout << "========== HESAP MAKİNESİ ==========" << endl;
		cout << "         Editör ===> BTU-EEM" << endl;
		cout << "İşleminizi Seçiniz:\n\n";
		cout << "1) Toplama \n2) Çıkarma\n";
		cout << "3) Çarpma \n4) Bölme\n";
		cout << "5) Üs Alma\n6) Kök Alma\n";
		cout << "7) Faktöriyel\n8) Trigonometrik Değerler\n";
		cout << "9) Logaritma\n\n";

		cin >> choice;

		// Eğer seçim -1 ise döngüden çıksın.
		if (choice == -1) {
			break;
		}

		history = fopen("history.txt", "a+");

		// Kök alma işlemi.
		if (choice == 6){
			cout << "Bir sayı giriniz: ";
			cin >> num1;
			cout << num1 << " Sayısının Karekökü = " << sqrt(num1);
			if (history != NULL) {
				fprintf(history, "karekök %.3f = %f\n", num1, sqrt(num1));
			}
		}
		// Faktöriyel işlemi. shifte basarak sağ tıklıyom
		else if(choice == 7){
			cout << "Faktöriyelini Almak İstediğiniz Sayıyı Giriniz: ";
			cin >> num1;
			for(int i = 1; i <= num1; i++){
				carpim *= i;
			}
			cout << num1 << "! = " << carpim;
			if (history != NULL) {
				fprintf(history, "%.0f! = %d\n", num1, carpim);
				// %f idi değiştirdim düzeldi...
			}
		}
		// Trigonometrik değer hesaplama.
		else if(choice == 8){
			cout << "Açıyı Giriniz: ";
			cin >> angle;
			cout << "1)Sinüs\n2)Kosinüs\n";
			cout << "3)Tanjant\n4)Kotanjant\n";
			cin >> t;
			rad = angle*(pi/180);

			if(t == 1) {
				cout << "Sinüs " << angle << "=" << sin(rad);
				if (history != NULL) {
					fprintf(history, "sin(%.3f) = %.3f\n", angle, sin(rad));
				}
			}
			else if(t == 2) {
				cout << "Kosinüs " << angle << "=" << cos(rad);
				if (history != NULL) {
					fprintf(history, "cos(%.3f) = %.3f\n", angle, cos(rad));
				}
			}
			else if(t == 3) {
				cout << "Tanjant " << angle << "=" << sin(rad)/cos(rad);
				if (history != NULL) {
					fprintf(history, "tan(%.3f) = %.3f\n", angle, sin(rad)/cos(rad));
				}
			}
			else if(t == 4) {
				cout << "Kotanjant " << angle << "=" << cos(rad)/sin(rad);
				if (history != NULL) {
					fprintf(history, "cot(%.3f) = %.3f\n", angle, cos(rad)/sin(rad));
				}
			}
		}
		// Logaritma hesaplama.
		else if(choice == 9){
			cout << "Tabanı Giriniz: ";
			cin >> num1;
			cout << "Değeri Giriniz: ";
			cin >> num2;
			ans = log(num2)/log(num1);
			cout << "Logaritma " << num1 << " Tabanında " << num2 << "==> " << ans;
			if (history != NULL) {
				fprintf(history, "log%.0f(%.3f) = %f\n", num1, num2, ans);
			}
		}
		// Diğer işlemler.
		else {
			cout << "1. Sayıyı Giriniz: ";
			cin >> num1;
			cout << "2. Sayıyı Giriniz: ";
			cin >> num2;

			if(choice == 1) {
				cout << "Toplama Sonucu = " << num1+num2;
				if (history != NULL) {
					fprintf(history, "%.3f + %.3f = %f\n", num1, num2, num1+num2);
				}
			}
			else if(choice == 2) {
				cout << "Çıkarma Sonucu = " << num1-num2;
				if (history != NULL) {
					fprintf(history, "%.3f - %.3f = %f\n", num1, num2, num1-num2);
				}
			}
			else if(choice == 3) {
				cout << "Çarpma Sonucu = " << num1*num2;
				if (history != NULL) {
					fprintf(history, "%.3f * %.3f = %f\n", num1, num2, num1*num2);
				}
			}
			else if(choice == 4) {
				cout << "Bölme Sonucu = " << num1/num2;
				if (history != NULL) {
					fprintf(history, "%.3f / %.3f = %f\n", num1, num2, num1/num2);
				}
			}
			else if(choice == 5) {
				cout << "Üs Sonucu = " << pow(num1, num2);
				if (history != NULL) {
					fprintf(history, "%.3f ^ %.3f = %f\n", num1, num2, pow(num1, num2));
				}
			}
		}

		cout << "\n\nDevam etmek için bir tuşa basınız...\n";
		cout << "---Programı sonlandırmak için Esc tuşuna basınız.---\n\n";
		ext = getche(); // Bu fonksiyon ile girilen karakteri alıp ext değişkenine kaydediyoruz.
		// Bu fonksiyon sayesinde sadece karakter değil esc gibi tuşlarıda alabiliyoruz.
		// Bunu daha sonra burda kontrol ederek esc mi değil mi dye
		// 27 değeride esc nin ascii deki karşılığı. Tamam mı bir sorun varmı

}	while (ext != 27);
// Nedense P harfini yazdırmadı.
cout << " Programı Kullandığınız İçin Teşekkür Ederiz!!!";

	return 0;
}
