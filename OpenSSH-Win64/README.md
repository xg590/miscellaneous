## OpenSSH on Windows
* Download OpenSSH-Win64.zip from [PowerShell/Win32-OpenSSH](https://github.com/PowerShell/Win32-OpenSSH/releases/)
* Create WinRAR Comment
```
;The comment below contains SFX script commands

Path=C:\Progra~1\openssh
SavePath
Setup=C:\Progra~1\openssh\install.bat
Silent=1
Shortcut=D, ssh.bat, , , ssh, 
Shortcut=T, ssh.vbs, , , ssh, 
```