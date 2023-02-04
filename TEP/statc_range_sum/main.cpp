#include "bits/stdc++.h"

using namespace std;

int main(){

    cin.tie(0);

    int n, sunTol;

    cin >> n >> sunTol;

    vector<int> array(n);

    for(int &x : array) cin >> x;
    
    vector<int> sums(n);

    sums[0] = array[0];

    for(int i=1; i < n; i++) sums[i] = sums[i-1] + array[i];

    auto soma = [&](int a, int b){
        if(a == 0) return sums[b];
        return sums[b] - sums[a-1];
    };

    int a, b;
    for(int i=0; i < sunTol; i++){
        cin >> a >> b;
        cout << soma(a-1,b-1) << endl;
    }
    
    // 3 2 4 5 1 1 5 3


}

