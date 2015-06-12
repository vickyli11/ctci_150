//
//  myhash.h
//  cc1.1
//
//  Created by likexin on 15/6/9.
//  Copyright (c) 2015年 likexin. All rights reserved.
//

#ifndef cc1_1_myhash_h
#define cc1_1_myhash_h

#include <iostream>

using namespace std;

typedef int KeyType;
const int NULLKEY = 0;
int c = 0;

struct Elemtype{
    KeyType key;
    int ord;
};

int hashsize[] = {11,19,29,37,47};
int Hash_length = 0;

class HashTable
{
private:
    Elemtype *elem;
    int count;                                  // number of element
    int size;                                   //the volume of hash table
    
public:
    int Init_HashTable()
    {
        int i;
        count = 0;
        size = 0;
        Hash_length = hashsize[0];              //11
        elem = new Elemtype[Hash_length];
        
        if(!elem){
            cout<<"fail to apply"<<endl;
            exit(0);
        }
        
        for(i=0;i<Hash_length;i++){
            elem[i].key=NULLKEY;                 //keytype key = 0
        }
        cout<<"init hash table"<<endl;
        return 1;
    }
    
    void Destroy_HashTable()
    {
        delete[]elem;
        elem=NULL;
        count = 0;
        size = 0;
    }
    
    unsigned Hash(KeyType k)
    {
        return k%Hash_length;
    }
    void Collision(int &p, int d)
    {
        p=(p+d)%Hash_length;
    }
    bool Search_Hash(KeyType k, int &p)
    {
        c=0;
        p=Hash(k);
        //cout<<"p is "<<p<<endl;
        while(elem[p].key!=NULLKEY && elem[p].key!=k)
        {
            c++;
            if(c<Hash_length)
                Collision(p, c);                //p=(p+c)%Hash_length
            else
                return 0;
        }
        if(elem[p].key == k)
            return 1;
        else
            return 0;
    }
    int Insert_Hash(Elemtype e)
    {
        int p;
        if(Search_Hash(e.key, p))
            return -1;
        else if (c<hashsize[size])
        {
            elem[p]=e;
            count++;
            return 1;
        }
        else
            ReCreat_HashTable();
        return 0;
    }
    void ReCreat_HashTable()
    {
        int i, count2=count;
        Elemtype *p, *elem2 = new Elemtype[Hash_length];
        p=elem2;
        cout<<"___rebuilt hash table"<<endl;
        for(i=0;i<Hash_length;i++)
        {
            if(elem[i].key!=NULL)
                *p++ = *(elem+1);
        }
        count = 0;
        size++;
        Hash_length=hashsize[size];
        p=new Elemtype[Hash_length];
        if (!p) {
            cout<<"faill to apply"<<endl;
            exit(0);
        }
        elem=p;
        for(i=0;i<Hash_length;i++)
            elem[i].key=NULLKEY;
        for (p=elem2; p<elem2+count; p++) {
            Insert_Hash(*p);
        }
    }
    void Traverse_HashTable()
    {
        cout<<"hash address 0 ->"<<Hash_length<<endl;
        for(int i=0; i<Hash_length; i++)
            if(elem[i].key!=NULLKEY)
                cout<<"key is "<<elem[i].key<<", ord is "<<elem[i].ord<<endl;
        
    }
    void Get_Data(int p)
    {
        cout<<elem[p].ord<<endl;
    }
};
#endif
