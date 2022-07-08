
#include "../ExpressionObject/ExpressionCompleteComputation.h"
// #include "../ExpressionObject/ExpressionDecomposition.h"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    string s = "log(sin(x-y))";
    ExpressionCompleteComputation O;
    O.ExpressionComputationCompleteInputAPI(s);
    cout << O.ComputeExpression();
}

// int main()
// {
//     string s = "3-log(5*sin(x)-3*cos(4*log(x)-5))";
//     ExpressionDecomposition O;
//     O.ExpressionDecompositionInputAPI(s);
//     CustomTokenUnit a = O.OutputExpressionCustomTokenInfix();
//     for (unsigned int i = 0; i < a.size(); ++i)
//         cout << a[i] << endl;
// }
