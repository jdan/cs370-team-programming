N = int(raw_input())
K = int(raw_input())
candies = []

for i in range(N):
    candies.append(int(raw_input()))

candies.sort()

min_unfairness = float('inf')
for i in range(N - K):

    max_index = i + K - 1
    min_index = i

    delta =

    #max_number = candies[i + K - 1]
    #min_number = candies[i]

    unfairness = max_number - min_number



    if unfairness < min_unfairness:
        min_unfairness = unfairness

print min_unfairness
