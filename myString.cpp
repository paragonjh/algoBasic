#include <iostream>
#include <cstring>
using namespace std;

class myString
{
private:
    char* str = NULL;
    int strSize = 0;
	
public:
	myString()
	{
		strSize = 0;
		str = NULL;
	}

    myString(char* _str)
    {
    	if(_str == NULL)
    	    return;
    	if(str != NULL)
    	{
    		delete []str;
    		strSize = 0;
    	}
    	int _size = strlen(_str);
    	str = new char[_size+1];
    	strSize = _size;
    	strncpy(str, _str, strSize);
    	str[strSize] = '\0';
    }
    myString(myString& s)
    {
    	strSize = s.size();
    	str = new char[strSize];
    	strcpy(str, s.c_str());
    }

    ~myString()
    {
    	if(str != NULL) {
    		delete []str;
    		str = NULL;
    		strSize = 0;
    	}
    }
	char* c_str(void) {
		return str;
	}
	
	int size(void) {
		return strSize;
	}
	// 대입 연산자
	myString& operator= (myString& s)
	{
		if(str != NULL) {
			delete []str;
			strSize = 0;
		}
		strSize = s.size();
		str = new char[strSize];
		strcpy(str, s.c_str());
		return *this;
	}

	// + 연산자
	myString operator+ (myString& s)
	{
		char* tmpStr = new char[strSize+s.size()];
		strcpy(tmpStr,str);
		strcat(tmpStr,s.c_str());
		myString returnStr(tmpStr);
		delete []tmpStr;
		return returnStr;
	}
	
	// += 연산자
	myString& operator+= (myString& s)
	{
		strSize += s.size();
		char* tempStr = new char[strSize];
		strcpy(tempStr, str);
		strcat(tempStr, s.c_str());
		
		delete []str;
		str = tempStr;
		return *this;
	}
	
	//비교 연산자
	bool operator== (myString& s)
	{
		return strcmp(s.c_str(), str) == 0 ? true : false;
	}
};

int main() {
	// myString Class Create Test
	char text[] = "hello world";
	myString m_string(text);
	cout << m_string.size() << endl;
	cout << m_string.c_str() << endl;

    // "bool operator==" test
	myString m_string2(text);
	if(m_string == m_string2)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	// 복사 생성자 테스트
	myString m_string3(m_string);
	cout << m_string3.c_str() << endl;
	myString m_string4 = m_string;
	cout << m_string4.c_str() << endl;
	
	//대입 연산자, + 연산자 테스트
	//myString m_string5 = m_string + m_string2;
	//cout << m_string5.c_str() << endl;
	m_string += m_string2;
	cout << m_string.c_str()  << endl;
	return 0;
}
