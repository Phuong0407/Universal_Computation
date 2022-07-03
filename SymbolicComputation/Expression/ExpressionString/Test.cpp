#include "ExpressionStringStorage.h"
#include "ExpressionStringStorage.cpp"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    ExpressionStringStorage O;
    O.ExpressionStringStorageInputAPI("A B C ! ! !");
    cout << O.OutputExpressionNoBlank() << endl;
    cout << O.OutputExpressionInitial() << endl;
}