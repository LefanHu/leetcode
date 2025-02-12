# Description
Given `n` points on a 2D plane, find the minimum area square that strictly contains at least `k` points on the grid.

The points are given as `vector<int> x` and `vector<int> y`

## Constraints
`0 <= n <= 100`

`0 <= k <= n`

`-1e9 <= x[i], y[i] <= 1e9`

# Approach

Brute force all possible rectangle starting points (`101` possible starting points). Binary search square size from starting point.

# Code
```cpp
// simple counter for points in square
int countPoints(vector<int>& x, vector<int>& y, int sx, int sy, int side_length) {
    int res{};
    for (int i{}; i < x.size(); ++i) {
        res += (x[i] > sx && x[i] < sx + side_length && y[i] > sy && y[i] < sy + side_length);
    }
    return res;
}

long minArea (vector<int>& x, vector<int>& y, int k) {
    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;

    // check max square that contains all points
    for (int i{}; i < x.size(); ++i) {
        minx = min(minx, x[i]);
        maxx = max(maxx, x[i]);
        miny = min(minx, y[i]);
        maxy = max(maxx, y[i]);
    }
    long max_square_side_len = max(maxy - miny, maxx - minx) + 2;
    long ans = max_square_side_len * max_square_side_len;

    // brute force all starting points from point
    for (int i{}; i < x.size(); ++i) {
        int sx = x[i] - 1, sy = y[i] - 1;
        long side_length = max(1e9 - sx, 1e9 - sy) + 2;

        // check if max square from here contains at least k
        int points = countPoint(x, y, sx, sy, side_length);
        if (points < k) continue;

        // binary search
        long l = 3, r = side_length;
        while (l < r) {
            long mid = l + (r - l) / 2;
            if (countPoints(x, y, sx, sy, mid) < k) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        ans = min(ans, l * l);
    }

    return ans;
}
```