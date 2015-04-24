#include <iostream>

class HashException
{
private:
	std::string info;
public:
	HashException(std::string info = "Hash Exception"):info(info){}
	~HashException(){}
	std::string what(){return info;}
};

//T is the type of the element in the hash table, k represents the key
//Key -> Val
template <typename K, typename V>
class Hash
{
private:
	int divisor;
	V* hash_table;
	bool* empty;
	int hSearch(const K& k) const;
public:
	Hash(int divisor):divisor(divisor), hash_table(new V[divisor]), empty(new bool[divisor]){ for(int i = 0; i < divisor; i++) empty[i] = true;}
	~Hash(){delete [] hash_table;}
	bool Search(const K& k, V& v) const;
	Hash<K, V>& insert(const V& v);
};

//return the number of bucket in the hash table
template <typename K, typename V>
int Hash<K, V>::hSearch(const K& k) const
{
	int begin = k % divisor;
	int iterator = k % divisor;
	do
	{
		if (empty[iterator] || hash_table[iterator] == k) return iterator;
		iterator = (iterator + 1) % divisor;
	}
	while (begin != iterator);//used to determine if the element exists in the table
	return iterator;//if begin == iterator which means the key does not exist in the hash_table and the table is full
}

//v is used to store the found value of key k.
template <typename K, typename V>
bool Hash<K, V>::Search(const K& k, V& v) const
{
	int pos = hSearch(k);
	if (empty[pos] || hash_table[pos] != k) return false;//if empty[pos] is true, then the key does not exist, otherwise the table is full.
	v = hash_table[pos];
	return true;
}

//Insert a value
template <typename K, typename V>
Hash<K, V>& Hash<K, V>::insert(const V& v)
{
	K k = v;
	int b = hSearch(k);
	if (empty[b])
	{
		empty[b] = false;
		hash_table[b] = v;
		return *this;
	}
	//else false, then check if there is any duplicate numbers  or the table is full.
	if (hash_table[b] == k)
		throw HashException("Duplicate input!");
	else
		throw HashException("Table is full!");
}

