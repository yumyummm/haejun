#ifndef QUEUE_H
#define QUEUE_H
//#define QUEUE_SIZE 100
// extern const int QUEUE_SIZE = 100;

class Queue{
private:
    static const int QUEUE_SIZE;

    int *pArr_;
    int size_; // 큐의 크기
    int rear_;
    int front_;
    Queue(const Queue&);
    Queue& operator=(const Queue&);
public:
    explicit Queue(int size  = QUEUE_SIZE); 
    ~Queue();

    bool empty() const;
    bool full() const;

    int size() const;
    int remain() const;
    
    void push(int data);
    int pop();
};

#endif

