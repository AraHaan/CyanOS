1. implement kernel functions.
2. implement c99 and c++17 runtimes.
3. implement an easy to use desktop.
4. make a program permission system.
5. maybe some other useful stuff?
6. 64-bit long mode.
7. Touch screen support (Missing the needed ports to communicate using the Interrupt Descriptor Table (IDT)).
8. A fully working GUI Toolkit that implements 100% of gdiplus capabilities with wrapper methods to allow Windows Code to just Work:tm: without changes.
9. Full .NET Core 3.0 support with Windows Forms and WPF. WPF Implies that I need some way to wrap DirectX stuff somehow and use open source alternatives on the back end?
10. Full Win32 and Win64 Executable support. This would mean I would need some way to resolve Windows DLL's by wrappers for all of them which calls kernel functions that does the same (or similar) things.
