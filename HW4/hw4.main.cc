#include <iostream>

using namespace std;

// 1. (6 points) Convert this to a template class so you can make a MyQueue
//    of different types.

// A queue is first-in first-out, meaning that the items are popped in the
// order that they are pushed.
// The MyQueue class implements a queue using a circular array.
template<class T>
class MyQueue {
 private:
  T* data;
  int capacity;
  int start_index;
  int length;
  int rear;
 public:
 MyQueue() : capacity(2), start_index(0), length(0), rear(0){
    data = new T[2];
  };

  // 2. (8 points) Insert a new element into the back of the queue.
  //    This is done by writing the element to its rightful position in data,
  //    and by incrementing length. If the capacity of the data array has been
  //    reached, meaning all elements of data contains items still on the
  //    queue, allocate twice the space to data.
  void Push(T n) {
    //When reached capacity, allocating twice the capacity to data, and copying over
    //from old data 
    if(length == capacity){
        T* temp = data; 
        data = new T[capacity*2];
        int counter = 0; 
        for(int i = start_index; i < capacity; i++){
          data[counter++] = temp[i]; 
        }
        if(rear < start_index){
          for(int i = 0; i <= rear; i++){
            data[counter++] = temp[i];
          }
        }
        start_index = 0; 
        rear = counter-1; 
        capacity *= 2; 
      }
    if(!IsEmpty()){
      rear = (rear+1)%capacity;
    }
    data[rear] = n; 
    length++; 

  };

  // 3. (6 points) Return the element in the front of the queue. Then set
  //    the front of the queue to be the next element. In practice, this is
  //    done by incrementing the start_index. Remember that in a circular
  //    array, when start_index gets to the end of the array, it wraps around
  //    to the beginning of the array.
  T Pop() {
    T temp = data[start_index];
    if(start_index == capacity-1){
      start_index = 0;
    }
    else{
      start_index++;
    }
    length--;
    return temp;
  };

  bool IsEmpty() {
    return length == 0;
  };
  
  int Capacity() {
    return capacity;
  };
};

class Student {
private:
  string name;
  int id;
public:
  Student() : name(""), id(0) { };
  Student(string s, int i) : name(s), id(i) { };
  friend ostream& operator<<(ostream& os, const Student& s);
};

ostream& operator<<(ostream& os, const Student& s) {
  os << s.name << " " << s.id;
  return os;
}

int main() {
  MyQueue<int> Q;

  Q.Push(5);
  Q.Push(6);
  Q.Push(7);
  Q.Push(8);
  cout << Q.Pop() << endl;
  Q.Push(9);
  cout << Q.Pop() << endl;
  Q.Push(10);
  cout << "Capacity: " << Q.Capacity() << endl;
  cout << Q.Pop() << endl;
  Q.Push(11);
  Q.Push(12);
  Q.Push(13);
  Q.Push(14);
  Q.Push(15);
  cout << Q.Pop() << endl;
  cout << Q.Pop() << endl;
  cout << Q.Pop() << endl;
  cout << Q.Pop() << endl;
  cout << Q.Pop() << endl;

  MyQueue<Student> SQ;
  SQ.Push(Student("Ann", 1234));
  SQ.Push(Student("Bob", 5678));
  SQ.Push(Student("Cary", 1111));
  SQ.Push(Student("Diane", 2222));
  cout << SQ.Pop() << endl;
  cout << SQ.Pop() << endl;
  cout << SQ.Pop() << endl;
  SQ.Push(Student("Edward", 3333));
  cout << SQ.Pop() << endl;
  cout << SQ.Pop() << endl;

  return 0;
}
/*
Output:
5
6
Capacity: 4
7
8
9
10
11
12
Ann 1234
Bob 5678
Cary 1111
Diane 2222
Edward 3333
*/
