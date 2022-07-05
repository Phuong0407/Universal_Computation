#include "ExpressionTreeStorage.cpp"

using namespace ExpressionManagement;
using namespace std;

int main()
{
    string s = "cos(log(log(log(x-5)*4+3*tanh(x)-abs(c-x))))";
    ExpressionTreeStorage O;
    O.TreeExpressionStorageInputAPI(s);
    O.OutputExpressionTreeInOrderTraversal();
}
