#include <unistd.h>
#include <windows.h>
#include <bits/stdc++.h>
#include <string>
#include <string.h>
#include <ctime>
#include <fstream>

using namespace std;
const int x =24;   //tọa độ CUA TABLE
const int y =4;   //tọa độ CUA TABLE
int z = y;

void GoTo(int posX, int posY);
void TextColor(int x);

struct sinhvien{
  string name;
  int id;
  float score;
  string subject;
  
  sinhvien(){
    name ="Nguyen Van Minh Quan";
    id = 2722225;
    score = 8.9;
    subject = "IT";
  }
  sinhvien (string hoten, int ID, float diem, string monhoc){
    name = hoten;
    id = ID;
    score = diem;
    subject = monhoc;
  };
    void Nhap(){
        GoTo(x-3, y+19); cout <<"(!) Nhap ho ten sinh vien: ";
        fflush(stdin);
        getline(cin, name);
        cin.ignore();
        do{
            fflush(stdin);
            GoTo(x-3, y+20);
            cout <<"(!) Nhap ma so sinh vien: ";
            cin>>id;
            fflush(stdin);
            GoTo(x-3, y+21);
            cout<<"(!) Nhap diem so sinh vien: ";
            cin>>score;
            GoTo(x-3, y+22);
            cout<<"(!) Nhap mon hoc: ";
            fflush(stdin);
            getline(cin, subject);
            cin.ignore();
            if(score<0 || score>10){
                TextColor(4); GoTo(x+25, y+21); cout<<score;
                TextColor(7);
                cout <<"\n\n\n\t\t\t  Diem khong hop le";
                cout<<"\n\t\tChuong trinh se chay toi khi diem hop le";
                cout<<"\n\t\t\t   Xin hay nhap lai\n";
                Sleep(3000);
                GoTo(x-3, y+22);
                cout<<"\n\n                                             ";
                cout<<"\n                                                         ";
                cout<<"\n                                             ";
                do {
                    TextColor(7);
                    GoTo(x-3, y+21);
                    cout<<"(!) Nhap diem so sinh vien: ";
                    cout<<"        ";
                    GoTo(x-3, y+21);
                    cout<<"(!) Nhap diem so sinh vien: ";
                    cin>>score;
                    if(score<0 || score>10){
                    TextColor(4); GoTo(x+25, y+21); cout<<score;
                    Sleep(153);
                    }
                } while (score <0 || score > 10);
            }
        }while(score <0 || score > 10);

    }
};

void sort(sinhvien *person, int n);
void CapNhat(sinhvien *person, int n);
float Min(sinhvien *person, int n);
float Max(sinhvien *person, int n);
void drawTable();
void Press();
void NhapSV(sinhvien *person, int &n);
void printtable(int n);
void printinfor(sinhvien *person, int n);
void XoaSV(sinhvien *person, int &n);
void search(sinhvien *person, int n);
void swap(sinhvien &x, sinhvien &y);
void sort(sinhvien *person, int n);


int main(){
    system("cls");
    SetConsoleOutputCP(65001);
    sinhvien *person = new sinhvien[10];
    int count =1, choice;
    // sinhvien("Quan"
    // for (int i=0; i<=10; ++i){
    //     // if ((person[i].score <= 0) && (person[i].score >=0) ){
    //         if((person[i].name).size() != 0){
    //         count++;
    //     } else {
    //         count=0;
    //     }
    // }
    do{
        TextColor(7);
        SetConsoleOutputCP(65001);
        system("cls");
        drawTable();
        GoTo(x+12, y+16); cout<<"⚠️  LỰA CHỌN CỦA BẠN LÀ: ";
        cin>>choice;
        switch (choice){
        case 0:
            printtable(count);
            printinfor(person, count);
            cout<<endl<<endl<<endl;
            Press();
            break;
        case 1:
            NhapSV(person, count);
            count++;
            Sleep(2534);
            break;
        case 2:
            printtable(count);
            printinfor(person, count);
            CapNhat(person, count);
            Press();
            break;
        ///////////////////////////  
        case 3:
            printtable(count);
            printinfor(person, count);
            XoaSV(person, count);
            Sleep(2543);
            break;
         ///////////////////////////   
        case 4:
            printtable(count);
            printinfor(person, count);
            search(person, count);
            Sleep(2543);
            break;
        ////////////////////////
        case 5:
            sort(person, count);
            Sleep(2543);
            break;
        // case 7:
        //     loadingbar();
        //     Press();
        //     TextColor(7);
        //     SetConsoleOutputCP(65001);
        //     break;
        // case 8:
        //     loadingbar();
        //     Press();
        //     TextColor(7);
        //     SetConsoleOutputCP(65001);
        //     break;
        case 9:
            system("cls");
            break;
        default:
            system("cls");
            cout<<"\n\n\t\t\t Lua chon khong hop le !";\
            break;
        }
    } while (choice != 9);
    system("cls");
    cout<<"Thank for watching !";
    delete[] person;
    return 0;
}       


