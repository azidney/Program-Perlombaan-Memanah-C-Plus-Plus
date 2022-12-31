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
void footer();
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
