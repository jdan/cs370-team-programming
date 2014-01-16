## Input

Input will consist of a series of lines. No line will be more than 80 characters long, but may contain any number of words. Words consist of up to 20 upper and/or lower case letters, and will not be broken across lines. Spaces may appear freely around words, and at least one space separates multiple words on the same line. Note that words that contain the same letters but of differing case are considered to be anagrams of each other, thus tIeD and EdiT are anagrams. The file will be terminated by a line consisting of a single #.

## Output

Output will consist of a series of lines. Each line will consist of a single word that is a relative ananagram in the input dictionary. Words must be output in lexicographic (case-sensitive) order. There will always be at least one relative ananagram.

## Sample input

    ladder came tape soon leader acme RIDE lone Dreis peat
     ScAlE orb  eye  Rides dealer  NotE derail LaCeS  drIed
    noel dire Disk mace Rob dries
    #

## Sample output

    Disk
    NotE
    derail
    drIed
    eye
    ladder
    soon
