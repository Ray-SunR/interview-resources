#include <iostream>
#include <map>
#include <list>

template <typename T1,typename T2>
class Hash_Table
{
private:
	std::map<T1,std::list<T2> > m;
public:
	Hash_Table(){}
	~Hash_Table(){};
	void add(const T1& key,const T2& val);
	void del(const T1& key,const T2& val);
	void modify(const T1& key,const T2& origin,const T2& val);
	std::list<T2> find(const T1& key);
	void print(const T1& key);
};

template <typename T1,typename T2>
void Hash_Table<T1,T2>::modify(const T1& key,const T2& origin,const T2& val)
{
	if (m.find(key) == m.end())
		return;
	for (typename std::list<T2>::iterator i = m[key].begin(); i != m[key].end(); i++)
	{
		if (*i == origin)
			*i = val;
	}
}

template <typename T1,typename T2>
void Hash_Table<T1,T2>::print(const T1& key)
{
	if (m.find(key) == m.end())
		return;
	std::list<T2> l = m[key];
	typename std::list<T2>::iterator i = l.begin();
	std::cout << std::fixed;
	for (;i != l.end(); i++)
		std::cout << *i << "  ";
	std::cout << std::endl;
}


template <typename T1,typename T2>
void Hash_Table<T1,T2>::add(const T1& key,const T2& val)
{
	if (m.find(key) != m.end())
		m[key].push_back(val);
	else
	{
		std::list<T2> l;
		l.push_back(val);
		m[key] = l;
	}
}

template <typename T1,typename T2>
void Hash_Table<T1,T2>::del(const T1& key,const T2& val)
{
	if (m.find(key) != m.end())
		m[key].remove(val);
}

template <typename T1, typename T2>
std::list<T2> Hash_Table<T1,T2>::find(const T1& key)
{
	if (m.find(key) == m.end())
		return false;
	return m[key];
}
