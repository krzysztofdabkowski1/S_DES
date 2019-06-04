#include <iostream>
#include <string>
using namespace std;
void PW(int* T)
{
	int T2[8];
	for (int i = 0; i < 8; i++) T2[i] = T[i];
	T[0] = T2[1]; T[1] = T2[5]; T[3] = T2[0]; T[4] = T2[3]; T[5] = T2[7]; T[6] = T2[4]; T[7] = T2[6];

}
void KRZYZOWANIE(int *T)
{
	int T2[8];
	for (int i = 0; i < 8; i++) T2[i] = T[i];
	T[0] = T2[4]; T[1] = T2[5]; T[2] = T2[6]; T[3] = T2[7]; T[4] = T2[0]; T[5] = T2[1]; T[6] = T2[2]; T[7] = T2[3];

}
void PO(int *T)
{
	int T2[8];
	for (int i = 0; i < 8; i++) T2[i] = T[i];
	T[0] = T2[3]; T[1] = T2[0]; T[3] = T2[4]; T[4] = T2[6]; T[5] = T2[1]; T[6] = T2[7]; T[7] = T2[5];

}
void SBOX1(int *IN, int *OUT)
{
	int i, tab;
	int TAB[4][4] = { { 1, 0 ,3, 2 },{ 3, 2, 1, 0 },{ 0, 2, 1, 3 },{ 3, 1, 3, 2 } };
	if (IN[0] == 1 && IN[3] == 1) i = 3;
	else if (IN[0] == 0 && IN[3] == 0) i = 0;
	else if (IN[0] == 0 && IN[3] == 1) i = 1;
	else if (IN[0] == 1 && IN[3] == 0) i = 2;

	if (IN[1] == 1 && IN[2] == 1) tab = TAB[i][3];
	else if (IN[1] == 0 && IN[2] == 0) tab = TAB[i][0];
	else if (IN[1] == 0 && IN[2] == 1) tab = TAB[i][1];
	else if (IN[1] == 1 && IN[2] == 0) tab = TAB[i][2];

	if (tab == 0) { OUT[0] = 0; OUT[1] = 0; }
	if (tab == 1) { OUT[0] = 0; OUT[1] = 1; }
	if (tab == 2) { OUT[0] = 1; OUT[1] = 0; }
	if (tab == 3) { OUT[0] = 1; OUT[1] = 1; }
}
void SBOX2(int *IN, int *OUT)
{
	int i, tab;
	int TAB[4][4] = { { 0, 1, 2 ,3 },{ 2, 0 ,1 ,3 },{ 3, 0, 1, 0 },{ 2, 1 ,0, 3 } };
	if (IN[0] == 1 && IN[3] == 1) i = 3;
	else if (IN[0] == 0 && IN[3] == 0) i = 0;
	else if (IN[0] == 0 && IN[3] == 1) i = 1;
	else if (IN[0] == 1 && IN[3] == 0) i = 2;

	if (IN[1] == 1 && IN[2] == 1) tab = TAB[i][3];
	else if (IN[1] == 0 && IN[2] == 0) tab = TAB[i][0];
	else if (IN[1] == 0 && IN[2] == 1) tab = TAB[i][1];
	else if (IN[1] == 1 && IN[2] == 0) tab = TAB[i][2];

	if (tab == 0) { OUT[0] = 0; OUT[1] = 0; }
	else if (tab == 1) { OUT[0] = 0; OUT[1] = 1; }
	else if (tab == 2) { OUT[0] = 1; OUT[1] = 0; }
	else if (tab == 3) { OUT[0] = 1; OUT[1] = 1; }
}
void KEY(int *K, int runda,int *K3)
{
	int K2[10];
	for (int i = 0; i <10; i++) K2[i] =K[i];
	K2[0] = K[2]; K2[1] = K[4]; K2[2] = K[1]; K2[3] = K[6]; K2[4] = K[3]; K2[5] = K[9]; K2[6] = K[0]; K2[7] = K[8]; K2[8] = K[7]; K2[9] = K[5];
	
	for (int i = 0; i < 5; i++) {            //
		K3[i] = K2[(i + 1) % 5];             //  SL1
		K3[i + 5] = K2[5 + ((i + 1) % 5)];   //
	}
	if (runda == 2)
	{
		for (int i = 0; i < 10; i++) K2[i] = K3[i];
		for (int i = 0; i < 5; i++) {            //
			K3[i] = K2[(i + 2) % 5];             //  SL2
			K3[i + 5] = K2[5 + ((i + 2) % 5)];   //
		}
	}

	for (int i = 0; i < 10; i++) K2[i] = K3[i];
	K3[0] = K2[5]; K3[1] = K2[2]; K3[2] = K2[6]; K3[3] = K2[3]; K3[4] = K2[7]; K3[5] = K2[4]; K3[6] = K2[9]; K3[7] = K2[8];
	
	cout <<endl<< "KLUCZ RUNDY " << runda << ": ";
	for (int i = 0; i < 8; i++) cout << K3[i];
	cout << endl;
	



}
void P4w8(int *T2)
{
	int T3[8];
	for (int i = 0; i < 8; i++) T3[i] = T2[i];
	T2[0] = T3[7]; T2[1] = T3[4]; T2[2] = T3[5]; T2[3] = T3[6]; T2[4] = T3[5]; T2[5] = T3[6]; T2[6] = T3[7]; T2[7] = T3[4];

}
void P4w4(int *P4)
{
	int P4_2[4];
	for (int i = 0; i < 4; i++) P4_2[i] = P4[i];
	P4[0] = P4_2[1]; P4[1] = P4_2[3]; P4[3] = P4_2[0];
}

