//Class notes

void SetHWScore(int i, float s){
    hw[i].setScore(s);
}


void Course::AddCredit(int c){
    
}





// ------------------------------------ 5.th February 

int main(){
    int *iptr1;
    iptr1 = new int(3); //New is gonna allocate space on the heap, and return its adress
    iptr1 = new int(4);
    return 0;
}



class MyArray{
    private:
        int capacity, len;
        int *data;

    public:
        MyArray(): capacity(2), len(0){
            data = new int[2];
        }
        void insert(int n){
            if(len < capacity){
                data[len] = n;
            }
            else if (capacity >= len){
                int temp* = data;
                capacity *= 2;
                data = new int[capacity];
                for (int i = 0; i < len; i++){
                    data[i] = temp[i];
                }
            }
            //only use delete, whe some thing is used b new
            delete [] temp;

        }
}

void MyArray::Append(const MyArray& other){
    MyArray temp = other;
    if(capacity < len + other.len){
        int* old = data;
        data = new int[len + other.len];
        for (int i = 0; i < len; i++){
            data[i] = old[i];
        }
        delete[] old;
        capacity = len + other.len;
        for (int i = 0; i < other.len; i++){
            data[len+i] = n
        }
    }

    
}


void MyArray::Append(const MyArray& other){
    MyArray temp = other;
    for(int i = 0; i < temp.capacity; i++){
        this.insert(temp[i]);
    }
}


ostream& operator <<(const ostream& os, const MyArray& n){
    for (int i = 0; i < n.length; i++){
        os << n.getItem(i);

    }
    return os;
}


int MyArray::getItem(int index) const{
    if(index < 0 || index >= len){
        cout << "error" << endl;
        exit(0);
    }
    return data[index];
}

int& MyArray::operator[](int index){
    if (index < 0 || index >= len){
        cout << "error" << endl;
        exit(0);
()    }
    return data[i];
}



Myarray operator=(const MyArray other){
    capacity = other.capacity;
    len = other.len;
    delete [] cata;
    data = new int[caoacity];
    for (int i = 0; i < len; i++){
        data[i] = other.data[i];
    }
    return *this;
}

//Constructor, same as operator= but constructor made

Myarray(const MyArray other){
    capacity = other.capacity;
    len = other.len;
    data = new int[caoacity];
    for (int i = 0; i < len; i++){
        data[i] = other.data[i];
    }
}


//When passing by value, we dont want func to change the object passed to

// Pointer to
//When class has dynamically allocated memory, make sure overload operator=, define copy constructor 

// When pass by value, copy constructor is called

//desrtuctor-> prevent memory leak



ostreams& operator<<(ostreams& os, MyArray m){
    for loop:
        os << m.data[i];
        os << m.><<getData[i]
}



//WHen a class (inside a class def) declares non member functions as frined, then the friend function has acces to private/publicprotecged variables and functions
//friend ostreams& operator<<(ostreams& os, const MyArray m)