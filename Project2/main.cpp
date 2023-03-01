#include <sdl.h> 
using namespace std;
string balancedSums(vector<int> arr) {
    int len = arr.size();
    int sumleft = 0;
    int sumright = 0;
    int res = -1;
    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += arr[i];
    }
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            sumleft += arr[j];
        }

        if (sum - sumleft - arr[i] == sumleft) {
            res = i;
            break;
        }
    }
    if (res != -1) return "YES";
    else return "NO";
}
int main()
{
    vector <int> input;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> input[i];
    cout << balancedSums(input);

}
