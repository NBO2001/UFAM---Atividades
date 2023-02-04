#include "bits/stdc++.h"

using namespace std;

const int maxn = 1e5 + 10;
int vet[maxn], tree[4 * maxn];

void build(int node, int l, int r){

    if(l == r){
        tree[node] = vet[l];
        return;
    }

    // Meio
    int mid = (l + r)/2;

    build(2 * node + 1, l, mid);
    build(2 * node + 2, mid+1, r);

    tree[node] = min(tree[2 * node + 1],tree[2 * node + 2]);

}

void update(int node, int tl, int tr, int idx, int v){

    if(tl == tr){
        tree[node] = v;
        return;
    }

    int mid = (tl + tr) / 2;

    if(tl <= idx && idx <= mid) update(2 * node +1, tl, mid, idx,v);
    else update(2* node +2, mid + 1, tr, idx,v);

    tree[node] = tree[2 * node + 1] + tree[ 2 * node + 2];

}

int query(int node, int tl, int tr, int l, int r){

    if(r < tl || l > tr) return maxn;

    if(l <= tl && r >= tr) return tree[node];

    int mid = (tl + tr) / 2;

    return min(query(2*node + 1, tl, mid, l,r), query(2 * node + 2, mid + 1, tr, l, r));
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

