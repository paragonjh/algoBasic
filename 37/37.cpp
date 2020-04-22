#include <iostream>
#include <list>
using namespace std;
list<int> a;
int S,N;

int isExistNum(int num)
{
	int index = -1;
	for(list<int>::iterator it = a.begin(); it != a.end(); it++) {
        if(*it == num) {
        	index = distance(a.begin(), it);
        	break;
        }
	}
	return index;
}

void LRU(int num) {
	int index = isExistNum(num);
	if(index == -1) {
		// Not Exist
		if(a.size() >= S)
			a.pop_back();
	} else {
		// Exist
		a.remove(num);
	}
	a.push_front(num);
	
	for (list<int>::iterator it=a.begin(); it!=a.end(); ++it)
    	cout << *it << " ";
	cout << endl;
}

int main() {
	// your code goes here
	cin >> S >> N;

	for(int i = 0; i < N; i++) {
		int num = 0;
		cin >> num;
        LRU(num);
	}

	cout <<"-------------"<<endl;
	for (list<int>::iterator it=a.begin(); it!=a.end(); ++it)
    	cout << *it << " ";
	cout << endl;
	
	//cout << "list:" << isExistNum(1) <<endl;
	return 0;
}
