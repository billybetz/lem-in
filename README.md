Lem-in is an algorithm project in C from 42School.

Explications + goal : 

The input is a file with 
- a number of ants
- rooms declaration (including START room and END room) (name coord1 coord2) ex: "room1 25 25"
- links declaration (beetween rooms previously declared)
- comments (#this is a comment)
- command line with double # (##COMMAND_LINE) (## that's not a comment !)

goal : put all the ants who begin in START room in the END room with the less number of round possible
condition : - only one ant by room
            - only one deplacement by ant by round

File exemple : 
3
##START
start 5 5
##END
end 10 10
# comment : declaration of a ordinary room
room1 5 5
# another
room2 7 7
# declaration of the connection beetween the rooms
# link beetween start room and room2 room
start-room2
room2-room1
room1-end

# L1 mean : the ant number 1 
# L2 mean : the ant number 2 ... after the '-' is the name of the room where the ant is mooving on

The output :
L1-2
L1-1 L2-2
L1-end L2-1 L3-2
L2-end L3-1
L3-end

# The algorithm ended in 5 round (that was the best way here)
