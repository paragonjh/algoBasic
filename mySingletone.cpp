#include <iostream>
#include <mutex>
using namespace std;

class Singletone
{
public:
	Singletone(void){}
	~Singletone(void){ 
		std::lock_guard<std::mutex> lock(_getInstanceMutex);
		_instance = nullptr; 
	}
	static Singletone* GetInstance(void)
	{
		std::lock_guard<std::mutex> lock(_getInstanceMutex);
		if(_instance == nullptr)
			_instance = new Singletone;
		return _instance;
	}
	
private:
	static Singletone* _instance;
	static std::mutex _getInstanceMutex;
};

Singletone* Singletone::_instance = nullptr;
std::mutex Singletone::_getInstanceMutex;

int main() {
	// your code goes here
	Singletone *instance = Singletone::GetInstance();
	delete instance;
	return 0;
}
