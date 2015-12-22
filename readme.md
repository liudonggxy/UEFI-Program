Uefi routines run in QEMU
step 1 tools
1.nasm.exe in c:\nasm
2.iasl.exe in c:\asl
3.VS2012
4.qemu

step 2 config tools
1.in edksetup.bat
  add PATH = %PATH%;C:\asl;c:nasm 
2.make a BAT file names BuildApp.bat example as below
  build -p MdeModulePkg\MdeModulePkg.dsc -m MdeModulePkg\Application\StdLibTest2\StdLibTestMain.inf
3.in target.txt
  ACTIVE_PLATFORM       = OvmfPkg/OvmfPkgX64.dsc
  TARGET_ARCH           = X64
  TOOL_CHAIN_TAG        = VS2012
4.make a bat file names qemu.bat
  set path=%path%;D:\Program Files\qemu
  qemu-system-x86_64.exe -bios OVMF.fd -hda fat:hda
