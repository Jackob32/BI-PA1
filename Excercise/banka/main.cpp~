#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
#endif /* __PROGTEST__ */
class Transakce{
public:
    Transakce();
    Transakce(const char* mdebitAcc,const char* mcreditAcc,int mamount,const char* msign,int mcounter);
   // Transakce operator=(Transakce &trans);
    ~Transakce();
   void Rozpust();
  void Counter();
  void Out(char *accID);
private:
  char* debitAcc ;
  char* creditAcc  ;
  int amount ;
  char* sign ; 
  int counter;
};
/*Transakce::Transakce() {
 char* debitAcc ;
 char* creditAcc  ;
  int amount ;
   char* sign ; 
  int counter;
}*/
Transakce::~Transakce(){ 
  if (counter > 1) { counter--; return; }
  else{
    delete [] debitAcc;
  delete [] creditAcc;
  delete [] sign;
  amount = 0;
  counter = 0;
}}
/*Transakce Transakce::operator=(Transakce &trans) {
  debitAcc=new char[strlen(trans.debitAcc)+1];
strcpy (debitAcc,trans.debitAcc);
    creditAcc=new char[strlen(trans.creditAcc)+1];
strcpy (creditAcc,trans.creditAcc);
    sign=new char[strlen(trans.sign)+1];
strcpy (sign,trans.sign);
   amount=trans.amount ;
   counter=trans.counter;
return *this;
}*/
void Transakce::Out(char *accID){
if(strcmp (debitAcc,accID)==0)
{
cout<< " " << "-" << " " <<amount<<", to: "<<creditAcc<<", sign: "<<sign<<endl;
}
else if(strcmp (creditAcc,accID)==0)
{
cout<<" " << "+" << " "<<amount<<", from: "<<debitAcc<<", sign: "<<sign<<endl;
}
else{
  //  cout<<"neosetrena vyjimka v transakce out"<<endl;
}
}
void Transakce::Rozpust() { if (counter > 1) { counter--; return; }
  else
 delete this;
}
void Transakce::Counter() {
    this->counter++;
}
Transakce::Transakce(const char* mdebitAcc,const char* mcreditAcc,int mamount,const char* msign,int mcounter) {
   debitAcc=new char[strlen(mdebitAcc)+1];
strcpy (debitAcc,mdebitAcc);
    creditAcc=new char[strlen(mcreditAcc)+1];
strcpy (creditAcc,mcreditAcc);
    sign=new char[strlen(msign)+1];
strcpy (sign,msign);
   amount=mamount ;
   counter=mcounter;
}
class CBank{
public:
    CBank();
    ~CBank();
    CBank& Account(const char *accID);
    int   HledejAcc(const char *accID);
    void  copy(); 
    int   Balance();
    void odstran();
    bool  TrimAccount(const char *accID);
    bool  NewAccount ( const char * accID,int initialBalance );
    bool  Transaction  ( const char * debAccID,const char * credAccID,int amount,const char * signature );
    CBank operator=(CBank &bank);
    CBank (CBank &bank);
    friend ostream& operator<<(ostream&, const CBank& x);
private:
    void vytvorpole();
    void realloc( );
    void CopyAccount(int x);
    void CopyTrans(int x);
    void ReallocTransaction(int x);
    int* Cbankcounter;
    int maxpocet;    
    int posledni;
    int umisteni;
    struct person {
            char* accID;
            Transakce **poleT = new Transakce * [10];
            int Balance;
            int initialBalance;
            int Trans;
            int maxpocet;  
            int counter;
        };
    struct person **array = new struct person * [10];
    /* vynuluje to pole -> auto AccArray = new person[100]();
    char *a=new char[s.size()+1]
    a[s.size()]=0;
    memcpy(a,s.c_str(),s.size());
    */
};
void CBank::vytvorpole(){
  struct person **temp = new struct person * [maxpocet];
  for(int i=0;i<posledni;i++)
      {temp[i]=this->array[i]; 
  this->array[i]->counter++;
  }
        // memcpy (temp, array, maxpocet *sizeof(person **));
     //  temp=array;
   this->array=temp;
   this->Cbankcounter[0]=1;
}
void CBank::realloc( ) {
   struct person **temp = new struct person * [maxpocet*2];
  for(int i=0;i<maxpocet;i++)
      {temp[i]=this->array[i]; }
        // memcpy (temp, array, maxpocet *sizeof(person **));
     //  temp=array;
   delete [] array;
   this->array=temp;
        maxpocet *= 2;
        //   struct person **array = new struct person * [maxpocet];
      //for(int i=0;i<maxpocet;i++)      {      array[i]=temp[i];      }
         // for(int i=(maxpocet/2);i<maxpocet;i++){    array[i]=new person;}  
       // memcpy (array, temp, (maxpocet/2) *sizeof(person **));
    //   delete [] temp;
}
int CBank::HledejAcc(const char *accID){
 int hledana=-1;
      for(int i=0;i<posledni;i++)
      {  if ( strcmp (array[i]->accID,accID)==0) {
          hledana=i;
             break;
          }  
      }
 umisteni=hledana;
 return hledana;
 }
