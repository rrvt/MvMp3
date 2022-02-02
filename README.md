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
   * Disk0
     * Track0.mp3
     * Track1.mp3
   * Disk1
     * Track0.mp3
     * Track1.mp3

The application will translate this organization into:

 - Testdir
   * Prfx-01-001.mp3
   * Prfx-01-002.mp3
   * Prfx-02-001.mp3
   * Prfx-02-002.mp3

## Updates

### Update 01/31/22

Updates to the library, mostly about the toolbar, but also NewAllocator, and a minor addition to
Expandable.

Also scrubbed the project files to remove all references to precompiled header files which I turned off
in VS17.  Unfortnately VS does not remove all references and pch files kept cropping up.  Not only does
that slow down the compiler but the files are large...

### Update 12/18/21

While creating a template for a dialog box only application with a toolbar the Library was added to and
changed to hopefully simplify toolbar creation.  This version of the toolbar includes buttons, edit boxes,
combo boxes and drop down menus as well as the traditional 16x15 icons.

MvMp3 is a tradional App, has a traditional 16x15 pixel icon toolbar.

### Update 11/13/21

But the major changes are in the library:

  - Expandable and ExpandableP -- moved the functions out of the class to make the compilation smaller,
also fixed one bug (or feature) in the ExpandableP insert sorted function that would throw out entries
that were already in in the array.
  - FileIO -- Changed the type of path from "String&" to "TCchar*".  It turns out that automatic
conversion from String to TCchar* is easy, but the reverse is is not easy.  Also added a function to
get the length of a file given a path.
  - FineName -- Added a function to get the directory name of from a path
  - NewAllocator -- Corrected the debug dependency from if to ifdef
  - ToolBar -- Added data for drop down menus

### Update 10/31/21

Changed Resources (i.e. xxx.rc data) access so that it will work with a dll.  Changed the logic in the
About Box code.  Some other library changes.  Some corresponding changes in the application.

## Authors

Robert R. Van Tuyl, K6RWY

Contact:  romeo romeo victor tango alpha tango sam whisky delta echo dot charlie oscar mike

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details



