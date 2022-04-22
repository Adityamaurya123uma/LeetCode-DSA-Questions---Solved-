class MyHashMap {
public:
    vector<int>x;
    // **Initialize your data structure here
    MyHashMap():x(1000001,-1){
        
    }
    
    // ** Values will always be in non-negative
    void put(int key, int value) {
        x[key]=value;
    }
    
    // ** Returns the value to which the specifies keu is mapped, or -1 if this map contians no mapping for the key*/
    int get(int key) {
        return x[key];
    }
    
    
    // ** removes the mapping of the specified value keyif this map contains a mapping for the key */
    void remove(int key) {
        x[key] = -1;
    }
};