CBank& CBank::Account(const char *accID){
     umisteni=HledejAcc(accID);
         return *this;
}
int CBank::Balance(){
    if(umisteni==-1){
      // throw  (50);
        
    }
    else{
 //cout<<"BALANCE:"<<this->array[this->umisteni]->Balance<<endl;
 return this->array[this->umisteni]->Balance;
    }
}
void CBank::ReallocTransaction(int x){
      int vetsi= (array[x]->maxpocet*2);
          Transakce **temp = new Transakce * [vetsi];
  for(int i=0;i<array[x]->maxpocet;i++)
      {temp[i]=this->array[x]->poleT[i]; }
   delete [] array[x]->poleT;
   this->array[x]->poleT=temp;
   array[x]->maxpocet*= 2;}
bool  CBank::Transaction  ( const char * debAccID,const char * credAccID,int amount,const char * signature ){
       int deb=HledejAcc(debAccID);
     int cred=HledejAcc(credAccID);
 if ( strcmp (debAccID,credAccID)==0) {
      // cout<<"stejne"<<endl;
       return false; }  
    else if(deb==-1 || cred==-1){
          //cout<<"neexistuje"<<endl;
     return false; }
    else if(deb!=-1 && cred!=-1)
{
     if(array[cred]->Trans==array[cred]->maxpocet){
       ReallocTransaction(cred);
      /* int vetsi= (array[cred]->maxpocet*2);
           Transakce **temp = new Transakce * [vetsi];

   for(int i=0;i<array[cred]->maxpocet;i++)
       {temp[i]=this->array[cred]->poleT[i]; }
    delete [] array[cred]->poleT;
    this->array[cred]->poleT=temp;
       array[cred]->maxpocet*= 2;*/
    } 
   if(array[deb]->Trans==array[deb]->maxpocet){
           ReallocTransaction(deb);
         /*  int vetsi= array[deb]->maxpocet*2;

   Transakce **temp = new Transakce * [vetsi];
   for(int i=0;i<array[deb]->maxpocet;i++)
       {temp[i]=this->array[deb]->poleT[i]; }
     delete [] array[deb]->poleT;
    this->array[deb]->poleT=temp;
        array[deb]->maxpocet*= 2;
         // memcpy (temp, array, maxpocet *sizeof(person **));
      //  temp=array;
         //   struct person **array = new struct person * [maxpocet];
       //for(int i=0;i<maxpocet;i++)      {      array[i]=temp[i];      }
          // for(int i=(maxpocet/2);i<maxpocet;i++){    array[i]=new person;}  
        // memcpy (array, temp, (maxpocet/2) *sizeof(person **));
     //   delete [] temp; */ 
       }
     
     if(this->Cbankcounter[0]>1)
      {
       vytvorpole();
      }
     if(array[deb]->counter>1){
     CopyAccount(deb);
      }
      if(array[cred]->counter>1){
     CopyAccount(cred);
      }
       array[deb]-> Balance-=amount;
       array[cred]-> Balance+=amount;
       int counter=2;
Transakce * point = new Transakce (debAccID,credAccID,amount,signature,counter);
       array[deb]->poleT[array[deb]->Trans]=point;
    array[cred]->poleT[array[cred]->Trans]=point;
   array[deb]->Trans++;
      array[cred]->Trans++;
      return true;
    }
     else{
     // cout<<"neosetrena vzjimka"<<endl;
     } return true;
  }
