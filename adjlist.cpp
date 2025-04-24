#include<iostream>
using namespace std;

class Al{
    public:
    string city;
    int fuel;
    Al *next;
    void create();
    void display();
    void edge();
    int v;


}*head[10];

void Al::create()
{ 
    cout<<"how many cities you want to insert";
    cin>>v;
   for(int i=0;i<v;i++)
   {
    head[i]=new Al;
     cout<<"enter the city no\t"<<i+1<<":";
     cin>>head[i]->city;
     head[i]->next=NULL;
   }
}
void Al::edge(){
    string s,d;
    int e,j;
    Al *n1,*temp;
    cout<<"enter the number of edges";
    cin>>e;
    for (int i = 0; i < e; i++)
    {
        cout<<"enter the source and destination city";
        cin>>s>>d;
        for( j=0;j<v;j++)
        {
            if(head[j]->city==s)
            {
                break;
            }
        }
        n1=new Al;
        n1->city=d;
        cout<<"enter the fuel required:";
        cin>>n1->fuel;
        n1->next=NULL;
        temp=head[j];
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=n1;
    }
    
}

void Al::display() {
    
    for (int i = 0; i < v; i++) {
        Al *temp = head[i];
        cout << temp->city;
        temp = temp->next;
        while (temp != NULL) {
            cout << " -- " << temp->city << ", Fuel: " << temp->fuel << "";
            temp = temp->next;
        }
        cout <<"\n";
    }
}

int main() {
    Al obj; 
    obj.create();  
    obj.edge();   
    obj.display(); 
    
    return 0;
}
