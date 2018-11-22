#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include<stdlib.h>
using namespace std;
char Xor (char x , char y)
{
    if((x=='0'&&y=='0')||(x=='1'&&y=='1'))
        return '0';
    else
        return '1';
}
string alter(int index,string m_in)
{   cout<<" Index = ";
    cin>>index;
    if(index!=0)
        {
    if(m_in[index]=='0')
    m_in[index]='1';
    else
    m_in[index]='0';
        }
        else
        {

        cout<<"Index should not equal 0"<<endl;
        m_in=alter(index,m_in);
        }
    return m_in;

}
string Remainder(string m,string p)
{
    string r="";
  string z="0";
  string transmitted_message="";
  for(int i=0;i<p.length()-1;i++)
   {
void verifier(string TransmittedM,string poly)
{
   string verify=Remainder(TransmittedM,poly);
   int flag=0;
   for(int i=0;i<verify.length();i++)
   {
       if(verify[i]!='0')
       {
           flag++;

       }

   }
    if(flag>0)
        cout<<"Ops!! There is an error"<<endl;
    else
        cout<<"Message is correct"<<endl;

}
   m+='0';
   z+='0';

   }
   r= m.substr(0,p.length());
    for(int j=p.length();j<m.length();j++){
     if(r[0]=='1')
    {
     for(int i=0;i<p.length();i++)
    {
        r[i]=Xor(r[i],p[i]);}}
        else{
                for(int i=0;i<p.length()-1;i++)
               {
        r[i]=Xor(r[i],z[i]);}}

    r.erase(0,1);
    r=r+m[j];
        }
    r.erase(0,1);
    return r;
}
string Generator(string mm,string pp)
{
    string rr=Remainder(mm,pp);
     mm+=rr;
     return mm;
}
void verifier(string TransmittedM,string poly)
{
   string verify=Remainder(TransmittedM,poly);
   int flag=0;
   for(int i=0;i<verify.length();i++)
   {
       if(verify[i]!='0')
       {
           flag++;

       }

   }
    if(flag>0)
        cout<<"Ops!! There is an error"<<endl;
    else
        cout<<"Message is correct"<<endl;

}

int main()
{
  string line;                         /*Input from file*/
  string frame="";                   /* initial message from sender before adding remainder*/
  string generator="";
  string x="";
  int indexxx=0;                       /*Index to be chosen by user to alter the message*/
  ifstream myfile ("CRC_in.txt");      /*Reading the input from CRC_in file*/
  if (myfile.is_open())
  {  getline (myfile,line);
      frame= line;                   /*Parse the line to get message*/
     getline (myfile,line) ;
     generator= line;                       /*Parse the line to get generator*/
     myfile.close();
  }
  string test=Generator(frame,generator); /*Generate message to be transmitted*/
  cout<<"Frame= "<<frame<<endl<<"Generator= "<<generator<<endl;
  cout<<"Transmitted message= "<<test<<endl;
  verifier(x,generator);
    return 0;
}
