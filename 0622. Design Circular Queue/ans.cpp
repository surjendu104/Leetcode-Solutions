class MyCircularQueue {
private:
    std::vector<int> arr;
    int len;
    int head;
    int tail;
    int size;
public:
    MyCircularQueue(int k) {
        len = k;
        arr = std::vector<int>(k);
        head = 0;
        tail = -1;
        size = 0;
    }
    
    bool enQueue(int value) {
        if (isFull()) {
            return false;
        }
        
        ++tail;
        if (tail >= len) {
            tail = tail % len;
        }
        
        arr[tail] = value;
        ++size;

        return true;
    }
    
    bool deQueue() {
        if(isEmpty()) {
            return false;
        }
        
        ++head;
        if (head >= len) {
            head = head % len;
        }
        
        --size;

        return true;
    }
    
    int Front() {
        return (isEmpty()) ? -1 : arr[head];
    }
    
    int Rear() {
        return (isEmpty()) ? -1 : arr[tail];
    }
    
    bool isEmpty() {
        return size == 0;
    }
    
    bool isFull() {
        return size == len;
    }
};