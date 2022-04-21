class MyHashSet {
public:
	static const int BUCKET_SIZE = 256;
	vector<int> bucket[BUCKET_SIZE];

	void add(int key) { 
		if (!contains(key))
			bucket[key%BUCKET_SIZE].push_back(key);
	}

	void remove(int key) {
		vector<int> &curr_bucket = bucket[key%BUCKET_SIZE];
		for (vector<int>::iterator it=curr_bucket.begin(); it!=curr_bucket.end(); it++) {
			if (*it == key) {
                curr_bucket.erase(it);
                break;
            }
        }
	}
    
	bool contains(int key) {
        vector<int> &curr_bucket = bucket[key%BUCKET_SIZE];
        return any_of(curr_bucket.begin(), curr_bucket.end(), [&key](int i){return i == key;});
	}
};