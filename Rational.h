#pragma once

#include<iostream>
#include<string>
#include<math.h>
#include<sstream>

using namespace std;

int NOD(int A, int B) {
    while (A != B)
        if (A > B) A -= B;
        else B -= A;
    return A;
}

struct Rational {
    int r;
    int q;

    Rational();
    Rational(int, int);
    void simplify() {
        int nod = NOD(this->r, this->q);
        this->r /= nod;
        this->q /= nod;
    }
    friend istream& operator>>(istream& in,Rational& rat){
        cout<<"Input r: ";
        in>>rat.r;
        cout<<"Input q: ";
        in>>rat.q;
        return in;
    }
    friend ostream& operator<<(ostream& out, Rational& rat) {
        rat.simplify();
        if(rat.q==1){
            out << rat.r<<endl;
        }
        else {
            out << rat.r << "/" << rat.q << endl;
        }
        return out;
    }
    void operator+=(Rational& a){
        this->simplify();
        a.simplify();
        this->r=this->r*a.q+this->q*a.r;
        this->q=this->q*a.q;
        this->simplify();
    }
    void operator-=(Rational& a){
        this->simplify();
        a.simplify();
        this->r=this->r*a.q-this->q*a.r;
        this->q=this->q*a.q;
        this->simplify();
    }
    void operator+=(int a){
        this->simplify();
        Rational current(a,1);
        this->r=this->r*current.q+this->q*current.r;
        this->q=this->q*current.q;
        this->simplify();
    }
    void operator-=(int a){
        this->simplify();
        Rational current(a,1);
        this->r=this->r*current.q-this->q*current.r;
        this->q=this->q*current.q;
        this->simplify();
    }
    void operator*=(Rational& a){
        this->simplify();
        a.simplify();
        this->r=this->r*a.r;
        this->q=this->q*a.q;
        this->simplify();
    }
    void operator/=(Rational& a){
        this->simplify();
        a.simplify();
        this->r=this->r*a.q;
        this->q=this->q*a.r;
        this->simplify();
    }
    void operator*=(int a){
        this->simplify();
        this->r=this->r*a;
        this->simplify();
    }
    void operator/=(int a){
        this->simplify();
        Rational current(a,1);
        this->r=this->r*current.q;
        this->q=this->q*current.r;
        this->simplify();
    }
};

Rational::Rational() {
    r = 0;
    q = 1;
}

Rational::Rational(int a, int b) {
    r = a;
    q = b;
}

Rational operator+(Rational &a, Rational &b) {
    a.simplify();
    b.simplify();
    Rational neo(a.r * b.q + b.r * a.q, a.q * b.q);
    neo.simplify();
    return neo;
}
Rational operator-(Rational &a, Rational &b) {
    a.simplify();
    b.simplify();
    Rational neo(a.r * b.q - b.r * a.q, a.q * b.q);
    neo.simplify();
    return neo;
}
Rational operator+(Rational& a, int b){
    Rational current(b,1);
    return current+a;
}
Rational operator-(Rational& a, int b){
    Rational current(b,1);
    return current-a;
}
Rational operator*(Rational& a,Rational& b){
    a.simplify();
    b.simplify();
    Rational neo(a.r*b.r,a.q*b.q);
    neo.simplify();
    return neo;
}
Rational operator*(Rational& a,int b){
    Rational current(b,1);
    return a*b;
}
Rational operator/(Rational& a,Rational& b){
    a.simplify();
    b.simplify();
    Rational neo(a.r*b.q,a.q*b.r);
    neo.simplify();
    return neo;
}
Rational operator/(Rational& a,int b){
    Rational current(b,1);
    return a/b;
}
