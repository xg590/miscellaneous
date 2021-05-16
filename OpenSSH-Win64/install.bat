REM netsh advfirewall firewall add rule name="sshd" dir=in action=allow protocol=TCP localport=2222

powershell -ExecutionPolicy Bypass -File install-sshd.ps1
powershell Start-Service -Name "sshd"
powershell Start-Service -Name "ssh-agent"
powershell Set-Service -Name "sshd" -StartupType Automatic
powershell Set-Service -Name "ssh-agent" -StartupType Automatic

icacls administrators_authorized_keys /inheritance:r
icacls administrators_authorized_keys /grant SYSTEM:(F)
icacls administrators_authorized_keys /grant BUILTIN\Administrators:(F)
icacls pri /inheritance:r
icacls pri /grant SYSTEM:(F)
icacls pri /grant BUILTIN\Administrators:(F)

move administrators_authorized_keys %PROGRAMDATA%\ssh
WSCript C:\Progra~1\openssh\ssh.vbs