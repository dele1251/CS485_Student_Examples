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

PacString::PacString(const char *pszString)
{
	mpszData = new char[strlen(pszString)];
	//strcpy(mpszData, pszString);
	strncpy_s(mpszData, strlen(pszString), pszString, strlen(pszString));
}

PacString::PacString(const PacString &rcData)
{
	mpszData = new char[strlen(rcData.mpszData)];
	//strcpy(mpszData, rcData.mpszData);
	strncpy_s(mpszData, strlen(rcData.mpszData), rcData.mpszData, strlen(rcData.mpszData));
}

