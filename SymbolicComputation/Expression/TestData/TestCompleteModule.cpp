
#include "../ExpressionObject/ExpressionCompleteComputation.h"
// #include "../ExpressionObject/ExpressionDecomposition.h"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    string s = "((sin(y)-cos(y))/(1+y^2))^3-5";
    ExpressionCompleteComputation O;
    O.ExpressionComputationCompleteInputAPI(s);
    cout << O.ComputeExpression();
}