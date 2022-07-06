#include "../ExpressionObject/TreeObjectComputation.h"
using namespace std;
using namespace ExpressionManagement;

int main()
{
    vector<ArgumentPairUnit> a;
    string s = "(x^x)/(x+1-e^x)^2";
    TreeObjectComputation O;
    O.TreeComputationInputAPI(s, true, a);
    cout << O.OutputExpressionValueComputed();
}