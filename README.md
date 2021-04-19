# MvMp3

Move Mp3 from disk files to a single directory.

## What Will It Do?

There are two relevant commands:

 - Specify the Target Directory.  The target directory shall only have subdirectories that contain MP3
   files.
 - Specify the prefix for the files so that an useful identifier on an MP3 player.  Then move all the
   MP3 files into the target directory.

## Getting Started

CodeGen is composed of four projects and compiled with Visual Studio 2017.  The three projects are:
 - MvMp3.prj -- Source of the application.
 - MvMp3.hlp -- Help file for the application.  Use the Help Workshop.
 - Library -- This project produces a static library of which some object files are loaded into
   the executable (installer file)
 - Installer -- A Wix Toolset Installer.  Currently this file (Product.wxs) contains references to
   MvMp3.exe and MvMp3.chm.  If you wish to change the installer then I suggest you look
   at WixApp.

### Prerequisites

Of course this all depends on having an Access database, a Visual Studio 2017 +/- and the ability to
debug if things don't go right.  The Extension "Wix Toolset visual Studio 2017 Extension" is also
required.  It can be found in "Tools/Extensions and Updates".  If you wish to changed the installer then
look at the WixApp.

Microsoft HTML Help Workshop (last version).  This is the link to the last version:
```
https://docs.microsoft.com/en-us/previous-versions/windows/desktop/htmlhelp/microsoft-html-help-downloads
```

All the code is contained in the two directories, MvMp3 and Library.

### Installing

Run the "msi" installer file.

## Running the tests

Construct a TestDir which has two or more subdirectories:

 - TestDir
   o Disk0
     * Track0.mp3
     * Track1.mp3
   o Disk1
     * Track0.mp3
     * Track1.mp3

The application will translate this organization into:

 - Testdir
   o Prfx-01-001.mp3
   o Prfx-01-002.mp3
   O Prfx-02-001.mp3
   o Prfx-02-002.mp3

## Authors

Robert R. Van Tuyl, K6RWY

Contact:  romeo romeo victor tango alpha tango sam whisky delta echo dot charlie oscar mike

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details



