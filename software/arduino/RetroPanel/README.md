# RetroPanel

The functionality of the *RetroPanel* was put together with the *Arduino Pro Micro* in mind, specifically the 5 volt variant running at 16Mhz similar to the classic Uno. Its usage within this project is because it has a second HW-based UART available, perfectly suitable for reliable communication over RS-232 through the level conversion circuitry featured on the RetroPanel.

Consider editing *settings.h* to your liking instead of relying on run-time configuration, especially if you intend on making more than one of them. The serial interface is slightly more suitable for later configuration without a dedicated programming environment, allowing you to spend more time with ancient hardware and less time tethered to a modern laptop.

## Libraries

While the installation of libraries should be handled automatically when using PlatformIO from within Visual Studio Code, but I recognize that many will simply want to get the code onto the board while using the standard *Arduino IDE* instead. In that case you may need to install libraries manually, the ones that are currently needed are as follows:

- [BMP280_DEV](https://github.com/MartinL1/BMP280_DEV)
- [RTCLib](https://github.com/NeiroNx/RTCLib)

Some of these may seem like odd choices, but I found their more popular counterparts to be a bit too resource-heavy for what I could manage to fit onto a single *Arduino Pro Micro*. Be sure that you check that you end up installing the correct library as specified, there are many libraries with similar sounding names.