## CLRadeonExtender Assembler

This is CLRadeonExtender assembler. This assembler can assemble code for all Radeon GPU's
that based on the GCN1.0/1.1/1.2/1.4 (AMD VEGA) architecture and it can generate AMD Catalyst
OpenCL binaries and the GalliumCompute OpenCL binaries. It is compatible with GNU assembler
and support the almost GNU assembler's pseudo-operations (directives) including macros and
repetitions.

### Invoking an assembler

The `clrxasm` can be invoked in following way:

clrxasm [-6Swam?] [-D SYM[=VALUE]] [-I PATH] [-o OUTFILE] [-b BINFORMAT]
[-g GPUDEVICE] [-A ARCH] [-t VERSION] [--defsym=SYM[=VALUE]] [--includePath=PATH]
[--output OUTFILE] [--binaryFormat=BINFORMAT] [--64bit] [--gpuType=GPUDEVICE]
[--arch=ARCH] [--driverVersion=VERSION] [--llvmVersion=VERSION] [--forceAddSymbols]
[--noWarnings] [--alternate] [--buggyFPLit] [--noMacroCase] [--help] [--usage]
[--version] [file...]

### Input

An assembler read source from many files. If no input file specified an assembler
will read source from standard input.

### Program options

Following options `clrxasm` can recognize:

* **-D SYMBOL[=VALUE]**, **--defsym=SYMBOL[=VALUE]**

    Define symbol. Value is optional and if it is not given then assembler set 0 by default.
This option can be occurred many times to defining many symbols.

* **-I PATH**, **--includePath=PATH**

    Add  an include path to search path list. Assembler begins search from current directory
and follows to next include paths.
This option can be occurred many times to adding many include paths.

* **-o FILENAME**, **--output=FILENAME**

    Set output file name. By default assembler write output to the 'a.out' file.

* **-b BINFORMAT**, **--binaryFormat=BINFORMAT**

    Set output binary format. This settings can be overriden in source code.
Assembler accepts following formats: 'amd', 'amdcl2', 'gallium', 'rocm', 'rawcode'.

* **-6**, **--64bit**

    Enable generating of the 64-bit binaries (only for AMD catalyst format).

* **-g GPUDEVICE**, **--gpuType=GPUDEVICE**

    Choose device type. Device type name is case-insensitive.
Currently is supported: 
CapeVerde, Pitcairn, Tahiti, Oland, Bonaire, Spectre, Spooky, Kalindi,
Hainan, Hawaii, Iceland, Tonga, Mullins, Fiji, Carrizo, Dummy, Goose, Horse, Stoney,
Ellesmere, Baffin, GFX804 and GFX900.

* **-A ARCH**, **--arch=ARCH**

    Choose device architecture. Architecture name is case-insensitive.
List of supported architectures:
SI, VI, CI, VEGA, GFX6, GFX7, GFX8, GFX9, GCN1.0, GCN1.1, GCN1.2 and GCN1.4.

* **-t VERSION**, **--driverVersion=VERSION**

    Choose AMD Catalyst OpenCL driver version. Version can retrieved from clinfo program
that display field 'Driver version' where version is. Version is number in that form:
MajorVersion*100 + MinorVersion.

* **--llvmVersion=VERSION**

    Choose LLVM compiler version. Version can be retrieved from clinfo program that display
field Version. Version is number in that form: MajorVersion*100 + MinorVersion.

* **-S**, **--forceAddSymbols**

    Add all non-local symbols to binaries. By default any assembler does not add any symbols
to keep compatibility with original format.

* **-w**, **--noWarnings**

    Do not print all warnings.

* **-a**, **--alternate**

    Enable alternate macro syntax.

* **--buggyFPLit**

    Choose old and buggy floating point literals rules (to 0.1.2 version)
for compatibility.

* **-m**, **--noMacroCase**

    Do not ignore letter's case in macro names (by default is ignored).
    
* **-?**, **--help**

    Print help and list of the options.

* **--usage**

    Print usage for this program

* **--version**

    Print version

### Environment

Following environment variables impacts on assembler work:

* CLRX_AMDOCL_PATH

    Path to AMDOCL (AMD OpenCL implementation) shared library (libamdocl32.so,
libamdocl64.so, amdocl.dll or amdocl64.dll).

* CLRX_MESAOCL_PATH

    Path to Mesa3D Gallium OpenCL (libMesaOpenCL.so or libOpenCL.so)
shared library.

* CLRX_LLVMCONFIG_PATH

    Path to llvm-config program.


### Output

An assembler generates single output binary. If no output specified an assembler will
generate `a.out` binary file. `clrxasm` returns 0 if succeeded, otherwise
it returns 1 and prints an error messages to stderr.

