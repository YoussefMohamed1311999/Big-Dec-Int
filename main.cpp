#include <iostream>
#include <bits/stdc++.h>
#include <string>
#include <iomanip>
#include"BigDec.h"
using namespace std;

int main()
{
    BigDec B1("33333333333333333333333333333333333333");
    BigDec B2("11111111111111111111111111111111111111");
    cout<<B1.getNumber()<<endl;
    cout<<B2.getNumber()<<endl;
    BigDec B3("-33333333333333333333333333333333333333");
    cout<<B3.getNumber()<<endl;

    cout<<"B1 + B2 =";
    B1+B2;
    cout<<"B1 + B3 =";
    B1+B3;
    cout<<endl;

    cout<<"B1-B3 =";
    B1-B3;
    cout<<endl;

    cout<<"B2-B3 =";
    B2-B3;
    cout<<endl;
    cout<<"B1-B2 =";
    B1-B2;
    return 0;
}
