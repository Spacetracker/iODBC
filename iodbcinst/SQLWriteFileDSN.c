/*
 *  SQLWriteFileDSN.c
 *
 *  $Id$
 *
 *  These functions intentionally left blank
 *
 *  The iODBC driver manager.
 *
 *  Copyright (C) 2001 by OpenLink Software <iodbc@openlinksw.com>
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Library General Public
 *  License as published by the Free Software Foundation; either
 *  version 2 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Library General Public License for more details.
 *
 *  You should have received a copy of the GNU Library General Public
 *  License along with this library; if not, write to the Free
 *  Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <iodbc.h>
#include <iodbcinst.h>

#include "inifile.h"
#include "iodbc_error.h"
#include "misc.h"

extern BOOL WritePrivateProfileString (LPCSTR lpszSection, LPCSTR lpszEntry,
    LPCSTR lpszString, LPCSTR lpszFilename);

BOOL INSTAPI
SQLWriteFileDSN (LPCSTR lpszFileName, LPCSTR lpszAppName, LPCSTR lpszKeyName,
    LPSTR lpszString)
{
  BOOL retcode = FALSE;

  /* Check input parameters */
  CLEAR_ERROR ();

  /* Is a file is specified */
  if (lpszFileName)
    {
      retcode =
	  WritePrivateProfileString (lpszAppName, lpszKeyName, lpszString,
	  lpszFileName);
      goto quit;
    }

  PUSH_ERROR (ODBC_ERROR_INVALID_PATH);
  goto quit;

quit:
  return retcode;
}
