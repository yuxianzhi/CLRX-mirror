## CLRadeonExtender Assembler

This is CLRadeonExtender assembler. This assembler can assemble code for all Radeon GPU's
that based on the GCN1.0/1.1/1.2 architecture and it can generate AMD Catalyst
OpenCL binaries and the GalliumCompute OpenCL binaries. It is compatible with GNU as
and support the almost GNU as pseudo-operations (directives) including macros and
repetitions.

### Invoking an assembler

the `clrxasm` can be invoked in following way:

```
clrxasm [-6Sw?] [-D SYM[=VALUE]] [-I PATH] [-o OUTFILE] [-b BINFORMAT]
[-g GPUDEVICE] [-A ARCH] [-t VERSION] [--defsym=SYM[=VALUE]] [--includePath=PATH]
[--output OUTFILE] [--binaryFormat=BINFORMAT] [--64bit] [--gpuType=GPUDEVICE]
[--arch=ARCH] [--driverVersion=VERSION] [--forceAddSymbols] [--noWarnings]
[--help] [--usage] [--version] [file...]
```

### Input

An assembler read source from many files. If no input file specified an assembler
will read source from standard input.

### Program options

Following options `clrxasm` can recognize:

* **<-D SYMBOL=[VALUE]**, **--defsym=SYMBOL[=VALUE]**

    Define symbol. Value is optional and if it is not given then assembler set 0 by default.
This option can be occurred many times to defining many symbols.

* **-I PATH**, **--includePath=PATH**

    Add to search path list an include path. Assembler begins search from current directory
and follows to next include paths.
This option can be occurred many times to adding many include paths.

* **-o FILENAME**, **--output=FILENAME**

    Set output file name. By default assembler write output to the 'a.out' file.

* **-b BINFORMAT**, **--binaryFormat=BINFORMAT**

    Set output binary format. This settings can be overriden in source code.
Assembler accepts following formats: 'amd', 'gallium', 'rawcode'.

* **-6**, **--64bit**

    Enable generating of the 64-bit binaries (only for AMD catalyst format).

* **-g GPUDEVICE**, **--gpuType=GPUDEVICE**

    Choose device type. Device type name is case-insensitive.
Currently is supported: 
CapeVerde, Pitcairn, Tahiti, Oland, Bonaire, Spectre, Spooky, Kalindi,
Hainan, Hawaii, Iceland, Tonga, Mullins, Fiji and Carrizo.

* **-A ARCH**, **--arch=ARCH**

    Choose device architecture. Architecture name is case-insensitive.
List of supported architectures:
GCN1.0, GCN1.1 and GCN1.2.

* **-t VERSION**, **--driverVersion=VERSION**

    Choose AMD Catalyst OpenCL driver version. Version can retrieved from clinfo program
that display field 'Driver version' where version is. Version is number in that form:
MajorVersion*100 + MinorVersion.

* **-S**, **--forceAddSymbols**

    Add all non-local symbols to binaries. By default any assembler does not add any symbols
to keep compatibility with original format.

* **-w**, **--noWarnings**

    Do not print all warnings.

* **-?**, **--help**

    Print help and list of the options.

* **--usage**

    Print usage for this program

* **--version**

    Print version

### Output

An assembler generates single output binary. If no output specified an assembler will
generate `a.out` binary file. `clrxasm` returns 0 if succeeded, otherwise
it returns 1 and prints an error messages to stderr.
