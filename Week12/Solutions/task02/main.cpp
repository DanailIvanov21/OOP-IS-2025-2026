#include <iostream>
#include "Form.h"
#include "Label.h"
#include "CheckBox.h"
#include "RadioButton.h"

int main() {
    Form f(500, 400, "MainForm");

    Label lbl(100, 20, 10, 10, "Hello");
    CheckBox cb(20, 20, 50, 50, "Accept", false);

    MyString opts[3] = {"Red", "Green", "Blue"};
    RadioButton rb(100, 30, 100, 100, opts, 3, 0);

    f.addControl(lbl);
    f.addControl(cb);
    f.addControl(rb);

    std::cout << "Initial form:\n";
    f.print();

    std::cout << "\nChanging control 1 (CheckBox):\n";
    f.change(1);

    std::cout << "\nMoving control 0 to (200,200):\n";
    f.moveControl(0, 200, 200);

    std::cout << "\nResizing control 2:\n";
    f.resizeControl(2, 150, 40);

    std::cout << "\nFinal form:\n";
    f.print();

    return 0;
}
