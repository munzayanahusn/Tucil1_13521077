// TUGAS KECIL 1 STRATEGI ALGORITMA
// Nama : Husnia Munzayana
// NIM  : 13521077

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>
#include <ctime>
#include "calculation.cpp"
using namespace std;

// Inisiasi Variabel
string user[4], inp[4];
float inpNum[4];
int inpInteger[4];
char op[4] = {'+', '-', '*', '/'};
char op1, op2, op3, op4;
bool validInput = false, validSistem = false;
int count = 0;
float calResult;
vector<string> result;
vector<string> temp;
vector<vector<string>> permInput;
int inKartu;
char inputPil;
string namaFile, inputUser;
clock_t start, endTime;

// Fungsi pengecekan apakah terdapat susunan temp sudah ada di permInput
bool isThereVector(vector<string> temp, vector<vector<string>> permInput)
{
    bool tempFound = true, found = false;
    int i = 0;
    while (i < permInput.size() and !found)
    {
        int j = 0;
        while (j < 4 and tempFound)
        {
            if (permInput[i][j] == temp[j])
            {
                if (j == 3)
                {
                    found = true;
                }
                j++;
            }
            else
                tempFound = false;
        }
        i++;
    }
    return found;
}

// Program Utama
int main()
{
    cout << "\n*** SELAMAT DATANG DI PERMAINAN KARTU 24 ***\n";
    cout << "\nPilih sistem pemilihan kartu:\n    (1) Input nilai kartu sendiri\n    (2) Pilih kartu secara acak\nInput answer : ";
    while (!validSistem)
    { // Validasi masukkan user
        cin >> inKartu;
        if (inKartu == 1 or inKartu == 2)
            validSistem = true;
        else
            cout << "\nMasukkan tidak sesuai! Coba Ulangi (1/2)\nInput answer : ";
    }

    if (inKartu == 2)
    { // Generate 4 kartu random
        string number[13] = {"A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"};
        cout << "Kartu :";
        for (int i = 0; i < 4; i++)
        {
            user[i] = number[rand() % 13];
            cout << " " << user[i];
        }
        cout << "\n";
    }
    else
    { // Pengguna memasukkan sendiri 4 kartu yang dipilih
        cout << "\nMasukkan 4 nilai kartu! Setiap input kartu (K/Q/J/A/2-10) dipisahkan sebuah spasi \nInput Kartu : ";

        while (!validInput)
        { // Validasi input
            cin.clear();
            cin.sync();
            getline(cin, inputUser);
            validInput = true;

            count = 0;
            for (int i = 0; i < inputUser.length(); i++)
            {
                if (inputUser[i] == ' ')
                    count++;
                else
                    user[count] += inputUser[i];
            }

            if (count != 3)
            {
                validInput = false;
                for (int i = 0; i < count; i++)
                    user[i] = "";
                count = 0;
            }
            else
            {
                int i = 0;
                while (i < 4 and validInput)
                {
                    if (user[i] == "A" or user[i] == "2" or user[i] == "3" or user[i] == "4" or user[i] == "5" or user[i] == "6" or user[i] == "7" or user[i] == "8" or user[i] == "9" or user[i] == "10" or user[i] == "J" or user[i] == "Q" or user[i] == "K")
                        i++;
                    else
                        validInput = false;
                }
            }
            if (!validInput)
                cout << "\nMasukkan 4 nilai kartu! Setiap input kartu (K/Q/J/A/2-10) dipisahkan sebuah spasi \nInput Kartu : ";
        }
    }

    // Memulai perhitungan waktu eksekusi
    start = clock();
    count = 0;
    // Permutasi susunan 4 angka/kartu
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (i != j)
            {
                for (int k = 0; k < 4; k++)
                {
                    if (k != i and k != j)
                    {
                        temp.push_back(user[i]);
                        temp.push_back(user[j]);
                        temp.push_back(user[k]);
                        temp.push_back(user[6 - i - j - k]);
                        if (permInput.empty())
                            permInput.push_back(temp);
                        else if (!isThereVector(temp, permInput))
                            permInput.push_back(temp);
                        while (!temp.empty())
                            temp.pop_back();
                    }
                }
            }
        }
    }

    for (int l = 0; l < permInput.size(); l++)
    {
        for (int m = 0; m < 4; m++)
        {
            inp[m] = permInput[l][m];
        }

        // Representasi nilai string kartu menjadi bilangan
        for (int i = 0; i < 4; i++)
        {
            if (inp[i] == "10")
                inpNum[i] = 10;
            else
            {
                switch (inp[i][0])
                {
                case 'A':
                    inpNum[i] = 1;
                    break;
                case 'J':
                    inpNum[i] = 11;
                    break;
                case 'Q':
                    inpNum[i] = 12;
                    break;
                case 'K':
                    inpNum[i] = 13;
                    break;
                default:
                    inpNum[i] = inp[i][0] - '0';
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            inpInteger[i] = static_cast<int>(inpNum[i]);
        }

        // Kemungkinan susunan tanda kurung yang digunakan
        // Kemungkinan 1 : Tanpa tanda kurung
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op1 == '*' or op1 == '/')
                    {
                        if (op2 == '*' or op2 == '/')
                            calResult = calculateA(inpNum, op1, op2, op3);
                        else
                        {
                            if (op3 == '*' or op3 == '/')
                                calResult = calculateB(inpNum, op1, op2, op3);
                            else
                                calResult = calculateA(inpNum, op1, op2, op3);
                        }
                    }
                    else
                    {
                        if (op2 == '*' or op2 == '/')
                        {
                            if (op3 == '*' or op3 == '/')
                                calResult = calculateD(inpNum, op1, op2, op3);
                            else
                                calResult = calculateC(inpNum, op1, op2, op3);
                        }
                        else
                        {
                            if (op3 == '*' or op3 == '/')
                                calResult = calculateE(inpNum, op1, op2, op3);
                            else
                                calResult = calculateA(inpNum, op1, op2, op3);
                        }
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // Kemungkinan 2 : Sepasang tanda kurung mengapit 2 angka
        // (A o B) o C o D
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op2 == '*' or op2 == '/')
                        calResult = calculateA(inpNum, op1, op2, op3);
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                            calResult = calculateB(inpNum, op1, op2, op3);
                        else
                            calResult = calculateA(inpNum, op1, op2, op3);
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back("( " + to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + ")" + " " + op2 + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // A o (B o C) o D
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op1 == '*' or op1 == '/')
                        calResult = calculateC(inpNum, op1, op2, op3);
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                            calResult = calculateD(inpNum, op1, op2, op3);
                        else
                            calResult = calculateC(inpNum, op1, op2, op3);
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + "(" + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + ")" + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // A o B o (C o D)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op1 == '*' or op1 == '/')
                        calResult = calculateE(inpNum, op1, op2, op3);
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                            calResult = calculateF(inpNum, op1, op2, op3);
                        else
                            calResult = calculateE(inpNum, op1, op2, op3);
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + op2 + " " + "(" + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]) + " " + ")");
                    }
                }
            }
        }

        // Kemungkinan 3
        // (A o B o C) o D
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op1 == '*' or op1 == '/')
                        calResult = calculateA(inpNum, op1, op2, op3);
                    else
                    {
                        if (op2 == '*' or op2 == '/')
                            calResult = calculateC(inpNum, op1, op2, op3);
                        else
                            calResult = calculateA(inpNum, op1, op2, op3);
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back("( " + to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + ")" + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // A o (B o C o D)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    if (op2 == '*' or op2 == '/')
                        calResult = calculateD(inpNum, op1, op2, op3);
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                            calResult = calculateF(inpNum, op1, op2, op3);
                        else
                            calResult = calculateD(inpNum, op1, op2, op3);
                    }

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + "(" + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]) + " " + ")");
                    }
                }
            }
        }

        // Kemungkinan 4
        // (A o B) o (C  o D)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    calResult = calculateB(inpNum, op1, op2, op3);

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back("( " + to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + ")" + " " + op2 + " " + "(" + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]) + " " + ")");
                    }
                }
            }
        }

        // Kemungkinan 5
        // ((A o B) o C) o D
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    calResult = calculateA(inpNum, op1, op2, op3);

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back("(( " + to_string(inpInteger[0]) + " " + op1 + " " + to_string(inpInteger[1]) + " " + ")" + " " + op2 + " " + to_string(inpInteger[2]) + " " + ")" + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // (A o (B o C)) o D
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    calResult = calculateC(inpNum, op1, op2, op3);

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back("( " + to_string(inpInteger[0]) + " " + op1 + " " + "(" + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + "))" + " " + op3 + " " + to_string(inpInteger[3]));
                    }
                }
            }
        }

        // A o ((B o C) o D)
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    calResult = calculateD(inpNum, op1, op2, op3);

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + "((" + " " + to_string(inpInteger[1]) + " " + op2 + " " + to_string(inpInteger[2]) + " " + ")" + " " + op3 + " " + to_string(inpInteger[3]) + " " + ")");
                    }
                }
            }
        }

        // A o (B o (C o D))
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    op1 = op[i];
                    op2 = op[j];
                    op3 = op[k];
                    calResult = calculateF(inpNum, op1, op2, op3);

                    // Menyimpan susunan operasi yang menghasilkan nilai 24
                    if (calResult == 24)
                    {
                        count++;
                        result.push_back(to_string(inpInteger[0]) + " " + op1 + " " + "(" + " " + to_string(inpInteger[1]) + " " + op2 + " " + "(" + " " + to_string(inpInteger[2]) + " " + op3 + " " + to_string(inpInteger[3]) + " " + "))");
                    }
                }
            }
        }
    }

    // Akhir eksekusi program, menghitung durasi waktu eksekusi
    endTime = clock();
    double duration = double(endTime - start) / double(CLOCKS_PER_SEC);

    // Menampilkan hasil
    if (count != 0)
    {
        cout << "\n"
             << count << " Solution Found!\n";
        for (auto i = result.begin(); i != result.end(); ++i)
        {
            cout << *i << "\n";
        }
    }
    else
    {
        cout << "Tidak ada solusi\n";
    }
    cout << "Execution time : " << fixed << duration << setprecision(5) << " seconds.\n";

    // Menyimpan solusi pada file .txt
    validInput = false;
    cout << "\nApakah Anda ingin menyimpan hasil ? (Y/N)\nInput answer : ";
    while (!validInput)
    {
        cin >> inputPil;
        if (inputPil == 'Y' or inputPil == 'y')
        {
            validInput = true;
            cout << "Masukkan nama file : ";
            cin >> namaFile;
            ofstream file;
            file.open("../test/" + namaFile + ".txt");
            file << "Kartu : " << user[0] << " " << user[1] << " " << user[2] << " " << user[3] << "\n";
            if (count != 0)
            {
                file << count << " Solution Found!\n";
                for (auto i = result.begin(); i != result.end(); ++i)
                {
                    file << *i << "\n";
                }
            }
            else
            {
                file << "No solution found\n";
            }
            file << "Execution time : " << fixed << duration << setprecision(5) << " seconds.\n";
            file.close();
            cout << "Berhasil menyimpan solusi di '../test/" + namaFile + ".txt'\n";
        }
        else if (inputPil == 'N' or inputPil == 'n')
            validInput = true;
        else
        {
            cout << "\nMasukkan tidak sesuai! Coba Ulangi (Y/N)\nInput answer : ";
        }
    }

    cout << "\nPermainan berakhir. Terimakasih :) \n";
    return 0;
}