CBank::CBank() {
       this->posledni=0;
       this->maxpocet=10; 
       int *foo = new int[1];
       this->Cbankcounter=foo;
       this->Cbankcounter[0]=1;
       this->umisteni=-1;
             // struct person **array = new struct person * [maxpocet];
 }   
CBank::~CBank() {
 if(this->Cbankcounter[0]>1){
     this->Cbankcounter[0]--;
 }
 else{
 for(int i=0;i<posledni;i++){
     if(array[i]->counter==0){
         
        for(int p=0;p<array[i]->Trans;p++){
           array[i]->poleT[p]->Rozpust();
      }
       delete [] array[i]->accID;
 delete [] array[i];
      }
else{
  array[i]->counter--;
  
}
 }
 delete [] array;
 }
} 
void odstran(){
 
 
 }
void CBank::CopyAccount(int x){
 person *temp=new struct person;
temp->Balance=array[x]->Balance;
temp->initialBalance=array[x]->initialBalance;
temp->counter=1;
temp->maxpocet=array[x]->maxpocet;
temp->Trans=array[x]->Trans;
Transakce **tempTrans = new Transakce * [array[x]->maxpocet];
for(int i=0;i<array[x]->Trans;i++){
  //tempTrans[i]=new Transakce;
 //Transakce * point = new Transakce;
  //tempTrans[i]=new Transakce;
  tempTrans[i]=array[x]->poleT[i];
  array[x]->poleT[i]->Counter();
  // tempTrans[i][0].Rozpust();
}
temp->poleT=tempTrans;
temp->accID=new char[strlen(array[x]->accID)+1];
strcpy (temp->accID,array[x]->accID);
array[x]=temp;
}
bool CBank::NewAccount(const char* accID, int initialBalance){
    int p=HledejAcc(accID);
    if(p==-1){
      if(posledni==maxpocet)
    {
        realloc();
    }
    if(this->Cbankcounter[0]>1)
      {
          vytvorpole();
      }
      
array[posledni]=new person;
array[posledni]-> accID=new char[strlen(accID)+1];
strcpy (array[posledni]-> accID,accID);
 //Transakce **poleT = new Transakce * [100];
 array[posledni]-> Balance=initialBalance;
 array[posledni]-> initialBalance=initialBalance;
 array[posledni]-> counter=1;
 array[posledni]->Trans=0;
 array[posledni]->maxpocet=10;
 posledni++;
 return true;
    }else if(p>=0)
    {
       // cout<<"uz takovz existuje"<<endl;
     return false;
    }
    else{
    // cout<<"neosetrena vyjimka na 182"<<endl;
        return false;
    }
  return true;    //realloc();
  }
