class Listnode{
    private:
        int data;
        Listnode* next;

    public:
        Listnode(int i): data(i), next(nullptr){};
        Listnode(int i, Listnode* n): data(i), next(n){};
        friend class list;
};

class List {
    private:
        Listnode* head;
    public:
        List(): head(nullptr){};

        void InsertFront(int i){
            Listnode newNode = new Listnode(i);
            if(head == nullptr){
                head = newNode;
                return;
            }
            Listnode prev = head;

        }

        void Print(){
            if (head == nullptr){
                //print error
            }
            Listnode temp = head;
            while(temp != nullptr){
                //print temp
                temp = temp->next
            }

            for(Listnode* lptr = head; lptr!=nullptr; lptr = lptr->next){}
            
        }

};


int main(){
    List L;
    return 0;
}


//Notes
//Listnode LN;
/*


*/