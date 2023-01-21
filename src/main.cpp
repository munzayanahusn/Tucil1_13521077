// TUGAS KECIL 1 STRATEGI ALGORITMA
// Nama : Husnia Munzayana
// NIM  : 13521077

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>
using namespace std;

// Inisiasi Variabel
string inp[4];
float inpNum[4];
int inpInteger[4];
char op[4] = {'+', '-', '*', '/'};
char op1, op2, op3, op4;
bool valInput = false;
int count = 0;
float calResult;
vector<string> result;
clock_t start;
double duration;

// Fungsi kalkulasi
float calculate(float input1, float input2, char op)
{
    float hasilbagi;
    switch (op)
    {
    case '+':
        return input1 + input2;
    case '-':
        return input1 - input2;
    case '*':
        return input1 * input2;
    case '/':
        if (input2 == 0)
            hasilbagi = -1;
        else
            hasilbagi = float(input1) / input2;
        return hasilbagi;
    }
}
float calculateA(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 123
    float res;
    res = calculate(input[0], input[1], op1);
    res = calculate(res, input[2], op2);
    res = calculate(res, input[3], op3);
    return res;
}
float calculateB(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 132
    float res, res1, res2;
    res1 = calculate(input[0], input[1], op1);
    res2 = calculate(input[2], input[3], op3);
    res = calculate(res1, res2, op2);
    return res;
}
float calculateC(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 213
    float res;
    res = calculate(input[1], input[2], op2);
    res = calculate(input[0], res, op1);
    res = calculate(res, input[3], op3);
    return res;
}
float calculateD(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 231
    float res;
    res = calculate(input[1], input[2], op2);
    res = calculate(res, input[3], op3);
    res = calculate(input[0], res, op1);
    return res;
}
float calculateE(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 312
    float res, res1, res2;
    res2 = calculate(input[2], input[3], op3);
    res1 = calculate(input[0], input[1], op1);
    res = calculate(res1, res2, op2);
    return res;
}
float calculateF(float input[4], char op1, char op2, char op3)
{ // Skema perhitungan 321
    float res;
    res = calculate(input[2], input[3], op3);
    res = calculate(input[1], res, op2);
    res = calculate(input[0], res, op1);
    return res;
}

