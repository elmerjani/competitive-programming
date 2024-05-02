#include <bits/stdc++.h>
using namespace std;


struct Point {
    double x, y;
    Point(double _x, double _y) : x(_x), y(_y) {}
};

Point rotate_point(double x, double y, double cx, double cy, double angle) {
    double angle_rad = angle * (M_PI / 180.0);
    double x_new = (x - cx) * cos(angle_rad) - (y - cy) * sin(angle_rad) + cx;
    double y_new = (x - cx) * sin(angle_rad) + (y - cy) * cos(angle_rad) + cy;
    return Point(x_new, y_new);
}

pair<double, double> min_enclosing_rectangle(const vector<vector<double>>& rectangles,double &maxwidth,double &maxheight) {
    double leftmost = numeric_limits<double>::infinity();
    double rightmost = -numeric_limits<double>::infinity();
    double topmost = -numeric_limits<double>::infinity();
    double bottommost = numeric_limits<double>::infinity();

    

    for (const auto& rectangle : rectangles) {
        double x = rectangle[0];
        double y = rectangle[1];
        double w = rectangle[2];
        double h = rectangle[3];
        double angle = rectangle[4];

        

        Point corners[4] = {
            rotate_point(x - w/2, y - h/2, x, y, angle),
            rotate_point(x + w/2, y - h/2, x, y, angle),
            rotate_point(x - w/2, y + h/2, x, y, angle),
            rotate_point(x + w/2, y + h/2, x, y, angle)
        };

        for (const auto& corner : corners) {
            leftmost = min(leftmost, corner.x);
            rightmost = max(rightmost, corner.x);
            topmost = max(topmost, corner.y);
            bottommost = min(bottommost, corner.y);
        }
    }

    double center_x = (leftmost + rightmost) / 2;
    double center_y = (topmost + bottommost) / 2;
    maxwidth = rightmost - leftmost ;
    maxheight = topmost - bottommost;

    return make_pair(center_x, center_y);
}

int main() {
    int n;
    cin >> n;

    vector<vector<double>> rectangles(n, vector<double>(5));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 5; ++j) {
            cin >> rectangles[i][j];
        }
    }
    double maxwidth=0,maxheight=0;
    pair<double, double> center = min_enclosing_rectangle(rectangles,maxwidth,maxheight);
    cout << center.first << " " << center.second << " ";
    cout << maxwidth<< " " << maxheight<< endl;

    return 0;
}
