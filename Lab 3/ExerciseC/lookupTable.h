/*
 * File Name: lookupTable.h
 * Assignment: Lab 3 Exercise C
 * Lab Section: B01
 * Completed by: Chloe Choi, Joshua Geng
 * Submission Date: Sept 27, 2024
 */

#ifndef LOOKUPTABLE_H
#define LOOKUPTABLE_H
#include <iostream>
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

template <class TKey, class TDat>
class LookupTable;

typedef int LT_Key;
typedef Customer LT_Datum;

template <class TKey, class TDat>
struct Pair
{
  Pair(TKey keyA, TDat datumA) : key(keyA), datum(datumA) {} // Constructor

  TKey key;
  TDat datum;
};

template <class TKey, class TDat>
class LT_Node
{
  friend class LookupTable<TKey, TDat>;

private:
  Pair<TKey, TDat> pairM;
  LT_Node<TKey, TDat> *nextM;

  // This ctor should be convenient in insert and copy operations.
  LT_Node(const Pair<TKey, TDat> &pairA, LT_Node<TKey, TDat> *nextA);
};

template <class TKey, class TDat>
class LookupTable
{
public:
  // Nested class
  class Iterator
  {
    friend class LookupTable;
    LookupTable *LT;
    //    LT_Node* cursor;

  public:
    Iterator() : LT(0) {}
    Iterator(LookupTable &x) : LT(&x) {}
    const TDat &operator*();
    const TDat &operator++();
    const TDat &operator++(int);
    int operator!();

    void step_fwd()
    {
      assert(LT->cursor_ok());
      LT->step_fwd();
    }
  };

  LookupTable();
  LookupTable(const LookupTable &source);
  LookupTable &operator=(const LookupTable &rhs);
  ~LookupTable();

  LookupTable &begin();

  int size() const;
  // PROMISES: Returns number of keys in the table.

  int cursor_ok() const;
  // PROMISES:
  //   Returns 1 if the cursor is attached to a key/datum pair,
  //   and 0 if the cursor is in the off-list state.

  const TKey &cursor_key() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns key of key/datum pair to which cursor is attached.

  const TDat &cursor_datum() const;
  // REQUIRES: cursor_ok()
  // PROMISES: Returns datum of key/datum pair to which cursor is attached.

  void insert(const Pair<TKey, TDat> &pariA);
  // PROMISES:
  //   If keyA matches a key in the table, the datum for that
  //   key is set equal to datumA.
  //   If keyA does not match an existing key, keyA and datumM are
  //   used to create a new key/datum pair in the table.
  //   In either case, the cursor goes to the off-list state.

  void remove(const TKey &keyA);
  // PROMISES:
  //   If keyA matches a key in the table, the corresponding
  //   key/datum pair is removed from the table.
  //   If keyA does not match an existing key, the table is unchanged.
  //   In either case, the cursor goes to the off-list state.

  void find(const TKey &keyA);
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

  // friend ostream &operator<<(ostream &os, const LookupTable<T, TKey> &lt);

private:
  int sizeM;
  LT_Node<TKey, TDat> *headM;
  LT_Node<TKey, TDat> *cursorM;

  void destroy();
  // Deallocate all nodes, set headM to zero.

  void copy(const LookupTable &source);
  // Establishes *this as a copy of source.  Cursor of *this will
  // point to the twin of whatever the source's cursor points to.
};

#endif

template <class TKey, class TDat>
LookupTable<TKey, TDat> &LookupTable<TKey, TDat>::begin()
{
  cursorM = headM;
  return *this;
}

template <class TKey, class TDat>
LT_Node<TKey, TDat>::LT_Node(const Pair<TKey, TDat> &pairA, LT_Node<TKey, TDat> *nextA)
    : pairM(pairA), nextM(nextA)
{
}

template <class TKey, class TDat>
LookupTable<TKey, TDat>::LookupTable()
    : sizeM(0), headM(0), cursorM(0)
{
}

template <class TKey, class TDat>
LookupTable<TKey, TDat>::LookupTable(const LookupTable &source)
{
  copy(source);
}

template <class TKey, class TDat>
LookupTable<TKey, TDat> &LookupTable<TKey, TDat>::operator=(const LookupTable<TKey, TDat> &rhs)
{
  if (this != &rhs)
  {
    destroy();
    copy(rhs);
  }
  return *this;
}

template <class TKey, class TDat>
LookupTable<TKey, TDat>::~LookupTable()
{
  destroy();
}

template <class TKey, class TDat>
int LookupTable<TKey, TDat>::size() const
{
  return sizeM;
}

