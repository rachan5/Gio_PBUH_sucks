Gio_PBUH_sucks
==============


---------- old ----------

Gio, praise be upon him, sucks

I'll attach one of my first program's for ECS 60 in here.
It's called timetest.
We were suppose to compare and contrast the different data structures,
on how they inserted and deleted some numbers.
Pay attention to how the program parses the input file.
ITS MAGIC YO!
---Raymond S. Chan 


--------- new for fun (USE JAVA) ----------

<http://www.reddit.com/r/dailyprogrammer/comments/263dp1/5212014_challenge_163_intermediate_fallouts/>


Description:

The popular video games Fallout 3 and Fallout: New Vegas has a computer hacking mini game.

This game requires the player to correctly guess a password from a list of same length words. Your challenge is to implement this game yourself.

The game works like the classic game of Mastermind The player has only 4 guesses and on each incorrect guess the computer will indicate how many letter positions are correct.

For example, if the password is MIND and the player guesses MEND, the game will indicate that 3 out of 4 positions are correct (M_ND). If the password is COMPUTE and the player guesses PLAYFUL, the game will report 0/7. While some of the letters match, they're in the wrong position.

Ask the player for a difficulty (very easy, easy, average, hard, very hard), then present the player with 5 to 15 words of the same length. The length can be 4 to 15 letters. More words and letters make for a harder puzzle. The player then has 4 guesses, and on each incorrect guess indicate the number of correct positions.

Here's an example game:

Difficulty (1-5)? 3
SCORPION
FLOGGING
CROPPERS
MIGRAINE
FOOTNOTE
REFINERY
VAULTING
VICARAGE
PROTRACT
DESCENTS
Guess (4 left)? migraine
0/8 correct
Guess (3 left)? protract
2/8 correct
Guess (2 left)? croppers
8/8 correct
You win!

You can draw words from our favorite dictionary file: enable1.txt . Your program should completely ignore case when making the position checks.

Input/Output:

Using the above description, design the input/output as you desire. It should ask for a difficulty level and show a list of words and report back how many guess left and how many matches you had on your guess.

The logic and design of how many words you display and the length based on the difficulty is up to you to implement.

Easier Challenge:

The game will only give words of size 7 in the list of words.
