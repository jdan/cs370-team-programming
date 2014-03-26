# Baylor 4238 Solution
# see README.md
#
# Jordan Scales <scalesjordan@gmail.com>
# for CS370 (Spring 2014)
# 25 Mar 2014

from math import ceil

def main():
    cases = int(raw_input())

    for i in range(cases):
        # Read in the number of blocks
        n_blocks = int(raw_input())
        block_stream = []

        # Read in the blocks (8 per line)
        for j in range(int(ceil(n_blocks / 8.0))):
            block_stream += raw_input().split(' ')

        blocks = []
        for item in block_stream:
            # Append a tuple
            # Consisting of the item split by commas, converted to ints
            blocks.append(tuple(map(int, item.split(','))))

        # A map of neighbor counts
        neighborMap = {}

        # Add the first block
        neighborMap[blocks[0]] = 0

        # Index to keep track of a block that doesn't share a face with
        # another block
        badBlockIndex = 2
        badBlockFound = False

        for (x, y, z) in blocks[1:]:
            block = (x, y, z)
            neighborMap[block] = 0

            # Add each block to the neighborMap
            for candidate in [(x-1, y, z), (x+1, y, z), \
                              (x, y-1, z), (x, y+1, z), \
                              (x, y, z-1), (x, y, z+1)]:
                if candidate in neighborMap:
                    # A neighbor is in the map!
                    # Increase the count for both our neighbor and ourselves
                    neighborMap[block] += 1
                    neighborMap[candidate] += 1

            if neighborMap[block] == 0:
                # No neighbor :(
                badBlockFound = True
                break

            # Increase the index of the "Bad Block"
            badBlockIndex += 1

        if badBlockFound:
            print '%d NO %d' % (i + 1, badBlockIndex)
        else:
            # Calculate the total surface area
            totalSurfaceArea = 0
            for entry in neighborMap:
                totalSurfaceArea += 6 - neighborMap[entry]

            print '%d %d' % (i + 1, totalSurfaceArea)

if __name__ == '__main__':
    main()
