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

	setlocale(LC_ALL, "Turkish"); // T�rk�e karakter kullan�m�na izin verir.

	do {
		system("cls"); // Ekran temizlenir.
		cout << "========== HESAP MAK�NES� ==========" << endl;
		cout << "         Edit�r ===> BTU-EEM" << endl;
		cout << "��leminizi Se�iniz:\n\n";
		cout << "1) Toplama \n2) ��karma\n";
		cout << "3) �arpma \n4) B�lme\n";
		cout << "5) �s Alma\n6) K�k Alma\n";
		cout << "7) Fakt�riyel\n8) Trigonometrik De�erler\n";
		cout << "9) Logaritma\n\n";

		cin >> choice;

		// E�er se�im -1 ise d�ng�den ��ks�n.
		if (choice == -1) {
			break;
		}

		history = fopen("history.txt", "a+");

		// K�k alma i�lemi.
		if (choice == 6){
			cout << "Bir say� giriniz: ";
			cin >> num1;
			cout << num1 << " Say�s�n�n Karek�k� = " << sqrt(num1);
			if (history != NULL) {
				fprintf(history, "karek�k %.3f = %f\n", num1, sqrt(num1));
			}
		}
		// Fakt�riyel i�lemi. shifte basarak sa� t�kl�yom
		else if(choice == 7){
			cout << "Fakt�riyelini Almak �stedi�iniz Say�y� Giriniz: ";
			cin >> num1;
			for(int i = 1; i <= num1; i++){
				carpim *= i;
			}
			cout << num1 << "! = " << carpim;
			if (history != NULL) {
				fprintf(history, "%.0f! = %d\n", num1, carpim);
				// %f idi de�i�tirdim d�zeldi...
			}
		}
		// Trigonometrik de�er hesaplama.
		else if(choice == 8){
			cout << "A��y� Giriniz: ";
			cin >> angle;
			cout << "1)Sin�s\n2)Kosin�s\n";
			cout << "3)Tanjant\n4)Kotanjant\n";
			cin >> t;
			rad = angle*(pi/180);

			if(t == 1) {
				cout << "Sin�s " << angle << "=" << sin(rad);
				if (history != NULL) {
					fprintf(history, "sin(%.3f) = %.3f\n", angle, sin(rad));
				}
			}
			else if(t == 2) {
				cout << "Kosin�s " << angle << "=" << cos(rad);
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
			cout << "Taban� Giriniz: ";
			cin >> num1;
			cout << "De�eri Giriniz: ";
			cin >> num2;
			ans = log(num2)/log(num1);
			cout << "Logaritma " << num1 << " Taban�nda " << num2 << "==> " << ans;
			if (history != NULL) {
				fprintf(history, "log%.0f(%.3f) = %f\n", num1, num2, ans);
			}
		}
		// Di�er i�lemler.
		else {
			cout << "1. Say�y� Giriniz: ";
			cin >> num1;
			cout << "2. Say�y� Giriniz: ";
			cin >> num2;

			if(choice == 1) {
				cout << "Toplama Sonucu = " << num1+num2;
				if (history != NULL) {
					fprintf(history, "%.3f + %.3f = %f\n", num1, num2, num1+num2);
				}
			}
			else if(choice == 2) {
				cout << "��karma Sonucu = " << num1-num2;
				if (history != NULL) {
					fprintf(history, "%.3f - %.3f = %f\n", num1, num2, num1-num2);
				}
			}
			else if(choice == 3) {
				cout << "�arpma Sonucu = " << num1*num2;
				if (history != NULL) {
					fprintf(history, "%.3f * %.3f = %f\n", num1, num2, num1*num2);
				}
			}
			else if(choice == 4) {
				cout << "B�lme Sonucu = " << num1/num2;
				if (history != NULL) {
					fprintf(history, "%.3f / %.3f = %f\n", num1, num2, num1/num2);
				}
			}
			else if(choice == 5) {
				cout << "�s Sonucu = " << pow(num1, num2);
				if (history != NULL) {
					fprintf(history, "%.3f ^ %.3f = %f\n", num1, num2, pow(num1, num2));
				}
			}
		}

		cout << "\n\nDevam etmek i�in bir tu�a bas�n�z...\n";
		cout << "---Program� sonland�rmak i�in Esc tu�una bas�n�z.---\n\n";
		ext = getche(); // Bu fonksiyon ile girilen karakteri al�p ext de�i�kenine kaydediyoruz.
		// Bu fonksiyon sayesinde sadece karakter de�il esc gibi tu�lar�da alabiliyoruz.
		// Bunu daha sonra burda kontrol ederek esc mi de�il mi dye
		// 27 de�eride esc nin ascii deki kar��l���. Tamam m� bir sorun varm�

}	while (ext != 27);
// Nedense P harfini yazd�rmad�.
cout << " Program� Kulland���n�z ��in Te�ekk�r Ederiz!!!";

	return 0;
}
