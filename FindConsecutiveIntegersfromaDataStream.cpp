class DataStream {
    int count;
    int value;
    int k;
public:
    DataStream(int value, int k) {
        this->count = 0;
        this->value = value;
        this->k = k;
    }
    
    bool consec(int num) {
        if(num == this->value){
            if(this->count < this->k)this->count += 1;
            return this->count == this->k;
        }
        this->count = 0;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */