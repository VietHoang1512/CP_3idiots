#include<bits/stdc++.h>

using namespace std ;

struct bigNum{
    // sign indicates the quantity of digit in this number
    // sign of sign also indicates the sign of this number
    char sign;

    char num[101]; // knows that num[100]= "\0" aka NULL
};

ostream &operator <<(ostream &out, const bigNum &a){
    out<<((a.sign>0)?1:0);
    int i,j;
    for (i=0;i<100;++i){
        if (a.num[i]!='0') {
            break;
        }
    }
    // i=0;
    for (j=i;j<101;++j){
        out<<a.num[j];
    }

    return out;
}

istream &operator >>(istream &in, bigNum &a){
    string s;
    in >> s;

    a.sign=0;
    int i,j=100, len = s.length()-1;
    for (i=len;i>0;--i){
        a.num[j]=s[i];
        j--;
        a.sign++;
    }

    for (i=j;i>=0;--i){
        a.num[i]='0';
    }

    a.sign = ((s[0]=='1')?a.sign:(-a.sign));

    return in;
}

bigNum long_to_bigNum(long long number){
    bigNum c;
    bool c_sign = true;
    int i;
    if (number<0){
        number = -number;
        c_sign = false;
    }

    for (i=100;i>=0;i--){
        c.num[i] = (number%10) + '0';
        number /=10;
    }
    for (i=0;i<101;++i){
        if (c.num[i]!='0') {
            break;
        }
    }
    c.sign = 101-i;
    if (!c_sign) {
        c.sign = -c.sign;
    }
    return c;
}

bool operator < (bigNum a, bigNum b){
    if (a.sign!= b.sign) {
        return (a.sign<b.sign);
    } else {
        int isSmaller = 0; // 0 indicates equal, 1 indicate smaller, -1 indicates bigger
        int len= 100 - a.sign;
        for (int i=len;i<101;++i){
            if (a.num[i]<b.num[i]) {
                isSmaller = 1;
                break;
            }
            else if (a.num[i]>b.num[i]) {
                isSmaller = -1;
                break;
            }
        }
        if (isSmaller==0) {
            return false;
        } else {
            return (((isSmaller==1)&&(a.sign>0))||((isSmaller==-1)&&(a.sign<0)));
        }
    }
}


bigNum operator + (bigNum a, bigNum b){
    bigNum c; 
    c.sign = 0;
    // cout<<"input\n"<<a<<"\n"<<b<<"\n";
    int memo=0, i, diff_digit, len, temp;
    if (a.sign==0) {
        return b;
    } else if (b.sign==0) {
        return a;
    } else {
        if (a.sign*b.sign>0) { // a and b are on the same side
            len = 100-max(abs(a.sign), abs(b.sign));
            for (i=100;i>len;--i){
                temp = (a.num[i]-'0')+(b.num[i]-'0')+memo;
                memo = temp/10;
                c.num[i] = (temp%10) + '0';
                c.sign++ ;
            }
            if (memo) {
                c.num[i--] = memo + '0';
                c.sign++; 
            }
            c.sign = (a.sign>0)?c.sign:(-c.sign);
        } else {
            bool c_sign=true;
            if (a.sign<0) {
                a.sign = -a.sign;
                if (a<b) {
                    swap(a,b);
                }
                a.sign = -a.sign;
                c_sign = false;
            } else {
                b.sign = -b.sign;
                if (a<b) {
                    swap(a,b);
                    c_sign = false;
                }
                b.sign = -b.sign;
            }
        
            len = 100 - max(abs(a.sign), abs(b.sign));
            for (i=100;i>len;--i) {
                temp = (a.num[i]-'0') - (b.num[i]-'0') - memo;
                memo = (temp<0)?1:0;
                c.num[i] = (temp+10)%10 + '0';
                c.sign++;
            }
            c.sign = (c_sign)?c.sign:(-c.sign);
        }
        while(i>=0){
            c.num[i--]='0';
        }
    }
    return c;
}



bigNum operator - (bigNum a, bigNum b){
    bigNum c;
    b.sign = -b.sign;
    c = a+b;
    b.sign = -b.sign;
    return c;
}

bigNum multiply_digit (bigNum a, int digit){
    bigNum c; 
    int memo=0, first_digit = 100-abs(a.sign), temp;
    c.sign=0;
    int i;
    for (i=100;i>first_digit;--i){
        temp = (a.num[i]-'0')*digit+memo;
        memo = temp/10;
        c.num[i]= (temp%10)+'0';
        c.sign++;
    }

    if (memo){
        c.num[i--]= memo+'0';
        c.sign++;
    }

    while(i>=0){
        c.num[i--]='0';
    }
    return c;
}

bigNum shipNumZero(bigNum a, int numZero){
    bigNum c;
    c.sign = abs(a.sign) + numZero;
    int j =100;
    for (int i=0;i<numZero;++i){
        c.num[j--]= '0';
    }
    int i=100;
    while(j>=0){
        c.num[j--]=a.num[i--];
    }
    return c;
}

bigNum operator * (bigNum a, bigNum b){
    bigNum result = long_to_bigNum(0), temp;
    int numShipZero=0;
    int first_digit = 100-abs(b.sign);
    for (int i=100;i>first_digit;--i){
        temp = shipNumZero(multiply_digit(a,b.num[i]-'0'),numShipZero);
        numShipZero++;
        result = result + temp;
    }

    result.sign = ((a.sign*b.sign)>0)?result.sign:(-result.sign);
    return result;
}

bigNum operator * (bigNum a, long long number){
    bigNum b = long_to_bigNum(number);
    return (a*b);
}

int main(){
    bigNum a, b, c, d, e;
    cin >> a>>b;
    cout<<a*b-a*3+b*4<<"\n";
    return 0;
}