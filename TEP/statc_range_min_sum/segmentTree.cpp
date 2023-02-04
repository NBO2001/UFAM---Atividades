#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;
int vet[maxn], tree[4 * maxn];


void build(int node, int childrenLeft, int childrenRight){


    if(childrenLeft == childrenRight){
        tree[node] = vet[childrenLeft];
        return;
    }

    int half = (childrenLeft + childrenRight) / 2;

    build(2*node + 1, childrenLeft, half);
    build(2*node + 2, half + 1, childrenRight);

    tree[node] = min(tree[2*node + 1], tree[2*node + 2]);

}


int query(int node, int rangeStart, int rangeEnd, int childrenLeft, int childrenRight){

    if(rangeStart <= childrenLeft && rangeEnd >= childrenRight)return tree[node];

    if(childrenRight < rangeStart || childrenLeft > rangeEnd) return maxn;

    int mid = (rangeStart + rangeEnd) / 2;
   
    return min(query(2*node + 1, rangeStart, mid, childrenLeft,childrenRight), query(2 * node + 2, mid + 1, rangeEnd, childrenLeft, childrenRight));

}

int main(){

    cin.tie(0);

    int n, qts;

    cin >> n >> qts;

    for(int i=0; i < n; i++){
        cin >> vet[i];
    }

    build(0,0,n-1);

    int a, b;

    for(int i=0; i < qts; i++){
        
        cin >> a >> b;
        cout << query(0,0,n-1, a-1,b-1) << endl;

    }


    
}