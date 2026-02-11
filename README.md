# MvMp3

Move Mp3 from disk files to a single directory.

## What Will It Do?

There are two relevant commands:

 - Specify the Target Directory.  The target directory shall only have subdirectories that contain MP3
   files.
 - Specify the prefix for the files so that an useful identifier on an MP3 player.  Then move all the
   MP3 files into the target directory.

## Getting Started

The application is built with Visual Studio 2022 (VS22).  It was compiled with the following
properties:

  o Windows Latest SDK Version
  o Platfor Toolset: visual Studio 2022
  o MFC: Use MFC in a Shared DLL
  o Character Set:  Use Unicode Character Set
  o Additional Include Directories:
    * $(ProjectDir)
    * $(SolutionDir)..\..\Library\Library.prj\
    * $(SolutionDir)..\..\Library\DocView\
  o  Precompiled Header:  Not Using Precompiled Headers
  o  Linker/Additional Dependencies:  Htmlhelp.lib

The HTML Help Workshop (HHW), Version 4.74.8702.0 was used to prepare the help file (WixApp.chm).  It is
copied into the Release directory.  I used Dreamweaver (DW) to do most of the content production of the
help files that the HTML Help Workshop produces (i.e. HHW is used to produce the pages/files needed
and DW is used to fill in the content).

The Installer requires the Wix, HeatWave and NuGet-Tools Extensions to VS22.  WixApp (one of my
applications, see git) was used to produce the product.wxs file.

### Prerequisites

The WiX, HeatWave, NuGet-Tools Toolsets must be installed in Visual Studio.
The "HTML Help Workshop" (google it) must be installed.  Visual Studio 2022 or later.

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

### Update 2/10/26

Added ability to build in 64 bit mode.  Upgraded Wix to HeatWave version 4.

### Update 7/7/25

Improve memory leak debugging.  Factored IniFile in three classes.

### Update 12/25/24

Split the library into DocLib and Library where DocLib supports the MFC Document/Library App
projects and Library has support classes and supports the Dialog Apps with only one class.

### Update 6/27/24

Add MIT License to installation.

### Update 6/13/24

Fix WinPos.

### Update 4/18/24

Improved the way Toolbars and Window Position and size are handled.

### Update 2/17/24

Reorganized the Library so that it compiles once into Debug and Release directories under the Library
directory.

### Update 1/7/24

Library and other changes.

### Update 7/1/23

Library Update.

### Update 4/4/23

Updates to Library and application.

### Update 10/26/22

Added logic to start window in the same position and size as when it exited the last time.  Update the
toolbar background.

### Update 8/3/22

Minor Library update.

### Update 4/15/22

Big adventure in February when I started moving to a new Win11 and Visual Studio 2022.  I now
feel that this version is working in the new environment.  There were several changes made to the app
in order to compile properly on VS22.

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



