#include <iostream>
using namespace std;
template<class t>
class Linkedlist{
private:
    struct node{
        node*prev;
        t data;
        node*next;
    };
    node*head,*cur;
    int size,even;
    double sum,avg;
    void update_avg(){
        avg=sum/size;
    }
    void increment(t d){
        size++;
        even+=d&1?0:1;
        sum+=d;
        update_avg();
    }
    void decrement(t d){
        size--;
        even-=d&1?0:1;
        sum-=d;
        update_avg();
    }
    void replacer(t r,t d){
        decrement(r);
        increment(d);
        update_avg();
    }
    to_beginning(){
        delete(head);
        head=NULL;
        cur=NULL;
        size=0;sum=0;avg=0;even=0;
    }
    void empty_msg(){
        cout<<"The list is empty\n";
    }
    NOT_FOUND(t d){
        cout<<"ELEMENT "<<d<<" NOT FOUND\n";
    }
    void first_element(t d){
        node*tmp=new node;
        head=tmp;cur=tmp;tmp->next=head;tmp->prev=head;head->data=d;
    }
public:
    Linkedlist(){to_beginning();}
    bool empty(){
        return size?false:true;
    }
    void push_back(t d){
        if(head==NULL)
            first_element(d);
        else{
            node*tmp=new node;
            tmp->data=d;
            cur->next=tmp;
            tmp->prev=cur;
            tmp->next=head;
            head->prev=tmp;
            cur=tmp;
        }
        increment(d);
    }
    void push_front(t d){
        if(head==NULL)
            first_element(d);
        else{
            node*tmp=new node;
            tmp->next=head;
            tmp->prev=cur;
            tmp->data=d;
            head->prev=tmp;
            cur->next=tmp;
            head=tmp;
        }
        increment(d);
    }
    void pop_back(){
        if(empty()){empty_msg();return;}
        if(size>1){
            node*tmp=cur;
            cur=cur->prev;
            cur->next=head;
            head->prev=cur;
            decrement(tmp->data);
            delete(tmp);
        }
        else to_beginning();
    }
    void pop_front(){
        if(empty()){empty_msg();return;}
        if(size>1){
            node*tmp=head;
            head=head->next;
            head->prev=cur;
            decrement(tmp->data);
            cur->next=head;
            delete(tmp);
        }
        else to_beginning();
    }
    void push_after(t after,t d){
        if(!empty()){
            if(head->data==after){
                if(head->next==head){
                    push_back(d);
                    return;
                }
                node*tmp=new node;
                tmp->data=d;
                node*tmp2=head->next;
                tmp2->prev=tmp;
                tmp->next=tmp2;
                tmp->prev=head;
                head->next=tmp;
                increment(d);
                return;
            }
            if(cur->data==after){
                push_back(d);
                return;
            }
            if(size>1){
                node*tmp=head->next;
                node*ins=new node;
                while(tmp!=head){
                    if(tmp->data==after){
                        ins->data=d;
                        ins->next=tmp->next;
                        ins->prev=tmp;
                        tmp->next=ins;
                        increment(d);
                        return;
                    }
                    tmp=tmp->next;
                }
            }
        }
        NOT_FOUND(after);
    }
    void replace(t rep,t d){
        if(!empty()){
            if(head->data==rep){
                head->data=d;
                replacer(rep,d);
                return;
            }
            if(cur->data==rep){
                cur->data=d;
                replacer(rep,d);
                return;
            }
            if(size>1){
                node*tmp=head->next;
                while(tmp!=head){
                    if(tmp->data==rep){
                        tmp->data=d;
                        replacer(rep,d);
                        return;
                    }
                    tmp=tmp->next;
                }
            }
        }
        NOT_FOUND(rep);
    }
    void display(){
        if(empty()){empty_msg();return;}
        cout<<head->data<<" ";
        if(size>1){
            node*tmp=head->next;
            while(tmp!=head){
                cout<<tmp->data<<" ";
                tmp=tmp->next;
            }
        }
        cout<<"\n";
    }
    double average(){
        return avg;
    }
    double summition(){
        return sum;
    }
    int get_size(){
        return size;
    }
    int get_even(){
        return even;
    }
};
int main()
{
    Linkedlist<int>li;
    li.display();
    cout<<li.get_size()<<" "<<li.summition()<<" "<<li.average()<<" "<<li.get_even()<<"\n";
    return 0;
}
