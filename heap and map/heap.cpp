#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<algorithm>
#include<set>

using namespace std;
//question1 
int mod1=(int)1e9+7;
//good way to calculate nCr
//dp me ek baar dekh lena
long long int nCr(int n,int r){
    vector<int>C(r+1,0);
    //memset(C, 0, sizeof(C));
 
    C[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j-1])%mod1;
    }
    return C[r];
}
long solve1(int a,vector<long>&b)
{
    if(a==1 or a==2)return b[a]=1;
    
    if(a==3)return b[a]=2;
    
    //int num=a/2;
    
       if(b[a]!=-1)
         return b[a];
         
      int h=log2(a);
        int m=pow(2,h);
        int p=a+1-m;
        int l;
        if(p>=m/2)
            l=m-1;
        else
            l=m/2-1+p;
        int r=a-1-l;
        long long int x = nCr(a-1,l);
        long long int y = solve1(l,b);
        long long int z = solve1(r,b);
        return b[a]=(((x*y) % mod1)* z) % mod1;  
         //good way to do modulus if 3 number are getting multiplied        
}

int solve(int A) {

      vector<long>b(101,-1);
         int x=solve1(A,b);
         
    return b[A];
}

//merge k sorted list

// * Definition for singly-linked list.
 struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 //
 
 class comp{
   public:  
     bool operator()(const ListNode* a,const ListNode* b)const{
         return a->val>b->val;
     }
 };
ListNode* mergeKLists(vector<ListNode*> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
 
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    priority_queue<ListNode*,vector<ListNode*>,comp>pq;
    
     ListNode* head=new ListNode(-1);
     ListNode* prev=head; 
      for(int i=0;i<A.size();i++)
      {
          if(A[i]!=nullptr)
             pq.push(A[i]);
      }
      
      while(pq.size()!=0)
      {
          ListNode* a=pq.top();
          prev->next=a;
          prev=prev->next;
          pq.pop();
          
          if(a->next!=nullptr)pq.push(a->next);
          
      }
      
      return head->next;
}

// largest k number
vector<int> solve(vector<int> &A, int B) {
    
    
     priority_queue<int>pq;
     
     vector<int>ans;
     
     for(int i=0;i<A.size();i++)
     {
         pq.push(A[i]);
     }
     
      while(B-->0 && pq.size()!=0)
      {
          ans.push_back(pq.top());
          pq.pop();
         // B--;
      }
      
      return ans;
}

//Maximum Sum Combinations
vector<int> solve(vector<int> &A, vector<int> &B, int C) {
    
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    //{val,i,j};
    int size=A.size();
    
    priority_queue<vector<int>>pq;
      
      pq.push({A[size-1]+B[size-1],size-1,size-1});
      
      
     set<vector<int>>s;
     s.insert({size-1,size-1});
     vector<int>ans;
       while(C-->0)
       {
           vector<int>a=pq.top();
           pq.pop();
             ans.push_back(a[0]);
             
             if(s.find({a[1]-1,a[2]})==s.end())
             {
                 pq.push({A[a[1]-1]+B[a[2]],a[1]-1,a[2]});
                 s.insert({a[1]-1,a[2]});
             }
            if(s.find({a[1],a[2]-1})==s.end())
             {
                 pq.push({A[a[1]]+B[a[2]-1],a[1],a[2]-1});
                 s.insert({a[1],a[2]-1});
             }
             
             
       }
      
      return ans;
}

//Magician and Chocolates

int nchoc(int A, vector<int> &B) 
{
    int mod1=(int)1e9+7;
    priority_queue<long>pq;
    
        for(int &i:B)
        {
            pq.push(i);
        }
        
        long count=0;
        while(A-->0 && pq.size()!=0)
        {
            long l=pq.top();
        //    l=l%mod1;
           count+=l;
           count=count%mod1;
           
           pq.pop();
           long z=l/2;
           if(z>0)
            pq.push(z);
        }
        
        return count%mod1;
}
//N max pair combinations

vector<int> solve(vector<int> &A, vector<int> &B) {
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int s1=A.size();
    int k=s1;
    //{sum,i,j}
    
    priority_queue<vector<int>>pq;
    
      pq.push({A[s1-1]+B[s1-1],s1-1,s1-1});
      set<vector<int>>s;
      s.insert({s1-1,s1-1});
      
      vector<int>ans;
        while(k-->0)
        {
            vector<int>a=pq.top();
            ans.push_back(a[0]);
            
            pq.pop();
            
            if(s.find({a[1]-1,a[2]})==s.end())
            {
                pq.push({A[a[1]-1]+B[a[2]],a[1]-1,a[2]});
                s.insert({a[1]-1,a[2]});
            }
             if(s.find({a[1],a[2]-1})==s.end())
            {
                pq.push({A[a[1]]+B[a[2]-1],a[1],a[2]-1});
                s.insert({a[1],a[2]-1});
            }
            
            
            
                  
        }
        return ans;
}
