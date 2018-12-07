#include <iostream>

template <class K_Type, class V_Type> class Map {
private:
	struct node {
		node * next;
		K_Type key;
		V_Type val;
		node (const K_Type k) : next(nullptr) {
			this->key = k;
		}
	};
	node * head;
	void clear() {
		while (head) {
			node *t = head->next;
			delete head;
			head = t;
		};
	}
public:
	Map() {
		head = nullptr;
	};
	Map(const Map& m) {
		node *src, **dst;
		head = NULL;
		src = m.head;
		dst = &head;
		try {
			while (src) {
				*dst = new node(*src);
				src = src->next;
				dst = &((*dst)->next);
			}
		} catch (...) {
			this->clear();
			throw;
		};
	};
	~Map() {
		this->clear();
	}
	void add(K_Type key, V_Type value) {
		node * newnode = new node(key);
		newnode->next = head;
		head = newnode;
		head->val = value;
	}
	V_Type * find(K_Type key) {
		node * c = head;
		while (c) {
			if (c->key == key)
				return &c->val;
			c = c->next;
		}
		return nullptr;
	}
	friend std::ostream& operator << (std::ostream& stream, const Map& m) {
		node * c = m.head;
		while (c) {
			stream << "-- Key --" << std::endl << c->key << std::endl;
			stream << "-- Value --" << std::endl << c->val << std::endl;
			c = c->next;
		}
		return stream;
	}
	Map& operator= (const Map& m) {
		if (&m == this)
			return *this;
		Map t(m);
		this->swap(t);
		return *this;
	}
	void swap (Map& m) {
		node *t = head;
		head = m.head;
		m.head = t;
	}
};