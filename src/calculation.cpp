// TUGAS KECIL 1 STRATEGI ALGORITMA
// Nama : Husnia Munzayana
// NIM  : 13521077

#include <iostream>
#include <iomanip>

// Fungsi kalkulasi sesuai dengan urutan prioritas pengerjaan
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
