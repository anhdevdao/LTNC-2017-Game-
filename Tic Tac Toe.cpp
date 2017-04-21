#include <string.h>
//#include <stdio.h>
#include <iostream>
#include <windows.h>
#include <conio.h>
//x: chieu Ngang; y: chien doc
using namespace std;
char a[79][24], key;
int x,y,i,m,n,m1,n1, luaChon; //m1,n1: phuc vu cho viec kiem tra Dieu Kien chien thang
//Cac thu tuc trang tri
void taoBackground(){
    for (int i=1; i<=79; i++)
        for (int j=1; j<=24; j++)
            a[i][j]=' ';
}
void moDau(int);
void choi2Nguoi();
void thoat();
void huongDan(int);
void veKhung(int);
void choiLai();

void Goto(int x, int y){
    COORD spot = {x,y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), spot);
}

void TextColor(int x)//Xac dinh mau cua chu
{
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}
//Tro Choi
int Chan(int i){// Kiem tra chan le de phuc vu cho chia luot
    if (i%2==0) return 1;
    else return 0;
}

char OX(int i){
    if (Chan(i)==1) return 'O';
    else return 'X';
}

void veOX(int x, int y){//Ve O, X theo luot
    if (a[x][y] != 'X' && a[x][y] != 'O'){
         if (Chan(i)==1) TextColor(11); else TextColor(12);
         a[x][y]=OX(i);
         cout<<a[x][y];
         i+=1;
    }
    else a[n][m];
    TextColor(7);
}

void trai(){
    x-=1;
    if (x<13) x=13;
}

void phai(){
    x+=1;
    if (x>=77) x=77;
}

void len(){
    y-=1;
    if (y<3) y=3;
}

void xuong(){
    y+=1;
    if (y>=24) y=24;
}

void conTro(int x, int y){  //Phuc vu cho di chuyen
    Goto(x,y);
    n=x;m=y;
}

void thongTintranDau(){
    TextColor(7);
    //Thong tin
    Goto(0,0); cout<<"Toa Do: "<<x-12<<"-"<<y-2<<"    Q : thoat tran dau."<<endl<<"Luot thu: "<<i;
    //Trang tri
    cout<<"     M, E: chon X/O.";
    TextColor(12); cout<<"           PLAYER 1 VS PLAYER 2";
    Goto(0,4); TextColor(11);cout<<"Nguoi Choi 1"<<endl<<"A,D,W,S"<<endl<<endl;
               cout<<"Nguoi choi 2"<<endl<<"Phim di "<<endl<<"chuyen"<<endl<<endl;
    TextColor(14); cout<<"p/s:"<<endl<<"Chan dau,"<<endl<<"chan duoi "<<endl; TextColor(12); cout<<"khong";TextColor(14); cout<<" tinh"<<endl<<endl;
    TextColor(9); cout<<"B: Back"<<endl<<"R: Choi lai"<<endl;
    TextColor(10); cout<<endl<<"Luot: "<<OX(i);
    TextColor(7);
}

