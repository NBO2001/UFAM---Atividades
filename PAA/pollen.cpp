#include <bits/stdc++.h>

using namespace std;

int sumDigs(int num){

    int sum = 0;

    while (num)
    {
        sum += num%10;
        num = num/10;
    }

    return sum;
    

}

int main(){


    vector<int> v1;
    
    int flores_tam, ger_position;

    cin >> flores_tam >> ger_position;
    
    int tmp;
    for(int i=0; i < flores_tam; i++){
        cin >> tmp;
        v1.push_back(tmp);
    }

    make_heap(v1.begin(), v1.end());


    for(int i=1; i < ger_position; i++){
        pop_heap(v1.begin(), v1.end());

        tmp = v1.back();
        
        tmp -= sumDigs(tmp);
        v1.pop_back(); 
        v1.push_back(tmp);
        push_heap(v1.begin(), v1.end()); 

    }
    
    pop_heap(v1.begin(), v1.end());

    cout << sumDigs(v1.back()) << "\n";


}