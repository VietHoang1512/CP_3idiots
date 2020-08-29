#include <iostream>

using namespace std;

int HNTower(int, char, char, char);

int HNTower(int n, char src, char sink, char idle){
    if(n==1){
        cout << "Move a disk form " << src << " to " << sink <<endl;
        return 0;
    }
    else{
        HNTower(n-1, src, idle, sink);
        HNTower(1, src, sink, idle);
        HNTower(n-1, idle, sink, src);
    }
    return 0;
}


int main()
{   int n;
    cout << "N = ";
    cin >> n;
    HNTower(n, 'a', 'b', 'c');
}