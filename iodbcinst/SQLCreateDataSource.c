/*
 *  SQLCreateDataSource.c
 *
 *  $Id$
 *
 *  Add, modify or delete datasources
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

#include "iodbc_error.h"

extern BOOL ValidDSN (LPCSTR lpszDSN);
extern SQLRETURN iodbcdm_drvconn_dialbox(HWND, LPSTR, DWORD, int FAR*);

BOOL CreateDataSource (HWND parent, LPCSTR lpszDSN)
{
  char dsn[1024] = { 0 };

  iodbcdm_drvconn_dialbox (parent, dsn, sizeof (dsn), NULL);

  return TRUE;
}


BOOL INSTAPI
SQLCreateDataSource (HWND hwndParent, LPCSTR lpszDSN)
{
  BOOL retcode = FALSE;

  /* Check input parameters */
  CLEAR_ERROR ();
  if (!hwndParent)
    {
      PUSH_ERROR (ODBC_ERROR_INVALID_HWND);
      goto quit;
    }

  if ((!lpszDSN && !ValidDSN (lpszDSN)) || (!lpszDSN && !STRLEN (lpszDSN)))
    {
      PUSH_ERROR (ODBC_ERROR_INVALID_DSN);
      goto quit;
    }

  retcode = CreateDataSource (hwndParent, lpszDSN);

quit:
  return retcode;
}
