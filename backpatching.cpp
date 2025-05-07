#include <iostream>
#include <vector>

using namespace std;

class Backpatch {
public:
    vector<int*> locs;
    void add(int* loc) { locs.push_back(loc); }
    void patch(int val) { for (auto loc : locs) *loc = val; }
};

int main() {
    int x = 0, y = 0;
    Backpatch bp;

    bp.add(&x);
    bp.add(&y);

    cout << "Before patching: " << x << " " << y << endl;

    bp.patch(42);

    cout << "After patching: " << x << " " << y << endl;

    return 0;
}
