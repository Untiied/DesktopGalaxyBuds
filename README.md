
# DesktopGalaxyBuds

Implementation for native galaxy bud support on all desktops.

  

## Building

To make the solution for mac or windows run Build.bat;

  

The windows build requires the winrt be be installed - https://docs.microsoft.com/en-us/windows/uwp/cpp-and-winrt-apis/get-started

One of the easiest ways to install the windows run time is through nuget.

1. Tools -> NuGet Package Manag

2. Search "C++/WinRT Visual Studio Extension (VSIX)"

3. Click install, and then procced to restart visual studio.

  

Although if you don't use visual studio you may link manually.

  

## Contributing

Pull requests are allowed, and encouraged! Larger edits to the code would require a discussion first.

  

## Direction
![enter image description here](https://media.idownloadblog.com/wp-content/uploads/2019/01/AirBuddy-Popup.png)
Credit to [idownloadblog](https://www.idownloadblog.com/2019/01/29/airbuddy-brings-proper-airpods-support-to-the-mac/) for the image.

In the end the project is looking for a clean looking user interface that allows for rapid connection with the GalaxyPods upon receiving a "notification" that the device is ready for connection. Alongside rapid connection we need to display signal strength, and the charge of each of the ear pods.

## License
[MIT](https://choosealicense.com/licenses/mit/)