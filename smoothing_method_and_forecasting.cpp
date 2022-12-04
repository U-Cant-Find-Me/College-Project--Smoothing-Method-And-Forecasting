#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <cmath>
#define int long long int
using namespace std;

// class answer
// {
// public:
//     vector<int> Single_Exponential_Smoothing_An_Adaptive_Method()
//     {
//         cout << "Single Exponential Smoothing : An Adaptive Method " << endl;
//         int n;
//         cin >> n;
//         vector<int> v(n);
//         for (int i = 0; i < n; i++)
//             cin >> v[i];
//         float alpha;
//         cin >> alpha;
//         vector<int> s(n);
//         s[0] = v[0];
//         for (int i = 1; i < n; i++)
//             s[i] = alpha * v[i] + (1 - alpha) * s[i - 1];
//         for (int i = 0; i < n; i++)
//             cout << s[i] << " ";
//         return s;
//     }
// };

// signed main()
// {
//     answer a;
//     a.Single_Exponential_Smoothing_An_Adaptive_Method();
//     return 0;
// }

// vector<int> Single_Exponential_Smoothing_An_Adaptive_Method()
// {
//     cout << "Single Exponential Smoothing : An Adaptive Method " << endl;
//     int n;
//     cin >> n;
//     vector<int> v(n);
//     for (int i = 0; i < n; i++)
//         cin >> v[i];
//     float alpha;
//     cin >> alpha;
//     vector<int> s(n);
//     s[0] = v[0];
//     for (int i = 1; i < n; i++)
//         s[i] = alpha * v[i] + (1 - alpha) * s[i - 1];
//     for (int i = 0; i < n; i++)
//         cout << s[i] << " ";
//     return s;
// }

// vector<int> Single_Exponential_Smoothing_An_Adaptive_Method_2()
// {
//     // int n;
//     // cin >> n;
//     // vector<int> v(n);
//     // for (int i = 0; i < n; i++)
//     //     cin >> v[i];
//     // float alpha, beta;
//     // vector<float> E(n), M(n), error(n);
//     // // cin >> alpha;
//     // vector<int> s(n);
//     // for(int i = 0; i < n; i++) {
//     //     if(i == 0) {
//     //         E[i] = v[i];
//     //         M[i] = v[i];
//     //         error[i] = 0;
//     //     }
//     //     else {
//     //         error[i] = (v[i] - s[i]);
//     //         E[i] = beta * v[i] + (1 - alpha) * E[i - 1];
//     //         M[i] = beta * E[i] + (1 - beta) * M[i - 1];
//     //         alpha = alpha + 0.1 * error[i];
//     //         beta = beta + 0.1 * error[i];
//     //     }
//     // }
//     // s[0] = v[0];
//     // for (int i = 1; i < n; i++)
//     //     s[i] = alpha * v[i] + (1 - alpha) * s[i - 1];
//     // for (int i = 0; i < n; i++)
//     //     cout << s[i] << " ";
//     // return s;
// }

//  Single_Exponential_Smoothing Starts Here

void Single_Exponential_Smoothing()
{
}

//  Single_Exponential_Smoothing Ends Here

//  Single_Exponential_Smoothing_An_Adaptive_Method Starts Here

void Single_Exponential_Smoothing_An_Adaptive_Method()
{
}

//  Single_Exponential_Smoothing_An_Adaptive_Method Ends Here

// Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method Starts Here

