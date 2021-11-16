/* Your code here! */
#include "dsets.h"
#include <iostream>
#include <vector>

using namespace std;

void DisjointSets::addelements(int num) {
    for(int i = 0; i < num; i++) {
        vec.push_back(-1);
    }
}

int DisjointSets::find(int elem) {
    if(vec[elem] < 0) {
        return elem;
    }
    int temp = find(vec[elem]);
    vec[elem] = temp;
    return temp;
}

void DisjointSets::setunion(int a, int b) {
    int i_a = find(a);
    int i_b = find(b);
    if(i_a==i_b){
        return;
    }
    int summ = vec[i_a] + vec[i_b];
    if(vec[i_a] > vec[i_b]) {
        vec[i_a] = i_b;
        vec[i_b] = summ;
    } else {
        vec[i_b] = i_a;
        vec[i_a] = summ;
    }
}

int DisjointSets::size(int elem) {
    while(elem >= 0) {
        elem = vec[elem];
    }
    return -elem;
}
