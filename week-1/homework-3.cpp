class MyCircularDeque {
public:
    MyCircularDeque(int k) {
        m_vec.reserve(k+2);
        capacity = k;
        front_idx = 0;
        last_idx = 1;
    }
    
    bool insertFront(int value) {
        if(isFull())
            return false;
        m_vec[front_idx] = value;
        front_idx = (front_idx - 1 + capacity + 2) % (capacity + 2);
        return true;
    }
    
    bool insertLast(int value) {
        if(isFull())
            return false;
        m_vec[last_idx] = value;
        last_idx = (last_idx + 1) % (capacity + 2);
        return true;
    }
    
    bool deleteFront() {
        if(isEmpty())
            return false;
        front_idx = (front_idx + 1) % (capacity + 2);
        return true;
    }
    
    bool deleteLast() {
        if(isEmpty())
            return false;
        last_idx = (last_idx - 1 + capacity + 2) % (capacity + 2);
        return true;
    }
    
    int getFront() {
        if(isEmpty())
            return -1;
        return m_vec[(front_idx + 1) % (capacity + 2)];
    }
    
    int getRear() {
        if(isEmpty())
            return -1;
        return m_vec[(last_idx - 1 + capacity + 2) % (capacity + 2)];
    }
    
    bool isEmpty() {
        if((front_idx + 1)%(capacity + 2) == last_idx)
            return true;
        return false;
    }
    
    bool isFull() {
        if((last_idx + 1)%(last_idx + 2) == front_idx)
            return true;
        return false;
    }

private:
    vector<int> m_vec;
    int front_idx;
    int last_idx;
    int capacity;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
