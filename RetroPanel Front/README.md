# RetroPanel Front
This is a front-facing panel for controlling the *RetroPanel*, it holds all of the LEDs, switches as well as the 7-segment display associated with the RetroPanel itself. It mounts on the [RetroPanel Module](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Module) using right-angle pin headers with slots cut into the PCBs to offer it some mechanical strength. The instructions for assembling one is mostly organized along with the main module, but the [BOM](#3-bom) included at the bottom of this document should be taken into account when ordering parts.

- [1> Building the device](#1-building-the-device)
  - [1.1> Soldering it together](#11-soldering-it-together)
- [2> Schematic](#2-schematic)
- [3> BOM](#3-bom)

# 1> Building the device
Building a device such as this assumes you have at least minor experience soldering things together, recommended is that you at the very least have access to a soldering station with adjustable temperature. If currently available, you should probably start with 60/40 rosin core solder as the lead-free alternatives tends to be a bit harder to work with.

With requirements for basic equipment sorted, we need to talk a bit about what you want to achieve while building this project. The reason I ask is that while you can build a *RetroPanel* with every feature available, it may not make sense for the computer it's going into. What I mean by that is that adding a turbo-switch wouldn't make sense unless your motherboard has a way of connecting it up. Have a read-through of the assembly instructions for the main [RetroPanel Module](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Module) for a bit more details.

Now that you know what you want to build, we can get started on the most expensive step in any build process - shopping! So, head on over to the [BOM](#3-bom)-section for some information on what kind of components that you'll need. While I would have liked to give you specific part numbers for "reputable" electronic part suppliers, I can't afford to shop there so I usually make due with what I can find on sites such as ebay, AliExpress and any similar sites that sell cheap chinese components. The downside to this is that I can't link to a part directly and expect it to stay listed, so you'll need to consider the description listed as suggested search terms.

## 1.1> Soldering it together
The construction of this unit should be fairly straight-forward, just take your time in order to make sure everything goes into place - more or less straight. I usually recommend starting by having a good look at the PCBs, try to figure out where all of the listed components go and in which orientation they go in (all of this should be clearly marked on the silkscreen). The process of building it up should be covered in the assembly-video, click the picture below to jump directly to the relevant section.

[![YouTube image](https://github.com/tebl/RetroPanel/raw/main/gallery/youtube_clip_assembling_panel.jpg)](https://www.youtube.com/watch?v=NcJ1v0hauTQ&t=729s)

The first component to go in, is a section of standard right-angle pin-headers - these are installed on the reverse of the PCB from what would otherwise be expected. The alignment must be done as neatly as you can, the easiest way of doing it is to soldering in a pin at each end - reheat and push the pin so that the plastic ends up sitting flush with the PCB. When satisfied with it, solder in the remaining pins.

Second is the switches that you need, these must have a black base at the bottom of them - this is important as the others will have a different pinout. Depending on the functionality that you need, some of these must be latching (*turbo*-switch in particular) while others must be non-latching (*reset* and the *tool*-button in particular). The power switch is a special case as it can be either, generally you want the latching variety when main unit is built **without** the smart power switch circuitry - in any other case you may prefer to use the switch already on your ATX-case.

The switches themselves has six pins and it may not be directly evident which of them is pin 1, so one common error is installing these upside down. Looking a bit closer at them you may observe that there is a square hole on the underside of them that is closer to one side, this is the square shown on the silkscreen. To avoid binding on the switches, take some care to get them sitting straight.

A faceplate is mounted on the top of the front, with 10mm hex standoffs between the two - in order to get the positioning of the LEDs correct, you should add them to the outside corners and fix them in place using M3 nuts.

Depending on what features you wanted to use it with, you may require up to three standard 5mm LEDs - these should be roughly put into place in their holes without soldering them into place. Longer pin of the LED goes into the round-shaped pad on the PCB. Temporarily adding the faceplate into place on top, allow the LEDs to fall into the cutouts made for them - only then, do you solder them into their place.

The 7-segment display can be added to the module in a couple of ways, at least two ways that I've though of so far:
- The first is to solder female machined header pins to the PCB, then insert a display with shortened pins into the header pins. This does include the joys of dealing with female machined pins such as those usually found on sockets, but at the advantage of being able to easily change out or replace the display later.
- The other is to align the display with the inside edge of the faceplate, that way the pins of the display should almost poke through to the back of the PCB. Filling the holes with a controlled amount of solder should still allow a good connection, just allow it to flow completely through to the front edge of it. 

In either case, if you cant seem to get the display to fit through the cutout on the faceplate you may need to shave a bit off the inside edges with a sharp disposable blade. The reason for this is that PCB fabrication tend to be less exact when dealing with inside edges such as these. Additionally you may find that it also becomes easier once the plastic film on the front of the displays have either been removed, or slightly trimmed down to fit the outline better (I think it's supposed to be removed, but I don't know for sure).

That should be all there is to it when it comes to assembling the front panel, for actually installing it on the main module - jump on over to the main assembly [documentation](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Module/README.md#12-adding-the-front).

# 2> Schematic
The supplied KiCad files should be sufficient as both a schematic and as a  starting point for ordering PCBs (basically you could just zip the contents of the export folder and upload that on a fabrication site), the schematic is also available in [PDF-format](https://github.com/tebl/RetroPanel/tree/main/documentation/schematic) and this is what you'll need to print and work your way through this things don't work as expected after assembly.


# 3> BOM
Most parts should be easy to get a hold of from your favourite local electronic component shop, but given that I don't have access to such shops where I live so everything was based on whatever I could get cheapest from eBay/AliExpress (free shipping, but plan on waiting 3-4 weeks for delivery). Normally I would specify the number of components in parenthesis that can be considered optional for features beyond the more basic functionality, but at this point you should already have a concise idea of what you're going to need.

| Reference             | Item                                                              | Count | Order  |
| --------------------- | ----------------------------------------------------------------- | ----- | ------ |
| Panel PCB             | Fabricate using Gerber files                                      |     1 | PCBWay
| D1-D3                 | 5mm LEDs, preferably frosted or solid colour (not the bright clear ones)          |     3 |
| J1                    | Breakable right-angle pin headers                                  |     1 |
| SW1                   | 6pin 8.5mm x 8.5mm latching switch                                |     1 |
| SW2 *1                | 6pin 8.5mm x 8.5mm latching **OR** non-latching switch                             |     1 |
| SW3,SW4               | 6pin 8.5mm x 8.5mm non-latching switch                             |     2 |
| Mounting *2         | Nylon M3 hex standoffs 10mm (M-F)                                  |     4 |
| Mounting *2         | Nylon M3x6mm nylon screws                                         |     4 |
| Mounting *2         | Nylon M3x6mm nylon nuts                                           |     4 |

1) As mentioned in the documentation, the power switch can be a a non-latching (also known as a momentary switch) when used with the smart power circuitry on the main module. When assembling a module without this functionality, you will need a latching switch here in order to turn on an ATX-PSU when used with an AT-motherboard.
2) These are available in the form of kits usually advertised *M3 nylon standoff kit* which should contain most of what you'd need. I do however recommend that you pick up extra M-F standoffs of lengths 8mm and 20mm, as quite a lot of them will be used when building more than one module.