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

void solve_Double_Exponential_Smoothing_Browns_One_Parameter_Linear_Method(vector<int> x, int n, float alpha = 0.15)
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
    vector<int> v(n);
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

void solve_Double_Exponential_Smoothing_Holts_Two_Parameter_Method(vector<int> x, int n, float alpha = 0.2, float gama = 0.3)
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
    vector<int> v(n);
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

void solve_Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method(vector<int> x, int n, float alpha = 0.15)
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
}

void Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method()
{
    int n;
    cout << "Enter The No of Datasets you have: ";
    cin >> n;
    vector<int> v(n);
    cout << "Enter the data you have followed by space separated " << endl;
    for (int i = 0; i < n; i++)
        cin >> v[i];
    float alpha;
    cout << "Enter the alpha value: ";
    cin >> alpha;
    solve_Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method(v, n, alpha);
}

// Triple_Exponential_Smoothing_Browns_One_Parameter_Quadratic_Method Ends Here

// Main Function

int32_t main()
{
    cout << fixed << setprecision(3) << endl;
    cout << "Which Method You Want to Use ?\n Please select your Option, " << endl;
    cout << "1. Single Exponential Smoothing" << endl;
    cout << "2. Single Exponential Smoothing: An Adaptive Method" << endl;
    cout << "3. Double Exponential Smoothing: Brown's One-Parameter Linear Method" << endl;
    cout << "4. Double Exponential Smoothing: Holt's Two-Parameter Method" << endl;
    cout << "5. Triple Exponential Smoothing: Brown's One-Parameter Quadratic Method" << endl;
    cout << "6. Triple Exponential Smoothing: Three-Parameter Trend and Seasonality Method" << endl;
    cout << "7. Exponential Smoothing: Pegels' Classification" << endl;

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
