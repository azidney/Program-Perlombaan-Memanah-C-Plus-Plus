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

int main(int argc, char const *argv[])
{

    return 0;
}
