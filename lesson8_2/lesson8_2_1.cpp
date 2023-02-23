#include <iostream>

using namespace std;

float divide(float);

int main() {
    try {
        cout << divide(1.024);
        cout << divide(0);
    }
    catch(const invalid_argument& e) {
        cout << e.what() << '\n';
    }
    
    return 0;
}

float divide(float i) {
    if (i == 0)
        throw invalid_argument("\nMust be non zero");
    else
        i/= 1024;
    
    return i;
}