int Owin(){//Dieu kien de ben O chien thang
    //Theo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='O')
        n1++;
    n1--;
    //Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giua hang se khong xet
    if ((a[n1][m]=='O') && (a[n1+1][m]=='O') && (a[n1+2][m]=='O') && (a[n1+3][m]=='O') && (a[n1+4][m]=='O') && ((a[n1+5][m] != 'X') || (a[n1-1][m] != 'X')) ) return 1; else
    if ((a[n1][m]=='O') && (a[n1-1][m]=='O') && (a[n1-2][m]=='O') && (a[n1-3][m]=='O') && (a[n1-4][m]=='O') && ((a[n1-5][m] != 'X') || (a[n1+1][m] != 'X')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='O')
        m1++;
    m1--;
    //Theo duong cheo chinh
    if ((a[n][m1]=='O') && (a[n][m1+1]=='O') && (a[n][m1+2]=='O') && (a[n][m1+3]=='O') && (a[n][m1+4]=='O') && ((a[n][m1+5] != 'X') || (a[n][m1-1] != 'X')) ) return 1; else
    if ((a[n][m1]=='O') && (a[n][m1-1]=='O') && (a[n][m1-2]=='O') && (a[n][m1-3]=='O') && (a[n][m1-4]=='O') && ((a[n][m1-5] != 'X') || (a[n][m1+1] != 'X')) ) return 1;
    //Theo duong cheo phu
    m1=m; n1=n;
    while (a[n1][m1]=='O'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='O') && (a[n1+1][m1+1]=='O') && (a[n1+2][m1+2]=='O') && (a[n1+3][m1+3]=='O') && (a[n1+4][m1+4]=='O') && ((a[n1+5][m1+5] != 'X') || (a[n1-1][m1-1] != 'X')) ) return 1; else
    if ((a[n1][m1]=='O') && (a[n1-1][m1-1]=='O') && (a[n1-2][m1-2]=='O') && (a[n1-3][m1-3]=='O') && (a[n1-4][m1-4]=='O') && ((a[n1-5][m1-5] != 'X') || (a[n1+1][m1+1] != 'X')) ) return 1;
    m1=m; n1=n;
    while (a[n1][m1]=='O'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='O' && (a[n1+1][m1-1])=='O' && (a[n1+2][m1-2])=='O' && (a[n1+3][m1-3])=='O' && (a[n1+4][m1-4]=='O' ) && ((a[n1+5][m1-5] != 'X') || (a[n1-1][m1+1] != 'X')) ) return 1; else
    if ((a[n1][m1])=='O' && (a[n1-1][m1+1])=='O' && (a[n1-2][m1+2])=='O' && (a[n1-3][m1+3])=='O' && (a[n1-4][m1+4]=='O' ) && ((a[n1-5][m1+5] != 'X') || (a[n1+1][m1-1] != 'X')) ) return 1;

    return 0;
}

