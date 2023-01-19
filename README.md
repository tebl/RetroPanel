# RetroPanel
Having found a motherboard I really wanted to use, I found that obtaining an AT-case wasn't quite as easy as I had expected - at least none that met my demands for condition, price and availability anywhere near me. That's the short of it, see [Background](#2-background) for the full story. Anyway, my solution to my predicament was to simply use a slightly more modern ATX-case, but I wanted it to have all of the features available to even the earlies of computer generations available to me - that includes a working power switch, a turbo-switch and one of those awesome looking Mhz-displays. Add a clock and a temperature-sensor and it soon becomes apparent: such a thing, only had the potential to exist in my head.

![RetroPanel](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-16%2023.27.25.jpg)

So I made one.

![In action](https://github.com/tebl/RetroPanel/raw/main/gallery/2023-01-13%2018.41.06.jpg)

The computer isn't what I had intended to build, but I am happy with it. There are better MBs, there are faster CPU options available and the graphics card will excite no other retro enthusiast other the one I grew into - however, it is exactly the *"right"* kind of slow for the games I remember. The *RetroPanel* was the missing piece to make all of that work, and with the wonders of *open-source* you should now have everything you need to build one as well.

- [1> Versions](#1-versions)
  - [1.1> RetroPanel](#11-retropanel)
- [2> Background](#2-background)
- [3> Resources](#3-resources)
- [4> Acknowledgements](#4-acknowledgements)

# 1> Versions
While there may only be one version of the RetroPanel for quite some time, but knowing myself and the fact that it has become a form factor that I really like - in time there will be more than one version of the RetroPanel. The differences will more than likely be in core functionality, not in terms of different faceplates that should already be catered for in the standard version.

| Module                            | Description                                      |
| --------------------------------- | ------------------------------------------------ | 
| [RetroPanel](#11-retropanel)      | Standard version

## 1.1> RetroPanel
![RetroPanel](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-16%2023.27.25.jpg)

The standard version of the RetroPanel, envisioned to provide most features found on cases from even the earlies of computer generations - that includes a working power switch, a turbo-switch and one of those awesome looking Mhz-displays. With options for installing modules for adding a clock (RTC) to it as well as a temperature-sensor (BMP280).

The standard version is composed of the following set of PCBs, in the cases of alternative faceplates you would only need the one that is suitable for your needs. Follow the documentation links for specific information related to each of them, note that the documentation on building one of these units this is covered through the documentation for the main PCB ([RetroPanel Module](https://github.com/tebl/BulkyMIDI-32/tree/main/BulkyMIDI-32%20Module)).

| PCB                 | # Required    | Description                        | Documentation                      | Order      |
| ---------------------- | ----------- | ---------------------------------- | ---------------------------------- | ---------- |
| [RetroPanel Module](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Module) | 1 | Main module | [Documentation](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Module/README.md), [BOM](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Module/README.md#3-bom) | PCBWay
| [RetroPanel Front](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Front) | 1 | Front-facing board holding components | [Documentation](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Front/README.md), [BOM](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Front/README.md#3-bom) | PCBWay
| [RetroPanel Side](https://github.com/tebl/RetroPanel/tree/main/RetroPanel%20Side) | 2 | Design for the sides, you need two of these. | [Documentation](https://github.com/tebl/RetroPanel/blob/main/RetroPanel%20Side/README.md) | PCBWay
| [RetroPanel Faceplate (FP1)](https://github.com/tebl/RetroPanel/tree/main/faceplates/RetroPanel%20FP1) | 1 | Faceplate that goes on the very front of the module, this has provisions for all switches and LEDs | [Documentation](https://github.com/tebl/RetroPanel/tree/main/faceplates/RetroPanel%20FP1) | PCBWay

# 2> Background
Recently I had the glorious idea of rebuilding the first PC I bought, it was a low-budget option put together from a list of parts in the later parts of 1995. Due to sheer luck I still had some driver disks that came with it, so I knew that what I was looking for was a motherboard with the model number *P51437P4/FMB* as well as a *Cirrus Logic 5436* graphics card. Surprisingly expensive, no doubt because noone had felt like keeping the super-cheap hardware options in the first place - additionally it was an AT-motherboard with one of those clocks that you couldn't exchange the battery for.

![Old motherboard](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-18%2000.56.13.jpg)

Why does that matter? It doesn't, but the next thing does: I couldn't find an AT-case that wasn't either horribly mangled, situated around a collectors more beloved hardware or any combination of the two. Well, that's not completely true - I found and bought a case, but it was thrown from every moving postal vehicle from Poland up to where I live - bringing us back to the first point on my little list.

![RetroPanel in new case](https://github.com/tebl/RetroPanel/raw/main/gallery/2023-01-13%2018.41.06.jpg)

No doubt having already listened in on my internal dialogue, YouTube gave me a viewing recommendation for a video from [philscomputerlab](https://www.youtube.com/@philscomputerlab) - [Building the 486 DX2 66 Retro Sleeper DOS PC](https://youtu.be/9bqqpuJ7M_I). What I liked with it was that he gave me a viable option by gently reminding me that ATX-cases are still plentiful, they're even easier to match the aesthetics of as most of the little bits are still being sold. His solution for powering was to use an ATX to AT-cable and using a simple toggle switch as a power switch, as is the common way of doing it.

There's just one thing I don't like about that, is that a part of the designs of the ATX PSUs is telling the power-on circuit on your motherboard not to instantly turn it on again once a short has been detected on one of its power rails. Have you tried shorting a 35A power supply? It'll scare the crap out of you, possibly vaporizing something in the process. Add a latching switch and it may keep cycling until you remove the power lead.

![RetroPanel with PSU](https://github.com/tebl/RetroPanel/raw/main/gallery/2022-11-10%2000.19.29.jpg)

I'm not saying that the RetroPanel in any way can be considered a safety precaution, because it haven't been tested enough to give you any other guarantee other than it having worked the one time I tried it. I still wouldn't keep a vintage computer powered without being in the room with it, but it gives me the peace of mind needed to turn my back long enough to fiddle with things such as this documentation.


# 3> Resources
The following resources where used as references when creating the RetroPanel, while they are in no particular order - you may find all of them interesting when looking for more information beyond what have been provided as part of this [GitHub-repository](https://github.com/tebl/RetroPanel). 

- [AT Power Pinout](http://www.hilmanind.com/pinouts/atpwr.htm)
- [ATX Power Pinout](https://www.etechnog.com/2022/03/atx-power-supply-pinout-diagram.html)
- [ATX Momentary Switch](https://www.instructables.com/Latching-Momentary-Switch-for-ATX-PSU-Conversion/)
- [PC power supply cables and connectors](http://www.playtool.com/pages/psuconnectors/connectors.html)
- [DIY POST Card](https://bbright.tripod.com/information/postcard.htm)
- [More POST Card information](https://www.minuszerodegrees.net/misc/post_cards.htm)


# 4> Acknowledgements
Everything comes from something, in particular when it comes to most of my electronics projects. I mainly build things I would like to own, often doing a respin to fit my own particular style and preferences. In many cases the hardest parts of the designs will already have been provided by people far more knowledgable than I. In particular the smart switch circuit, was adapted from [ATX Momentary Switch](https://www.instructables.com/Latching-Momentary-Switch-for-ATX-PSU-Conversion/).