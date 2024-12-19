#include <iostream>
#include<fstream>
using namespace std;

class Time{
    public:
        int hour;
        int min;
        Time() : hour(0), min(0) {};
        Time(int h,int m){
            hour = h;
            min = m;
        }
        Time operator++(int){
            Time res;
            int h = hour * 60;
            int m = min;
            int total = h + m + 1;
            res.hour = total / 60;
            res.min = total % 60;
            return res;
        }
        void display(){
            cout << "HH = " << hour << "::" << min << "\n";
        }
};
int main()
{
    // int n;
    // cin >> n;
    // float arr[n];
    // for (int i = 0; i < n;i++){
    //     cin >> arr[i];
    //     arr[i] *= 0.1;
    // }
    // fstream fout("sample1.txt", ios::out | ios::binary);
    // fout.write(reinterpret_cast<char *>(arr), n);
    // fout.close();
    // cout << "Reading\n";
    // fstream fin("sample1.txt", ios::in | ios::binary);
    // fin.read(reinterpret_cast<char *>(arr), n);
    // fin.close();
    // for (int i = 0; i < n;i++){
    //     cout << arr[i] << " ";
    // }
    int h, m;
    cin >> h >> m;
    Time t(h, m);
    t = t++;
    t.display();
    return 0;
}