# Rope Intranet
# Google CodeJam Round 1C (2010)
# https://code.google.com/codejam/contest/619102/dashboard#s=p0
#
# Jordan Scales <scalesjordan@gmail.com>
# for CS370
# 4 Mar 2014

cases = int(raw_input())

for n in range(cases):
    numWires = int(raw_input())
    wires = []
    intersections = 0

    for i in range(numWires):
        wire = map(int, raw_input().split(' '))

        for j in range(len(wires)):
            if wire[0] > wires[j][0] and wire[1] < wires[j][1] or \
               wire[0] < wires[j][0] and wire[1] > wires[j][1]:
                intersections += 1

        wires.append(wire)

    print 'Case #%d: %d' % (n + 1, intersections)
