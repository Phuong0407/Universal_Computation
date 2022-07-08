#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

void VectorReplacer(vector<string> &InfixToReplace, std::string NameToCheck, vector<string> InfixReplacer)
{
    unsigned int Index = 0;
    vector<string> Output;
    do
    {
        if (InfixToReplace[Index] == NameToCheck)
        {
            InfixToReplace.insert(InfixToReplace.begin() + Index, InfixReplacer.begin(), InfixReplacer.end());
            Index += InfixReplacer.size();
            InfixToReplace.erase(InfixToReplace.begin() + Index);
        }
        else
            Index++;
    } while (Index < InfixToReplace.size());
}

int main()
{
    vector<string> s, v, a;
    s.push_back("adfs");
    s.push_back("aswqe");
    s.push_back("dqwr");
    s.push_back("adfs");
    s.push_back("aswqe_q");
    s.push_back("asdqweqe_Q");
    s.push_back("adfs");
    s.push_back("12.3434");
    s.push_back("eee324324");
    s.push_back("23/324324234");
    s.push_back("adfs");
    v.push_back("anh");
    v.push_back("adfs");
    v.push_back("nguyen");

    VectorReplacer(s, "adf", v);
    for (unsigned int i = 0; i < s.size(); ++i)
        cout << s[i] << endl;
}