//***************************************************************************
// File name:  PacString.h
// Author:     
// Date:       2/3/2017
// Class:      CS485
// Assignment: Dynamic Memory Lab
// Purpose:    Practice using raw pointers
//***************************************************************************

#include "PacString.h"
#include <string.h>

using namespace std;

PacString::PacString ()
{
}

PacString::~PacString ()
{
  if (nullptr != mpszData)
  {
    cout << "dtor\n";
    delete[]mpszData;
  }

}

PacString::PacString (const char *pszString)
{
  cout << "cctor\n";
  char *pcNew = new char[strlen (pszString) + 1];
  mpszData = pcNew; new char[strlen (pszString) + 1];
  //strcpy(mpszData, pszString);
  strncpy_s (mpszData, strlen (pszString) + 1, pszString, strlen (pszString) + 1);
  //mpszData[strlen (pszString)];// = '\0';
}

PacString::PacString (const PacString &rcData)
{
  char *pcNew = new char[strlen (rcData.mpszData) + 1];
  mpszData = pcNew;//new char[strlen (rcData.mpszData)];
  //strcpy(mpszData, rcData.mpszData);
  strncpy_s (mpszData, strlen (rcData.mpszData) + 1, rcData.mpszData,
    strlen (rcData.mpszData) + 1);
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
  out << rcData.mpszData;

  return out;
}

PacString& PacString::operator=(PacString rcData)
{
  delete[]mpszData;
  //char *pcNew = new char[strlen (rcData.mpszData) + 1];
  mpszData = new char[strlen (rcData.mpszData) + 1];
  //pcNew = rcData.mpszData;
  mpszData = rcData.mpszData;
  return mpszData;
}

//PacString& PacString::operator=(const PacString &rcData)
//{
//	if (mpszData != nullptr)
//	{
//		delete(mpszData);
//	}
//	mpszData = new char[strlen (rcData.mpszData)];
//	strncpy_s (mpszData, strlen (rcData.mpszData), rcData.mpszData,
//		strlen (rcData.mpszData));
//
//  return PacString();
//}

PacString& PacString::operator+=(const PacString &rcData)
{
  char * concat = new char[strlen (mpszData) + strlen (rcData.mpszData) + 1];
  concat[0];// = '\0';

  strcat_s (concat, strlen (mpszData) + strlen (rcData.mpszData) + 1, mpszData);

  strcat_s (concat, strlen (mpszData)
    + strlen (rcData.mpszData) + 1, rcData.mpszData);

  delete []mpszData;
  mpszData = concat;

  return PacString (concat);
}

PacString PacString::operator+(const PacString &rcData) const
{
  char *concat = new char[strlen (mpszData) + strlen (rcData.mpszData) + 1];
  concat[0] = '\0';

  strcat_s (concat, sizeof (mpszData) /*strlen (mpszData) + strlen (rcData.mpszData) + 1*/, mpszData);
  strcat_s (concat, sizeof (mpszData) + sizeof (rcData.mpszData), rcData.mpszData);

  //strcat_s (concat, strlen (mpszData)
    //+ strlen (rcData.mpszData) + 1, rcData.mpszData);

  return PacString (concat);
  //return PacString (concat);
}
