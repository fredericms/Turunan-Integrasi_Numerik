#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>

using namespace std;

float a,b,h,n,x,y,z[100],prahasil,hasil,r[100],xr[100],fxr[100],gxr[100],zx[100];
float sigma = 0;
int pilihan;
int i;

float f (float x){
	return exp(x);
}

float g(float x){
	return 1/(1+x);
}

float func(float x){
    return 1/(1+x); 
} 

float simpsons_(float a, float b, float h) 
{ 
    // Menghitung nilai n 
    float n = (b - a) / h; 
    
    // Menghitung hasil x dan f(x) 
    for (int i = 0; i <= n; i++) { 
        z[i] = a + i * h; 
        zx[i] = func(z[i]); 
    } 
  
    // Mengkalkulasi Perhitungan
    float res = 0; 
    for (int i = 0; i <= n; i++) { 
        if (i == 0 || i == n) 
            res += zx[i]; 
        else if (i % 2 != 0) 
            res += 4 * zx[i]; 
        else
            res += 2 * zx[i]; 
    } 
    res = res * (h / 3); 
    return res; 
} 

int main(){
	string pertanyaan;
	pertanyaan = "ya";
	while(pertanyaan == "ya"){
		cout << "===============================================";
		cout << "\nProgram Integrasi dan Turunan Numerik";
		cout << "\nOleh: Frederic Morado Saragih";
		cout << "\n===============================================";
		cout << "\n\nMenu:";
		cout << "\n1. Integrasi Numerik Metode Trapesium";
		cout << "\n2. Integrasi Numerik Metode Titik Tengah";
		cout << "\n3. Integrasi Numerik Metode Simpson 1/3";
		cout << "\n4. Turunan Numerik Pertama dengan Orde O(h^2)";
		cout << "\n\nMasukkan Pilihan Anda: "; cin >> pilihan;
		if (pilihan == 1){
			cout << "Integrasi Numerik menggunakan Metode Trapesium";
			cout << "\nPersamaan (f(x)): e^x";
			cout << "\nMasukan batas bawah (a) : "; cin >> a;
			cout << "Masukan batas atas (b)  : "; cin >> b;
			cout << "Masukan jumlah pias (h) : "; cin >> h;
		
			n = (b-a)/h;
			
			// Masukan fungsi
			xr[0] = a;
			for(int i = 1;i < n;i++){
				xr[i] = xr[i-1] + h;
			}
			for(int i = 0;i < n;i++){
				x = xr[i];
				fxr[i] = f(x);
			}
			
			// sigma
			for(int i = 1;i < n-1;i++){
				sigma = sigma + (2*fxr[i]);
			}
			for(int i = n-1;i < n;i++){
				sigma = sigma + fxr[i+1];
			}
			
			// hasil
			prahasil = fxr[0] + sigma;
			hasil = h/2 * prahasil;
			
			// tampilan & tabel
			cout << "\nr\txr\tf(xr)\n"
				 << "----------------------\n";
			for(int i = 0;i < n;i++){
				cout << i << "\t" << xr[i] << "\t" << fxr[i] << endl;
			}
			cout << "\nSigma: " << sigma <<"\nHasil Integrasi Numerik: " << hasil;
			cout << "\nHasil Integrasi Sejati: 23.914";
		}
		else if (pilihan == 2){
		  	cout << "Integrasi Numerik menggunakan Kaidah Titik Tengah\nPersamaan (f(x)) = 1/(1+x)\n";
			cout << "Masukan Nilai a : "; cin >> a;
			cout << "Masukan Nilai b : "; cin >> b;
			cout << "Masukan Nilai h : "; cin >> h;
			
			n = (b-a)/h;
			
			// rumus
			for(int i = 1;i < n+n;i=i+2){
				r[i] = i;
			}
			for(int i = 1;i < sizeof(r)+1;i+=2){
				xr[i] = r[i]*h/2;
			}
			for(int i = 1;i < sizeof(xr)+1;i+=2){
				gxr[i] = g(xr[i]);
			}
			
			// hasil 
			for(int i = 1;i < n+n;i+=2){
				sigma = sigma + gxr[i];
			}
			hasil = h*sigma;
			
			// tampilan
			cout << "\n--------------------------"
				 << "\n|  r\t|  xr\t|  f(xr)\t\n"
				 << "---------------------------\n";
				 
			for(int i = 1;i < n+n;i+=2){
				cout << "| " << r[i] <<"/2\t|" <<xr[i] << "\t|" << gxr[i] << endl;
			}
			
			cout << "\n\nSigma: "<< sigma << "\nHasil: " << hasil;
			cout << "\nHasil Integrasi Sejati: 0.69314718";
		}
		else if (pilihan == 3){
			cout << "Integrasi Numerik menggunakan Metode Simpson 1/3";
			cout << "\nPersamaan (f(x)): 1 / (1 + x)";
			cout << "\nMasukan batas bawah (a) : "; cin >> a;
			cout << "Masukan batas atas (b)  : "; cin >> b;
			cout << "Masukan jumlah pias (h) : "; cin >> h;
			
			n = (b-a) / h;
			//Tabel:
			cout << "\nr\txr\tf(xr)\n"
				 << "----------------------\n";
			for(int i = 0;i <= n; i++){
				z[i] = a + i * h; 
        		zx[i] = func(z[i]); 
				cout << i << "\t" << z[i] << "\t" << zx[i] << endl;
			}
			//Hasil Perhitungan:
			cout << fixed;
			cout << "\nHasil: " << setprecision(5) << simpsons_(a, b, h);
			cout << "\nHasil Integrasi Sejati: 0.69314718";  	
		}
		else if (pilihan == 4){
			cout << "Turunan Numerik Pertama dengan Orde O(h^2)\n";
			cout << "Diketahui data dalam bentuk tabel sebagai berikut:\n";
			int k,l,q;
			string orde;
			float turunan;
			string tabel[8][2] = {{" x ","  f(x) "},{"1,3"," 3,669 "},{"1,5"," 4,482 "},{"1,7"," 5,474 "},{"1,9"," 6,686 "},{"2,1"," 8,166 "},{"2,3"," 9,974 "},{"2,5"," 12,182 "}};
			for (k=0; k<8; k++){
				for (l=0; l<2; l++){
					cout << "|" << tabel[k][l] << "|";
				}
			cout << endl;
			}
			a = 1.3;
			b = 2.5;
			n = 6;
			h = (b - a)/n;
			cout << "\nMasukkan nilai x: "; cin >> orde;
			if (orde == "1.7"){
				cout << "x(0) = 1.7, maka x(-1) = 1.5 dan x(1) = 1.9 dengan h = (1.5 - 1.3) = 0.2";
				turunan = (6.686 - 4.482) / (2*h);
				cout << fixed;
				cout << "\nf'(x) = (f(1) - f(-1)) / 2h";
				cout << "\nf'(1.7) = (6.686 - 4.482) / " << setprecision(1) << 2*h << " = " << setprecision(3) << turunan;
				cout << endl; 
			}
			else if(orde == "1.4"){
				h = 0.1;
				cout << "x(0) = 1.4, maka x(-1) = 1.3 dan x(1) = 1.5 dengan h = (1.4 - 1.3) = 0.1";
				turunan = (4.482 - 3.669) / (2*h);
				cout << fixed;
				cout << "\nf'(x) = (f(1) - f(-1)) / 2h";
				cout << "\nf'(1.4) = (4.482 - 3.669) / " << setprecision(1) << 2*h << " = " << setprecision(3) << turunan;
				cout << endl; 
			}
		}
		else{
			cout << "Pilihan yang Anda masukkan tidak tersedia";
		}
	tanya:
	cout << "\n\nApakah Anda ingin beralih ke menu lain? (ya/tidak): "; cin >> pertanyaan;
	if(pertanyaan == "ya"){
		system("cls");
	}
	else if(pertanyaan == "tidak"){
		cout << "\nTerima kasih telah menggunakan program ini.";
		return 0;
	}
	else{
		cout << "Jawaban yang Anda masukkan salah";
		goto tanya;
	}
	}
}
