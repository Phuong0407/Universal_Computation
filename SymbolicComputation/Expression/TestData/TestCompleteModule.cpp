
#include "../ExpressionObject/ExpressionCompleteComputation.h"
// #include "../ExpressionObject/ExpressionDecomposition.h"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    string s = "";
    cout << "Enter expression to compute:"<< endl;
    std::getline(std::cin, s);
    ExpressionCompleteComputation O;
    O.ExpressionComputationCompleteInputAPI(s);
    cout << "     The result is " <<  setprecision(30) << O.ComputeExpression()<<endl;
}