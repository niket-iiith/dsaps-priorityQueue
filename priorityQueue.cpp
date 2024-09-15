#include<iostream>
#include<math.h>

using namespace std;

// custom dynamic array which doubles in size whenever full
class myArr {
    private: 
        int* arr;                           // pointer to the array
        int capacity;                       // current capacity of the array
        int length;                         // number of elements
                                              
        void resize(int _capacity) {         
            int* newArr = new int[_capacity];   
            for(int i=0; i<length; i++){        
                newArr[i] = arr[i];          
            }                                 
            delete[] arr;                   // delete old array
            arr = newArr;                   // point old array to new array
            capacity = _capacity;           // capacity updated to 2 * capacity
        }

    public:                                             
        myArr() {                                       
            arr = new int[1];                              
            capacity = 1;                               
            length = 0;                             
        }                                               

        void push_back(int _val) {                  
            if(length == capacity){         // if capacity full, resize to 2 * capacity
                resize(capacity * 2);
            }
            arr[length++] = _val;
        }

        void pop_back() {
            if(length == 0) {
                cout << "error: array empty" << endl;
                return;
            }
            length--;
        }

        int& operator[](int ind) {
            if(ind < 0 || ind > length-1) {
                throw out_of_range("Index out of bounds");
            }
            return arr[ind]; 
        }

        int size() {
            return length;
        }
};


class max_priority_queue {
    private:
        myArr heap;

        void heapifyUp(int index) {
            while(index > 0) {
                int parent = (index - 1) / 2;
                if(heap[index] > heap[parent]){
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else {
                    break;
                }
            }
        }

        void heapifyDown(int index) {
            while(index < heap.size()){
                int leftChild = index * 2 + 1;
                int rightChild = index * 2 + 2;
                int largest = index;

                if(leftChild < heap.size() && heap[leftChild] > heap[largest])
                    largest = leftChild;
                if(rightChild < heap.size() && heap[rightChild] > heap[largest])
                    largest = rightChild;

                if(largest != index){
                    swap(heap[largest], heap[index]);
                    index = largest;
                }
                else{
                    break;
                }
            }
        }

    public:
        max_priority_queue() {
            // initialize an empty max priority queue
        }

        int size() {
            return heap.size();
        }

        void push(int _val){
            heap.push_back(_val);
            heapifyUp(heap.size() - 1);
        }

        int top() {
            if(heap.size() > 0) {
                return heap[0];
            }
            else{
                throw out_of_range("Priority Queue is Empty");
            }
        }

        void pop() {
            if(heap.size() > 0) {
                swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();
                heapifyDown(0);
            }
            else{
                throw out_of_range("Priority Queue is Empty");
            }
        }

        bool empty() {
            if(heap.size() == 0) return true;
            else return false;
        }
};

class min_priority_queue {
    private:
        myArr heap;

        void heapifyUp(int index) {
            while(index > 0) {
                int parent = (index - 1) / 2;
                if(heap[index] < heap[parent]){
                    swap(heap[index], heap[parent]);
                    index = parent;
                }
                else {
                    break;
                }
            }
        }

        void heapifyDown(int index) {
            while(index < heap.size()){
                int leftChild = index * 2 + 1;
                int rightChild = index * 2 + 2;
                int smallest = index;

                if(leftChild < heap.size() && heap[leftChild] < heap[smallest])
                    smallest = leftChild;
                if(rightChild < heap.size() && heap[rightChild] < heap[smallest])
                    smallest = rightChild;

                if(smallest != index){
                    swap(heap[smallest], heap[index]);
                    index = smallest;
                }
                else{
                    break;
                }
            }
        }

    public:
        min_priority_queue() {
            // initialize an empty max priority queue
        }

        int size() {
            return heap.size();
        }

        void push(int _val){
            heap.push_back(_val);
            heapifyUp(heap.size() - 1);
        }

        int top() {
            if(heap.size() > 0) {
                return heap[0];
            }
            else{
                throw out_of_range("Priority Queue is Empty");
            }
        }

        void pop() {
            if(heap.size() > 0) {
                swap(heap[0], heap[heap.size() - 1]);
                heap.pop_back();
                heapifyDown(0);
            }
            else{
                throw out_of_range("Priority Queue is Empty");
            }
        }

        bool empty() {
            if(heap.size() == 0) return true;
            else return false;
        }
};

int main() {
    max_priority_queue maxPQ;
    min_priority_queue minPQ;

    // Testing Max Priority Queue
    maxPQ.push(5);
    maxPQ.push(10);
    maxPQ.push(3);
    maxPQ.push(8);

    cout << "Max Priority Queue:" << endl;
    while (!maxPQ.empty()) {
        cout << "Top: " << maxPQ.top() << endl;
        maxPQ.pop();
    }

    // Testing Min Priority Queue
    minPQ.push(5);
    minPQ.push(10);
    minPQ.push(3);
    minPQ.push(8);

    cout << "\nMin Priority Queue:" << endl;
    while (!minPQ.empty()) {
        cout << "Top: " << minPQ.top() << endl;
        minPQ.pop();
    }

    return 0;
}