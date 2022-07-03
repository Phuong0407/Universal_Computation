#include "ExpressionTreeComputation.h"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    std::vector<double> values;
    string expression;
    cin >> expression;
    class ExpressionTreeComputation O;
    O.ComputeExpressionValueInitialization(expression, values, true);
    // cout << O.ComputeExpressionValue(O.OutputArgumentListValue(), O.OutputExpressionTree()) << endl;
    return 0;
}