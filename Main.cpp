// include beberapa library dari c++
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

// Class User
class User
{
private:
    // deklarasi atribut dari class user
    string username = "null";
    string password = "null";
    ofstream masukin;
    ifstream nampilin;
    string namafile = "data/dataUser.txt";

public:
    // constructor user
    User(string username, string password);
    // prototype
    // method getter dan beberapa method lainnya
    string getUser();
    string getUsername();
    bool daftar();
    int login(string username, string password);
};

// prototype method header
void headerScreen();
void headerMenu();
void headerMenuUser();

// prototype method footer
void footer();

int main(int argc, char const *argv[])
{
    string menu;
    system("cls");
    do
    {
        system("cls");
        headerMenu();
        cout << "Silahkan Pilih Menu : ";
        cin >> menu;
        if (menu == "1")
        {
            system("cls");
            string username, password;
            int login = 0;
            cout << "+======================+" << endl;
            cout << "|      LOGIN USER      |" << endl;
            cout << "+======================+\n"
                 << endl;
            cout << "Masukkan Username : ";
            cin >> username;
            cout << "Masukkan Password : ";
            cin >> password;
            User *user = new User(username, password);
            login = user->login(username, password);
            if (login == 1)
            {
                cout << "\nPassword Salah" << endl;
                system("pause");
            }
            else if (login == 2)
            {
                cout << "\nSukses Login" << endl;
                system("pause");
                dashboard(user);
            }
            else
            {
                cout << "\nUsername dan Password Salah" << endl;
                system("pause");
            }
        }
        else if (menu == "2")
        {
            system("cls");
            bool cek = false;
            while (!cek)
            {

                string username, password;
                cout << "+=======================+" << endl;
                cout << "|     REGISTER USER     |" << endl;
                cout << "+=======================+\n"
                     << endl;
                cout << "Masukkan Username : ";
                cin >> username;
                cout << "Masukkan Password : ";
                cin >> password;
                User *user = new User(username, password);
                if (user->daftar() == 1)
                {
                    cek = true;
                }
            }
        }
        else
        {
            system("cls");
        }
    } while (menu != "3");
    footer();
    return 0;
}

// method login dan register user
int User::login(string username, string password)
{
    int login = 0;
    nampilin.open(namafile, ios::in);
    if (nampilin.fail())
    {
        login = 0;
    }
    else
    {
        while (!nampilin.eof())
        {
            nampilin >> username;
            nampilin >> password;
            if (username == this->username || password == this->password)
            {
                if (username == this->username)
                {
                    login = 1;
                }

                if (password == this->password)
                {
                    login = login + 1;
                }
                if (password != this->password)
                {
                    login = login + 0;
                }
                if (username != this->username)
                {
                    login = 0;
                }
                break;
            }
            else
            {
                login = 0;
                continue;
            }
        }
    }
    nampilin.close();
    switch (login)
    {
    case 0:
        // cout << "Username dan Password Salah" << endl;
        return 0;
        break;
    case 1:
        // cout << "Password Salah" << endl;
        return 1;
        break;
    case 2:
        // cout << "Sukses" << endl;
        return 2;
        break;
    default:
        return 0;
        break;
    }
};

bool User::daftar()
{

    string username, password, pilihan = "0";
    bool cek = true;
    masukin.open(namafile, ios::app);
    masukin.close();
    nampilin.open(namafile, ios::in);
    while (!nampilin.eof())
    {
        nampilin >> username;
        nampilin >> password;
        if (username == this->username)
        {
            bool kosong = false;
            cout << "\nUsername Sudah Ada yang Punya!!\n"
                 << endl;
            while (!kosong)
            {
                cout << "1. Daftar Ulang\n2. Ke Halaman Login\nPilih : ";
                cin >> pilihan;
                if (pilihan == "1")
                {
                    system("cls");
                    cek = false;
                    pilihan = "1";
                    kosong = true;
                }
                else if (pilihan == "2")
                {
                    system("cls");
                    cek = false;
                    pilihan = "2";
                    kosong = true;
                }
                else
                {
                    cout << "Coba Lagi" << endl;
                    system("cls");
                }
            }
            break;
        }
    }
    nampilin.close();
    if (cek)
    {
        masukin.open(namafile, ios::app);
        masukin << this->getUser();
        cout << "\nBerhasil Daftar!!" << endl;
        system("pause");
        masukin.close();
        return 1;
    }
    else
    {
        if (pilihan == "1")
        {
            return 0;
        }
        else if (pilihan == "2")
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }
}

// method header
void headerScreen()
{
    cout << "+===================================+" << endl;
    cout << "| SELAMAT DATANG DI PROGRAM MEMANAH |" << endl;
    cout << "+===================================+" << endl;
    cout << endl;
}
void headerMenu()
{
    headerScreen();
    cout << "+==============+" << endl;
    cout << "|     MENU     |" << endl;
    cout << "|==============|" << endl;
    cout << "| 1. Login     |\n| 2. Register  |\n| 3. Exit      |\n";
    cout << "+==============+" << endl;
};
void headerMenuUser()
{
    cout << "+=======================+" << endl;
    cout << "|       MENU USER       |" << endl;
    cout << "|=======================|" << endl;
    cout << "| 1. Lomba Memanah      |" << endl;
    cout << "| 2. Cari Peserta       |" << endl;
    cout << "| 3. Hasil Pertandingan |" << endl;
    cout << "| 4. Daftar Juara       |" << endl;
    cout << "| 5. Logout             |" << endl;
    cout << "+=======================+" << endl;
};

// method footer
void footer()
{
    cout << "+===============================+" << endl;
    cout << "| TERIMAKASIH TELAH BERKUNGJUNG |" << endl;
    cout << "+===============================+" << endl;
};
