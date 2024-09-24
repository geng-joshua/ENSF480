// LookupTable.h
// ENSF 480 - Lab 3, Ex C

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
#include <assert.h>
using namespace std;

// class LookupTable: GENERAL CONCEPTS
//
//    key/datum pairs are ordered.  The first pair is the pair with
//    the lowest key, the second pair is the pair with the second
//    lowest key, and so on.  This implies that you must be able to
//    compare two keys with the < operator.
//
//    Each LookupTable has an embedded iterator class that allows users
//    of the class to traverse trhough the list and  have acess to each
//    node. 

#include "customer.h"

//    In this version of the LookupTable a new struct type called Pair
//    is introduced which represents a key/data pair.


typedef int LT_Key; 
typedef Customer LT_Datum;
 
template <class T>
struct Pair 
{
  Pair(LT_Key keyA,T datumA):key(keyA), datum(datumA)
  {
  } 
  
  LT_Key key;
  T datum;
};

// "argument list for class template "Pair" is missing"
// means that want Pair<T>, and to do so need to declare template as
// class T as well. 
template <class T>
class LT_Node {
  friend class LookupTable<T>;
private:
  Pair<T> pairM;
  LT_Node *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<T>& pairA, LT_Node *nextA);
};

template <class T>
class LookupTable {
 public:

  // Nested class
  class Iterator {
    friend class LookupTable ;
    T *LT;
//    LT_Node* cursor;
    
  public:
    Iterator():LT(0){}
    Iterator(T & x): LT(&x){}
    const T&  operator *();
    const T& operator ++();
    const T& operator ++(int);
    int operator !();

    void step_fwd(){  assert(LT->cursor_ok());
    LT->step_fwd();}
  };

  LookupTable();
  LookupTable(const T  & source);
  T& operator =(const T& rhs);
  ~LookupTable();

  T& begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES: 
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const LT_Key& cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const T& cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair& pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const LT_Key& keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the cursor is attached
  //   to the corresponding key/datum pair.
  //   If keyA does not match an existing key, the cursor is put in
  //   the off-list state.

  void go_to_first();
  // PROMISES: If size() > 0, cursor is moved to the first key/datum pair
  //   in the table.

  void step_fwd();
  // REQUIRES: cursor_ok()
  // PROMISES: 
  //   If cursor is at the last key/datum pair in the list, cursor
  //   goes to the off-list state.
  //   Otherwise the cursor moves forward from one pair to the next.

  void make_empty();
  // PROMISES: size() == 0.

  friend  ostream& operator << (ostream& os, const LookuTpTable& lt);

 private:
  int sizeM;
  LT_Node *headM;
  LT_Node *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.
  
  void copy(const T& source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template <class T> 
T& LookupTable<T>::begin(){
  cursorM = headM;
  return *this;
}

LT_Node::LT_Node(const Pair& pairA, LT_Node *nextA)
  : pairM(pairA), nextM(nextA)
{
}

template <class T> 
LookupTable<T>::LookupTable()
  : sizeM(0), headM(0), cursorM(0)
{
}

template <class T> 
LookupTable<T>::LookupTable(const T& source)
{
  copy(source);
}

template <class T>
T& LookupTable<T>::operator =(const T& rhs)
{
  if (this != &rhs) {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <class T>
LookupTable<T>::~LookupTable()
{
  destroy();
}

template <class T>
int LookupTable<T>::size() const
{
  return sizeM;
}

template <class T>
int LookupTable<T>::cursor_ok() const
{
  return cursorM != 0;
}

template <class T>
const LT_Key& LookupTable<T>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class T>
const T& LookupTable<T>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class T>
void LookupTable<T>::insert(const Pair& pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key) {
    headM = new LT_Node(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else {
    LT_Node* before= headM;
    LT_Node* after=headM->nextM;

    while(after!=NULL && (pairA.key > after->pairM.key))
      {
	before=after;
	after=after->nextM;
      }
    
    if(after!=NULL && pairA.key == after->pairM.key)
      {
	after->pairM.datum = pairA.datum;
      }
    else
      {
	before->nextM = new LT_Node (pairA, before->nextM);
	sizeM++;
      }
  }
}

void LookupTable::remove(const LT_Key& keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node* doomed_node = 0;
  if (keyA == headM->pairM.key) {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else {
    LT_Node      *before = headM;
    LT_Node *maybe_doomed = headM->nextM;
    while(maybe_doomed != 0 && keyA > maybe_doomed->pairM.key) {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA) {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }      
  } 
  delete doomed_node;           // Does nothing if doomed_node == 0.
}

void LookupTable::find(const LT_Key& keyA)
{
  LT_Node *ptr=headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
    {
     ptr=ptr->nextM;
    }

   cursorM = ptr;
}

void LookupTable::go_to_first()
{
  cursorM = headM;
}

void LookupTable::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

void LookupTable::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

void LookupTable::destroy()
{

  LT_Node *ptr = headM;
  while (ptr!=NULL)
    {
      headM=headM->nextM;
      delete ptr;
      ptr=headM;

    }
  cursorM = NULL;
  sizeM=0;
}

void LookupTable::copy(const LookupTable& source)
{

  headM=0;
  cursorM =0;

  if(source.headM ==0)
    return;
 
  for(LT_Node *p = source.headM; p != 0; p=p->nextM)
    {
      insert(Pair (p->pairM.key, p->pairM.datum));
      if(source.cursorM == p)
	find(p->pairM.key);
    }

}

ostream& operator <<   (ostream& os, const LookupTable& lt)
{
  if (lt.cursor_ok())
    os <<lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os<<"Not Found.";

  return os;
}

const LT_Datum& LookupTable::Iterator::operator *()
{
  assert(LT ->cursor_ok());
  return LT->cursor_datum();
}

const LT_Datum& LookupTable::Iterator::operator ++()
{
  assert(LT->cursor_ok());
  const LT_Datum & x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

const LT_Datum& LookupTable::Iterator::operator ++(int)
{
  assert(LT->cursor_ok());
 
  LT->step_fwd();
  return LT->cursor_datum();
}

int LookupTable::Iterator::operator!()
{
  return (LT->cursor_ok());
}


