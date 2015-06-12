//
//  main.cpp
//  cc1.1
//
//  Created by likexin on 15/6/9.
//  Copyright (c) 2015年 likexin. All rights reserved.
//

#include <iostream>
#include "myhash.h"
int main() {
    // insert code here...
    //{key,ord}
    Elemtype r[12]={{1,1},{2,9},{3,4},{4,1},{5,10},{6,11},{7,13},{8,8},{9,7},{10,12},{11,16},{12,25}};
    HashTable H;
    int i,p,j;
    KeyType k;
    H.Init_HashTable();
    
    for (i=0; i<11; i++)
    {
        j=H.Insert_Hash(r[i]);
        if(j==-1)
            cout<<"already exist"<<endl;
        
    }

    H.Traverse_HashTable();
    cout<<"please type in the key"<<endl;
    cin>>k;
    j=H.Search_Hash(k, p);
    if(j==1)
        H.Get_Data(p);
    else
        cout<<"not record"<<endl;
    
    j=H.Insert_Hash(r[11]);
    if(j==0)
    {
        cout<<"insert failed"<<endl;
        H.Insert_Hash(r[i]);
    }
    H.Traverse_HashTable();
    
    cout<<"please type in the key"<<endl;
    cin>>k;
    j=H.Search_Hash(k, p);
    if(j==1)
        H.Get_Data(p);
    else
        cout<<"not record"<<endl;
    
    cout<<"destroy hash table"<<endl;
    H.Destroy_HashTable();
    
    return 0;
    
    
}
