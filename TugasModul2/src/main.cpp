#include <iostream>
#include <math.h>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

float posisi_x = 0.00;
float posisi_y = 0.00;

vector<float> history_x{0.00};
vector<float> history_y{0.00};
int count = history_x.size()-1;
float n = 0;

float lokasi(){
    posisi_x = history_x[n];
    posisi_y = history_y[n];
    cout<<"Lokasi => ";
    cout<<"("<<posisi_x<<", "<<posisi_y/1<<")"<<endl;
    return posisi_x;
    return posisi_y;
}

float gerak(float x, float y){
    posisi_x += x;
    history_x.at(n+1)=posisi_x;
    posisi_y += y;
    history_y.at(n+1)=posisi_y;  
    n, count += 1;

    return posisi_x;
    return posisi_y;
}

float gerak_2(float v, float t, float theta){
    posisi_x += (v*t)*cos(theta*3.14159265359/180);
    history_x.at(n+1)=posisi_x;  
    posisi_y += (v*t)*sin(theta*3.14159265359/180);
    history_y.at(n+1)=posisi_y;   
    n, count += 1;
    return posisi_x;
    return posisi_y;
}

float undo(){
    if(n>0){
        n -= 1;
        cout<<"Undo berhasil!"<<endl;
    }
    else if(n==0){
        cout<<"Tidak dapat undo!"<<endl;
    }
    return n;
}

float redo(){
    if(n<count){
        n += 1;
        cout<<"Redo berhasil!"<<endl;
    }
    else if(n==count){
        cout<<"Tidak dapat redo!"<<endl;
    }
    return n;
}

int main(){
    string option;

    cout<<"---Silakan Pilih Fungsi---"<<endl;
    cout<<"[1] Lokasi"<<endl;
    cout<<"[2] Gerak"<<endl;
    cout<<"[3] Gerak_2"<<endl;
    cout<<"[4] Undo"<<endl;
    cout<<"[5] Redo"<<endl;
    cout<<"[0] Keluar"<<endl;

    while(option != "0"){
        cout<<"Masukkan pilihan: ";
        cin>>option;
        
        if(option=="1"){
            lokasi();
        }

        else if(option=="2"){
            float gerak_x;
            float gerak_y;
            cout<<"x: ";
            cin>>gerak_x;
            cout<<"y: ";
            cin>>gerak_y;
            gerak(gerak_x,gerak_y);
        }

        else if(option=="3"){
            float gerak_v;
            float gerak_t;
            float gerak_theta;
            cout<<"v: ";
            cin>>gerak_v;
            cout<<"t: ";
            cin>>gerak_t;
            cout<<"theta: ";
            cin>>gerak_theta;
            gerak_2(gerak_v,gerak_t,gerak_theta);
        }

        else if(option=="4"){
            undo();
        }

        else if(option=="5"){
            redo();
        }

        else if(option=="0"){
            break;
        }

    }

    return 0;
}