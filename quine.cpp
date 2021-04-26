#include <string>
#include <iostream>

using namespace std;

int main() {
    string first_block = R"(
#include <string>
#include <iostream>

using namespace std;

int main() {
)";
    string second_block = R"(
        cout << first_block
                << "    string first_block = R\"(" << first_block << ")\";\n"
                << "    string second_block = R\"(" << second_block << ")\";\n"
                << second_block;
}
)";

        cout << first_block
                << "    string first_block = R\"(" << first_block << ")\";\n"
                << "    string second_block = R\"(" << second_block << ")\";\n"
                << second_block;
}