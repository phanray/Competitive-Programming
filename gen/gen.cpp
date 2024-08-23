#include <bits/stdc++.h>
using namespace std;
// Tên chương trình
const string NAME = "template";
// Số test kiểm tra
const int NTEST = 100;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int Rand(int l,int r) {

    if (l > r) {

        cout << "Error l>r\n";
        assert(l>r);
    }

    return l + abs((int)rng() % (r - l + 1));

}
int main()
{
    srand(time(NULL));
    for (int iTest = 1; iTest <= NTEST; iTest++)
    {
        ofstream inp(("test.inp").c_str());
        // Code phần sinh test ở đây
        inp.close();
        // Nếu dùng Linux thì "./" + Tên chương trình
        system(("A.exe").c_str());
        system((NAME + "_trau.exe").c_str());
        // Nếu dùng linux thì thay fc bằng diff
        if (system(("fc " + NAME + ".out " + NAME + ".ans").c_str()) != 0)
        {
            cout << "Test " << iTest << ": WRONG!\n";
            return 0;
        }
        cout << "Test " << iTest << ": CORRECT!\n";
    }
    return 0;
}