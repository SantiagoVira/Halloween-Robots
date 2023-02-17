<h1 align="center">Halloween Robots</h1>
<p align="center"> by <a href="https://github.com/SantiagoVira"><strong>Santiago Vira</strong></a></p>

# Table of Contents
- [Backstory](#backstory)
- [Constraints](#constraints)
- [Super Bowl](#super-bowl)
- [Next Robot](#next-robot)
- [What Happened](#what-happened)
- [Solutions](#solutions)
- [Design Plans](#design-plans)


## Backstory
It started in 2020. My apartment building which normally had an elaborate trick-or-treating setup had been reduced to a few tables outside in the shared garden. I saw these people in the suburbs testing out these long tubes from their porches to the front yard for a socially distanced candy experience. From that, I got an idea. What if I just had to sit there and the candy dispensed itself? Obviously, this isn’t a unique idea, vending machines have probably existed since the middle ages or something, but I thought it would be a fun simple project.

## Constraints
- I wanted to use different candies. I didn’t want to make a gumball machine, I wanted something that can take a jumbo bag of assorted candies and dispense them.
- Candy is soft
  - Mechanisms that have any chance of smushing or damaging the candy won’t work
- Cheap.
  - I wanted to use things i already had as much as possible. I would maybe spend $10-$15 on my first attempt
  - This means my design would largely rely on cardboard, hot glue, 3d printed parts, and some electronics I had lying around

## Super Bowl
The first iteration, affectionately named after a sports thing but also the plastic bowl I carved up to serve as the main hub of the project, was named Super Bowl. 
### Design
The design consisted of the afformentioned plastic bowl with a 4x3 inch rectangular hole cut into the side. Covering the whole was a cardboard scoop attached to a servo controlled by an esp32 board. In the back, the bowl had a switch to determine whether the scoop was open or closed. 
### Usage
The bowl would be place on top of a large tripod I found in my house using a wing nut that interfaced with the tripod. This allowed for more control by tilting the bowl using the tripod without having to reposition everything. The opening in the bowl was placed in front of a long paper tube made at home which balanced precariously between the bowl and a cardboard stand. The cardboard stand was painted with a ghost with the mouth of the ghost centered around the place where the candy came out. I know, I'm hilarious.
### Functionality
It worked fairly well. About as well as a cardboard and hot glue robot designed by a beginner deserves to work. The candy got stuck. A lot (this is a recurring theme remember this part). Throughout the night the robot held up and was able to dispense candy to the masses.

After Halloween night I was able to connect the esp32 to my phone over bluetooth, allowing me to remotely open the bowl without having to stand up, all by clicking a button. It was pretty cool.

[![working](/SuperBowl/SuperBowl-Demo.jpg)](/SuperBowl/SuperBowl-Demonstration.mp4)

In this image (screenshot from a video linked [here](/SuperBowl/SuperBowl-Demonstration.mp4)), Super Bowl (top left) drops candy down the tube and through the ghost where it turns into the red blur (bottom right).

## Next Robot
## What Happened
it clogged
## Solutions
## Design Plans
