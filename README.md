## psprot - port scan protection tool
*(very old project, written around 2012)*

Linux daemon, detecting all of port scan methods (including SYN scan and UDP scan).

### Features:
- executes "ban command" specified in .conf file,
- allows to set up "trap" ports,
- allows to specify number of scans to tolerate from one IP,
- writes log to syslog/stdio,
- whitelist (with CIDR),
- rights drop to specified uid/gid.

### Build
*(uses conan to fetch required libs)*
```
cmake ../psprot/ -G Ninja
ninja
```

Daemon options:
```
-h --help Show help message (this) & exit.
-v --version Show version info & exit.
-c --config new_conf_file_path Set non-default configuration file.
-p --pidfile new_pidfile_path Set new pidfile path to new_pidfile_path.
-f --force Force run, ignores existing pidfile.
-d --daemonize Run in background.
```

Config file (pss.conf):
```
max_knock_count = 5 # maximum number of trap port knocks from one IP
tcp_trap_ports = { 5, 15, 20, 50-60 } # tcp trap ports (can be number, or range_start-rage_stop)
udp_trap_ports = { 234, 235, 236, 240-280 } # udp trap ports
write_to_syslog = false # if set to true, daemon will write all messages to syslog
whitelist = { 127.0.0.1, 128.0.0.1, 129.0.0.1 } # whitelisted IP (won't be banned)
uid = 0	# drop rights to this uid
gid = 0 # drop rights to this gid
banstring = "echo {IPNUM} >> /tmp/banned_ips" # Command to execute to ban ipnum.
```
