# RetroPanel Module
The standard version of the RetroPanel consists of several separate PCB designs, five in total with two of these being the duplicated side panels. The piece of documentation you're currently looking at covers the main module as well as the overall build details, but take note that many of the other boards such as the [RetroPanel Front](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Front) also comes with their own set of documenentation - so make sure that you browse around to get the full picture (especially when it comes to ordering parts). If you don't have any idea what all this is about, have a read through the [main documentation](https://github.com/tebl/RetroPanel) first.

![Completed unit](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-16%2023.27.25.jpg)
![Installed in a system](https://github.com/tebl/RetroPanel/raw/main/gallery/2023-01-13%2021.00.31.jpg)

- [1> Building the device](#1-building-the-device)
  - [1.1> Soldering it together](#11-soldering-it-together)
  - [1.2> Adding the front](#12-adding-the-front)
  - [1.3> Adding side panels](#13-adding-side-panels)
  - [1.4> Adding the cables](#14-adding-the-cables)
  - [1.5> Finishing touches](#15-finishing-touches)
- [2> Schematic](#2-schematic)
- [3> BOM](#3-bom)

# 1> Building the device
Building a device such as this assumes you have at least minor experience soldering things together, recommended is that you at the very least have access to a soldering station with adjustable temperature. If currently available, you should probably start with 60/40 rosin core solder as the lead-free alternatives tends to be a bit harder to work with.

With requirements for basic equipment sorted, we need to talk a bit about what you want to achieve while building this project. The reason I ask is that while you'll be able to find something for anyones taste in the project, at least provided that they enjoy building with vintage computer hardware. The following features can more or less be built separately:
- Panel for switches and LEDs missing from modern case
- Smart power switch
- One of the following:
    - External display for common ISA/PCI diagnostic cards
    - Arduino-driven display for use as a Mhz-display if needed, additionally the following features can be added to it:
      - Clock
      - Temperature display
      - RS-232 functionality for displaying information on the display, accessible through a simple serial interface.

[![YouTube image](https://github.com/tebl/RetroPanel/raw/main/gallery/youtube_clip_introduction.jpg)](https://youtu.be/AMw6y9zLjqE)

Now that you know what you want to build, we can get started on the most expensive step in any build process - shopping! So, head on over to the [BOM](#3-bom)-section for some information on what kind of components that you'll need.

**NB!** While I would have liked to give you specific part numbers for "reputable" electronic part suppliers, I can't afford to shop there so I usually make due with what can be found on sites such as ebay, AliExpress and other sites that sell *cheap* chinese components. The downside to this is that I can't link to a part directly and expect it to stay listed, so you'll need to consider the description listed as mere *suggested search terms*.

## 1.1> Soldering it together
The construction of this unit should be fairly straight-forward, just take your time in order to make sure everything goes into place - more or less straight. I usually recommend starting by having a good look at the PCBs, try to figure out where all of the listed components go and in which orientation they go in (all of this should be clearly marked on the silkscreen). While I would have liked to take every precaution and cover every possible combination of features, but for the purposes of this document I will assume that you're going to install every feature on the board. 

If you only want parts of it, follow along on the schematic so that you know where each part are used. If you only wanted to use this as an external display for a diagnostic card, you'll generally only install the *J9*-connector for it and almost no other component. It can easily be combined with the smart switch, if you need that - it is separate from all of the Arduino-related circuitry.

![Build 001](https://github.com/tebl/RetroPanel/raw/main/gallery/build_001.jpg)

In order to assure that the solder-jumpers are easy to set, it's a good idea to get those out of the way as the first we do - most of the information should be visible be in some form on your PCB (pin 1 out the 3 encountered will be square, with the others having a rounded shape). For example, the one marked *JP5* needs to be set according to the type of 7-segment display you've ordered, set it to *1-2* for CK (*Common Kathode*) or *2-3* for CA (*Common Anode*). *JP3* should be set to *1-2*. The safe choice for *JP1*, *JP2* and *JP4* is *2-3*, *2-3*, *2-3* though it won't be crucial unless you're building a cut-down version of the design.


When it comes to the components themselves, I will usually try to install them in the order according to their physical size. Doing it this way means you'll have an easier time keeping everything from looking crooked, but this is your board, your build and you want it perfect - don't you? If you said no, then go sit in the corner, because I worked hard on creating this for you.

I usually start by soldering in all of the resistors, ensuring that we're using the correct values in each of the positions. In some of the positions you will encounter the value specified as "0", or zero - these can be replaced with small pieces of wire. The reason that these exist is that a computer motherboard will likely expect an LED from that period in time, while you might be tempted to install something quite more modern in their place. The ones I'm referring to are usually sold as *"bright"* or *"clear"* LEDs, their efficiency is far higher than their old counterparts and for that reason you can install suitable resistors in these places to bring their brightness down (some may even require a value of 1k and above). All of that may require you to find and read the relevant datasheet, then do the needed math to find a suitable value. Or just do what I usually do: use the old style of coloured LEDs.

**NB!** Resistor *R23* directly next to the MAX232 is part of the MAX232-circuit, but you need to install it regardless of not wanting RS-232. The serial interface may have spurious issues working without it, so either add it - or - alternatively ensure that you disable the interface in the Arduino sketch before uploading it (*settings.h*).

The single diode marked *1n5819* is next, paying particular attention that the silver band of the component need to match that of the markings on the PCB. The purpose of it is to ensure that if you were to connect the USB-lead from the *Arduino Pro Micro* up to your modern laptop with the module installed in a different computer, this ensures that the Arduino won't attempt and more likely burn out while trying to power up the vintage PC. Meaning in theory you could replace it with a wire as can be shown in some of the gallery images, but this shouldn't be part of any kind of recommendation.

Sockets should be installed for the two ICs needed for the complete unit - you could probably manage without them if you know that you're using known good parts. However, they're cheap and you could probably afford to be quite so *cheap*!  I recommend tacking opposing corners into place, then reheat and push flush against the board before soldering the remaining pins.

Next to follow will be the non-polarized capacitors, the kind I use are mostly monolithic capacitors - mostly because I prefer their uniform look over the standard ceramic capacitors. Whatever the difference is, I have no idea beyond that so far they have worked as expected. The area around *U1*, the MAX232 chip, will have some rather peculiar-looking footprints - the reason for this is that the requirements are different for different versions of the chip - the slightly more expensive chip in the form of the MAX232**A** will want the regular 100nF capacitors and you should therefore add those now. The slightly cheaper is usually option will have something else as their first letter, usually a "**C**" though that stands for something else in the comparison - generally these will require polarized electrolytic capacitors added later. 

**NB!** Most electrolytic capacitors have a 100nF value (usually marked *104* directly on it), the ones that require a different value specifically have that printed on the board. Specifically I'm talking about *C8*, it is part of the smart switch and needs a value of 1000nF (this should me marked *105*).

Moving on we'll look at connectors, of which there are only two that we need to think about. As the Arduino is mutually exclusive with using the display with a diagnostic card, you'd only install *J9* when no Arduino is installed (I put my Arduino on a socket so that I can decide later). *J11* is used with RS-232, install if needed and intended. I prefer using IDC-connectors as those are properly keyed, but if you don't have any of the correct size available you may substitute them with regular straight pin-headers.

Speaking of capacitors, we'll just go ahead and install the polarized ones as well. If you opted for the cheaper variant of the MAX232-chip (the one not marked MAX232 and **A** as its first letter), there should be four of them close to this chip. Ideally you've not yet installed a bunch of non-polarized capacitors here already, if you have - then you either need to get the better chip or remove them. As polarized as they are, we need to ensure that these are always installed the right way around - the stripe on the side of the capacitor denotes the negative side of it, this should match the filled in (white) area on the footprint. When in doubt, the longer pin goes into the other hole - the one marked with an extremely tiny "+" next to it.

![Arduino Pro Micro variants](https://github.com/tebl/RetroPanel/raw/main/gallery/arduino_pro_micro.jpg)

I usually tend to solder female pin-headers to modules that I want to remove later, such as the *Arduino Pro Micro*. The *Pro Micro* unfortunately comes in a slightly wider, and a more narrow version depending on what you're used to - this is the reason for the double set of pins on one side. When using female pin-headers on the module itself, this does not matter much. However when we instead intend to solder it straight to the board, you need to make sure to solder in the version that matches your board specifically. *A2* and *A3* we give the same treatment, they're for the *clock* and *temperature* modules that we have the option of adding.

While we're already dealing with pin-headers, just go ahead and all of those that we intend to a signal from the computers motherboard at some point. That should be all of those remaining, primarily the column directly under the *Arduino Pro Micro*. Personally I tend to use different coloured pin headers for those that will connect up to a LED compared to those going to switches, mostly so that I don't have to think so hard about what's going where. They'll never go in straight the first time, so just solder in the first pin - that way you can adjust them before soldering it all the way. You will burn your fingers doing at least one of them, that's the natural law of soldering short pin-header segments. 

## 1.2> Adding the front
Soldering together the front panel will be covered as part of its [documentation](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Front/README.md#11-soldering-it-together), including a separate [BOM](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Front/README.md#3-bom). Remembering that we earlier set some jumpers according to the display that was used, also - we remembered to use a latching power switch if we had decided against installing the smart switch circuit (momentary switch when it is used).

With a completed front panel in front of you, it should easily slot into the main PCB - some resistance due to slightly crooked right-angle pin can be expected, but it shouldn't be an issue if you did your job well. When soldering it to the main board, just start with the opposing corners and ensure that it is at an almost perfect **90 degree angle**. While that sounds like something that'd be hard to do, you can easily use the sharp angle on your two side panels to check.

Do this for **both** of the outer edges!

When satisfied, solder the remaining pins. Using your most solid wire clippers to trim the excess of the pin headers from the underside.

**WARNING!** Do **NOT** use your standard side cutters as this will either dull them - OR - have them break in a spectacular fashion. By "*spectacular*" I mean sharp shrapnel, suddenly flying past your head. Failing that, at least use some sort of eye protection. 

## 1.3> Adding side panels
Start by adding some screws to each of the four corners of the PCB, with the nut on the underside - the screw should be loose, and **NOT** poke through the bottom of the nuts. You may need to temporarily remove the hex standoffs from the front panel in order to access these.

On each of the outside edges there is a cutout for another M3 nylon nut, with two of the flat edges inserted so that it'll sit flush with interior edges of the PCB (use a small set of pliers, if you're having a rough time of it with large fingers). Rougly put one of the side panels into place, inserting a short M3 screw from the outside into this middle groove - it should grab onto the nut and pull the side panel firmly into place. You may need to hold a finger on the underside to keep the nut from falling through, it's a bit fiddly though you'll soon get the hang of it. Do the same for the other side.

Put the whole construction back on a clean work surface, ideally one that isn't warped in any way. Push it gently down so that both sides as well as main PCB, sit as straight as they can. The sides will rotate slightly into the correct place, the main PCB should level itself with the nuts at the bottom ensuring that the distance becomes correct in relation to eachother (this was why the screws used here shouldn't poke through them). If unsure about any angles, use a spare PCB as a level as done earlier.

**NB!** PCBs do tend to warp slightly when heated, this is why you're gently pushing and prodding things here and there to get things right. If something straight up feels like it's scraping against the table, there may be something on the underside that have been left poking to far through. Cut it down to a reasonable height and try re-adjusting the whole thing again.

Notice that on the inside of the module, there are large SMD-pads that'll align in the intersection between the various boards. Working along the outside edges, add a lot of solder to first one of the pads and then the one near it - moving between them to distribute heat between the two, you should be able to permanently stick the two together using this now rather large blob of solder. Intentionally shorting them together, you've now welded the corner together.

Keep working until you're sure no part of it will ever come loose again, remember that this also includes the parts where the side panels interlock with the front panel. When satisfied, turn the whole thing over and keep doing there the same as well.

Remove the nuts and screws from the four corners, use them to re-attach the front panel with its faceplate again. Sorry about the back and forth, but I find that having all the pieces available at the right helps to get things right the first time.

## 1.4> Adding the cables
The RS-232 cable isn't what I was aiming at, at least at this point in the guide beyond a few short hints. It was designed to simply be a 10-wire ribbon cable, with a 2x5 IDC-connector on one side and a female DE-9 (often mistakenly described as a DB-9) on the other. Usually I a bunch of cables with 2x5 IDC-connectors on each end, then cut one end off before adding a DE-9 IDC to that end (pin 1 matched to pin 1). Given that serial cables can have all sorts of weird wiring, it's easier this way as you can control what you end up getting.

![ATX to AT cables](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-09%2023.39.49.jpg)

Over to the part you were probably wondering about, the one belonging to the smart switch in combination with cheap ATX to AT cables - normally requiring four cables:
- a *black* ground
- a *normally* green *PS_ON*
- a *normally* purple *5v Standby*
- a *normally* *gray* *PS_OK*.

That's a lot of *"normally"* to use in a description, the reason is that whoever produced the cable might not have followed the standard and just ensured that the cables went in the expected places. When in doubt, refer to this [pinout](https://www.etechnog.com/2022/03/atx-power-supply-pinout-diagram.html) so that you know what the positions of the cables you're working with. At first that might not make sense when staring at it, but once you realize that the three orange wires at the top are missing, leaving a recognizable shape in the connector - the rest should fall into place.

You should already have the *black* and *green* cables hanging off to the side on your cable, using an ATX-extension cable as a source of mostly suitable wire - you should take the oppurtunity to get rid of the spade-connector and extend these cables. The *purple* one is missing entirely so this one we need to salvage from the extension cable, a couple of needles inserted to the sides at the front should eventually release the cable from its current use - ideally without the destroying the little hooks, salvage some other similar wire and extend it as with the others. The *gray* one is also going to the white AT power-connectors, cut it and add an additional new cable going through it - we're splitting it two (meaning it should still go to the  PCs *motherboard* in addition to the *RetroPanel*).

![Soldered to the board](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-09%2023.40.31.jpg)

Solder the cables to the board, going from the outside edge these should be *black*, *gray*, *green* and then finally the *purple* one (I didn't actually have this colour cable, so it is blue in the picture). In order to ensure that these do not easily detach from the board, I usually add the shortes F-F standoff I have available to the hole next to them - adding a screw to the underside to hold it in place. A second screw is added at the top, but loosely. Adding a zip-tie around the cables and this screw, I can then tighten the screw/zip-tie to ensure that the cable harness can withstand significantly more handling before coming undone.

**WARNING!** Remember to trim the wires on the underside - we don't want these wires to accidentally short against whatever is directly beneath the module when installed in a PC. It should provide enough of a space that this isn't a problem, just don't get sloppy with it.

## 1.5> Finishing touches
Start by inserting the chips into their sockets if you have not already done so, enshure that you get the indent marking pin 1 facing towards the front panel. New chips will have their pins splayed slightly and could be hard to get into a socket, if you don't have a DIP pin-straightener then just push one side flat against the work surface. You will need to have some way of screwing it into your computer case, by far the easiest way of doing that is to superglue M3 nuts into the groove cut into the main PCB, to get the positioning correct: Put a screw through the PCB from the outside and into the nut, then use superglue to glue the nut into place. Remove the screw halfway through curing so that you don't accidentally glue that in as well. Depending on the type of case, you might not need any screws towards the front. The PCB has wide cutouts to accomodate different cases, and you may need to test that it sits flush against the front before committing to a placement - the purpose is to allow the design to be slightly moved forwards or backwards.

Unless one had been provided to you by a kit-maker, you will more than likely not have the correct firmware installed on your *Arduino Pro Micro*. The code you need can be found as part of this repository on the URL [software/arduino/RetroPanel](https://github.com/tebl/RetroPanel/tree/main/software/arduino/RetroPanel), and you will need to download a complete copy of this repository. This is accomplished by using the green button on the [main page](https://github.com/tebl/RetroPanel) of the GitHub-repository and then hitting *Download ZIP*.

Additionally, you will need to install a couple of libraries in order for the code to actually compile. The [README](https://github.com/tebl/RetroPanel/blob/main/software/arduino/RetroPanel/README.md) contains links to all of these, the easiest way of obtaining a copy of them will be to install them via your Arduino development environment. 

For Arduino Studio, open the sketch and then select the board that you have (Arduino Nano of some kind). Install the two libraries from *Tools* --> *Manage libraries...* - to search for and install the missing libraries. Check that the code now compiles, select the serial port corresponding to your module and upload the sketch.

PlatformIO should handle dependencies somewhat automatically, though I find that in practice we need to run a command for it to happen. Open up a new PlatformIO Terminal (not PowerShell, it's probably the last icon on your bottom toolbar), then run the command *"pio pkg install"*, and it should download and install the latest version of the libraries needed. Ensure that the environment selected on the bottom toolbar corresponds to the board you are using, you may need to edit *platformio.ini* if neither of the combinations is correct for you. Compile and upload the code.

Using a serial terminal connected to the *Arduino Pro Micro*, you may configure the device according to your preferences. Among the more helpful commands is the *help*-command, as that should tell you most that is needed. Settings need to be explicitly saved using the *save*-command to store them permanently to the onboard EEPROM, this helps when you're unfamiliar with the interface. For more detailed information as well as serving as a reference, see [Serial Interface](https://github.com/tebl/RetroPanel/blob/main/documentation/serial_interface.md).

# 2> Schematic
The supplied KiCad files should be sufficient as both a schematic and as a  starting point for ordering PCBs (basically you could just zip the contents of the export folder and upload that on a fabrication site), the schematic is also available in [PDF-format](https://github.com/tebl/RetroPanel/tree/main/documentation/schematic) and this is what you'll need to print and work your way through this things don't work as expected after assembly.

# 3> BOM
Most parts should be easy to get a hold of from your favourite local electronic component shop, but given that I don't have access to such shops where I live so everything was based on whatever I could get cheapest from eBay/AliExpress (free shipping, but plan on waiting 3-4 weeks for delivery). Components in parenthesis can be considered optional for features beyond the more basic functionality, but where's the fun in that? You deserve the complete package.

I've made an attempt at including everything, and possibly the feature it is associated with. Note that for this reason, one identical part will be listed several times and you need to add the counts to get the total number of parts. Remember that the front panel also has its BOM-section. I recommend picking up extra sets of pin-headers if you don't already have those available, in particular the female variety if you intend for the modules to be removable.

| Reference             | Feature               | Item                                                              | Count | Order  |
| --------------------- | --------------------- | ----------------------------------------------------------------- | ----- | ------ |
| RetroPanel Module     |                       | Fabricate using Gerber files                                      |     1 | PCBWay
| [RetroPanel Front](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Front) | | Fabricate using Gerber files |     1 | PCBWay
| [RetroPanel Side](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Side) | | Fabricate using Gerber files |     2 | PCBWay
| [RetroPanel Faceplate (FP1)](https://github.com/tebl/RetroPanel/tree/main/faceplates/RetroPanel%20FP1) *1 | | Fabricate using Gerber files |     1 | PCBWay
| A1                    | Arduino features      | Arduino Pro Micro (5v)                                            |     1 |
| A2                    | Arduino features      | DS3231-module, I2C RTC - usually marked ZS-042                    |    (1)|
| A3                    | Arduino features      | BMP280 **5V**, I2C temperature sensor                             |    (1)|
| C1-C4 *2              | RS-232                | 100nF ceramic capacitor (5mm) or 1uF electrolytic capacitor (D4mm, 2mm) |     1 |
| C5                    | RS-232                | 100nF ceramic capacitor (5mm)                                     |     1 |
| C6                    | Smart Power           | 100nF ceramic capacitor (5mm)                                     |     1 |
| C7                    | Smart Power           | 4.7uF electrolytic capacitor (2mm pin spacing)                    |     1 |
| C8                    | Smart Power           | 1000nF ceramic capacitor (5mm)                                    |     1 |
| D1                    |                       | 1N5819 Schottky diode (DO-41)                                     |     1 |
| D2                    | Smart Power           | 5mm LED                                                           |    (1)|
| J2-J6,J10,J17         |                       | 1x2 pin, straight header pins                                     |     7 |
| J7                    |                       | JVC Mini 4P Connector Floppy Power Supply Jack 2.54mm             |     1 |
| J8                    | Arduino features      | 1x4 pin straight header pins                                      |    (1)|
| J9 *3                 | External POST-display | 2x10 pin straight header pins, preferably 2x10 IDC socket         |    (1)|
| J11                   | RS-232                | 2x5 pin straight header pins, preferably 2x5 IDC socket           |     1 |
| J16                   |                       | 1x4 pin straight header pins                                      |    (1)|
| LS1                   |                       | Small passive speaker, fits pin spacing from 3.8mm  up to 8.7mm   |    (1)|
| Q1-Q4 *5              | Arduino features      | 2N3904 (TO-92), alternatively 2N3906 (TO-92)                      |     4 |
| R1,R2                 | Optional I2C modules  | 4k7 (4700) ohm resistor                                           |    (2)|
| R3,R17,R21            |                       | Used to offset resistance needed by LEDs, use wire if not needed  |    (3)|
| R4                    |                       | 470 ohm resistor                                                  |     1 |
| R5-R12                | Arduino features      | 470 ohm resistor                                                  |     8 |
| R13-R16               | Arduino features      | 3k3 (3300) ohm resistor                                           |     4 |
| R18                   | Smart Power           | 33k ohm resistor                                                  |     1 |
| R19                   | Smart Power           | 27k ohm resistor                                                  |     1 |
| R20                   | Smart Power           | 220k ohm resistor                                                 |     1 |
| R22                   | Smart Power           | 470 ohm resistor                                                  |    (1)|
| R23                   |                       | 10k ohm resistor                                                  |     1 |
| U1                    | RS-232                | MAX232 (DIP-16), preferably MAX232**A**                           |     1 |
| U2                    | Smart Power           | NE555 timer (DIP-8)                                               |     1 |
| ATX to AT cable       | Smart Power           | Cheap cables sold for ATX to AT PSU conversion                    |     1 |
| ATX extension cable   | Smart Power           | Cheap cable, used for spare parts                                 |     1 |
| Mounting              |                       | Nylon M3x6mm hex standoff (F-F)) 									|     8 |
| Mounting              |                       | Nylon M3x6mm nylon screws                                         |     8 |
| Mounting              |                       | Nylon M3x6mm nylon nuts                                           |     6 |

1) Various [faceplates](https://github.com/tebl/RetroPanel/tree/main/faceplates) will be made available as part of this project, the one linked here is simply the one with provisions for all features.
2) As mentioned in the build instructions, the value of these depend on the type of MAX232-chip used. The MAX232**A** requires 100nF capacitors, the others require 1uF electrolytic capacitors installed here (these should have a maximum diameter of 4mm, with a pin spacing of 2mm).
3) The usage of the module as an external display for common ISA/PCI diagnostic cards (also known as POST cards), requires that the 7-segment display on the front is of the Common Anode variety. This option can't be combined with the Arduiono.
4) These are used in various places of the project, these are available in the form of kits usually advertised *M3 nylon standoff kit* which should contain most of what you'd need.
5) The type of transistor depends on type of display to install on front panel, 2n3904 when used with CK (Common Kathode) displays. 2n3906 installed backwards when used with CA (Common Anode) displays.