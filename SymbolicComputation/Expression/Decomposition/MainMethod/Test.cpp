#include "DecompositionToInfix.cpp"

using namespace std;
using namespace ExpressionManagement;

int main()
{
    // string s;
    // cin >> s;
    DecompositionToInfix O;
    O.DecompositionToInfixInputAPI("s * d * df - df");
    cout << O.InfixExpressionCustomToken.size();
    // for (unsigned int i = 0; i < O.DecompositionToInfixOutputAPI().size(); i++)
    //     cout << O.DecompositionToInfixOutputAPI()[i] << endl;
}