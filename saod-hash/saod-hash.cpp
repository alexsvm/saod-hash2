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
public:
	struct data {
		string key;
		string val;
	};

	typedef  data* pdata;

private:
	int _size;
	pdata *table;

	int Hash(const string  &str) {
		int i = 0;
		for (const auto c : str)
			i = i ^ c;
		return i % _size;
	};

	int Next_Index() { // Возвращает следущий ключ

	}

public:

	Hash_Table(int size) : _size(size), table(new pdata[size]) {
		for (int i = 0; i < _size; i++)
			table[i] = nullptr;
	};
	
	~Hash_Table() {
		delete[] table;
	};

	pdata const Get(const string &Key) {
		int _key = Hash(Key);
		pdata _item = table[_key];
		srand(_key);
		while (true) {
			if (_item != nullptr) {
				if (Key == _item->key) {
					return _item;
				} else {
					_key = rand() % _size; // Следующее значение индекса
					_item = table[_key];
				}
			} else return nullptr;
		}
		string k = table[_key]->key;
	};

	int Get_Index(const string &Key) {
		int _key = Hash(Key);
		pdata _item = table[_key];
		srand(_key);
		while (true) {
			if (_item != nullptr) {
				if (Key == _item->key) {
					return _key;
				}
				else {
					_key = rand() % _size; // Следующее значение индекса
					_item = table[_key];
				}
			}
			else return _key;
		}
		string k = table[_key]->key;
	};

	void Set(const string &Key, const string &Value) {
		int idx = Get_Index(Key);
		if (table[idx] != nullptr) {
			table[idx]->val = Value;
		} else {
			table[idx] = new data;
			table[idx]->key = Key;
			table[idx]->val = Value;
		}
	};

	bool Del(const string &Key) {

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



	Hash_Table ht(100);
	ht.Set("asdf", "asdgfhdgsfjhadgsdhg");
	ht.Set("qwert", "qwertyoipojlkdklfksjd");
	ht.Set("zxcv", "zxcvnjhfkdjhfksjdfksjdf");

	Hash_Table::pdata pd = ht.Get("asdf");
	if (pd != nullptr) {
		string s = pd->val;
		cout << "Value found [" << pd->key << "]=" << pd->val << endl;
	}
	else
		cout << "Value not found!" << endl;

	// The end
	cout << endl << "\n\nEnter x to exit...";
	char a;
	do { a = cin.get(); } while (a != 'x');

	return 0;
}

