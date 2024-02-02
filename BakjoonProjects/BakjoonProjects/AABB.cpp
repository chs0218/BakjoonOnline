#include <iostream>

struct Rectangle {
    int left;
    int bottom;
    int right;
    int top;
};

bool CheckCollision(const Rectangle& rect1, const Rectangle& rect2) {
    if (rect1.right < rect2.left) return false;
    if (rect1.left < rect2.right) return false;
    if (rect1.top < rect2.bottom) return false;
    if (rect1.bottom < rect2.top) return false;
    return true;
}

int main() {
    Rectangle rectangle1 = { 0, 0, 3, 3 };
    Rectangle rectangle2 = { 4, 4, 7, 7 };

    if (CheckCollision(rectangle1, rectangle2)) {
        cout << "Collide" << endl;
    }
    else {
        cout << "Not Collide" << endl;
    }
    return 0;
}