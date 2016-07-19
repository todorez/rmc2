### RMC (Runtime Machine Configuration)?

RMC is an open source framework for configuring the boot and initialization flow of x86 platforms at run time. This implementation of RMC builds on the knowledge gained from [RMCv1](http://git.yoctoproject.org/cgit/cgit.cgi/rmc/)

### RMC COMPONENTS

The RMC framework consists of three main components:

* **EFI application** - runs in EFI context and uses SMBIOS strings to uniquely identify hardware platforms

* **Userspace Tool** - runs in userspace context and is used to uniquely identify hardware platforms and to register new platforms with the data store

* **Data store** - stores configuration files for each supported platform

### BUILDING RMC

**Required Prerequisites**

* **libssl-dev** - Secure Sockets Layer toolkit - development files.

**Release Build**

```
make
```

**Debug Build**

```
make debug
```

### CONTRIBUTING TO RMC

Issues and pull requests will be tracked on GitHub.

### MAINTAINERS

**todor.minchev@linux.intel.com**