template <class TKey, class TDat>
int LookupTable<TKey, TDat>::cursor_ok() const
{
  return cursorM != 0;
}

template <class TKey, class TDat>
const TKey &LookupTable<TKey,TDat>::cursor_key() const
{
  assert(cursor_ok());
  return cursorM->pairM.key;
}

template <class TKey, class TDat>
const TDat &LookupTable<TKey, TDat>::cursor_datum() const
{
  assert(cursor_ok());
  return cursorM->pairM.datum;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::insert(const Pair<TKey, TDat> &pairA)
{
  // Add new node at head?
  if (headM == 0 || pairA.key < headM->pairM.key)
  {
    headM = new LT_Node<TKey, TDat>(pairA, headM);
    sizeM++;
  }

  // Overwrite datum at head?
  else if (pairA.key == headM->pairM.key)
    headM->pairM.datum = pairA.datum;

  // Have to search ...

  else
  {
    LT_Node<TKey, TDat> *before = headM;
    LT_Node<TKey, TDat> *after = headM->nextM;

    while (after != NULL && (pairA.key > after->pairM.key))
    {
      before = after;
      after = after->nextM;
    }

    if (after != NULL && pairA.key == after->pairM.key)
    {
      after->pairM.datum = pairA.datum;
    }
    else
    {
      before->nextM = new LT_Node<TKey, TDat>(pairA, before->nextM);
      sizeM++;
    }
  }
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::remove(const TKey &keyA)
{

  if (headM == 0 || keyA < headM->pairM.key)
    return;

  LT_Node<TKey, TDat> *doomed_node = 0;
  if (keyA == headM->pairM.key)
  {
    doomed_node = headM;
    headM = headM->nextM;
    sizeM--;
  }
  else
  {
    LT_Node<TKey, TDat> *before = headM;
    LT_Node<TKey, TDat> *maybe_doomed = headM->nextM;
    while (maybe_doomed != 0 && keyA > maybe_doomed->pairM.key)
    {
      before = maybe_doomed;
      maybe_doomed = maybe_doomed->nextM;
    }

    if (maybe_doomed != 0 && maybe_doomed->pairM.key == keyA)
    {
      doomed_node = maybe_doomed;
      before->nextM = maybe_doomed->nextM;
      sizeM--;
    }
  }
  delete doomed_node; // Does nothing if doomed_node == 0.
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::find(const TKey &keyA)
{
  LT_Node<TKey, TDat> *ptr = headM;
  while (ptr != NULL && ptr->pairM.key != keyA)
  {
    ptr = ptr->nextM;
  }

  cursorM = ptr;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::go_to_first()
{
  cursorM = headM;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::step_fwd()
{
  assert(cursor_ok());
  cursorM = cursorM->nextM;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::make_empty()
{
  destroy();
  sizeM = 0;
  cursorM = 0;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::destroy()
{

  LT_Node<TKey, TDat> *ptr = headM;
  while (ptr != NULL)
  {
    headM = headM->nextM;
    delete ptr;
    ptr = headM;
  }
  cursorM = NULL;
  sizeM = 0;
}

template <class TKey, class TDat>
void LookupTable<TKey, TDat>::copy(const LookupTable<TKey, TDat> &source)
{

  headM = 0;
  cursorM = 0;

  if (source.headM == 0)
    return;

  for (LT_Node<TKey, TDat> *p = source.headM; p != 0; p = p->nextM)
  {
    insert(Pair<TKey, TDat>(p->pairM.key, p->pairM.datum));
    if (source.cursorM == p)
      find(p->pairM.key);
  }
}

template <class TKey, class TDat>
ostream &operator<<(ostream &os, const LookupTable<TKey, TDat> &lt)
{
  if (lt.cursor_ok())
    os << lt.cursor_key() << "  " << lt.cursor_datum();
  else
    os << "Not Found.";

  return os;
}

template <class TKey, class TDat>
const TDat &LookupTable<TKey, TDat>::Iterator::operator*()
{
  assert(LT->cursor_ok());
  return LT->cursor_datum();
}

template <class TKey, class TDat>
const TDat &LookupTable<TKey, TDat>::Iterator::operator++()
{
  assert(LT->cursor_ok());
  const TDat &x = LT->cursor_datum();
  LT->step_fwd();
  return x;
}

template <class TKey, class TDat>
const TDat &LookupTable<TKey, TDat>::Iterator::operator++(int)
{
  assert(LT->cursor_ok());

  LT->step_fwd();
  return LT->cursor_datum();
}

template <class TKey, class TDat>
int LookupTable<TKey, TDat>::Iterator::operator!()
{
  return (LT->cursor_ok());
}