// Program Utama
int main()
{
    cin >> inp[0] >> inp[1] >> inp[2] >> inp[3];

    // Validasi Input
    /*
    while (!valInput)
    {
        valInput = true;
        cin >> inp[0];
        cout << "input 1 " << inp[0];
        cin >> inp[1];
        cout << "input 1 " << inp[1];
        cin >> inp[2];
        cout << "input 1 " << inp[2];
        cin >> inp[3];
        cout << "input 1 " << inp[3];

        for (int i = 0; i < 4; i++)
        {
            if (inp[i] != "A" or inp[i] != "2" or inp[i] != "3" or inp[i] != "4" or inp[i] != "5" or inp[i] != "6" or inp[i] != "7" or inp[i] != "8" or inp[i] != "9" or inp[i] != "10" or inp[i] != "J" or inp[i] != "Q" or inp[i] != "K")
            {
                valInput = false;
                break;
            }
        }
    }
    */

    // Mengubah input jadi angka
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
    // Kemungkinan susunan penggunaan kurung:
    /*
    1. Tanpa tanda kurung
    2. 1 Kurung 2 input
        (A o B) o C o D
        A o (B o C) o D
        A o B o (C o D)
    3. 1 Kurung 3 Input
        (A o B o C) o D
        A o (B o C o D)
    4. 2 Kurung/2 input
        (A o B) o (C  o D)
    5. Nested
        ((A o B) o C) o D
        (A o (B o C)) o D
        A o ((B o C) o D)
        A o (B o (C o D))
    */

    start = clock();
    // Kemungkinan 1
    cout << "Kemungkinan 1 \n";
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
                    {
                        calResult = calculateA(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                        {
                            calResult = calculateB(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                        else
                        {
                            calResult = calculateA(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                    }
                }
                else
                {
                    if (op2 == '*' or op2 == '/')
                    {
                        if (op3 == '*' or op3 == '/')
                        {
                            calResult = calculateD(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                        else
                        {
                            calResult = calculateC(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                    }
                    else
                    {
                        if (op3 == '*' or op3 == '/')
                        {
                            calResult = calculateE(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                        else
                        {
                            calResult = calculateA(inpNum, op1, op2, op3);
                            // cout << op1 << op2 << op3 << " " << calResult << "\n";
                        }
                    }
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]));
                }
            }
        }
    }

    // Kemungkinan 2
    // (A o B) o C o D
    cout << "Kemungkinan 2a \n";
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
                {
                    calResult = calculateA(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }
                else
                {
                    if (op3 == '*' or op3 == '/')
                    {
                        calResult = calculateB(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                        calResult = calculateA(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back("(" + to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + ")" + op2 + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]));
                }
            }
        }
    }

    // A o (B o C) o D
    cout << "Kemungkinan 2b \n";
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
                    calResult = calculateC(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }
                else
                {
                    if (op3 == '*' or op3 == '/')
                    {
                        calResult = calculateD(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                        calResult = calculateC(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + "(" + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + ")" + op3 + to_string(inpNum[3]));
                }
            }
        }
    }

    // A o B o (C o D)
    cout << "Kemungkinan 2c \n";
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
                    calResult = calculateE(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }
                else
                {
                    if (op3 == '*' or op3 == '/')
                    {
                        calResult = calculateF(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                        calResult = calculateE(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + op2 + "(" + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]) + ")");
                }
            }
        }
    }

    // Kemungkinan 3
    // (A o B o C) o D
    cout << "Kemungkinan 3a \n";
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
                    calResult = calculateA(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }
                else
                {
                    if (op2 == '*' or op2 == '/')
                    {
                        calResult = calculateC(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                    {
                        calResult = calculateA(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back("(" + to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + ")" + op3 + to_string(inpInteger[3]));
                }
            }
        }
    }

    // A o (B o C o D)
    cout << "Kemungkinan 3b \n";
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
                {
                    calResult = calculateD(inpNum, op1, op2, op3);
                    // cout << op1 << op2 << op3 << " " << calResult << "\n";
                }
                else
                {
                    if (op3 == '*' or op3 == '/')
                    {
                        calResult = calculateF(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                    else
                    {
                        calResult = calculateD(inpNum, op1, op2, op3);
                        // cout << op1 << op2 << op3 << " " << calResult << "\n";
                    }
                }

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + "(" + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]) + ")");
                }
            }
        }
    }

    // Kemungkinan 4
    // (A o B) o (C  o D)
    cout << "Kemungkinan 4 \n";
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
                // cout << op1 << op2 << op3 << " " << calResult << "\n";

                if (calResult == 24)
                {
                    count++;
                    result.push_back("(" + to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + ")" + op2 + "(" + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]) + ")");
                }
            }
        }
    }

    // Kemungkinan 5
    // ((A o B) o C) o D
    cout << "Kemungkinan 5a \n";
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
                // cout << op1 << op2 << op3 << " " << calResult << "\n";

                if (calResult == 24)
                {
                    count++;
                    result.push_back("((" + to_string(inpInteger[0]) + op1 + to_string(inpInteger[1]) + ")" + op2 + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]));
                }
            }
        }
    }

    // (A o (B o C)) o D
    cout << "Kemungkinan 5b \n";
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
                // cout << op1 << op2 << op3 << " " << calResult << "\n";

                if (calResult == 24)
                {
                    count++;
                    result.push_back("(" + to_string(inpInteger[0]) + op1 + "(" + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + "))" + op3 + to_string(inpInteger[3]));
                }
            }
        }
    }

    // A o ((B o C) o D)
    cout << "Kemungkinan 5c \n";
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
                // cout << op1 << op2 << op3 << " " << calResult << "\n";

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + "((" + to_string(inpInteger[1]) + op2 + to_string(inpInteger[2]) + ")" + op3 + to_string(inpInteger[3]) + ")");
                }
            }
        }
    }

    // A o (B o (C o D))
    cout << "Kemungkinan 5d \n";
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
                // cout << op1 << op2 << op3 << " " << calResult << "\n";

                if (calResult == 24)
                {
                    count++;
                    result.push_back(to_string(inpInteger[0]) + op1 + "(" + to_string(inpInteger[1]) + op2 + "(" + to_string(inpInteger[2]) + op3 + to_string(inpInteger[3]) + "))");
                }
            }
        }
    }
    duration = clock() - start;

    // Tampilkan hasil
    if (count != 0)
    {
        cout << count << " Solution Found!\n";
        for (auto i = result.begin(); i != result.end(); ++i)
        {
            cout << *i << "\n";
        }
    }
    else
    {
        cout << "No solution found";
    }
    cout << "Execution time : " << duration << " seconds.\n";
    return 0;
}

/* VECTOR
    for (int i = 1; i <= 5; i++)
        g1.push_back(i);

    cout << "Output of begin and end: ";
    for (auto i = g1.begin(); i != g1.end(); ++i)
        cout << *i << " ";
*/

/* Simpan file
int main () {
  ofstream myfile;
  myfile.open ("example.txt");
  myfile << "Writing this to a file.\n";
  myfile.close();
  return 0;
}
*/

/* Time counter
    std::clock_t start;
    double duration;

    start = std::clock(); // get current time

    // Do your stuff here

    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;

    std::cout << "Operation took "<< duration << "seconds" << std::endl;

    return 0;
*/