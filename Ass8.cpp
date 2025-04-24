#include<iostream>
using namespace std;

class OBST{
    public:
    float c[100][100];
    float w[100][100];
    float r[100][100];
    int key[100];
    float p[100],q[100];
    void accept();
    void calculateOBST();
    void display();

}obj;
int n;
void OBST::accept()
{
     cout<<"how many keys you want to insert";
     cin>>n;
     cout<<"Enter the keys";
     for(int i=0;i<n;i++)
     {
        cin>>key[i];
     }
     cout<<"Enter the successfull search probabilities";
     for(int i=0;i<n;i++)
     {
        cin>>p[i];
     }
     cout<<"Enter the UNsuccessfull search probabilities";
     for(int i=0;i<=n;i++)
     {
        cin>>q[i];
     }
     
} 
void OBST::calculateOBST()
{   //float temp[10];
    float minimum=999;
    int minimum_K=-1;
    for(int i=0;i<n;i++)
    {
        for(int j=i;j<n;j++)
        {
            if(i==j)
            {
                c[i][j]=0;
                r[i][j]=0;
                w[i][j]=q[i];
            }
            else{
                w[i][j]=p[j]+q[j]+w[i][j-1];
                //int s=0;
                for(int k=i+1;k<=j;k++)
                {
                    //temp[s]=c[i][k-1]+c[k][j]+w[i][j];
                    //s++;
                    float cost=c[i][k-1]+c[k][j]+w[i][j];
                    if(cost<minimum)
                    {
                        minimum=cost;
                        minimum_K=k;
                    }
                }
                c[i][j]=minimum;
                r[i][j]=minimum_K;

            }
        }
    }
}
void OBST::display()
{  int i=0,j=n-1;
  float root=r[i][j];

}