void XoaSV(sinhvien *person, int &n){
    int so, count =0;
    for (int i=0; i<n; ++i){
        count++;
    }

    bool loop = false;
    GoTo(x+10, y+27+count); cout<<"+-------------------------------+";
    GoTo(x+10, y+28+count); cout<<"|";
    GoTo(x+42, y+28+count); cout<<"|";
    GoTo(x+14, y+28+count); cout<<"(4)Xoa thong tin sinh vien";

    GoTo(x+10, y+29+count); cout<<"+------";
    GoTo(x+10, y+30+count); cout<<"|";
    GoTo(x+13, y+30+count); cout<<"ID";

    GoTo(x+17, y+29+count); cout<<"+------------------------+";
    GoTo(x+17, y+30+count); cout<<"|";
    GoTo(x+42, y+30+count); cout<<"|";

    GoTo(x+10, y+31+count); cout<<"+------";
    GoTo(x+10, y+32+count); cout<<"|Status";
    GoTo(x+10, y+33+count); cout<<"+------";

    GoTo(x+17, y+31+count); cout<<"+------------------------+";
    GoTo(x+17, y+32+count); cout<<"|";	
    GoTo(x+42, y+32+count); cout<<"|";
    GoTo(x+17, y+33+count); cout<<"+------------------------+";

    do {
        GoTo(x+23, y+30+count); cout<<"              ";
        GoTo(x+23,y+32+count); cout<<"              ";
        GoTo(x+26, y+30+count);
        cin >>so;
        for(int i=0; i<n;i++){
                if(person[i].id == so){
                    for(int j=i; j<n; j++){
                        person[j] = person[j+1];
                    }
                    n--;
                    break;
                } else if (person[i].id != so) {
                    GoTo(x+23,y+32+count);
                    cout<<"KHONG HOP LE!";
                    Sleep(243);
                    loop = true;
                }
            }
    } while (loop == true);   
	srand(time(NULL));
    //Set ASCII to print special character.
    //Code page 437
    GoTo(x+18, y+32+count);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
	int m;
    for(int i = 0; i < 24; i++){
		TextColor(10);
        cout << (char)bar1;
	}
    GoTo(x+18,y+32+count);
    for(int i = 0; i < 23; i++){
		TextColor(10);
        cout << (char)bar2;
		m = rand() % 500 +1;
        Sleep(m);
    }
    Sleep(645);
    GoTo(x+18,y+32+count); cout<<"                        ";
    GoTo(x+25,y+32+count); cout<<"COMPLETE!";
    GoTo(x+25,y+35+count);
}
void printinfor(sinhvien *person, int n){
    for (int i=0; i<n; ++i){
        GoTo(x+4, y+22+i); cout<<person[i].name;
        GoTo(x+28, y+22+i); cout<<person[i].id;       
        GoTo(x+40, y+22+i); cout<<person[i].score;
        GoTo(x+49, y+22+i); cout<<person[i].subject;
        GoTo(x+4, y+26+i);
    }
}
float Max(sinhvien *person, int n){
    float max = person[0].score;
    for(int i=1;i<n;i++){
        if(person[i].score >max)
        {
            max = person[i].score;
        }
    }
    return max;
}
float Min(sinhvien *person, int n){
    float min = person[0].score;
    for(int i=1; i<n; i++){
        if(person[i].score < min)
        {
            min = person[i].score;
        }
    }
    return min;
}
void NhapSV(sinhvien *person, int &n){
    bool loop = true;
    char choice;
    do {
        //system("cls");
        TextColor(7);
        person[n].Nhap();
        GoTo(x-3, y+24); cout<<"                                                                 "<<endl<<"                                                                                                          ";
        GoTo(x-3, y+23);
        cout<<"(?) Ban co muon tiep tuc khong (y/n) ";
        cin>>choice;
        if (choice =='y' || choice =='Y'){
            loop = true;
            system("cls");
            drawTable();
            ++n;
        } else if (choice =='n' || choice =='N'){
            loop = false;
            system("cls");
        }
    } while (loop == true);
}
void printtable(int n){
    GoTo(x-4, y+19); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+19); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+19); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+19); cout<<"+";

    GoTo(x-4, y+20); cout<<"|";
    GoTo(x+2, y+20); cout<<"|";
    GoTo(x+26, y+20); cout<<"|";
    GoTo(x+36, y+20); cout<<"|";
    GoTo(x+46, y+20); cout<<"|";
    GoTo(x+56, y+20); cout<<"|";

    GoTo(x-4, y+21); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+21); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+21); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+21); cout<<"+";

    GoTo(x-2, y+20); cout<<"STT";
    GoTo(x+10, y+20); cout<<"Họ và Tên";
    GoTo(x+30, y+20); cout<<"ID";
    GoTo(x+38, y+20); cout<<"Điểm số";
    GoTo(x+48, y+20); cout<<"Môn học";
    GoTo(x+13, y+24);

    int count =0;
    for (int i=0; i<n; ++i){
        GoTo(x-4, y+22+i); cout<<"|";
        GoTo(x-1, y+22+i); cout<<i+1;
        GoTo(x+2, y+22+i); cout<<"|";
        GoTo(x+26, y+22+i); cout<<"|";
        GoTo(x+36, y+22+i); cout<<"|";
        GoTo(x+46, y+22+i); cout<<"|";
        GoTo(x+56, y+22+i); cout<<"|";

        count++;
    }
    GoTo(x-4, y+22+count); cout<<"+"; cout<<"-----"; 
    GoTo(x+2, y+22+count); cout<<"+"; cout<<"-----------------------";
    GoTo(x+26, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+36, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+46, y+22+count); cout<<"+"; cout<<"---------";
    GoTo(x+56, y+22+count); cout<<"+";
    cout<<endl;
}
void GoTo(int posX, int posY){
    //Hàm di chuyển con trỏ 
    //scr :stackoverflow
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Position;
    Position.X = posX;
    Position.Y = posY;
	SetConsoleCursorPosition(hStdout, Position);
}
void drawTable(){
    // KẺ ĐƯỜNG VIỀN CHO TABLE
    GoTo(x,y); cout<<"+"; cout<<"-----";
    GoTo(x+6,y); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33,y); cout<<"+"; cout<<"----------------";
    GoTo(x+50,y); cout<<"+"; 
    GoTo(x, y+1); cout<<"|"; GoTo(x+6, y+1); cout<<"|"; GoTo(x+33, y+1); cout<<"|"; GoTo(x+50, y+1); cout<<"|";
    GoTo(x, y+2); cout<<"+"; cout<<"-----";
    GoTo(x+6, y+2); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33, y+2); cout<<"+"; cout<<"----------------";
    GoTo(x+50, y+2); cout<<"+";

    GoTo(x+34, y+6); cout<<"----------------";
    GoTo(x+34, y+9); cout<<"----------------";

    GoTo(x, y+13); cout<<"+"; cout<<"-----";
    GoTo(x+6, y+13); cout<<"+"; cout<<"--------------------------";
    GoTo(x+33, y+13); cout<<"+"; cout<<"----------------";
    GoTo(x+50, y+13); cout<<"+";
    GoTo(x+2, y+1); cout<<"STT"; GoTo(x+12, y+1); cout<<"-> CHỨC NĂNG <-"; GoTo(x+37, y+1); cout<<"SỠ HỮU BỞI";

    //  KẺ "|"
    for (int i=y+3-z; i<y+13-z; ++i){
        GoTo(x, y+i); cout<<"|";
        GoTo(x+6, y+i); cout<<"|"; 
        GoTo(x+33, y+i); cout<<"|"; 
        GoTo(x+50, y+i); cout<<"|";
    }
    //  VIẾT SỐ
    for (int i=0; i<10; ++i){
        GoTo(x+3, y+3+i); cout<<i;
    }
    //  VIẾT CHỨC NĂNG
    for (int i=0; i<10; ++i){
        switch (i){
        case 0:
            GoTo(x+8, y+3+i);
            cout<<"In danh sách sinh viên";
            GoTo(x+39, y+3+i);
            cout<<"Name: ";
            break;
        case 1:
            GoTo(x+8, y+3+i);
            cout<<"Thêm sinh viên";
            GoTo(x+37, y+3+i);
            cout<<"Nguyễn Văn";
            break;
        case 2:
            GoTo(x+8, y+3+i);
            cout<<"Sữa thông tin sinh viên";
            GoTo(x+37, y+3+i);
            cout<<"Minh Quân";
            break;
        case 3:
            GoTo(x+8, y+3+i);
            cout<<"Xóa thông tin sinh viên";
            break;
        case 4:
            GoTo(x+8, y+3+i);
            cout<<"Tìm kiếm thông tin";
            GoTo(x+39, y+3+i);
            cout<<"Class: ";
            break;
        case 5:
            GoTo(x+8, y+3+i);
            cout<<"Sắp xếp sinh viên";
            GoTo(x+38, y+3+i);
            cout<<"TH27.40";
            break;
        case 6:
            GoTo(x+8, y+3+i);
            cout<<"Thống kê sinh viên";
            break;
        case 7:
            GoTo(x+8, y+3+i);
            cout<<"Sao lưu thông tin";
            GoTo(x+37, y+3+i);
            cout<<"Quê quán: ";
            break;
        case 8:
            GoTo(x+8, y+3+i);
            cout<<"Khôi phục thông tin";
            GoTo(x+38, y+3+i);
            cout<<"Nghệ An";
            break;
        case 9: 
            GoTo(x+8, y+3+i);
            cout<<"Thoát chương trình";
            GoTo(x+37, y+3+i);
            cout<<"Hoàng Mai";
            break;
        }
    }
}
void Press(){
    system("pause");
    system("cls");
}
void TextColor(int x){
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, x);
}
void search(sinhvien *person, int n){
    bool loop = true;
    int ID =0;
    do{
        cout<<"(4) Tim kiem thong tin sinh vien";
        cout<<"           (!) Nhap ID sinh vien: ";
        cin>>ID;
        for (int i=0; i<n; ++i){
            if (ID == person[i].id){ //**
                system("cls");
                GoTo(x+4, y+22+i); cout<<person[i].name;
                GoTo(x+28, y+22+i); cout<<person[i].id;       
                GoTo(x+40, y+22+i); cout<<person[i].score;
                GoTo(x+49, y+22+i); cout<<person[i].subject;
                GoTo(x+4, y+26+i);
                loop = false;
            } else { 
                cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
                loop = true;
            }
        }    
    } while (loop == true);
}
void CapNhat(sinhvien *person, int n){
    int so;
    bool loop = false;
    cout <<"ID THONG TIN SINH VIEN CAN THAY DOI: ";
    cin >>so;
    for(int i=0; i<n;i++){
        if(person[i].id == so){
            system("cls");
           person[i].Nhap();
           loop = true;
        }
    }
    if(loop == false)
        cout <<"Ban da nhap ma so sinh vien sai!"<<endl;
} 
void sort(sinhvien *person, int n){
    bool loop = true;
    char choice;
    do{
        cout<<"(5) Sap xep thong tin sinh vien";
        cout<<"           (!) Sap xep theo diem sinh vien: ";
        cout<<"           (?) Sap xep theo ten sinh vien";
        cout<<"\n                     Lua chon cua ban la: ";
        cin>>choice;
        system("cls");
        switch (choice){
        case '!':
            for (int i=0; i<n; ++i){ //***
                for (int j=i+1; j<n; ++j){
                if (person[i].score < person[j].score) 
                    swap(person[i], person[j]);
                }
            }
            for (int i=0; i<n; ++i){
                cout<<person[i].name<<endl;
                cout<<person[i].id<<endl;       
                cout<<person[i].score<<endl;
                cout<<person[i].subject;
                cout<<"\n\n\n";
            }
            loop = false;
            break;
        case '?':
            for (int i= (person[i].name).size(); i>0; --i){ //***

            }
            loop = false;
            break;
        default:
            system("cls");
            cout<<"\n\n\t\t\t Lua chon khong hop le !";
            break;
        }
    } while (loop == true);
}
void swap(sinhvien &x,sinhvien &y){
   sinhvien index=x;
   x=y;
   y=index;
}
