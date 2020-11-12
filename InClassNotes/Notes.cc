template<class T>
class ListNode{
    private:
        ListNode<T> *next;
        T data;
    public:
        ListNode(T n):
        data(n), next(nullptr){}
        friend class List<T>;
};

template<class T>
class List{
    private:
        ListNode<T>* head;
    public:
        List():head(nullptr);
        void insertFront(T n){
            head = new ListNode<T>(n);
            n->next = head; //????
        }

        void insertBack(T n){
            if(head == nullptr){
                head = new ListNode<T>(n);
                return;
            }
            ListNode<T>* temp = head;
            while(temp->next != nullptr){
                temp = temp->next;
            }
            temp->next = new ListNode<T>(n);
            delete[] temp;
        }
};



/*class MyArray{
    private: 
        int* data;
        int cap;
        int len;
    public:
        MyArray(): cap(2), len(0){
            data = new int[2];
        }
};*/


template<class T>
class MyArray{
    private:
        T* data;
        int cap;
        int len;
    public:
        MyArray(): cap(2), len(0){
            data = new T[2];
        }
        
        T& operator[](int index){
            if(index < 0) || (index >= len){
                cout<<"error";
                exit(0);
            }
            return data[index];
        }
    
};

int main(){
    MyArray<char> A1;
    //A1.insert('c');
    //A1.insert('d');
    //A1.insert('g');
}

List::InsertFront(int n){
    ListNode* nn = new ListNode(n);
    nn->next = head;
    head = nn;
}


// ------------------ HOMWORK
//Queue FIFO: First in first out

//Implement a queue this way

class MyQueue{
    int* data;
    int capacity;
    int length;
    int start_index;
    //Push. Puts at back of stack
    //Pops first element at stack, return front and remove it 

};

template<class T>
T FindMax(T a, T b){
    if (a > b){
        return a;
    }
    else{
        return b;
    }
}

// eg
/*
Student s1;
Student s2;

s2 = FindMax(s1, s2) <-- compilér complains if operator> overloaded for student



*/


template<class T1, class T2>
void print(T1 a, T2 b){
    cout << a << " " << b << endl;
}

//print("Hello", 7.2)
//Tempalte for two types


//std::pair
int main(){
    pair<string, int> p1;
    p1.first = "Ann";
    p1.second = 100;
    p1.first = 'd'; //--Error, first must be string not char.
    //Public member variable of pair
    pair<char, int> arr[4];
    for(int i = 0; i < 4; i++){
        arr[i].first = 'a' + i;
        arr[i].second = i;
    }
    return 0;
}

C++ standard template libarary STL


#include <vector>

//Basically vector is MyArray

int main(){
    //vector v0; // <-- doesnt compile
    vector<int> v1;
    v1.push_back(5);
    v1.push_back(30);
    v1.push_back(53); //<- insert at back
    v1[2] = 200;
    int k = v1[1] + 5 //k gets set to 35
    v1.at(2) = 200;

    for (vector<int>::iterator it = v1.begin();
        it!= v1.end(); it++){
            cout << *it << " ";
        }
        //deferences an iterator means conent of what iterator points to


    for (int i : v1){
        cout << i << " ";
    }    

    vector<int> v1;
    v1.push_back(5);
    v1.push_back(30);
    vector<int> v2;
    v2 = v1;
    v2[1] = 300;
    v1[1]= 300;
    if(v1 == v2){
        cout << "same";
    }
}

template <class T>
class vector{
    T operator[](int index);
}

//A vector class is called a container class
//Iterator defined
//go through each element in container


//begin() return iterator poitning at first element of vector





// ---------------- March 2

//#include vector

int main(){
    vector<float> fv;
    fv.push_back(3.5);
    fv.erase(fv.begin()+3, fv.begin()+7);
    //Erase form first iterator not to but not included to 2nd iterator 


    sort(fv.begin(), fv.end(), greater<float>()); 
    vector<Student> sv; 
    sv.push_back(s); 
    sort(sv.begin(), sv.end(), greate<Student>);
}


//Greater than methods

//Containers = {Set, vector}
//#include<set>
int main(){
    set<int> si; //Ordered set
    si.insert(3);
    si.insert(2);
    si.insert(7);
    si.insert(2);
    for (int i : si){
        cout << i << " "; //Output would be 2,3,7
    }
    return 0;
}


//#include<unordered_set>
//#include<map>
//#include<unorderer_map>

//map is key value pair

struct Student
{
    int id;
    std::string name;
    float gpa;
};


int main(){
    unorderer_map <int, Student> smap;
    Student s1;
    snap.insert(pair <int, Student> (s1.id, s1));
    unordered_map<int, Student>::iterator it;
    it = smap.find(3728); //Sending key
    if(it != smap.end()){
        cout << it->second.name;
    }
    //(*it.second.name)
    return 0;
}


void main(){
    vector<int> v1;
    unordered_set<int> s;
    for(int i: v1){
        s.insert(i);
    }
    for(int i : s){
        cout << i << " "; 
    }


    unordered_map<string, int> nmap;
    nmap.insert(pair<string, int> ("chair", 3));
    nmap.insert(pair<string, int> ("chair", 18)); //<-- if key is alredy exist, this is ignored. Keeps original value

    //nmap["table"] = 7;
    nmap["chair"] = 12;
    //    Key       Value
    unordered_map::iterator it = nmap.find("chair");
    if (it != nmap.end()){ //Each iterator passes to a key-value pair
        it->second = 12;
    }
    else{
        nmap.insert(pair<string, int> ("chair", 12));

    }
    
}



unordered_map<int, int> counts;
for (int i : v){
    //unordered_map<int, int>::iterator it = counter.find(i);
    counts[i] += 1
}



//read from file
#include<fstream>
#include<iostream>

using namespace std;

int main(){
    vector<float> nums;
    ifstream myFile(); //i stands for input 
    myFile.open("data.txt");
    float num;
    while(!myFile.eof()){ //EOF is not true yet after reading last float. Only when read again then EOF true
        myFile >> num;
        if(!myFile.fail()){nums.push_back(num)} //if no check last num inserted twice


    }

    myFile.close()
    return 0;
}

void tokenize(char buffer[], std::string arr[], char seperator){
    int i = 0;
    int index = 0;
    int start = 0;
    while(buffer[i] != '10'){
        if(buffer[i] == seperator){
            buffer[i] = '10';
            arr[index] = &(buffer[start]);
            start = i + 1;
            index++;
        }
    }
    buffer[i] = '10';
    arr[index] = &(buffer[start]);
    start = i + 1;
    index++;
}