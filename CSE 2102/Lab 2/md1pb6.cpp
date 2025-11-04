#include <iostream>
#include <vector>
using namespace std;

int setA[3] = {1,2,3}; 
int setB[3] = {1,4,9}; 


bool proposition(int x, int y) {
    return x*x==y;
}

bool universalUniversal() {
    //  Universal x, Universal y: p(x, y)
    for (int x : setA) {
        for (int y : setB) {
            if (!proposition(x, y)) {
                return false; // If any pair (x, y) fails the proposition, return false
            }
        }
    }
    return true; // All pairs (x, y) satisfy the proposition
}

bool existentialExistential(){
    //Existential x,Existential y:p(x,y)
    for (int x : setA) {
        for (int y : setB) {
            if(proposition(x,y)){
                return true;
            }
        }
        
    }
    return false;
}

bool universalExistential() {
    // Universal x, Existential y: p(x, y)
    for (int i:setA) {
        bool existsY = false;
        for (int j:setB) {
            if (proposition(i, j)) {
                existsY = true;
                break;
            }
        }
        if (!existsY) {
            return false; // If there's an x without any matching y, return false
        }
    }
    return true; // All x have at least one matching y
}

bool existentialUniversal() {
    // Existential x, Universal y: p(x, y)
    for (int j: setB) {
        bool forAllX = true;
        for (int i:setA) {
            if (!proposition(i, j)) {
                forAllX = false;
                break;
            }
        }
        if (forAllX) {
            return true; // There exists at least one x for which p(x, y) holds for all y
        }
    }
    return false; // No x exists for which p(x, y) holds for all y
}

int main() {
    bool result1 = universalExistential();
    bool result2 = existentialUniversal();
    bool result3 = universalUniversal();
    bool result4 = existentialExistential();

    cout << "Universal x, Existential y: p(x, y) is " << (result1 ? "true" : "false") << endl;
    cout << "Existential x, Universal y: p(x, y) is " << (result2 ? "true" : "false") << endl;
    cout << "Universal x, Universal y: p(x, y) is " << (result3 ? "true" : "false") << endl;
    cout << "Existential x, Existential y: p(x, y) is " << (result4 ? "true" : "false") << endl;

    return 0;
}