void SZYFR(int T[8], int *K,int runda)
{
	int T2[8] , K2[10] ;
    int S1[4] , S2[4], r1[4], r2[2],P4[4];
	for (int i = 0; i < 8; i++) T2[i] = T[i];
	P4w8(T2);
	KEY(K, runda,K2);
	for (int i = 0; i < 8; i++) T2[i] = (T2[i] + K2[i]) % 2;
	
	for (int i = 0; i < 4; i++)
	{
		S1[i] = T2[i];
		S2[i] = T2[i+4];
	}
	SBOX1(S1, r1);
	SBOX2(S2, r2);
	cout << endl << "SBOX1 dla rundy " << runda << ": " << r1[0] << r1[1];
	cout << endl << "SBOX2 dla rundy " << runda << ": " << r2[0] << r2[1];
	P4[0] = r1[0]; P4[1] = r1[1]; P4[2] = r2[0]; P4[3] = r2[1];
	P4w4(P4);
	
	for (int i = 0; i < 4; i++) T[i] = (T[i] + P4[i]) % 2;




}
int main()
{
	int runda;
	int T[8] = { 1,1,1,1,0,0,0,0 };
	int K[10] = { 1,1,0,0,0,0,0,0,1,1};
	string oct;
	for (int i = 0; i < 8; i++) T[i] = 0;
	cout << "Wprowadz ciag osmiobitowy: ";
	cin >> oct;

	for (int i = 0; i < 8; i++)
	{
		stoi(oct);
		if (oct.length()==i) break;
		T[i] = oct[i]-48; 
		
	}
	PW(T);
	
	runda = 2;
	SZYFR(T, K,runda);
	cout << endl <<endl<< "SZYFR RUNDY "<<runda<<": ";
	for (int i = 0; i < 8; i++) cout << T[i];
	
	KRZYZOWANIE(T);
	
	runda = 1;
	SZYFR(T, K, runda);
	cout << endl<<endl << "SZYFR RUNDY " << runda << ": ";
	for (int i = 0; i < 8; i++) cout << T[i];
	
	PO(T);
	cout << endl<<endl << "SZYFR KONCOWY: ";
	for (int i = 0; i < 8; i++) cout << T[i];
	
	system("pause");
	return 0;


}