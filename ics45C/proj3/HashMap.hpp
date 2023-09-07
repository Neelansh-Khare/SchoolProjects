#ifndef HASHMAP_HPP
#define HASHMAP_HPP

#include <iostream> //This was for testing output to see what was contained in each Nodelist as I created and tested HashMap
//Can comment above line out for final version

#include <functional> // To make functions as vaRiables
#include <string> //for strings
#include "Hashfunction.hpp" // A collection of Hashfunctions to set hasher equal to, default is ELFHash


class HashMap
{
public:
    
    typedef std::function<unsigned int(const std::string&)> HashFunction; 

    
    static constexpr unsigned int initialBucketCount = 10;


public:
   
    HashMap();

   
    HashMap(HashFunction hasher);

    HashMap(const HashMap& hm);
    ~HashMap();
    HashMap& operator=(const HashMap& hm);
    
    void add(const std::string& key, const std::string& value);

  
    void remove(const std::string& key);

    bool contains(const std::string& key) const;

    
    std::string value(const std::string& key) const;

    // size() returns the number of key/value pairs stored in this HashMap.
    unsigned int size() const;

    unsigned int bucketCount() const;

    
    double loadFactor() const;

    
    unsigned int maxBucketSize() const;
    //EDIT 
    void output() const; //outputs each node, first give its index and then gives all of its key,value pairs as outputs
private:

    struct Node
    {
        std::string key;
        std::string value;
        Node* next;
    };

     
    HashFunction hasher;
    
    Node** buckets;
    unsigned int bucketTotal; 
    unsigned int tableSize; //Number of ALL key value pairs in the hashMap, can grow and shrink
    void reHash(); //Increases total number of buckets and rehashes each key into a new or different bucket 
    //if necessary
    unsigned int getBucketLength(unsigned int index) const; //Amount of nodes in a linked list
    unsigned int applyHash(const std::string &key) const; //Find the bucket that a key should go to, is dependent 
    // on bucketTotal or number of buckets in a HashMap
    void setBuckets(); //Initializes all buckets in the HashMap due to bucketTotal, each bucket starts as a nullptr
    void destroyNode(Node* node);
    //Deallocation of one singly linked list
    //EDITS END HERE


    // You will no doubt need to add at least a few more private members
};

#endif // HASHMAP_HPP