int Xwin(){ //Dieu kien de ben X chien thang
    //THeo hang ngang
    m1=m; n1=n;
    while (a[n1][m]=='X') {
        n1++;
    }
    n1--;
    //Doan tren nham muc dich chuen con tro den vi tri 'O' dau hang de tien cho viec xet vi neu 'O' duoc nhap o giau hang se khong xet duoc
    if ((a[n1][m]=='X') && (a[n1+1][m]=='X') && (a[n1+2][m]=='X') && (a[n1+3][m]=='X') && (a[n1+4][m]=='X') && ((a[n1+5][m] != 'O') || (a[n1-1][m] != 'O')) ) return 1; else //Theo Hang ngang
    if ((a[n1][m]=='X') && (a[n1-1][m]=='X') && (a[n1-2][m]=='X') && (a[n1-3][m]=='X') && (a[n1-4][m]=='X') && ((a[n1-5][m] != 'O') || (a[n1+1][m] != 'O')) ) return 1;
    //Theo hang doc
    m1=m; n1=n;
    while (a[n][m1]=='X') {
        m1++;
    }
    m1--;
    if ((a[n][m1]=='X') && (a[n][m1+1]=='X') && (a[n][m1+2]=='X') && (a[n][m1+3]=='X') && (a[n][m1+4]=='X') && ((a[n][m1+5] != 'O') || (a[n][m1-1] != 'O')) ) return 1; else //Theo Hang doc
    if ((a[n][m1]=='X') && (a[n][m1-1]=='X') && (a[n][m1-2]=='X') && (a[n][m1-3]=='X') && (a[n][m1-4]=='X') && ((a[n][m1-5] != 'O') || (a[n][m1+1] != 'O')) ) return 1;
    //Theo duong cheo chinh
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        m1++; n1++;
    }
    m1--; n1--;
    if ((a[n1][m1]=='X') && (a[n1+1][m1+1]=='X') && (a[n1+2][m1+2]=='X') && (a[n1+3][m1+3]=='X') && (a[n1+4][m1+4]=='X') && ((a[n1+5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1; else //Theo Duong cheo chinh
    if ((a[n1][m1]=='X') && (a[n1-1][m1-1]=='X') && (a[n1-2][m1-2]=='X') && (a[n1-3][m1-3]=='X') && (a[n1-4][m1-4]=='X') && ((a[n1-5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1;
    //Theo duong cheo phu
    m1=m; n1=n;
    while (a[n1][m1]=='X'){
        n1++; m1--;
    }
    n1--; m1++;
    if ((a[n1][m1])=='X' && (a[n1+1][m1-1])=='X' && (a[n1+2][m1-2])=='X' && (a[n1+3][m1-3])=='X' && (a[n1+4][m1-4]=='X' ) && ((a[n1+5][m1-5] != 'O') || (a[n1+1][m1+1] != 'O')) ) return 1; else //Theo Duong cheo phu
    if ((a[n1][m1])=='X' && (a[n1-1][m1+1])=='X' && (a[n1-2][m1+2])=='X' && (a[n1-3][m1+3])=='X' && (a[n1-4][m1+4]=='X' ) && ((a[n1-5][m1+5] != 'O') || (a[n1-1][m1-1] != 'O')) ) return 1;
    //Khong chien thang
    return 0;
}
// Ai do chien thang
void win(){
    TextColor(12);
    if ((Owin()==1)){
        Goto(27,3); TextColor(11); cout<<"O chien thang. An R de choi lai. Q de thoat";
        key=getch();
        if (key=='r' || key=='R') choiLai();
        else
            if (key=='q' || key=='Q') thoat(); else moDau(50);
    }
    else
        if ((Xwin()==1)){
            Goto(27,3);  TextColor(12); cout<<"X Chien Thang. An R de choi lai. Q de thoat";
            key=getch();
        if (key=='r' || key=='R') choiLai();
        else
            if (key=='q' || key=='Q') thoat(); else moDau(50);
        }
    TextColor(7);
}

void choiLai(){ //Khoi phuc nguyen hien trang
    taoBackground();
    i=0; x=13; y=3;
    system("cls");
    thongTintranDau();
    veKhung(0);
}

void banPhim(){
    key=getch();
    if (key=='a' || key=='A' || int (key==75)) trai(); else
    if (key=='d' || key=='D' || int (key==77)) phai(); else
    if (key=='w' || key=='W' || int (key==72)) len(); else
    if (key=='s' || key=='S' || int (key==80)) xuong(); else
    if (key=='e' || key=='E' || key=='m' || key=='M') veOX(n,m); else
    if (key=='r' || key=='R') choiLai();
    if (key=='b' || key=='B') moDau(50);
}

int main(){
    taoBackground();
    moDau(100);
    return 0;
}

void moDau(int n){
    system("cls");
    TextColor(11);
    Goto(31,6);cout<<"1. Choi."<<endl;
    Sleep(n); Goto(31,7);cout<<"2. Huong Dan."<<endl;
    Sleep(n); Goto(31,8);cout<<"3. Thoat"<<endl;
    Sleep(n); Goto(31,9);cout<<"Menu: ";
    luaChon=getch();
    cout<<char (luaChon);
    Sleep(200);
    if (luaChon== '1') choi2Nguoi(); else
    if (luaChon== '2') huongDan(1); else
    if (luaChon== '3') thoat(); else moDau(0);
    TextColor(7);

}

void veKhung(int n){
    int i;
    Goto(12,2);
    for (i=0; i<=65; i++){
        cout<<"_"; Sleep(n);   //canh tren
    }
    for (i=0; i<=21; i++) {
        Goto(12,i+3);          //canh trai
        Sleep(n);
        cout<<"|";
    }
    Goto(13,24);
    for (i=0; i<=64; i++) {
        cout<<"_"; Sleep(n);   //canh duoi
    }

    for (i=0; i<=21; i++) {
        Goto(78,i+3);		   //canh phai
        Sleep(n);
        cout<<"|";
    }
}

void batDau(){
    system("cls");
    huongDan(2);
    system("cls");
    veKhung(3);
}

void choi2Nguoi(){
    batDau();
    x=n=13; y=m=3;
    i=0;
    do{
        thongTintranDau();
        conTro(x,y);
        win();
        banPhim();
    } while (key != 'q' && key != 'Q');
    thoat();
}

void huongDan(int k){
    cout<<endl<<endl<<"                             HUONG DAN"<<endl<<endl;
    cout<<"Dung";
    TextColor(12); cout<<" phim di chuyen";
    TextColor(7);  cout<<" hoac";
    TextColor(12); cout<<" A,D,W,S";
    TextColor(7);  cout<<" de di chuyen. Dung phim";
    TextColor(12); cout<<" E";
    TextColor(7);  cout<<" va";
    TextColor(12); cout<<" M";
    TextColor(7);  cout<<" de chon."<<endl<<"Let's play!"<<endl;;
    system("pause");
    if (k==1) moDau(0);
}


void thoat(){
    TextColor(10);
    Goto(31,11); cout << "Xin Chao! Hen Gap lai!";
    getch();
}
