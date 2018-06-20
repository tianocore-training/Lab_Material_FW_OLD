/** @file
  This is a simple shell application

  Copyright (c) 2008-2012, Intel Corporation                                                         
  All rights reserved. This program and the accompanying materials                          
  are licensed and made available under the terms and conditions of the BSD License         
  which accompanies this distribution.  The full text of the license may be found at        
  http://opensource.org/licenses/bsd-license.php                                            

  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,                     
  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.             

**/

#include <Uefi.h>
#include <Library/UefiApplicationEntryPoint.h>
#include <Library/UefiLib.h>
#include <Library/BaseMemoryLib.h>
#include <Library/UefiBootServicesTableLib.h>
#include <Library/DebugLib.h>

#define CHAR_DOT	0x002E    // '.' in Unicode

/**
  as the real entry point for the application.

  @param[in] ImageHandle    The firmware allocated handle for the EFI image.  
  @param[in] SystemTable    A pointer to the EFI System Table.
  
  @retval EFI_SUCCESS       The entry point is executed successfully.
  @retval other             Some error occurs when executing this entry point.

**/
EFI_STATUS
EFIAPI
UefiMain (
  IN EFI_HANDLE        ImageHandle,
  IN EFI_SYSTEM_TABLE  *SystemTable
  )
{
  	UINTN          EventIndex;
	BOOLEAN		   ExitLoop;
    EFI_INPUT_KEY	   Key;

   DEBUG ((0xffffffff, "\n\nUEFI Base Training DEBUG DEMO\n") );
   DEBUG ((0xffffffff, "0xffffffff USING DEBUG ALL Mask Bits Set\r\n") );
   

   DEBUG ((EFI_D_INIT,     " 0x%08x USING DEBUG EFI_D_INIT\r\n" , (UINTN)(EFI_D_INIT))  );
   DEBUG ((EFI_D_WARN,     " 0x%08x USING DEBUG EFI_D_WARN\r\n", (UINTN)(EFI_D_WARN))  );
   DEBUG ((EFI_D_LOAD,     " 0x%08x USING DEBUG EFI_D_LOAD\r\n", (UINTN)(EFI_D_LOAD))  );
   DEBUG ((EFI_D_FS,       " 0x%08x USING DEBUG EFI_D_FS\r\n", (UINTN)(EFI_D_FS))  );
   DEBUG ((EFI_D_POOL,     " 0x%08x USING DEBUG EFI_D_POOL\r\n", (UINTN)(EFI_D_POOL))  );
   DEBUG ((EFI_D_PAGE,     " 0x%08x USING DEBUG EFI_D_PAGE\r\n", (UINTN)(EFI_D_PAGE))  );
   DEBUG ((EFI_D_INFO,     " 0x%08x USING DEBUG EFI_D_INFO\r\n", (UINTN)(EFI_D_INFO))  );
   DEBUG ((EFI_D_DISPATCH, " 0x%08x USING DEBUG EFI_D_DISPATCH\r\n", (UINTN)(EFI_D_DISPATCH))  );
   DEBUG ((EFI_D_VARIABLE, " 0x%08x USING DEBUG EFI_D_VARIABLE\r\n", (UINTN)(EFI_D_VARIABLE))  );
   DEBUG ((EFI_D_BM,       " 0x%08x USING DEBUG EFI_D_BM\r\n", (UINTN)(EFI_D_BM))  );
   DEBUG ((EFI_D_BLKIO,    " 0x%08x USING DEBUG EFI_D_BLKIO\r\n", (UINTN)(EFI_D_BLKIO))  );
   DEBUG ((EFI_D_NET,      " 0x%08x USING DEBUG EFI_D_NET\r\n", (UINTN)(EFI_D_NET))  );
   DEBUG ((EFI_D_UNDI,     " 0x%08x USING DEBUG EFI_D_UNDI\r\n", (UINTN)(EFI_D_UNDI))  );
   DEBUG ((EFI_D_LOADFILE, " 0x%08x USING DEBUG EFI_D_LOADFILE\r\n", (UINTN)(EFI_D_LOADFILE))  );
   DEBUG ((EFI_D_EVENT,    " 0x%08x USING DEBUG EFI_D_EVENT\r\n", (UINTN)(EFI_D_EVENT))  );
   DEBUG ((EFI_D_ERROR,    " 0x%08x USING DEBUG EFI_D_ERROR\r\n", (UINTN)(EFI_D_ERROR))  );

  
	//1 7.3
  	Print(L"System Table: 0x%08x\n",SystemTable); 
	
	//2 7.4
	Print(L"\nPress any Key to continue : \n\n");
	gBS->WaitForEvent (1, &gST->ConIn->WaitForKey, &EventIndex);
	
	
	//3 7.5
	Print(L"Enter text. Include a dot ('.') in a sentence then <Enter> to exit:\n\n");
	ZeroMem (&Key, sizeof (EFI_INPUT_KEY));
	gST->ConIn->ReadKeyStroke (gST->ConIn, &Key);
	ExitLoop = FALSE;
	do {
		gBS->WaitForEvent (1, &gST->ConIn->WaitForKey, &EventIndex);
		gST->ConIn->ReadKeyStroke (gST->ConIn, &Key);
        Print(L"%c", Key.UnicodeChar);
	    if (Key.UnicodeChar == CHAR_DOT){
			ExitLoop = TRUE;
		}
	} while (!(Key.UnicodeChar == CHAR_LINEFEED || 
		       Key.UnicodeChar == CHAR_CARRIAGE_RETURN) || 
			   !(ExitLoop) );
	
	Print(L"\n");
	
	return EFI_SUCCESS;
}