//***************************************************************************
// File name:  bigger.h
// Author:     Chadd Williams
// Date:       1/31/2017
// Class:      CS485
// Assignment: Constructor Examples
// Purpose:    Demonstrate how constructors and assignment operator are called
//***************************************************************************
#pragma once

#include <iostream>

class bigger
{
public:

  bigger ();

  /*explicit*/ bigger (int x); //* dont do explicit will give an error to b7 
                               // because it cant be done inplicitly anymore 
                               // unless static cast 1 as bigger*

                               // ctor, cctor, dtor, and operator will be built automatically

  ~bigger ();

  bigger (const bigger &rcData); // will prevent from making copies of objects if = delete

  bigger& operator= (const bigger &rcData); // control compiler if = delete

private:
  int mData = 0;
  int mID;

  int getID () const;
};
