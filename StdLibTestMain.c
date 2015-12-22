#include <Uefi.h>
#include <stdio.h>
#include <StdLibTest2.h>

EFI_STATUS
EFIAPI
UefiMain (IN EFI_HANDLE  ImageHandle,IN EFI_SYSTEM_TABLE  *SystemTable)
{
    EFI_STATUS Status =0;
    CHAR8 Info [256];
    Status = InitStdLib(0,NULL);
    printf("Hello world");
    sprintf (Info, "Build Date: %s", __DATE__);
    printf("Date:%s\n",Info);
    DestroyStdLib();
    return Status;
    
}