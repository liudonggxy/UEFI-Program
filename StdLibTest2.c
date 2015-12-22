#include  <errno.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <time.h>
#include  <MainData.h>
#include  <unistd.h>

#include  <Uefi.h>
#include  <Library/UefiLib.h>
#include  <Library/DebugLib.h>

#include  <Library/ShellCEntryLib.h>
#include  <Library/MemoryAllocationLib.h>
#include  <Library/TimerLib.h>

#include  <LibConfig.h>

INTN
EFIAPI
InitStdLib (
    IN UINTN Argc,
    IN CHAR16 **Argv
)
{
    struct __filedes   *mfd;
    INTN   ExitVal;
    int                 i;

    ExitVal = (INTN)RETURN_SUCCESS;
    gMD = AllocateZeroPool(sizeof(struct __MainData));
    if( gMD == NULL )
    {
        ExitVal = (INTN)RETURN_OUT_OF_RESOURCES;
    }
    else
    {
        /* Initialize data */
        extern int __sse2_available;
        
        __sse2_available      = 0;
        _fltused              = 1;
        errno                 = 0;
        EFIerrno              = 0;

        gMD->ClocksPerSecond  = 1;
        gMD->AppStartTime     = (clock_t)((UINT32)time(NULL));

        // Initialize file descriptors
        mfd = gMD->fdarray;
        for(i = 0; i < (FOPEN_MAX); ++i)
        {
            mfd[i].MyFD = (UINT16)i;
        }

        i = open("stdin:", (O_RDONLY | O_TTY_INIT), 0444);
        if(i == 0)
        {
            i = open("stdout:", (O_WRONLY | O_TTY_INIT), 0222);
            if(i == 1)
            {
                i = open("stderr:", O_WRONLY, 0222);
            }
        }   
    }
    return ExitVal;
}

void EFIAPI DestroyStdLib()
{
    if(gMD == NULL)
        FreePool(gMD);
}

int main(int argc,char **argv)
{
    return 0;
}