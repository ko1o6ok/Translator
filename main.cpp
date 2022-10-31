
#include "Trans.h"
using namespace std;

int main() {
    Trans t("(3+2)*(5+6)/9");
    cout << t.polish_reverse();
    return 0;
}
