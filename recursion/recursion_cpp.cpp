#include <iostream>
#include<string>
using namespace std;

string B();
string C();
string A()
{
        return "A" + B();
}
string B()
{
        return "B" + C();
}
string C()
{
        return "C";
}
string reversal(string s)
{
        if (s.empty())
        {
            return "";
        }
        string res = "";
        res += reversal(s.substr(1)) + s[0];
        return res;
}
bool checkPalindrome(string pal){
        if(pal.size() == 0){
                return true;
        }
        if(pal[0] == pal[pal.size()-1]){
                return checkPalindrome(pal.substr(1, pal.size() - 2));
        }
        else{
                return false;
        }
}
int decimalToBinary(int d){
        if(d == 0){
                return 0;
        }
        string res = "";
        res = to_string(decimalToBinary(d / 2)) + to_string(d % 2);
        return stoi(res);
}
int sumN(int n){
        if(n == 1){
                return 1;
        }
        return n + sumN(n - 1);
}
int main()
{
        string ss = "pranjal";
        // getline(cin, ss);
        // for (int i = 0; i < ss.size();i++){
        //         ss[i] = tolower(ss[i]);
        //         cout << ss[i] << " ";
        // }
        // bool res = checkPalindrome(ss);
        // cout << res << endl;
        // ;
        // cout << res;
        cout << sumN(10) << endl;
}
