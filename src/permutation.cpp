// Coba permutasi

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cstdio>
#include <ctime>
using namespace std;

// Inisiasi Variabel
string user[4], inp[4];
float inpNum[4];
int inpInteger[4];
char op[4] = {'+', '-', '*', '/'};
char op1, op2, op3, op4;
bool valInput = false;
int count = 0;
float calResult;
vector<string> result;
vector<float> permInput[4];
clock_t start;
double duration;

// Program Utama
int main()
{
    cin >> user[0] >> user[1] >> user[2] >> user[3];

    // Permutasi Input
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
                        inp[0] = user[i];
                        inp[1] = user[j];
                        inp[2] = user[k];
                        inp[3] = user[6 - i - j - k];
                        count++;

                        for (int l = 0; l < 4; l++)
                        {
                            cout << inp[l] << "\n";
                        }
                        cout << "\n";
                    }
                }
            }
        }
    }
    cout << count << "\n";
}