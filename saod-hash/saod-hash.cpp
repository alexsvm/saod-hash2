#include <iostream>
#include <sstream>

using namespace std;

using HashIndexType = unsigned char;

HashIndexType Hash4(const string  &str) {
	unsigned char h = 0;
	for (const auto c : str)
		h = h ^ c;
	return h;
}

class Hash_Table {
private:
	int _size;
	struct data {
		string key;
		string data;
	};

	data *table;

	int Hash(const string  &str) {
		int i = 0;
		for (const auto c : str)
			i = i ^ c;
		return i;
	};

public:
	Hash_Table(int size) : _size(size), table(new data[size]) {
		
	};

	~Hash_Table() {
		delete[] table;
	};

	data* const Get(const string &Key) {
		int _key = Hash(Key);

	};

	void Set(const string &Key, const string &Value) {

	};

};



int main()
{
	string s1 = "Alpha";
	string s2 = "Beta";
	string s3 = "Gamma";
	cout << "s=" << s1 << ", hash=" << Hash4(s1) << endl;
	cout << "s=" << s2 << ", hash=" << Hash4(s2) << endl;
	cout << "s=" << s3 << ", hash=" << Hash4(s3) << endl;



	// The end
	cout << endl << "\n\nEnter x to exit...";
	char a;
	do { a = cin.get(); } while (a != 'x');

	return 0;
}