bool CBank::TrimAccount(const char *accID){
     if(HledejAcc(accID)==-1){
     // cout<<"ucet neexistuje"<<endl;
      return false;
      }
       if(this->Cbankcounter[0]>1)
      { vytvorpole(); }
     if(array[umisteni]->counter>1){
      CopyAccount(umisteni);}
     else{ 
      for(int i=0;i<(array[umisteni]->Trans);i++)   
     {array[umisteni]->poleT[i]->Rozpust();}
     array[umisteni]->Trans=0;
     delete [] array[umisteni]->poleT;
     array[umisteni]->initialBalance=array[umisteni]->Balance;
     Transakce **poleT = new Transakce * [100];
     array[umisteni]->poleT=poleT;
      // cout<<"refreshnuto"<<endl;
       return true;
     }return true;
}
ostream& operator<<(ostream& os,  const CBank& x){
   if(x.umisteni==-1){
      //cout<<"chyba"<<endl; 
  //throw  (50);
   }
    else{
   os<< x.array[x.umisteni]->accID<<":"<<endl;
   os<<"   " <<   x.array[x.umisteni]->initialBalance<<endl;
   for(int i=0;i<x.array[x.umisteni]->Trans;i++)
   {
   x.array[x.umisteni]->poleT[i]->Out(x.array[x.umisteni]->accID);
   }
     os<<" = "<< x.array[x.umisteni]->Balance; 
   return os;
    }
}
CBank CBank::operator=(CBank &bank) {
   for(int i=0;i<posledni;i++){
 delete [] array[i];}
 delete [] array;
 
 //delete this;
 array=bank.array;
 Cbankcounter=bank.Cbankcounter;
 bank.Cbankcounter[0]+=2;
 maxpocet=bank.maxpocet;  
 posledni=bank.posledni;
umisteni=bank.umisteni;
 
return *this;
}
CBank::CBank(CBank &bank) {
     
  for(int i=0;i<posledni;i++){
 delete [] array[i];}
 delete [] array;
 
    // delete this;
 array=bank.array;
 Cbankcounter=bank.Cbankcounter;
 bank.Cbankcounter[0]++;
 maxpocet=bank.maxpocet;  
 posledni=bank.posledni;
umisteni=bank.umisteni;
}
#ifndef __PROGTEST__
int main(int argc, char** argv) {
 
bool status;
int  balance;
char accCpy[100], debCpy[100], credCpy[100], signCpy[100];
CBank a;
status = a . NewAccount ( "123456", 1000 );
 // status = true
status = a . NewAccount ( "987654", -500 );
 // status = true
status = a . Transaction ( "123456", "987654", 300, "XAbG5uKz6E=" );
 // status = true
status = a . Transaction ( "123456", "987654", 2890, "AbG5uKz6E=" );
 // status = true
status = a . NewAccount ( "111111", 5000 );
 // status = true
status = a . Transaction ( "111111", "987654", 290, "Okh6e+8rAiuT5=" );
 // status = true
balance = a . Account ( "123456" ). Balance ( );
 // balance = -2190
balance = a . Account ( "987654" ). Balance ( );
 // balance = 2980
balance = a . Account ( "111111" ). Balance ( );
 // balance = 4710
cout << a . Account ( "123456" );
/*
---8<---8<---8<---8<---8<---8<---8<---
123456:
   1000
 - 300, to: 987654, sign: XAbG5uKz6E=
 - 2890, to: 987654, sign: AbG5uKz6E=
 = -2190
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << a . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   -500
 + 300, from: 123456, sign: XAbG5uKz6E=
 + 2890, from: 123456, sign: AbG5uKz6E=
 + 290, from: 111111, sign: Okh6e+8rAiuT5=
 = 2980
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << a . Account ( "111111" );
/*
---8<---8<---8<---8<---8<---8<---8<---
111111:
   5000
 - 290, to: 987654, sign: Okh6e+8rAiuT5=
 = 4710
---8<---8<---8<---8<---8<---8<---8<---
*/
status = a . TrimAccount ( "987654" );
 // status = true
status = a . Transaction ( "111111", "987654", 123, "asdf78wrnASDT3W" );
 // status = true
cout << a . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   2980
 + 123, from: 111111, sign: asdf78wrnASDT3W
 = 3103
---8<---8<---8<---8<---8<---8<---8<---
*/
 
CBank c;
strncpy ( accCpy, "123456", sizeof ( accCpy ) );
status = c . NewAccount ( accCpy, 1000 );
 // status = true
strncpy ( accCpy, "987654", sizeof ( accCpy ) );
status = c . NewAccount ( accCpy, -500 );
 // status = true
strncpy ( debCpy, "123456", sizeof ( debCpy ) );
strncpy ( credCpy, "987654", sizeof ( credCpy ) );
strncpy ( signCpy, "XAbG5uKz6E=", sizeof ( signCpy ) );
status = c . Transaction ( debCpy, credCpy, 300, signCpy );
 // status = true
strncpy ( debCpy, "123456", sizeof ( debCpy ) );
strncpy ( credCpy, "987654", sizeof ( credCpy ) );
strncpy ( signCpy, "AbG5uKz6E=", sizeof ( signCpy ) );
status = c . Transaction ( debCpy, credCpy, 2890, signCpy );
 // status = true
strncpy ( accCpy, "111111", sizeof ( accCpy ) );
status = c . NewAccount ( accCpy, 5000 );
 // status = true
strncpy ( debCpy, "111111", sizeof ( debCpy ) );
strncpy ( credCpy, "987654", sizeof ( credCpy ) );
strncpy ( signCpy, "Okh6e+8rAiuT5=", sizeof ( signCpy ) );
status = c . Transaction ( debCpy, credCpy, 2890, signCpy );
 // status = true
balance = c . Account ( "123456" ). Balance ( );
 // balance = -2190
balance = c . Account ( "987654" ). Balance ( );
 // balance = 5580
balance = c . Account ( "111111" ). Balance ( );
 // balance = 2110
cout << c . Account ( "123456" );
/*
---8<---8<---8<---8<---8<---8<---8<---
123456:
   1000
 - 300, to: 987654, sign: XAbG5uKz6E=
 - 2890, to: 987654, sign: AbG5uKz6E=
 = -2190
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << c . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   -500
 + 300, from: 123456, sign: XAbG5uKz6E=
 + 2890, from: 123456, sign: AbG5uKz6E=
 + 2890, from: 111111, sign: Okh6e+8rAiuT5=
 = 5580
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << c . Account ( "111111" );
/*
---8<---8<---8<---8<---8<---8<---8<---
111111:
   5000
 - 2890, to: 987654, sign: Okh6e+8rAiuT5=
 = 2110
---8<---8<---8<---8<---8<---8<---8<---
*/
status = c . TrimAccount ( "987654" );
 // status = true
strncpy ( debCpy, "111111", sizeof ( debCpy ) );
strncpy ( credCpy, "987654", sizeof ( credCpy ) );
strncpy ( signCpy, "asdf78wrnASDT3W", sizeof ( signCpy ) );
status = c . Transaction ( debCpy, credCpy, 123, signCpy );
 // status = true
cout << c . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   5580
 + 123, from: 111111, sign: asdf78wrnASDT3W
 = 5703
---8<---8<---8<---8<---8<---8<---8<---
*/
 
CBank e;
status = e . NewAccount ( "123456", 1000 );
 // status = true
status = e . NewAccount ( "987654", -500 );
 // status = true
status = e . NewAccount ( "123456", 3000 );
 // status = false
status = e . Transaction ( "123456", "666", 100, "123nr6dfqkwbv5" );
 // status = false
status = e . Transaction ( "666", "123456", 100, "34dGD74JsdfKGH" );
 // status = false
status = e . Transaction ( "123456", "123456", 100, "Juaw7Jasdkjb5" );
 // status = false
balance = e . Account ( "666" ). Balance ( );
 // exception thrown
cout << e . Account ( "666" );
 // exception thrown
status = e . TrimAccount ( "666" );
 // status = false
 
CBank g;
status = g . NewAccount ( "123456", 1000 );
 // status = true
status = g . NewAccount ( "987654", -500 );
 // status = true
status = g . Transaction ( "123456", "987654", 300, "XAbG5uKz6E=" );
 // status = true
status = g . Transaction ( "123456", "987654", 2890, "AbG5uKz6E=" );
 // status = true
status = g . NewAccount ( "111111", 5000 );
 // status = true
status = g . Transaction ( "111111", "987654", 2890, "Okh6e+8rAiuT5=" );
 // status = true
CBank h ( g );
status = g . Transaction ( "111111", "987654", 123, "asdf78wrnASDT3W" );
 // status = true
status = h . Transaction ( "111111", "987654", 789, "SGDFTYE3sdfsd3W" );
 // status = true
status = g . NewAccount ( "99999999", 7000 );
 // status = true
status = g . Transaction ( "111111", "99999999", 3789, "aher5asdVsAD" );
 // status = true
status = g . TrimAccount ( "111111" );
 // status = true
status = g . Transaction ( "123456", "111111", 221, "Q23wr234ER==" );
 // status = true
cout << g . Account ( "111111" );
 cout << "JOOOOOOOOOOOOOOOOOO" <<endl;
/*
---8<---8<---8<---8<---8<---8<---8<---
111111:
   -1802
 + 221, from: 123456, sign: Q23wr234ER==
 = -1581
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << g . Account ( "99999999" );
/*
---8<---8<---8<---8<---8<---8<---8<---
99999999:
   7000
 + 3789, from: 111111, sign: aher5asdVsAD
 = 10789
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << g . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   -500
 + 300, from: 123456, sign: XAbG5uKz6E=
 + 2890, from: 123456, sign: AbG5uKz6E=
 + 2890, from: 111111, sign: Okh6e+8rAiuT5=
 + 123, from: 111111, sign: asdf78wrnASDT3W
 = 5703
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << h . Account ( "111111" );
/*
---8<---8<---8<---8<---8<---8<---8<---
111111:
   5000
 - 2890, to: 987654, sign: Okh6e+8rAiuT5=
 - 789, to: 987654, sign: SGDFTYE3sdfsd3W
 = 1321
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << h . Account ( "99999999" );
 // exception thrown
cout << h . Account ( "987654" );
/*
---8<---8<---8<---8<---8<---8<---8<---
987654:
   -500
 + 300, from: 123456, sign: XAbG5uKz6E=
 + 2890, from: 123456, sign: AbG5uKz6E=
 + 2890, from: 111111, sign: Okh6e+8rAiuT5=
 + 789, from: 111111, sign: SGDFTYE3sdfsd3W
 = 6369
---8<---8<---8<---8<---8<---8<---8<---
*/
 cout << "JOOOOOOOOOOOOOOOOOO" <<endl;
CBank i;
CBank j;
status = i . NewAccount ( "123456", 1000 );
 // status = true
status = i . NewAccount ( "987654", -500 );
 // status = true
status = i . Transaction ( "123456", "987654", 300, "XAbG5uKz6E=" );
 // status = true
status = i . Transaction ( "123456", "987654", 2890, "AbG5uKz6E=" );
 // status = true
status = i . NewAccount ( "111111", 5000 );
 // status = true
status = i . Transaction ( "111111", "987654", 2890, "Okh6e+8rAiuT5=" );
 // status = true
j = i;
status = i . Transaction ( "111111", "987654", 123, "asdf78wrnASDT3W" );
 // status = true
status = j . Transaction ( "111111", "987654", 789, "SGDFTYE3sdfsd3W" );
 // status = true
status = i . NewAccount ( "99999999", 7000 );
 // status = true
status = i . Transaction ( "111111", "99999999", 3789, "aher5asdVsAD" );
 // status = true
status = i . TrimAccount ( "111111" );
 // status = true
cout << i . Account ( "111111" );
/*
---8<---8<---8<---8<---8<---8<---8<---
111111:
   -1802
 = -1802
---8<---8<---8<---8<---8<---8<---8<---
*/
cout << j . Account ( "111111" );
  return 0;
}

#endif /* __PROGTEST__ */




