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

PacString::PacString()
{
}

PacString::~PacString ()
{
}

PacString::PacString(const char *pszString)
{
	mpszData = new char[strlen(pszString) + 1];
	//strcpy(mpszData, pszString);
	strncpy_s(mpszData, strlen(pszString) + 1, pszString, strlen(pszString));
  mpszData[strlen (pszString)] = '\0';
}

PacString::PacString(const PacString &rcData)
{
	mpszData = new char[strlen(rcData.mpszData)];
	//strcpy(mpszData, rcData.mpszData);
	strncpy_s(mpszData, strlen(rcData.mpszData), rcData.mpszData, 
		strlen(rcData.mpszData));
}

std::ostream& operator<<(std::ostream &out, const PacString &rcData)
{
	out << rcData.mpszData;

	return out;
}

PacString& PacString::operator=(PacString rcData)
{
  mpszData = new char[strlen (rcData.mpszData) + 1];
	mpszData = rcData.mpszData;

	return rcData;
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
  concat[0] = '\0';

  strcat_s (concat, strlen (mpszData) + strlen (rcData.mpszData) + 1, mpszData);

  strcat_s (concat, strlen (mpszData)
    + strlen (rcData.mpszData) + 1, rcData.mpszData);

  delete (mpszData);
  mpszData = concat;

  return PacString (concat);
}

PacString PacString::operator+(const PacString &rcData) const
{
  char * concat = new char[strlen (mpszData) + strlen (rcData.mpszData) + 1];
  concat[0] = '\0';

  strcat_s (concat, strlen (mpszData) + strlen (rcData.mpszData) + 1, mpszData);

  strcat_s (concat, strlen (mpszData)
    + strlen (rcData.mpszData) + 1, rcData.mpszData);

  return PacString (concat);
}