void solve_Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method(vector<float> x, int n, float alpha = 0.15)
{
    vector<float> smooth1, smooth2, ai, bi, Ft;

    // First Smoothing
    for (int i = 1; i <= n; i++)
    {
        float s1;
        if (i - 1 <= 0)
            s1 = x[i - 1];
        else
        {
            s1 = alpha * x[i - 1] + (1 - alpha) * smooth1[i - 2];
            // cout << smooth1[i - 2] << " " << alphax1 << " " << smo1 << endl;
        }
        // cout << s1 << endl;
        smooth1.push_back(s1);
    }
    // cout << "Printing 1st Smoothing" << endl;
    // for (auto i : smooth1)
    //     cout << i << " ";
    // cout << endl;

    // Second Smoothing
    for (int i = 1; i <= n; i++)
    {
        float s2;
        if (i - 1 <= 0)
            s2 = x[i - 1];
        else
        {
            s2 = alpha * smooth1[i - 1] + (1 - alpha) * smooth2[i - 2];
            // cout << smooth2[i - 2] << " " << alphax2 << " " << smo2 << endl;
        }
        // cout << s2 << endl;
        smooth2.push_back(s2);
    }
    // cout << "Printing 2nd Smoothing" << endl;
    // for (auto i : smooth2)
    //     cout << i << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++)
    {
        float calcA = 2 * smooth1[i - 1] - smooth2[i - 1];
        ai.push_back(calcA);
        float calcB = (smooth1[i - 1] - smooth2[i - 1]) * alpha / (1 - alpha);
        bi.push_back(calcB);
        float calcFt = ai[i - 1] + bi[i - 1] * 1;
        Ft.push_back(calcFt);
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << "\t"
             << "\t" << smooth1[i] << "\t"
             << "\t" << smooth2[i] << "\t"
             << "\t" << ai[i] << "\t"
             << "\t" << bi[i] << "\t"
             << "\t" << Ft[i] << endl;
}

void Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method()
{
    int n;
    cout << "Enter The No of Datasets you have: ";
    cin >> n;
    vector<float> v(n);
    cout << "Enter the data you have followed by space separated " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    float alpha;
    cout << "Enter the alpha value: ";
    cin >> alpha;
    solve_Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method(v, n, alpha);
}

// Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method Ends Here

// Double_Exponential_Smoothing_Holts_Two_Parameter_Method Starts Here

void solve_Double_Exponential_Smoothing_Holts_Two_Parameter_Method(vector<float> x, int n, float alpha = 0.2, float gama = 0.3)
{
    vector<float> smooth1, bi, Ft;

    // Smoothing Part
    for (int i = 1; i <= n; i++)
    {
        float s1 = 0.0, calcB = 0.0;
        if ((i - 1) <= 0)
        {
            s1 = x[i - 1];
            calcB = x[1] - x[0];
        }
        else
        {
            s1 = alpha * x[i - 1] + (1 - alpha) * (smooth1[i - 2] + bi[i - 2]);
            calcB = gama * (s1 - smooth1[i - 2]) + (1 - gama) * bi[i - 2];
            // cout<<fixed<<setprecision(3) << smooth1[i - 2] << " " << s1 << " " << bi[i - 2] << endl;
        }
        // cout << s1 << endl;
        smooth1.push_back(s1);
        bi.push_back(calcB);
    }

    // cout << "Printing 1st Smoothing" << endl;
    // for (auto i : smooth1)
    //     cout << i << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++)
    {
        float calcFt = smooth1[i - 1] + bi[i - 1] * 1;
        Ft.push_back(calcFt);
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << "\t"
             << "\t" << smooth1[i] << "\t"
             << "\t" << bi[i] << "\t"
             << "\t" << Ft[i] << endl;
}

void Double_Exponential_Smoothing_Holts_Two_Parameter_Method()
{
    int n;
    cout << "Enter The No of Datasets you have: ";
    cin >> n;
    vector<float> v(n);
    cout << "Enter the data you have followed by space separated " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    float alpha;
    cout << "Enter the alpha value: ";
    cin >> alpha;
    float gama;
    cout << "Enter the gama value: ";
    cin >> gama;
    solve_Double_Exponential_Smoothing_Holts_Two_Parameter_Method(v, n, alpha, gama);
}

// Double_Exponential_Smoothing_Holts_Two_Parameter_Method Ends Here

// Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method Starts Here

void solve_Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method(vector<float> x, int n, float alpha = 0.15)
{
    vector<float> smooth1, smooth2, smooth3, ai, bi, ci, Ft;

    // First Smoothing
    for (int i = 1; i <= n; i++)
    {
        float s1;
        if (i - 1 <= 0)
            s1 = x[i - 1];
        else
        {
            s1 = alpha * x[i - 1] + (1 - alpha) * smooth1[i - 2];
            // cout << smooth1[i - 2] << " " << alphax1 << " " << smo1 << endl;
        }
        // cout << s1 << endl;
        smooth1.push_back(s1);
    }
    // cout << "Printing 1st Smoothing" << endl;
    // for (auto i : smooth1)
    //     cout << i << " ";
    // cout << endl;

    // Second Smoothing
    for (int i = 1; i <= n; i++)
    {
        float s2;
        if (i - 1 <= 0)
            s2 = x[i - 1];
        else
        {
            s2 = alpha * smooth1[i - 1] + (1 - alpha) * smooth2[i - 2];
            // cout << smooth2[i - 2] << " " << alphax2 << " " << smo2 << endl;
        }
        // cout << s2 << endl;
        smooth2.push_back(s2);
    }
    // cout << "Printing 2nd Smoothing" << endl;
    // for (auto i : smooth2)
    //     cout << i << " ";
    // cout << endl;

    // Third Smoothing
    for (int i = 1; i <= n; i++)
    {
        float s3;
        if (i - 1 <= 0)
            s3 = x[i - 1];
        else
        {
            s3 = alpha * smooth2[i - 1] + (1 - alpha) * smooth3[i - 2];
            // cout << smooth3[i - 2] << " " << alphax3 << " " << smo3 << endl;
        }
        // cout << s3 << endl;
        smooth3.push_back(s3);
    }
    // cout << "Printing 3rd Smoothing" << endl;
    // for (auto i : smooth3)
    //     cout << i << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++)
    {
        float calcA = 3 * smooth1[i - 1] - 3 * smooth2[i - 1] + smooth3[i - 1];
        ai.push_back(calcA);
        float calcB = ((6 - 5 * alpha) * smooth1[i - 1] - (10 - 8 * alpha) * smooth2[i - 1] + (4 - 3 * alpha) * smooth3[i - 1]) * alpha / (2 * pow((1 - alpha), 2));
        bi.push_back(calcB);
        float calcC = (smooth1[i - 1] - 2 * smooth2[i - 1] + smooth3[i - 1]) * pow(alpha, 2) / (pow((1 - alpha), 2));
        ci.push_back(calcC);
        float calcFt = ai[i - 1] + bi[i - 1] * 1 + ci[i - 1] * pow(1, 2) / 2;
        Ft.push_back(calcFt);
    }

    for (int i = 0; i < n; i++)
        cout << x[i] << "\t"
             << "\t" << smooth1[i] << "\t"
             << "\t" << smooth2[i] << "\t"
             << "\t" << smooth3[i] << "\t"
             << "\t" << ai[i] << "\t"
             << "\t" << bi[i] << "\t"
             << "\t" << ci[i] << "\t"
             << "\t" << Ft[i] << endl;

    cout << "Printing Forecasted Data" << endl;

    for (auto i : Ft)
        cout << i << " ";
}

// PLot next time...

void Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method()
{
    int n;
    cout << "Enter The No of Datasets you have: ";
    cin >> n;
    vector<float> v(n);
    cout << "Enter the data you have followed by space separated " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    float alpha;
    cout << "Enter the alpha value: ";
    cin >> alpha;
    cout << "Value of alpha: " << alpha << endl;
    solve_Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method(v, n, alpha);
}

// Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method Ends Here

// Main Function

int32_t main()
{
    cout << fixed << setprecision(4) << endl;
    cout << "Which Method You Want to Use ?\n Please select your Option, " << endl;
    cout << "1. Single Exponential Smoothing" << endl;
    cout << "2. Single Exponential Smoothing: An Adaptive Method" << endl;
    cout << "3. Double Exponential Smoothing: Brown's One-Parameter Linear Method" << endl;
    cout << "4. Double Exponential Smoothing: Holt's Two-Parameter Method" << endl;
    cout << "5. Triple Exponential Smoothing: Brown's One-Parameter Quadratic Method" << endl;
    // cout << "6. Triple Exponential Smoothing: Three-Parameter Trend and Seasonality Method" << endl;
    // cout << "7. Exponential Smoothing: Pegels' Classification" << endl;

    int expression;
    cout << "Enter Your Choice ";
    cin >> expression;

    switch (expression)
    {
    case 1:
        Single_Exponential_Smoothing();
        break;

    case 2:
        Single_Exponential_Smoothing_An_Adaptive_Method();
        break;

    case 3:
        Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method();
        break;

    case 4:
        Double_Exponential_Smoothing_Holts_Two_Parameter_Method();
        break;

    case 5:
        Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method();
        break;

    default:
        cout << "Please Select Correct Option" << endl;
        break;
    }
}

/*
    IEE 14 Bus System (Given Data)
    Bus No 12
    0.0264 0.0259 0.0251 0.0243 0.0246 0.0271 0.0301 0.0355 0.0397 0.0414 0.0418 0.0414 0.0389 0.0384 0.0376 0.0368 0.0376 0.0385 0.0401 0.0410 0.0401 0.0376 0.0334 0.0293

    0.0069 0.0068 0.0066 0.0064 0.0065 0.0071 0.0079 0.0093 0.0104 0.0108 0.0110 0.0108 0.0102 0.0101 0.0099 0.0096 0.0099 0.0101 0.0105 0.0108 0.0105 0.0099 0.0088 0.0077

    Forecasted Data
    0.0264 0.0262 0.0257 0.0249 0.0246 0.0255 0.0275 0.0313 0.0359 0.0398 0.0425 0.0441 0.0438 0.0432 0.0422 0.0410 0.0403 0.0402 0.0407 0.0414 0.0414 0.0401 0.0373 0.0335

    0.0069 0.0069 0.0067 0.0066 0.0065 0.0067 0.0072 0.0082 0.0094 0.0104 0.0111 0.0115 0.0115 0.0113 0.0111 0.0107 0.0106 0.0105 0.0107 0.0109 0.0109 0.0105 0.0098 0.0088

    Bus No 09
    1.0582 1.0585 1.0601 1.0606 1.0603 1.0577 1.0542 1.0456 1.0377 1.0365 1.0362 1.0365 1.0423 1.0426 1.0441 1.0447 1.0441 1.0425 1.0374 1.0368 1.0374 1.0441 1.0470 1.0547

    -0.1118 -0.1100 -0.1067 -0.1033 -0.1049 -0.1151 -0.1271 -0.1509 -0.1698 -0.1770 -0.1789 -0.1770 -0.1653 -0.1634 -0.1602 -0.1564 -0.1602 -0.1637 -0.1716 -0.1754 -0.1716 -0.1602 -0.1419 -0.1237

    Forecasted Data
    1.0582 1.0583 1.0591 1.0599 1.0603 1.0594 1.0572 1.0517 1.0444 1.0388 1.0350 1.0327 1.0340 1.0354 1.0373 1.0392 1.0404 1.0406 1.0386 1.0370 1.0363 1.0389 1.0422 1.0480

    -0.1118 -0.1110 -0.1089 -0.1060 -0.1047 -0.1084 -0.1166 -0.1330 -0.1529 -0.1698 -0.1818 -0.1886 -0.1871 -0.1843 -0.1800 -0.1745 -0.1718 -0.1710 -0.1735 -0.1767 -0.1769 -0.1715 -0.1591 -0.1421

    Bus No 30
    0.0458 0.0451 0.0436 0.0422 0.0428 0.0472 0.0523 0.0617 0.0690 0.0719 0.0726 0.0719 0.0675 0.0668 0.0654 0.0639 0.0654 0.0669 0.0697 0.0712 0.0697 0.0654 0.0581 0.0509

    0.0082 0.0081 0.0078 0.0076 0.0077 0.0085 0.0094 0.0111 0.0124 0.0129 0.0130 0.0129 0.0121 0.0120 0.0117 0.0115 0.0117 0.0120 0.0125 0.0128 0.0125 0.0117 0.0104 0.0091

    Forecasted Data // alpha = 0.25
    0.0458 0.0453 0.0439 0.0422 0.0418 0.0451 0.0507 0.0605 0.0707 0.0773 0.0801 0.0799 0.0754 0.0717 0.0682 0.0649 0.0643 0.0651 0.0677 0.0701 0.0702 0.0668 0.0596 0.0506

    0.0082 0.0081 0.0079 0.0076 0.0075 0.0081 0.0091 0.0109 0.0127 0.0139 0.0144 0.0143 0.0135 0.0129 0.0122 0.0117 0.0115 0.0117 0.0121 0.0126 0.0126 0.0120 0.0107 0.0090

    Bus No 21
    1.0280 1.0284 1.0292 1.0299 1.0296 1.0272 1.0243 1.0155 1.0063 1.0045 1.0040 1.0045 1.0072 1.0076 1.0084 1.0093 1.0084 1.0075 1.0058 1.0049 1.0058 1.0084 1.0177 1.0251

    -0.1186 -0.1165 -0.1124 -0.1085 -0.1102 -0.1224 -0.1367 -0.1626 -0.1838 -0.1922 -0.1944 -0.1922 -0.1796 -0.1775 -0.1735 -0.1692 -0.1735 -0.1777 -0.1860 -0.1903 -0.1860 -0.1735 -0.1523 -0.1329 

    Forecasted Data
    1.0280 1.0282 1.0287 1.0293 1.0296 1.0287 1.0268 1.0215 1.0136 1.0074 1.0031 1.0005 1.0003 1.0007 1.0016 1.0030 1.0037 1.0041 1.0038 1.0033 1.0035 1.0049 1.0103 1.0174

    -0.1186 -0.1177 -0.1151 -0.1117 -0.1100 -0.1145 -0.1241 -0.1426 -0.1649 -0.1840 -0.1976 -0.2053 -0.2039 -0.2009 -0.1960 -0.1898 -0.1867 -0.1859 -0.1886 -0.1920 -0.1921 -0.1861 -0.1720 -0.1531
*/
