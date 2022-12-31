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

// method algoritma lomba memanah
int hitungNomor(int i)
{
    int nomor = 0;
    for (int a = 1; a <= 10; ++a)
    {
        if (a == i)
        {
            nomor = 100 - ((a * 10) - 10);
            break;
        }
    }
    return nomor;
}

// method dashboard user (menu - menu yang ada di user)
void dashboard(User *user)
{

    string menu;
    do
    {
        system("cls");
        headerMenuUser();
        cout << "Selamat datang, " << user->getUsername() << " !!" << endl;
        cout << "Silahkan Pilih Menu : ";
        cin >> menu;
        if (menu == "1")
        {
            ofstream bikin;
            bikin.open("data/dataLomba.txt", ios::app);
            bikin.close();
            ifstream buka;
            int cek = 0;
            string username;
            buka.open("data/dataLomba.txt", ios::in);
            while (!buka.eof())
            {
                buka >> username;
                if (username == user->getUsername())
                {
                    cek++;
                    break;
                }
            }
            if (cek == 0)
            {
                system("cls");
                cout << "+============================+" << endl;
                cout << "|      PROGRAM MEMANAH       |" << endl;
                cout << "+============================+" << endl;
                cout << "KETENTUAN : " << endl;
                cout << "1. Peserta memili Kesempatan memanah sebanyak 3x" << endl;
                cout << "2. Sasaran memanah diberi nomor 1 hingga 10" << endl;
                cout << "3. Jika mengenai sasaran no 1, maka mendapatkan nilai adalah 100" << endl;
                cout << "4. Jika mengenari sasaran no 2, maka mendapatkan nilai adalah 90" << endl;
                cout << "5. Begitupun sasaran memanah berikutnya" << endl;
                cout << "6. Nilai total diperoleh dari akumulasi nilai" << endl;
                cout << "7. Good Luck !!\n"
                     << endl;
                system("pause");
                system("cls");
                cout << "+==========================+" << endl;
                cout << "|      LOMBA MEMANAH       |" << endl;
                cout << "+==========================+" << endl;
                int nomor[3];
                int nomorInput = 0;
                int nomorSize = sizeof(nomor) / sizeof(*nomor);
                for (int i = 0; i < nomorSize; i++)
                {

                    cout << "\nSasaran ke-" << i + 1;
                    cout << "\nMasukkan Nomor (1-10) : ";
                    cin >> nomorInput;
                    if (nomorInput > 10 || nomorInput < 1)
                    {
                        cout << "Nomor yang anda masukkan salah" << endl;
                        nomor[i] = 0;
                        continue;
                    }
                    else
                    {
                        nomor[i] = nomorInput;
                        continue;
                    }
                }
                int total = 0;
                for (int i = 0; i < nomorSize; i++)
                {
                    total += hitungNomor(nomor[i]);
                }

                string newNomor = user->getUsername();
                newNomor += " ";
                for (int i = 0; i < nomorSize; i++)
                {
                    newNomor += to_string(nomor[i]);
                    newNomor += " ";
                }

                newNomor += to_string(total);
                ofstream simpan;
                simpan.open("data/dataLomba.txt", ios::app);
                simpan << newNomor << "\n";
                simpan.close();
                system("pause");
            }
            else
            {
                system("cls");
                cout << "+==========================================+" << endl;
                cout << "|      ANDA SUDAH MELAKUKAN PERLOMBAAN     |" << endl;
                cout << "+==========================================+" << endl;
                system("pause");
            }
            buka.close();
        }
        else if (menu == "2")
        {
            string username, user, nilai1, nilai2, nilai3, total;
            int cek = 0;
            ifstream buka;
            system("cls");
            cout << "+==========================+" << endl;
            cout << "|       CARI PESERTA       |" << endl;
            cout << "+==========================+\n"
                 << endl;
            cout << "Masukkan Username : ";
            cin >> username;
            buka.open("data/dataUser.txt", ios::in);
            while (!buka.eof())
            {
                buka >> user;
                if (username == user)
                {
                    cek++;
                    break;
                }
            }
            buka.close();
            if (cek > 0)
            {
                system("cls");
                cout << "+=========================+" << endl;
                cout << "|    PESERTA DITEMUKAN    |" << endl;
                cout << "+=========================+\n"
                     << endl;
                cout << "Username : " << username << endl;
                buka.open("data/dataLomba.txt", ios::in);
                int cekLomba = 0;
                while (!buka.eof())
                {
                    buka >> user;
                    buka >> nilai1;
                    buka >> nilai2;
                    buka >> nilai3;
                    buka >> total;
                    cout << user << endl;
                    if (username == user)
                    {
                        cekLomba = 2;
                        break;
                    }
                    else
                    {
                        cekLomba = 1;
                    }
                }
                cout << cekLomba << endl;
                buka.close();
                if (cekLomba > 1)
                {
                    cout << "\n+=========================+" << endl;
                    cout << "|    Hasil Pertandingan   |" << endl;
                    cout << "+=========================+\n"
                         << endl;
                    cout << "Nilai Sasaran ke-1 : " << hitungNomor(stoi(nilai1)) << endl;
                    cout << "Nilai Sasaran ke-2 : " << hitungNomor(stoi(nilai2)) << endl;
                    cout << "Nilai Sasaran ke-3 : " << hitungNomor(stoi(nilai3)) << endl;
                    cout << "Total Perolehan Nilai : " << total << "\n"
                         << endl;
                }
                else
                {
                    cout << "\n* Peserta belum melakukan perlombaan\n\n";
                }
            }
            else
            {
                system("cls");
                cout << "+==============================+" << endl;
                cout << "|    MAAF PESERTA TIDAK ADA    |" << endl;
                cout << "+==============================+\n"
                     << endl;
            }
            system("pause");
        }

    } while (menu != "5");
};

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

// method constructor
User::User(string username, string password)
{
    this->username = username;
    this->password = password;
}

// method untuk user
string User::getUser()
{
    return this->username + " " + this->password + "\n";
}

string User::getUsername()
{
    return this->username;
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
