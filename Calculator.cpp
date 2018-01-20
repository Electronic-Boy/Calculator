#include <iostream>
#include <cmath>
using namespace std;
#define pi  3.14159265
int main() {;
	char k;
	int choice,carpim=1;
	double num1, num2, ans = 0,t,rad,aci;

	cout << "========== HESAP MAKINESI ==========" << endl;
	cout << "	Editor===> BTU-EEM        " << endl;

	do {
		cout << "Isleminizi Seciniz:\n";
		cout << "1) Toplama \n2) Cikarma\n";
		cout << "3) Carpma \n4) Bolme\n";
		cout << "5) Us Alma\n6)Kok Alma\n";
		cout << "7) Faktoryel\n8)Trigonometrik Degerler\n";
		cout << "9) Logaritma\n";
		cin >> choice;
		
		if(choice==6){
		cout<<"Bir sayi giriniz:";
		cin>>num1;
		cout<<num1<<" Sayisinin Koku = "<<sqrt(num1);
		goto a;
		}
		if(choice==7){
			cout<<"Faktoryelini Almak Istediginiz Sayiyi Giriniz:";
			cin>>num1;
			for(int i=1;i<=num1;i++){
				carpim*=i;
			}
			cout<<num1<<"! = "<<carpim;
			goto a;
		}
		if(choice==8){
			cout<<"Aciyi Giriniz:";
			cin>>aci;
			cout << "1)Sinus\n2)Kosinus\n";
			cout << "3)Tanjant\n4)Kotanjant\n";
			cin >>t;
			rad=aci*(pi/180);
			if(t==1)
				cout<<"Sinus "<<aci<<"="<<sin(rad);
				else if(t==2)
				cout<<"Kosinus "<<aci<<"="<<cos(rad);
				else if(t==3)
				cout<<"Tanjant "<<aci<<"="<<sin(rad)/cos(rad);
				else if(t==4)
				cout<<"Kotanjant "<<aci<<"="<<cos(rad)/sin(rad);
				goto a;			
		}
		if(choice==9){
			cout<<"Tabani Giriniz:";
			cin>>num1;
			cout<<"Degeri Giriniz:";
			cin>>num2;
			ans=log(num2)/log(num1);
			cout<<"Logaritma "<<num1<<" Tabaninda "<<num2<<"==>"<<ans;
			goto a;
		}
		
		cout << "1. Sayiyi Giriniz:";
		cin >> num1;
		cout << "2. Sayiyi Giriniz:";
		cin >> num2;

		if(choice == 1)
			cout << "Toplama Sonucu = " << num1+num2;
		else if(choice == 2)
			cout << "Cikarma Sonucu = " << num1-num2;
		else if(choice == 3)
			cout << "Carpma Sonucu = " << num1*num2;
		else if(choice == 4)
			cout << "Bolme Sonucu = " << num1/num2;
		else if(choice == 5)
			cout << "Us Sonucu = " << pow(num1, num2);
		a:	// Tek Sayýlarda iþlem yapmak için
		cout << endl;
		cout << "Devam Etmek Istiyor musunuz? (e/h):";
		cin >> k;
}	while (k != 'h' && k != 'H');
	return 0;
}
