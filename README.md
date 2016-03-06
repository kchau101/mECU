A Miata ECU (mECU)

Overview: 
  I plan to develop an open-source ECU which runs on an STM32,
much like some of the existing ECU solutions available (rusEFI, OpenECU)
I'm pulling some design ideas and concepts from them, but hopefully
develop something of my own, tailored to my own requirements --
a 1992 Mazda MX-5 with a BP swap. 

Design Goals:
  I hope to support COP for at least 4 cylinders and with wasted spark, up to 8.
I don't want to develop a device that can do everything and the kitchen sink.
That's more suited to other more entrenched developers like Haltech, AEM, etc.
I hope to build a kit that someone can throw together really fast or buy preassmbled,
much like Megasquirt is/was. 

Q & A:
  Q: Why not Megasquirt?
    I don't really agree with their design decisions and the price is a bit
ridiculous for what you get. And I believe that having more custom solutions
for different car families is more what communities tend towards regardless.
On different forums, you hear suggestions for this or that EMS anyways, so
why not roll my own? Learn something and hopefully don't grenade my car.
