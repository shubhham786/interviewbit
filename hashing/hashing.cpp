#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

//Window String

string minWindow(string A, string B) {

  if(A.size()<B.size())return "";

    //unordered_map<char,int>map;
     vector<int>map(126,0);
    int si=0,ei=0;
   
   int len=(int)1e9;
    int l=A.size();
    int count=B.size();
    int gsi=0;
      for(char &s:B)
      {
          map[s]++;
      }
          
          while(ei<l)
          {
              if(map[A[ei++]]-- >0)count--;

               while(count==0)
               {
                   if(ei-si<len)
                   {
                       len=ei-si;
                        gsi=si;
                   }

                   if(map[A[si++]]++ ==0)count++;
               }
          }

          return len==(int)1e9?"":A.substr(gsi,len);

}
//fraction
string fractionToDecimal(int A, int B) {
    
   
        
        string ans="";
        long num=(long)A;
        long den=(long)B;
        bool neg=false;
        if(num<0){
          //  cout<<"*"<<endl;
            neg=true;
            num=abs(num);
           // cout<<num<<endl;
        }
        if(den<0){
            if(neg==true){
                neg=false;
               // cout<<1<<endl;
            }
                
            else{
                neg=true;
            }
            
            den=0-den;
            
           // cout<<sizeof(int);
        }
        if(neg==true){
            ans+="-";
        }
       // cout<<ans<<endl;
       // cout<<num<<" "<<den;
        if(num==0)
            return "0";
        
        long num1=num/den;
        
        ans+=to_string(num1);
        
        unordered_map<int,int>map;
        
        long num2=num%den;
        
        if(num2==0)
          return ans;
        
        ans+=".";
        
        bool isrec=true;
         int val;
        while(num2>0 )
        {
            //while(num2<=den){
              num2=num2*10;
                
          
            if(map.find(num2)==map.end())
            {
               // jab tak ek authentic pattern nahi milta hai tab tak map me insert karte jaoo
                map[num2]=ans.size();
            }
            else
            {
              // mil gaya authentic pattern tu break kar do loop ko
                ans.insert(map[num2],"(");
                
                ans+=")";
                break;
                
                
            }
            
            // ans me add karte jaoo
            
            ans+=to_string(num2/den);
            num2=num2%den;
            
        }
        
        return ans;
     
        
        
    
}
//Longest Substring Without Repeat


int lengthOfLongestSubstring(string A) {
    
    int si=0,ei=0;
    
    int l=A.size();
    
    //vector<int>map(126,0);
    unordered_map<char,int>map;
    int count=0;
     int len=0;
      while(ei<l)
      {
          if(map[A[ei++]]++ >0)count++;
          
          //cout<<count<<" ";
         
            
            if(count==0)
             len=max(len,ei-si);
           while(count>0)
           {
              if(map[A[si++]]-- >1)count--;   
           }
          
      }
      
      return len;
}

//diff II

int diffPossible(const vector<int> &A, int B) {
    
    
    unordered_map<int,int>map;
    
    int sum=0;
     //vector<int>prefix(A.size(),0);
     if(A.size()<2)
      return 0;
     
    // if(B==0)
      // return 0;
       
     for(int ele:A)
       {
           map[ele]++;
       }
     for(int ele:A){
         
        if(B==0){
          if(map[ele]>=2)
            return 1;
        }
        else{
         if(map.find(ele+B)!=map.end())
              return 1;
        }              
              //map[ele]++;
     }
     
     return 0;
}

//anagram
vector<vector<int> > anagrams(const vector<string> &A) {
    
    vector<vector<int>>ans;
    
    unordered_map<string,vector<int>>map;
    
    for(int i=0;i<A.size();i++)
    {
        string str=A[i];
          
          sort(str.begin(),str.end());
          
          map[str].push_back(i+1);
    }
    
    for(auto &i:map)
    {
        ans.push_back(i.second);
    }
    
    return ans;
}

//Points on the Straight Line--here duplicates are allowed
//leetcode 149

int maxPoints(vector<int> &A, vector<int> &B) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

            int ans=0;
        for(int i=0;i<A.size();i++)
        {
            int x=0;
            int same=1;
                    unordered_map<double,int>map;
            for(int j=i+1;j<B.size();j++)
            {
                 double m;
                  if(A[i] == A[j] && B[i]==B[j]){
                    same++;
                }
                else if((A[j]-A[i])!=0){
                   m=(double)(B[j]-B[i])/(A[j]-A[i]);
                    map[m]++; 
                }
                else
                    map[(int)1e9]++;
               
                //if(map.find(m)==map.end())map[m]=1;
                
                //else
                  //  map[m]++;
                
               // cout<<j<<" "<<i<<" "<<m<<" "<<map[m]<<endl;
                 
                x=max(x,map[m]);
            }
            ans=max(ans,x+same);
        }
        
       return ans;
       
}
