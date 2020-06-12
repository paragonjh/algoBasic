#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;

class POS
{
public:
    POS(int _x, int _y): x(_x), y(_y) {};
    int x;
    int y;
};
int calcDistance(POS a, POS b)
{
    return abs(a.x-b.x) + abs(a.y-b.y);
}
vector<POS> house;
vector<POS> pizza;

int main() {
    // your code goes here
    cin >> N >> M;
    int num = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> num;
            if(num == 1)
                house.push_back(POS(j,i));
            else if(num == 2)
                pizza.push_back(POS(j,i));
        }
    }
    //cout << "house cnt:" << house.size() << endl;
    //cout << "pizza cnt:" << pizza.size() << endl;
    vector<int> combination;
    for(int i = 0; i < M; i++)
        combination.push_back(1);
    for(int i = 0; i < pizza.size()-M; i++)
        combination.push_back(0);
    sort(combination.begin(), combination.end());
    //cout << "combi size:" << combination.size() << endl;
    
    int minSum = INT_MAX;
    do
    {
        vector<POS> selectedPizza;
        for(int i = 0; i < combination.size(); i++)
        {
            if(combination[i] == 1)
            {
                selectedPizza.push_back(pizza[i]);
            }
        }
        
        int sum = 0;
        for(int i = 0; i < house.size(); i++)
        {
            int minDis = INT_MAX;
            for(int j = 0; j < selectedPizza.size(); j++)
            {
                int dis    = calcDistance(house[i], selectedPizza[j]);
                minDis = min(minDis, dis);
            }
            sum += minDis;
        }
        minSum = min(minSum, sum);
    }while(next_permutation(combination.begin(), combination.end()));
    
    cout << minSum << endl;
    return 0;
}
