#include "../ExpressionObject/TreeComputation.h"
using namespace std;
using namespace ExpressionManagement;

int main()
{
    vector<ArgumentPairUnit> a;
    string s = "(x^x)/(x+1-e^x)^2";
    TreeComputation O;
    O.TreeComputationInputAPI(s, true, a);
    cout << O.OutputExpressionValueComputed();
}