#include <vector>
using namespace std;

int quick_select(vector<int>& v, int k) {
        vector<int> low, mid, high;

        int piv = v[v.size() / 2];
        for (auto& n : v) {
            if (n < piv) {
                low.push_back(n);
            } else if (n > piv) {
                high.push_back(n);
            } else {
                mid.push_back(n);
            }
        }

        // divide & conquer
        if (k <= high.size()) {
            return quick_select(high, k);
        } else if (k <= high.size() + mid.size()) {
            return piv;
        } else {
            return quick_select(low, k - high.size() - mid.size());
        }
    }